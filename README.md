# TDA-List
//Tarea #6 de curso Estructura de Datos y Algoritmos. Prof.: Luis Alberto Sánchez Gatica.
Definición, implementación y uso de un contenedor List con uso de iteradores

Funciones propias del contenedor List:
  
  •list_create()crea un ejemplar List con memoria dinámica y asigna NULL, NULL y 0 a sus elementos.
  
  •list_destroy(List)elimina a todos los nodos y a la lista.
  
  •list_size(List)devuelve el tamaño de la lista.
  
  •list_add(List, Type)agrega un elemento al final de la lista, e incrementa el tamaño en uno.
  
  •list_get(List, int p)devuelve el elemento en la posición p.
  
  •list_set(List, Type, int p)reemplaza el elemento en la posición ppor el valor recibido.
  
  •list_remove(List, int p)elimina ydevuelve el elemento en la posición p. Decrementa el tamaño en uno
  
  
 
 Funciones de los iteradores:

  •list_begin(List)devuelve el iterador al pre-inicio.
  
  •list_end(List)devuelve al post-final.
  
  •list_hasNext(Iterator)devuelve TRUE sólo si hay un nodo siguiente.
  
  •list_hasPrior(Iterator)devuelve TRUE sólo si hay un nodo anterior.
  
  •list_next(Iterator)devuelve un iterador a la posición siguiente.
  
  •list_prior(Iterator)devuelve un iterador a la posición anterior.
  
  •list_data(Iterator)devuelve el dato referido por el iterador.
  
