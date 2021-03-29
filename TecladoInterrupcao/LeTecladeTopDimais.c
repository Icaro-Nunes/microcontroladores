#include <8051.h>

//char disp[4] = {0,0,0,0};
char current = 0;


char VarreLinha(char Coluna){
	char retornaTecla=0;
  switch (Coluna){
		case  1:
      if(P0_4==0) retornaTecla = '1';

      if(P0_5==0) retornaTecla = '4';

      if(P0_6==0) retornaTecla = '7';

      if(P0_7==0) retornaTecla = '*';

      break;
		case  2:
      if(P0_4==0) retornaTecla = '2';

      if(P0_5==0) retornaTecla = '5';

      if(P0_6==0) retornaTecla = '8';

      if(P0_7==0) retornaTecla = '0';

      break;
		case  3:
      if(P0_4==0) retornaTecla = '3';

      if(P0_5==0) retornaTecla = '6';

      if(P0_6==0) retornaTecla = '9';

      if(P0_7==0) retornaTecla = '#';

      break;
	
		default:   break;

	}
	return retornaTecla;
}

char LerTeclado() {

	//char i;
	
  char TeclaLida=0;

  for (char i=1; i<4; i++){ // Varre Coluna
		switch (i){
	    case 1:
	    	P0_0=0;
	    	
        if (TeclaLida==0) TeclaLida = VarreLinha(i);

        P0_0=1;

        break;

	    case 2:
	    	P0_1=0;
	    	
        if (TeclaLida==0) TeclaLida = VarreLinha(i);

        P0_1=1;

        break;
	    case 3:
	    	P0_2=0;

        if (TeclaLida==0) TeclaLida = VarreLinha(i);

        P0_2=1;

        break;
	    default: break;
	  }

  }

  return TeclaLida;
}


char outputDisplay(char output){
	switch(output){
		case '#':
			return 0b01110110;
			break;
		case '*':
			return 0b01000000;
			break;
		case '0':
			return 0b00111111;
			break;
		case '1':
			return 0b00000110;
			break;
		case '2':
			return 0b01011011;
			break;
		case '3':
			return 0b01001111;
			break;
		case '4':
			return 0b01100110;
			break;
		case '5':
			return 0b01101101;
			break;
		case '6':
			return 0b01111101;
			break;
		case '7':
			return 0b00000111;
			break;
		case '8':
			return 0b01111111;
			break;
		case '9':
			return 0b01101111;
			break;
		default: break;
	}
}

void setCurrent(){
	switch(current){
		case 0:
			P3_4 = 0;
			P3_5 = 1;
			P3_6 = 1;
			P3_7 = 1;
			break;
		case 1:
			P3_4 = 1;
			P3_5 = 0;
			P3_6 = 1;
			P3_7 = 1;
			break;
		case 2:
			P3_4 = 1;
			P3_5 = 1;
			P3_6 = 0;
			P3_7 = 1;
			break;
		case 3:
			P3_4 = 1;
			P3_5 = 1;
			P3_6 = 1;
			P3_7 = 0;
			break;
	}
}

void ISR0() __interrupt 0{
		char Tecla = LerTeclado(); // Ler teclado a cada 100ms

		setCurrent();

		P2 = ~outputDisplay(Tecla);

		current++;

		if(current>3) current = 0;
}


void main(){
	IT0 = 1;
	EX0 = 1;
	EA = 1;

	while(1){
	}
}