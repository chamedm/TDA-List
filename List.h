/*
 * List.h
 *
 *  Created on: 11 abr. 2017
 *      Author: Chavez
 */

#ifndef LIST_H_
#define LIST_H_

typedef struct list * List;
typedef void * Type;
typedef enum{false, true}Bool;
typedef struct node * Node;
typedef Node Iterator;

List list_create();
void list_destroy(List);
int  list_size(List);
void list_add(List, Type);
Type list_get(List, int p);
void list_set(List, Type, int p);
Type list_remove(List, int p);

Iterator list_begin(List);
Iterator list_end(List);
Bool list_hasNext(Iterator);
Bool list_hasPrior(Iterator);
Iterator list_next(Iterator);
Iterator list_prior(Iterator);
Type list_data(Iterator);



#endif /* LIST_H_ */
