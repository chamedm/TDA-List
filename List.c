/*
 * List.c
 *
 *  Created on: 11 abr. 2017
 *      Author: Chavez
 */

#include <stdlib.h>
#include "List.h"

struct node {
	struct node *prior, *next;
	Type data;
};

struct list {
	Node first, last, preFirst, postLast;
	int size;
};

List list_create(){ //crea un ejemplar List y asigna NULL, NULL y 0 a sus elementos.
	List l = calloc(1, sizeof(struct list));
	Iterator preF = calloc(1, sizeof(struct node)); // l->preFirst = calloc...
	Iterator posL = calloc(1, sizeof(struct node));// l->postLast = calloc...
	l->preFirst = preF;
	l->postLast = posL;
	return l;
}

int  list_size(List l){//devuelve el tamaño de la lista
	return l->size;
}

void list_add(List l, Type t){//agrega 1 elemento al final de la lista, ++ size
	Node n=calloc(1, sizeof(struct node));
	n->data = t;

	if(l->size == 0){
		l->first = l->last = n;
		l->preFirst->next = n;
		l->postLast->prior = n;
	}
	else{
		n->prior = l->last;
		l->last->next = n;
		l->last = n;
		l->postLast->prior = n;
	}
	l->size ++;
}

Type list_get(List l, int p){//devuelve el elemento en la posición p
	Node current;
	int i;
	current = l->first;
	if (l->size < p)
		return NULL;
	else{
		for(i=1; i<p; i++){
			current = current->next;
		}
		return current->data;
	}
}

void list_set(List l, Type t, int p){//reemplaza el elemento en la posición p por el valor recibido.
	//falto! : poner condicion de si p>size
	Node current;
	int i;
	current = l->first;
	for(i=1; i<p; i++){
		current = current->next;
	}
	current->data = t;


}

Type list_remove(List l, int p){//elimina y devuelve el elemento en la posición p. Decrementa el tamaño en uno.
	Node current;
	int i;

	if (l->size < p){
		return NULL;
	}
	else if(p == 1){
		current = l->first;
		l->first = current->next;
		current->next->prior = NULL;
		l->preFirst->next = l->postLast->prior;
		l->size --;
		return current->data;
		free(current);
	}

	else if(l->size == p){
		current = l->first;
		for(i=1; i<p; i++)
			current = current->next;
		l->size --;
		current->prior->next = l->postLast;
		l->postLast->prior = current->prior;
		return current->data;
		free(current);
	}

	else{
		current = l->first;
		for(i=1; i<p; i++)
			current = current->next;
		l->size--;
		current->prior->next = current->next;
		current->next->prior = current->prior;

		return current->data;
		free(current);
	}
}

void list_destroy(List l){//elimina a todos los nodos y a la lista.
	Node current;
	Node tempNode;
	int i;
	current = l->first;
	while(current != NULL){
		for(i=1; i==l->size; i++){
			current = current->next;
			tempNode = current;
			free(current);
			current = tempNode;
		}

	}
	free(l);
}

Iterator list_begin(List l){//devuelve el iterador al pre-inicio.
	return l->preFirst;
}

Iterator list_end(List l){//devuelve el iterador al post-final
	return l->postLast;

}
Bool list_hasNext(Iterator it){//devuelve TRUE si hay un nodo siguiente
	if (it->next != NULL)
		return 1;
	else
		return 0;

}
Bool list_hasPrior(Iterator it){//devuelve TRUE si hay un nodo anterior
	if ( it->prior != NULL)
		return 1;
	else
		return 0;

}
Iterator list_next(Iterator it){//devuelve un iterador a la posicion siguiente
	it = it->next;
	return it;
}
Iterator list_prior(Iterator it){//devuelve un iterador a la posicion anterior
	it = it->prior;
	return it;
}
Type list_data(Iterator it){//devuelve el dato referido por el iterador
	return it->data;
}


