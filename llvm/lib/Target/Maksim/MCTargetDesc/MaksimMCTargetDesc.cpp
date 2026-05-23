#include "MCTargetDesc/MaksimInfo.h"
#include "Maksim.h"
#include "MaksimInstPrinter.h"
#include "MaksimMCAsmInfo.h"
#include "TargetInfo/MaksimTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "MaksimGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "MaksimGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "MaksimGenSubtargetInfo.inc"

static MCRegisterInfo *createMaksimMCRegisterInfo(const Triple &TT) {
  MAKSIM_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitMaksimMCRegisterInfo(X, Maksim::R0);
  return X;
}

static MCInstrInfo *createMaksimMCInstrInfo() {
  MAKSIM_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitMaksimMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createMaksimMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  MAKSIM_DUMP_MAGENTA
  return createMaksimMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createMaksimMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  MAKSIM_DUMP_MAGENTA
  MCAsmInfo *MAI = new MaksimELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(Maksim::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createMaksimMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  MAKSIM_DUMP_MAGENTA
  return new MaksimInstPrinter(MAI, MII, MRI);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMaksimTargetMC() {
  MAKSIM_DUMP_MAGENTA
  Target &TheMaksimTarget = getTheMaksimTarget();
  RegisterMCAsmInfoFn X(TheMaksimTarget, createMaksimMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheMaksimTarget, createMaksimMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheMaksimTarget, createMaksimMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheMaksimTarget,
                                          createMaksimMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheMaksimTarget, createMaksimMCInstPrinter);
  // Register the MC Code Emitter.
  TargetRegistry::RegisterMCCodeEmitter(TheMaksimTarget, createMaksimMCCodeEmitter);
}
