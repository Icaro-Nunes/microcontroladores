#ifndef PORTAS_C
#include "portas.c"
#endif

#ifndef UTIL_C
#include "util.c"
#endif

#ifndef SOMADOR_LIB_C
#define SOMADOR_LIB_C

byte somaBits(__bit A, __bit B){
  byte out = 0;
  
  out = out + aND(A, B);

  out = (out<<1);
  
  out = out + xOR(A, B);
  
  return out;
}

byte somaBitCarry(__bit A, __bit B, __bit carry){
  byte out = 0;
  
  //carry bit
  out = out + oR(oR(aND(A, B),aND(B, carry)),aND(A, carry));

  out = (out<<1);
  
  //ouput bit
  out = out + xOR(xOR(A, B),carry);
  
  return out;
}

#endif
