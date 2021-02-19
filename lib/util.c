#ifndef PORTAS_C
#include "portas.c"
#endif

#ifndef UTIL_C
#define UTIL_C

typedef unsigned char byte;

//Gets the bit of position (pos) in the byte (word) - position based on 2 ^ (pos) notation

__bit getBit(byte word, int pos){
  byte deslocamento = word>>pos;
  __bit output = deslocamento&1;
  return output;
}

__bit corrigir(__bit A){
  return nOT(A);
}

byte corrigirByte(byte inp){
  return ~inp;
}

#endif
