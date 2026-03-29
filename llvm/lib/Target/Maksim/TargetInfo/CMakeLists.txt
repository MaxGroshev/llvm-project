add_llvm_component_library(LLVMMaksimInfo
  MaksimTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Maksim
  )
