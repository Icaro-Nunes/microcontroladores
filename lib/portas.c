#ifndef PORTAS_C
#define PORTAS_C
#include <8051.h>

__bit nOT(__bit A){
  return !A;
}

__bit aND(__bit A, __bit B){
  if(A&&B){
    return (1);
  } else {
    return (0);
  }
}

__bit nAND(__bit A, __bit B){
  if(!(A&&B)){
    return (1);
  } else {
    return (0);
  }
}

__bit oR(__bit A, __bit B){
  if(A||B){
    return (1);
  } else {
    return (0);
  }
}

__bit nOR(__bit A, __bit B){
  if(!(A||B)){
    return (1);
  } else {
    return (0);
  }
}

__bit xOR(__bit A, __bit B){
  if(A != B){
    return (1);
  } else {
    return (0);
  }
}

__bit nXOR(__bit A, __bit B){
  if(A == B){
    return (1);
  } else {
    return (0);
  }
}

#endif
