#include <stdio.h>
#include <stdlib.h>
//NODE SCTRUCT
typedef struct Nodo {
	int value;
	struct Nodo* izq;
	struct Nodo* der;
}Nodo;
//NODE TREE, GLOBAL
Nodo* arbol = NULL;
Nodo* crearArbol(){
    return NULL;
}

//CREATE FUNCTION, IT CREATER A NODE EACH TIME YOU TYPE A NEW VALUE
Nodo* createNodo(){
	Nodo* newNodo = (Nodo*)malloc(sizeof(Nodo));
	if(newNodo == NULL){
		printf("Error en memoria");
		exit(0);
	}
	/*newNodo->value =  n;
	newNodo->izq =  NULL;
	newNodo->der =  NULL;*/
	return newNodo;
}/*
void insert(Nodo* arbol, int n){
	Nodo* copia = arbol;
	if (arbol == NULL){
		Nodo* newNodo = createNodo(n);
		arbol = newNodo;
		arbol1 = arbol;
	}else{
		int vRaiz = arbol1->value;
		if(n<vRaiz){
			insert(arbol1->izq,n);
			
		}else{
			insert(arbol1->der,n);
		}
	}
}*/
void insertAux(Nodo* arbol, Nodo* n){
	if(n->value < arbol->value){
		if(arbol->izq == NULL){
			arbol->izq = n;
			//arbol->izq->value = x;
		}else{
			insertAux(arbol->izq,n);
		}
	}else{
	
		if(arbol->der == NULL){
			
			arbol->der = n;
			//arbol->der->value = x;
		}else{
			
			insertAux(arbol->der,n);
		}
	}
}void insert(Nodo* n){
	if(arbol==NULL){
		//n=createNodo(x);
		arbol=n;
	}else{
		
		insertAux(arbol,n);
	}
}
void preOrdenNodos(Nodo* arbol){
	
	if (arbol==NULL)return;else{
		printf("%d\n",arbol->value );
		preOrdenNodos(arbol->izq);
		preOrdenNodos(arbol->der);
		
	}
}
void postOrdenNodos(Nodo* arbol){
	
	if (arbol==NULL)return;else{
		
		postOrdenNodos(arbol->izq);
		postOrdenNodos(arbol->der);
		printf("%d\n",arbol->value );
	}
}
void inOrdenNodos(Nodo* arbol){
	
	if (arbol==NULL)return;else{	
		inOrdenNodos(arbol->izq);
		printf("%d\n",arbol->value );
		inOrdenNodos(arbol->der);
	}
}
void freeDropTree(Nodo* arbol){
	if(arbol == NULL){
		return;
	}
	freeDropTree(arbol->izq);
	freeDropTree(arbol->der);
	free(arbol);
}

int main(){
	arbol = crearArbol();
	int op,N;
	while(1){
		printf("Choose: \n");
		printf("1) Add\n");
		printf("2) PreOrder\n");
		printf("3) InOrder\n");
		printf("4) PostOrder\n");
		printf("5) Delete\n");
		printf("6) Exit\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Type a number: " );
				scanf("%d",&N);
				Nodo* n = createNodo();
				n->value = N;
				n->izq = NULL;
				n->der = NULL;

				insert(n);
				printf("\n" );

			break;
			case 2:
				preOrdenNodos(arbol);
			break;
			case 3:
				inOrdenNodos(arbol);
			break;
			case 4:
				postOrdenNodos(arbol);
			break;
			case 5:
			break;
			case 6:
				freeDropTree(arbol);
				printf("GoodBye!:)\n");
				return 0;
			break;
			default:
			return 0;
		}
	}
}