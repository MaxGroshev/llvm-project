add_llvm_component_group(Maksim)

set(LLVM_TARGET_DEFINITIONS Maksim.td)

tablegen(LLVM MaksimGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MaksimGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM MaksimGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM MaksimGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM MaksimGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM MaksimGenCallingConv.inc -gen-callingconv)
tablegen(LLVM MaksimGenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(MaksimCommonTableGen)

add_llvm_target(MaksimCodeGen
  MaksimTargetMachine.cpp
  MaksimRegisterInfo.cpp
  MaksimInstrInfo.cpp
  MaksimSubtarget.cpp
  MaksimAsmPrinter.cpp
  MaksimISelDagToDag.cpp
  MaksimISelLowering.cpp
  MaksimMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  MaksimInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  Maksim
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
