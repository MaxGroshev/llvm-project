#include "../MakSim.h"
#include "llvm/Support/raw_ostream.h"

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMakSimTargetMC() { SIM_DUMP_MAGENTA }
