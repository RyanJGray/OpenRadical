// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_GCC_LIBGCC2_H
#define SCE_EE_GCC_SRC_GCC_LIBGCC2_H

typedef void (*func_ptr)(/* parameters unknown */);
typedef long int DItype;
typedef long unsigned int UDItype;
extern func_ptr __CTOR_LIST__[2];
extern func_ptr __DTOR_LIST__[2];

void __do_global_dtors();
void __do_global_ctors();
void __main();
DItype __divdi3(DItype u, DItype v);
void exit(int status);
DItype __fixunsdfdi(DFtype a);
DFtype __floatdidf(DItype u);
DItype __moddi3(DItype u, DItype v);
UDItype __udivdi3(UDItype n, UDItype d);
UDItype __umoddi3(UDItype u, UDItype v);
DItype __muldi3(DItype u, DItype v);
DItype __fixdfdi(DFtype a);

#endif // SCE_EE_GCC_SRC_GCC_LIBGCC2_H
