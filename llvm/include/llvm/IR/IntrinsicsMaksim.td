let TargetPrefix = "maksim" in {  // All intrinsics start with "llvm.maksim.".
 
 // there is intrinsic in llvm for that, but just for POC
 
 def int_maksim_min:
   Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 def int_maksim_max:
   Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 def int_maksim_putpixel:
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_maksim_flush:
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "maksim"