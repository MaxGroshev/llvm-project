#ifndef LLVM_LIB_TARGET_MAKSIM_MCTARGETDESC_MAKSIMINFO_H
#define LLVM_LIB_TARGET_MAKSIM_MCTARGETDESC_MAKSIMINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace MaksimOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace MaksimOp

} // end namespace llvm

#endif
