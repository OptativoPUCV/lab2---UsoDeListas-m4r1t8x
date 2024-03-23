#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) 
{
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() 
{
  List* lista = create_list();
  for(int i = 1; i < 11; i++)
  {
    int *d = (int*) malloc(sizeof(int*)); 
    *d = i;
    pushBack(lista, d);
  }
  return lista;
  
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) 
{
  int *d = (int*) first(L);
  int suma = 0;
  while(d != NULL)
  {
    suma += *d;
    d = (int*) next(L);
  }
  
  return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
  int *d = (int*) first(L);
  while(d != NULL)
  {
    if(*d == elem)
       popCurrent(L);
    d = (int*) next(L);
  }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
  Stack *PN = create_stack();
  while(top(P1) != NULL)
  {
    push(PN,top(P1));
    pop(P1);
  }
  while(top(PN) != NULL)
  {
    push(P1,top(PN));
    push(P2,top(PN));
    pop(PN);
  }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena)
{
  Stack *caracter = create_stack();
  int i = 0;

  while(cadena[i] != '\0')
  {
    char *dato = (char*) malloc(sizeof(char));
    if (dato == NULL) exit(EXIT_FAILURE);
    *dato = cadena[i];
    
    if(cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '[')
      push(caracter,dato);
      
    else if(cadena[i] == ')' || cadena[i] == '}' || cadena[i] == ']' )
    {
      char *ultimoPar = (char*) top(caracter);
      pop(caracter);

      if((cadena[i] == ')' && *ultimoPar == '(') || (cadena[i] == '}' && *ultimoPar == '{') || (cadena[i] == ']' && *ultimoPar == '['))
        return 1;
    }
    
    i++;
  }
  return 0;
}

