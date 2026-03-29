#include "TargetInfo/MaksimTargetInfo.h"
#include "Maksim.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheMaksimTarget() {
  MAKSIM_DUMP_YELLOW
  static Target TheMaksimTarget;
  return TheMaksimTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMaksimTargetInfo() {
  MAKSIM_DUMP_YELLOW
  RegisterTarget<Triple::maksim> X(getTheMaksimTarget(), "maksim",
                                "Maksimulator target for LLVM course", "MAKSIM");
}
