#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Para a estruturacao dos nos
typedef struct no {
	int data;
	struct no *esquerda;
	struct no *direita;
	struct no *pai;
} no;

typedef struct ARV{
	no *root;
}ARV;
ARV binaria;

void initARV(ARV arv);
void initNO(no* n, int recebe_n);
void aplica_no(int recebe_valor);
void busca_preordem(no* root);
void initARV(ARV arv)
{
	arv.root = NULL;
}

//Criacao de novos nos
void initNO(no* n, int recebe_n){
	if(!n)
	{
		printf("Ops! Houve algum erro. Analise o codigo novamente.\n");
		return;
	}
	n->pai = NULL;
	n->esquerda = NULL;
	n->direita = NULL;
	n->data = recebe_n;
}

//Ordenamento
void aplica_no(int recebe_valor) 
{
	no* perc_no = binaria.root;
	no* pai;

	no* NoCria = (no*) malloc(sizeof(no));
	initNO(NoCria, recebe_valor);
	printf("\nNo %d inserido! ", NoCria->data);
	
	if(perc_no == NULL)
	{
		binaria.root = NoCria;
		printf("Posicao: No RAIZ.");
		return;
	}
	
	while(perc_no){
		pai = perc_no;
		if(NoCria->data < perc_no->data){
			perc_no = perc_no->esquerda;
			if(!perc_no){
				printf("Posicao: <- esquerda do no %d.", pai->data);
				pai->esquerda = NoCria;
				return;
			}
		}
		else{
			perc_no = perc_no->direita;
			if(!perc_no){
				printf("Posicao: -> direita do no %d.", pai->data);
				pai->direita = NoCria;
				return;
			}
		}
	}
}

//Pre-ordem
void busca_preordem(no* root){
	if(root){
		printf(" %d ", root->data);
		busca_preordem(root->esquerda);
		busca_preordem(root->direita);
	}
}


int main()
{

//Numeros abaixo apenas exemplificativos:

	initARV(binaria);
	
	aplica_no(2);
	aplica_no(2);
	aplica_no(0);
	aplica_no(2);
	aplica_no(9);
	aplica_no(5);
	aplica_no(5);
	aplica_no(0);
	aplica_no(6);
	
	printf("\n");
	printf("\nResultado da busca pre-ordem: \n\n");
	busca_preordem(binaria.root);
	printf("\n");

}
