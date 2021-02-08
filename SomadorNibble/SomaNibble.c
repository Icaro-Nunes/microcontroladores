#include <8051.h>
#include <portas.c>
#include <util.c>
#include <somador_lib.c>

void main(){
	__bit A0;
	__bit A1;
	__bit A2;
	__bit A3;
	
	__bit B0;
	__bit B1;
	__bit B2;
	__bit B3;

	__bit out0;
	__bit out1;
	__bit out2;
	__bit out3;
	__bit outCarry;
	byte temp_result = 0;

	while(1){
		A0 = corrigir(P2_0);
		A1 = corrigir(P2_1);
		A2 = corrigir(P2_2);
		A3 = corrigir(P2_3);

		B0 = corrigir(P2_4);
		B1 = corrigir(P2_5);
		B2 = corrigir(P2_6);
		B3 = corrigir(P2_7);
		
		temp_result = somaBits(A0, B0);
		out0 = getBit(temp_result,0);

		temp_result = somaBitCarry(A1,B1,getBit(temp_result,1));
		out1 = getBit(temp_result,0);

		temp_result = somaBitCarry(A2,B2,getBit(temp_result,1));
		out2 = getBit(temp_result,0);

		temp_result = somaBitCarry(A3,B3,getBit(temp_result,1));
		out3 = getBit(temp_result,0);
		
		outCarry = getBit(temp_result,1);

		P1_0= corrigir(out0);
		P1_1 = corrigir(out1);
		P1_2 = corrigir(out2);
		P1_3 = corrigir(out3);
		P1_4 = corrigir(outCarry);
	}
}