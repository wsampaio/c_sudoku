#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "jogos.c"

#define RED      "\x1b[31m" //cores em ANSI utilizadas 
#define GRAY     "\e[0;37m"
#define RESET     "\x1b[m"


/*






*/

#define CorBordaNum "\e[0;35m"
#define CorNum "\e[1;33m"


int jogo[9][9];




void montaJogo(){
	//monta o jogo com campos preenchidos

	int n = 0;
	srand( (unsigned) time(NULL) );
	n = rand() % 5;

	for (int i=0; i<9; i++){
		for(int j=0; j<9;j++){
			jogo[i][j] = jogoPronto[n][i][j];
		}
	}
}




int confArr(int *arr){
	//para conferir se não se repetem
	//numeros na array ou se contem zero

	int arrTMP [9];
	int aux;

	for (int i=0; i<9; i++){
		arrTMP[i] = arr[i];
	}

	for (int i=0; i<9; i++){
		for(int j=0; j<9;j++){

			if(arrTMP[i] > arrTMP[j] ){
				aux = arrTMP[i]; 
				arrTMP[i] = arrTMP[j];
				arrTMP[j] = aux;

			}

			if (arrTMP[i] == 0){
				return 0;
			} else if (i>0){
				if (arrTMP[i] == arrTMP[i-1]){
					return 0;
				}
			}
		}
	}

	return 1;
}

void verX(){
	//confere a array em colunas e 
	//printa o resultado na base da coluna
	char arrTMP [9];
	int arrX[9];

	for (int i=0; i<9; i++){
		for(int j=0; j<9;j++){
			arrX[j] = jogo[j][i];
		}

		if (confArr(arrX) == 0){
			arrTMP[i] = 'X';
		} else {
			arrTMP[i] = 'O';
		}
	}


	printf("------------------------------------------\n");
	printf(
		"     %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c\n",
		arrTMP[0], 
		arrTMP[1], 
		arrTMP[2], 
		arrTMP[3], 
		arrTMP[4], 
		arrTMP[5], 
		arrTMP[6], 
		arrTMP[7], 
		arrTMP[8]
	);
}

void verY(int linha){
	//confere a array em linha e 
	//printa o resultado no final dela
	char arrTMP [9];
	int arrY[9];

	for(int i=0; i<9;i++){
		arrY[i] = jogo[linha][i];
	}

	if (confArr(arrY) == 0){
		printf(" = X");
	} else {
		printf(" = O");
	}
}

int gameover(){
	//confere todas linhas e colunas
	//a cada impressao na tela e 
	//retorna false caso alguma delas esteja incorreta

	int gameover = 1;
	int arrX[9];
	int arrY[9];

	for (int i=0; i<9; i++){
		for(int j=0; j<9;j++){
			arrX[j] = jogo[i][j];
		}
		if (confArr(arrX) == 0){
			return 0;
		}
	}

	for(int i=0; i<9;i++){
		for(int j=0; j<9;j++){
			arrY[j] = jogo[j][i];
		}

		if (confArr(arrY) == 0){
			return 0;
		}

	}

	return 1;
}


void verNums(){
	//contador os números já utilizados
	//e printa no fim da tabela

	int contaNums[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	char verNums[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	for (int i=0; i<9; i++){
		for(int j=0; j<9;j++){
			switch (jogo[i][j]){
				case 1:
					contaNums[0] += 1;
					if (contaNums[0] > 8){verNums[0] = 'X';} 
					else {verNums[0] = '1';}
					break;
				case 2:
					contaNums[1] += 1;
					if (contaNums[1] > 8){verNums[1] = 'X';} 
					else {verNums[1] = '2';}
					break;
				case 3:
					contaNums[2] += 1;
					if (contaNums[2] > 8){verNums[2] = 'X';} 
					else {verNums[2] = '3';}
					break;
				case 4:
					contaNums[3] += 1;
					if (contaNums[3] > 8){verNums[3] = 'X';} 
					else {verNums[3] = '4';}
					break;
				case 5:
					contaNums[4] += 1;
					if (contaNums[4] > 8){verNums[4] = 'X';} 
					else {verNums[4] = '5';}
					break;
				case 6:
					contaNums[5] += 1;
					if (contaNums[5] > 8){verNums[5] = 'X';} 
					else {verNums[5] = '6';}
					break;
				case 7:
					contaNums[6] += 1;
					if (contaNums[6] > 8){verNums[6] = 'X';} 
					else {verNums[6] = '7';}
					break;
				case 8:
					contaNums[7] += 1;
					if (contaNums[7] > 8){verNums[7] = 'X';} 
					else {verNums[7] = '8';}
					break;
				case 9:
					contaNums[8] += 1;
					if (contaNums[8] > 8){verNums[8] = 'X';} 
					else {verNums[8] = '9';}
					break;
					
			}
		}
	}

	printf("\n     %c  %c  %c     %c  %c  %c     %c  %c  %c\n",
		verNums[0],
		verNums[1],
		verNums[2],
		verNums[3],
		verNums[4],
		verNums[5],
		verNums[6],
		verNums[7],
		verNums[8]
	);

}


void print(){
	//monta a tabela com o jogo preenchido

	int arrLinha[9];

	system("clear");

	printf("     1  2  3  |  4  5  6  |  7  8  9\n");


	for (int x=0;x<9;x++){

		if (x%3 == 0){
			printf("------------------------------------------\n");
		}


		for (int y=0;y<9;y++){
			arrLinha[y] = jogo[x][y];
			if (y == 0){
				printf("%i | ", x + 1);
			} else {
				if (y%3 == 0){
					printf(" | ");
				} else {
					//printf("");
				}
			}

			if (arrLinha[y] == 0){
				printf(CorBordaNum "[ ]" RESET);
			} else {
				printf(CorBordaNum "[" RESET);
				printf(CorNum "%i" RESET, arrLinha[y]);
				printf(CorBordaNum "]" RESET);
			}
		}

		verY(x);
		printf("\n");
	}

	verX();
	verNums();

}


int main(){

	char *jogada;
	char *msg = "GAMEOVER - Voce saiu do jogo!\n\n";
	int x, y, val;

	montaJogo();

	while (strncmp(jogada, "q", 1)){
		print();

		if (gameover() > 0){
			msg = "GAMEOVER - VOCE VENCEU. PARABÉNS!\n\n";
			jogada = "q";
		} else {
			printf("\nDigite: Coluna/Linha/Valor (XXX) para nova jogada ou\n");
			printf("q para sair: \n\n");
			scanf("%s", jogada);

			if (strlen(jogada) == 3){
				if ( isdigit(jogada[0]) > 0){
					if ( isdigit(jogada[1]) > 0){
						if ( isdigit(jogada[2]) > 0){

							y = jogada[0] - '0';
							x = jogada[1] - '0';
							val = jogada[2] - '0';

							jogo[x-1][y-1] = val;
						}
					}
				}
			}
		}
	}

	print();
	printf("\n%s", msg);
	return 0;
}



