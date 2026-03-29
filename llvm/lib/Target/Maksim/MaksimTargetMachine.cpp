#include "MaksimTargetMachine.h"
#include "Maksim.h"
#include "TargetInfo/MaksimTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMaksimTarget() {
  // Register the target.
  MAKSIM_DUMP_CYAN
  RegisterTargetMachine<MaksimTargetMachine> A(getTheMaksimTarget());
}

MaksimTargetMachine::MaksimTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  MAKSIM_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// Maksim Code Generator Pass Configuration Options.
class MaksimPassConfig : public TargetPassConfig {
public:
  MaksimPassConfig(MaksimTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  MaksimTargetMachine &getMaksimTargetMachine() const {
    return getTM<MaksimTargetMachine>();
  }

  bool addInstSelector() override {
    MAKSIM_DUMP_CYAN
    addPass(createMaksimISelDag(getMaksimTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *MaksimTargetMachine::createPassConfig(PassManagerBase &PM) {
  MAKSIM_DUMP_CYAN
  return new MaksimPassConfig(*this, PM);
}

TargetLoweringObjectFile *MaksimTargetMachine::getObjFileLowering() const {
  MAKSIM_DUMP_CYAN
  return TLOF.get();
}
