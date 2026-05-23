#ifndef LLVM_LIB_TARGET_MAKSIM_MCTARGETDESC_MAKSIMMCTARGETDESC_H
#define LLVM_LIB_TARGET_MAKSIM_MCTARGETDESC_MAKSIMMCTARGETDESC_H

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createMaksimMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createMaksimAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);
} // namespace llvm

// Defines symbolic names for Maksim registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "MaksimGenRegisterInfo.inc"

// Defines symbolic names for the Maksim instructions.
#define GET_INSTRINFO_ENUM
#include "MaksimGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_MAKSIM_MCTARGETDESC_MAKSIMMCTARGETDESC_H
