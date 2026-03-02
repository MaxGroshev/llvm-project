#include "TargetInfo/MakSimTargetInfo.h"
#include "MakSim.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheMakSimTarget() {
  SIM_DUMP_YELLOW
  static Target TheMakSimTarget;
  return TheMakSimTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMakSimTargetInfo() {
  SIM_DUMP_YELLOW
  RegisterTarget<Triple::maksim> X(getTheMakSimTarget(), "maksim",
                                "Maksim simulator:", "MAKSIM");
}
