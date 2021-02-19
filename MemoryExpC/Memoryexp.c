#include <8051.h>
#include <util.c>

void main(){
	char programa[9] = "Programa";

	byte posicao_letra_P = (byte) &programa[0];
	byte posicao_letra_a = (byte) &programa[7];
	
	while(1){
		posicao_letra_P = (byte) &programa[0];
		posicao_letra_a = (byte) &programa[7];
		
		P1 = corrigirByte(posicao_letra_P);
		P2 = corrigirByte(*((__idata char*) posicao_letra_P));
		P3 = corrigirByte(posicao_letra_a);
	}
}