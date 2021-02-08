#ifndef PORTAS_C
#include "portas.c"
#endif

#ifndef UTIL_C
#include "util.c"
#endif

#ifndef MEIO_SOMADOR_C
#define MEIO_SOMADOR_C

byte somaBits(__bit A, __bit B){
  byte out = 0;
  
  out = out + aND(A, B);

  out = (out<<1);
  
  out = out + xOR(A, B);
  
  return out;
}

#endif
