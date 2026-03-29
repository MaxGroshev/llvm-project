#include "MaksimSubtarget.h"
#include "Maksim.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "maksim-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "MaksimGenSubtargetInfo.inc"

MaksimSubtarget::MaksimSubtarget(const Triple &TT, const std::string &CPU,
                           const std::string &FS, const TargetMachine &TM)
    : MaksimGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), TLInfo(TM, *this),
      FrameLowering(*this), InstrInfo() {
  MAKSIM_DUMP_CYAN
}