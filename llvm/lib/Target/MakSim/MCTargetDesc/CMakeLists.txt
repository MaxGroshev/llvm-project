add_llvm_component_library(LLVMMakSimDesc
  MakSimMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Support
  MakSimInfo

  ADD_TO_COMPONENT
  MakSim
 )
