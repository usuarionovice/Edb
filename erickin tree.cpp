#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
	int num;
	struct No *esq;
	struct No *dir;
}tree;
tree *ca(){
	return NULL;
}
tree *ins(tree *novo,int valor){
	if(novo==NULL){
	novo=(tree*)malloc(sizeof(tree));
		novo->esq=NULL;
		novo->dir=NULL;
		novo->num=valor;
		return novo;
	}else{
		if(valor<novo->num){
			novo->esq=ins(novo->esq,valor);
		}else{
			novo->dir=ins(novo->dir,valor);
		}
	}
}
void emordem(tree *p){
	if(p!=NULL){
		emordem(p->esq);
		printf("\n %d",p->num);
		emordem(p->dir);
	}
}
bool buscar(int v,tree *p){
	if(p==NULL){
		return false;
	}else{
		if(v==p->num){
		return true;  
		}else{
			if(v<p->num){
				buscar(v,p->esq);
			}else{
				buscar(v,p->dir);
			}
		}
	}
}
int main(void){
	int i,valor;
	tree *arv1 = ca();
	printf("Insira os 12 nos\n");
	for(i=0;i<12;i++){
		fflush(stdin);
		scanf("%d",&valor);
		arv1=ins(arv1,valor);
	}
	printf("Listando arvore\n");
	emordem(arv1);
	printf("\nBuscar numero\n");
	scanf("%d",&valor);
	if(buscar(valor,arv1)==true){
		printf("Valor encontrado!!!\n");
	}else{
		printf("Valor NAO  encontrado!!!");
	}
}
