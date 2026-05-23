add_llvm_component_library(LLVMMaksimDesc
  MaksimMCTargetDesc.cpp
  MaksimMCAsmInfo.cpp
  MaksimInstPrinter.cpp
  MaksimMCCodeEmitter.cpp
  MaksimAsmBackend.cpp
  MaksimELFObjectWriter.cpp

  LINK_COMPONENTS
  MC
  Support
  MaksimInfo

  ADD_TO_COMPONENT
  Maksim
 )
