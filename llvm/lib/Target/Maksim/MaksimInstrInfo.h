#ifndef LLVM_LIB_TARGET_MAKSIM_MAKSIMINSTRINFO_H
#define LLVM_LIB_TARGET_MAKSIM_MAKSIMINSTRINFO_H

#include "MaksimRegisterInfo.h"
#include "MCTargetDesc/MaksimInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "MaksimGenInstrInfo.inc"

namespace llvm {

class MaksimSubtarget;

class MaksimInstrInfo : public MaksimGenInstrInfo {
public:
  MaksimInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MAKSIM_MAKSIMINSTRINFO_H
