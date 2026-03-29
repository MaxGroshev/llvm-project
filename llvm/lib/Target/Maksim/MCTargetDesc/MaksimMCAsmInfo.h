#ifndef LLVM_LIB_TARGET_MAKSIM_MCTARGETDESC_MAKSIMMCASMINFO_H
#define LLVM_LIB_TARGET_MAKSIM_MCTARGETDESC_MAKSIMMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class MaksimELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit MaksimELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MAKSIM_MCTARGETDESC_MAKSIMMCASMINFO_H