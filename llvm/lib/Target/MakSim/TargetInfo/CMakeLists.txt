add_llvm_component_library(LLVMMakSimInfo
  MakSimTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  MakSim
  )
