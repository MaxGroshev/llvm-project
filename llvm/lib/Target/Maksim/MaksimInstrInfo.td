//===----------------------------------------------------------------------===//
// Maksim profiles and nodes
//===----------------------------------------------------------------------===//

def maksim_ret      : SDNode<"MaksimISD::RET", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "MaksimInstrFormats.td"

//===----------------------------------------------------------------------===//
// Maksim Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

class MaksimmAsmOperand<int width> : AsmOperandClass {
  let Name = "Maksimm" # width;
  let RenderMethod = "addImmOperands";
  let DiagnosticType = !strconcat("Invalid", Name);
}

def maksimm16 : Operand<i32>, ImmLeaf<i32, [{return isInt<16>(Imm);}]> {
  let ParserMatchClass = MaksimmAsmOperand<16>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeMaksimmOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_MAKSIMM16";
  let OperandNamespace = "MaksimOp";
}

//===----------------------------------------------------------------------===//
// Maksim Instructions
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1 in
def BR : MaksimInst<0x0, (outs), (ins GPR:$rs1), "BR $rs1",
                  [(brind GPR:$rs1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : MaksimPseudoInst<(outs), (ins), "# PseudoRET",
                [(maksim_ret)]>,
                PseudoInstExpansion<(BR R0)>;

// movli
let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1 in
def MOVLI : MaksimInst<0x0, (outs GPR:$rd), (ins maksimm16:$imm),
                     "MOVli $rd $imm",
                     [(set GPR:$rd, maksimm16:$imm)]>;
