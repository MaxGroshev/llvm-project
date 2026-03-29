#include "MaksimInstrInfo.h"
#include "Maksim.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "MaksimGenInstrInfo.inc"

#define DEBUG_TYPE "Maksim-inst-info"

MaksimInstrInfo::MaksimInstrInfo() : MaksimGenInstrInfo() { MAKSIM_DUMP_GREEN }
