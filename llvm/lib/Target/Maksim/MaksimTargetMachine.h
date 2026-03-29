#ifndef LLVM_LIB_TARGET_MAKSIM_MAKSIMTARGETMACHINE_H
#define LLVM_LIB_TARGET_MAKSIM_MAKSIMTARGETMACHINE_H

#include "MaksimSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheMaksimTarget;

class MaksimTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  MaksimSubtarget Subtarget;

public:
  MaksimTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const MaksimSubtarget *getSubtargetImpl(const Function &) const override {
    MAKSIM_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_MAKSIM_MAKSIMTARGETMACHINE_H
