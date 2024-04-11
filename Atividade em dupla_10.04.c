/* Crie um algoritmo que receba o nome de três disciplinas, receba três notas, entre 
zero e dez, para cada disciplina e mostre a média ponderada de cada disciplina:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define NOMES_DISCIPLINAS 3
#define QUANTIDADES_NOTAS 3
#define CARACTER 200

int main() {
	setlocale(LC_ALL,"");
	
	char disciplinas[NOMES_DISCIPLINAS][CARACTER];
	float multiplicacao = 0, notas[NOMES_DISCIPLINAS][QUANTIDADES_NOTAS], media[NOMES_DISCIPLINAS], soma = 0, peso[3] = {3,3,4};
	int i, j; 
	
		
	for(i = 0; i < NOMES_DISCIPLINAS; i++) {
		printf("Digite o nome da %iª disciplina: ", i+1);
		scanf("%s",&disciplinas[i]);
		

		for(j = 0; j < QUANTIDADES_NOTAS; j++) {	
			do {
				printf("Digite a %iª nota: ", j+1);
				scanf("%f",&notas[i][j]);
			} while(notas[i][j] < 0 || notas[i][j] > 10);
			
			soma += (notas[i][j]*peso[j]);
   		}
		
		media[i] = soma / 10;
		soma = 0;
	}
	
	printf("\n");
	
	printf("\n***Exibindo resultados***\n");
	for(i = 0; i < NOMES_DISCIPLINAS; i++) {
		printf("\nNome da disciplina: %s\n", disciplinas[i]);
		
			for(j = 0; j < QUANTIDADES_NOTAS; j++) {
			printf("%iª nota: %.1f\n", j+1, notas[i][j]);
		}
	
		printf("\nMedia: %.1f\n", media[i]);
	}
	
	return 0;
}

