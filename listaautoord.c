/*
@autor:
 * César Villalobos
 * Estudiante: Ing.Sistemas UDI
 * 29/09/2018
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int dato;
	struct node* sgte;
}*nodo,TipoDato;

typedef struct{
	nodo inicio;
	nodo ultimo;
}*lista,tipoLista;

lista crearLista(){
	lista Lista=(lista)(malloc(sizeof(tipoLista)));
	Lista->inicio=NULL;
	Lista->ultimo=NULL;
	return Lista;
}

nodo crearnodo(int valor){
	nodo elemento=(nodo)malloc(sizeof(nodo));
	elemento -> dato=valor;
	elemento -> sgte=NULL;
	return elemento;
}

int First(lista Lista){
	int pdato;
	if(Lista->inicio==NULL){
		printf("La lista estï¿½ vacï¿½a");

	}else{
		pdato=Lista->inicio->dato;
	}
	return pdato;
}

int Last(lista Lista){
	int pdato;
	if(Lista->ultimo==NULL){
		printf("La lista esta vacia");

	}else{
		pdato=Lista->ultimo->dato;
	}
	return pdato;
}

void insertFront(int dato,lista Lista){
	nodo nuevo=crearnodo(dato);
	if(Lista->inicio==NULL){
		Lista->inicio=nuevo;
		Lista->ultimo=nuevo;
	}else{
		nuevo->sgte=Lista->inicio;
		Lista->inicio=nuevo;
	}
}

void insertLast(int dato,lista Lista){
	nodo nuevo=crearnodo(dato);
	if(Lista->ultimo==NULL){
		Lista->inicio=nuevo;
		Lista->ultimo=nuevo;
	}else{
		Lista->ultimo->sgte=nuevo;
		Lista->ultimo=nuevo;
	}
}

int deleteFront(lista Lista){
	int pdato;
	if(Lista->inicio==NULL){
		printf("La lista esta vacia");
		return 0;
	}else{
		pdato=Lista->inicio->dato;
		Lista->inicio=Lista->inicio->sgte;
		return pdato;
	}
}

int deleteLast(lista Lista){
	int ultimo;
	if(Lista->inicio==NULL){
		printf("La lista estï¿½ vacï¿½a");
	}else if(Lista->inicio->sgte==NULL){
		nodo elemento=Lista->ultimo;
		ultimo=elemento->dato;
		Lista->inicio=NULL;
		Lista->ultimo=NULL;
		free(elemento);
	}else{
		int i;
		nodo aux=Lista->inicio;
		nodo elemento=Lista->ultimo;
		ultimo=elemento->dato;
		for(i=2;i<ListaTamano(Lista);i++){
			aux=aux->sgte;
		}
		aux->sgte=elemento->sgte;
		Lista->ultimo=aux;
		free(elemento);
	}
	return ultimo;
}

int emptyList(lista Lista){
	return(Lista->inicio==NULL);
}

int ListaTamano(lista Lista){
	int tamano=0;
	nodo aux;
	aux=Lista->inicio;
	while(aux!=NULL){
		tamano++;
		aux=aux->sgte;
	}
	return tamano;
}

int Delete(int pos,lista Lista){
	int numero;
	if(pos==1){
		numero=deleteFront(Lista);
	}
	else{
		if(pos==ListaTamano(Lista)){
			numero=deleteLast(Lista);
		}
		else{
			int i;
			nodo aux=Lista->inicio;
			for(i=2;i<pos;i++){
				aux=aux->sgte;
			}
			nodo elemento=aux->sgte;
			numero=elemento->dato;
			aux->sgte=elemento->sgte;
			free(elemento);
		}
	}
	return numero;
}

void insert(int valor,int pos,lista Lista){
	if(pos==1){
		insertFront(valor,Lista);
	}else{
		int i;
		nodo elemento=crearnodo(valor);
		nodo aux=Lista->inicio;
		for(i=2;i<pos;i++){
			aux=aux->sgte;
		}
		elemento->sgte=aux->sgte;
		aux->sgte=elemento;
	}
}

int main(){
	lista a=crearLista();
	int d,b=1,c=1,i,l=2;
	nodo comp;
	scanf("%d",&b);
	insert(b,1,a);
	scanf("%d",&b);
	while(b!=0){
		if(b<a->inicio->dato){
			insert(b,1,a);
		}
		else{
			comp=a->inicio->sgte;
			l=2;
			if(comp!=NULL){
				while(comp!=NULL){
					if(comp->dato<b){
						comp=comp->sgte;
						l++;
					}else{
						insert(b,l,a);
						break;
					}
				}
			}
			if(comp==NULL){
				insert(b,l,a);
			}
		}
		scanf("%d",&b);
	}
	printf("El tamano de la lista es: %d\n",ListaTamano(a));
	while(!emptyList(a)){
		printf("%d\n",deleteFront(a));
	}
}
