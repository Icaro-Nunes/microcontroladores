#include <8051.h>
#include <portas.c>
#include <util.c>

void main(){
	__bit A;
	__bit B;
	__bit out;
	__bit carry;

	while(1){
		A = corrigir(P2_0);
		B = corrigir(P2_1);

		out = xOR(A,B);
		carry = aND(A,B);

		P2_6 = corrigir(out);
		P2_7 = corrigir(carry);
	}
}