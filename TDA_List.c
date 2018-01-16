/*
 ============================================================================
 Name        : TDA_List.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main(void) {
	setbuf(stdout, NULL);
	char s1[] = "Vamos a comer";
	char s2[] = "Que bonitas vacaciones";
	char s3[] = "Salu2 j3j3p";
	char s4[] = "#ganandoComoSiempre";
	char s5[] = "prueba add";
	char s6[] = "code code code";
	char s7[] = "ya quiero terminar";
	char s8[] = "iterators are useless";
	char s9[] = "cosa bien hecha";
	char s10[]= "cosa bonita";

	char cambio[] = "soy un remplazo, iterators arent useless";

	List lista = list_create();

	list_add(lista, s1);
	list_add(lista, s2);
	list_add(lista, s3);
	list_add(lista, s4);
	list_add(lista, s5);
	list_add(lista, s6);
	list_add(lista, s7);
	list_add(lista, s8);
	list_add(lista, s9);
	list_add(lista, s10);

	Iterator ite = list_begin(lista);
	Iterator ite2 = list_end(lista);

	while (list_hasNext(ite)){
		ite = list_next(ite);
		char *i = list_data(ite);
		puts(i);
	}

	printf("\n\n");

	while (list_hasPrior(ite2)){
		ite2 = list_prior(ite2);
		char *f = list_data(ite2);
		puts(f);
	}
	ite=list_begin(lista);
	ite2=list_end(lista);

	ite2 = list_prior(ite2);
	ite2 = list_prior(ite2);
	ite2 = list_prior(ite2);

	printf("\n");
	puts(list_data(ite2));

	list_remove(lista, 1);
	list_remove(lista, 5);
	printf("%i",list_size(lista));
	list_set(lista, cambio, 1);
	printf("\n");
	puts(list_get(lista, 1));

	list_destroy(lista);

	return 0;
}
