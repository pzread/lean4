// Lean compiler output
// Module: Init.Lean.Runtime
// Imports: Init.Core
#include "runtime/lean.h"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* l_Lean_closureMaxArgs___closed__1;
lean_object* l_Lean_maxSmallNatFn___boxed(lean_object*);
lean_object* lean_closure_max_args(lean_object*);
lean_object* lean_max_small_nat(lean_object*);
lean_object* l_Lean_closureMaxArgs;
lean_object* l_Lean_maxSmallNat;
lean_object* l_Lean_closureMaxArgsFn___boxed(lean_object*);
lean_object* l_Lean_maxSmallNat___closed__1;
lean_object* l_Lean_closureMaxArgsFn___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_closure_max_args(x_1);
return x_2;
}
}
lean_object* l_Lean_maxSmallNatFn___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_max_small_nat(x_1);
return x_2;
}
}
lean_object* _init_l_Lean_closureMaxArgs___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_box(0);
x_2 = lean_closure_max_args(x_1);
return x_2;
}
}
lean_object* _init_l_Lean_closureMaxArgs() {
_start:
{
lean_object* x_1; 
x_1 = l_Lean_closureMaxArgs___closed__1;
return x_1;
}
}
lean_object* _init_l_Lean_maxSmallNat___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_box(0);
x_2 = lean_max_small_nat(x_1);
return x_2;
}
}
lean_object* _init_l_Lean_maxSmallNat() {
_start:
{
lean_object* x_1; 
x_1 = l_Lean_maxSmallNat___closed__1;
return x_1;
}
}
lean_object* initialize_Init_Core(lean_object*);
static bool _G_initialized = false;
lean_object* initialize_Init_Lean_Runtime(lean_object* w) {
if (_G_initialized) return w;
_G_initialized = true;
if (lean_io_result_is_error(w)) return w;
w = initialize_Init_Core(w);
if (lean_io_result_is_error(w)) return w;
l_Lean_closureMaxArgs___closed__1 = _init_l_Lean_closureMaxArgs___closed__1();
lean_mark_persistent(l_Lean_closureMaxArgs___closed__1);
l_Lean_closureMaxArgs = _init_l_Lean_closureMaxArgs();
lean_mark_persistent(l_Lean_closureMaxArgs);
l_Lean_maxSmallNat___closed__1 = _init_l_Lean_maxSmallNat___closed__1();
lean_mark_persistent(l_Lean_maxSmallNat___closed__1);
l_Lean_maxSmallNat = _init_l_Lean_maxSmallNat();
lean_mark_persistent(l_Lean_maxSmallNat);
return w;
}
#ifdef __cplusplus
}
#endif
