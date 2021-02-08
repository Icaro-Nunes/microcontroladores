#ifndef PORTAS_C
#include "portas.c"
#endif

#ifndef MEIO_SOMADOR_C
#define MEIO_SOMADOR_C


void somaBits(__bit A, __bit B, __bit * out, __bit * carry){
  *out = xOR(A, B);
  *carry = aND(A, B);
}
#endif
