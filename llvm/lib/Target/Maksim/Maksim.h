#ifndef LLVM_LIB_TARGET_Maksim_Maksim_H
#define LLVM_LIB_TARGET_Maksim_Maksim_H

#include "MCTargetDesc/MaksimMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define MAKSIM_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define MAKSIM_DUMP(Color) {}

#define MAKSIM_DUMP_RED MAKSIM_DUMP(llvm::raw_ostream::RED)
#define MAKSIM_DUMP_GREEN MAKSIM_DUMP(llvm::raw_ostream::GREEN)
#define MAKSIM_DUMP_YELLOW MAKSIM_DUMP(llvm::raw_ostream::YELLOW)
#define MAKSIM_DUMP_CYAN MAKSIM_DUMP(llvm::raw_ostream::CYAN)
#define MAKSIM_DUMP_MAGENTA MAKSIM_DUMP(llvm::raw_ostream::MAGENTA)
#define MAKSIM_DUMP_WHITE MAKSIM_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class MaksimTargetMachine;
class FunctionPass;
class MaksimSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerMaksimMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerMaksimMachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createMaksimISelDag(MaksimTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_Maksim_Maksim_H