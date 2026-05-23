let TargetPrefix = "maksim" in {  // All intrinsics start with "llvm.maksim.".
 
 def int_maksim_putpixel:
   Intrinsic<[], [llvm_double_ty, llvm_double_ty, llvm_double_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_maksim_flush:
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "maksim"