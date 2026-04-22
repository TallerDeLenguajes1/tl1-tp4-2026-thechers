#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
} Tarea;

typedef struct Nodo{
Tarea T;
Nodo *Siguiente;
} Nodo;

Nodo * CrearListaVacia();

int main() 
{
    Nodo *TareasPendientes, *TareasRealizadas;


    TareasPendientes = CrearListaVacia();
    TareasRealizadas = CrearListaVacia();



    return 0;
}


Nodo * CrearListaVacia()
{

    return NULL;

}

Nodo *CrearNodo()
{
   
   Nodo *NNodo = (Nodo*)malloc(sizeof(Nodo));
   NNodo->T.TareaID += 1;
   printf("Ingrese duracion de la tarea: \n");
   scanf("%d",&NNodo->T.Duracion);
   printf("Ingrese descripcion de la tarea: \n");
   NNodo->T.Descripcion = (char*)malloc(50*sizeof(char));
   gets(NNodo->T.Descripcion);
   NNodo->Siguiente = NULL;

   return NNodo;
    
    

}