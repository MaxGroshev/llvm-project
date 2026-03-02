add_llvm_component_group(MakSim)

add_llvm_target(MakSimCodeGen
  MakSimTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  MakSimInfo

  ADD_TO_COMPONENT
  MakSim
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
