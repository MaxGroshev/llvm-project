#include "MaksimRegisterInfo.h"
#include "Maksim.h"
#include "MaksimFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "MaksimGenRegisterInfo.inc"

MaksimRegisterInfo::MaksimRegisterInfo() : MaksimGenRegisterInfo(Maksim::R0) {
  MAKSIM_DUMP_GREEN
}
const MCPhysReg *
MaksimRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  MAKSIM_DUMP_GREEN
  return CSR_Maksim_SaveList;
}

BitVector MaksimRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  MAKSIM_DUMP_GREEN
  MaksimFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Maksim::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Maksim::R2);
  }
  return Reserved;
}

bool MaksimRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool MaksimRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  MAKSIM_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register MaksimRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  MAKSIM_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Maksim::R2 : Maksim::R1;
}

const uint32_t *
MaksimRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  MAKSIM_DUMP_GREEN
  return CSR_Maksim_RegMask;
}
