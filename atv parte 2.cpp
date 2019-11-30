#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
	int num;
	struct No *esq;
	struct No *dir;
}tree;
No *MaiorDireita(tree *no){
    if(no->dir != NULL) 
       return MaiorDireita(no->dir);
    else{
       tree *aux = no;
       if(no->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esq!
          no = no->esq;
       else
          no = NULL;
       return aux;
       }
}

No *MenorEsquerda(tree *no){
    if(no->esq != NULL) 
       return MenorEsquerda(no->esq);
    else{
       tree *aux = no; 
       if(no->dir != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da dir!
          no = no->dir;
       else
          no = NULL;
       return aux;
       }
}

void remover(tree *pRaiz, int num){
    if(pRaiz == NULL){   // esta verificacao serve para caso o num nao exista na arvore.
       printf("Numero nao existe na arvore!");
       
       return;
    }
    if(num < pRaiz->num)
       remover(pRaiz->esq, num);
    else 
       if(num > pRaiz->num)
          remover(pRaiz->dir, num);
       else{    // se nao eh menor nem maior, logo, eh o num que estou procurando! :)
          tree *pAux = pRaiz;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
          if ((pRaiz->esq == NULL) && (pRaiz->dir == NULL)){         // se nao houver filhos...
                free(pAux);
                pRaiz = NULL; 
               }
          else{     // so tem o filho da dir
             if (pRaiz->esq == NULL){
                pRaiz = pRaiz->dir;
                pAux->dir = NULL;
                free(pAux); pAux = NULL;
                }
             else{            //so tem filho da esq
                if (pRaiz->dir == NULL){
                    pRaiz = pRaiz->esq;
                    pAux->esq = NULL;
                    free(pAux); pAux = NULL;
                    }
                else{       //Escolhi fazer o maior filho direito da subarvore esq.
                   pAux = MaiorDireita(pRaiz->esq); //se vc quiser usar o Menor da esq, so o que mudaria seria isso:
                   pAux->esq = pRaiz->esq;          //        pAux = MenorEsquerda(&(*pRaiz)->dir);
                   pAux->dir = pRaiz->dir;
                   pRaiz->esq = pRaiz->dir = NULL;
                   free(pRaiz);  pRaiz = pAux;  pAux = NULL;   
                   }
                }
             }
          }
}

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
	printf("\nBuscar num\n");
	scanf("%d",&valor);
	if(buscar(valor,arv1)==true){
		printf("Valor encontrado!!!\n");
	}else{
		printf("Valor NAO  encontrado!!!");
	}
	printf("insira o valor para remover\n");
	fflush(stdin);
	scanf("%d",&valor);
	remover(arv1,valor);
	emordem(arv1);
}
