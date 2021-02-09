#include <8051.h>
#include <portas.c>
#include <util.c>

void main(){
	__bit J;
	__bit K;
	__bit state = 0;
	__bit clockTransition = 0;
	byte count = 0;
	__bit out;

	while(1){
		count++;
		
		if(count == 10){
			clockTransition = 1;
			P2_6 = corrigir(clockTransition);
			count = 0;
		} else {
			clockTransition = 0;
			P2_6 = corrigir(clockTransition);
		}

		J = corrigir(P2_0);
		K = corrigir(P2_1);

		if(clockTransition){
			if(state){
				state = xOR(K,state);
			} else {
				state = xOR(J,state);
			}
		}

		P2_7 = corrigir(state);
	}
}