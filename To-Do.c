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
struct Nodo *Siguiente;
} Nodo;

Nodo * CrearListaVacia();
Nodo *CrearNodo(Nodo* TareasPendientes,int cont);
void insertarAlInicio(Nodo **Start,Nodo *NNodo);

int main() 
{
    int num,cont=0;
    Nodo *TareasPendientes, *TareasRealizadas,*NNodo;


    TareasPendientes = CrearListaVacia();
    TareasRealizadas = CrearListaVacia();

    printf("Desea ingresar una tarea?\n1.Si\n2.No\n");
    scanf("%d",&num);

    while (num != 2)
    {
    cont++;
      NNodo = CrearNodo(TareasPendientes,cont);
      insertarAlInicio(&TareasPendientes,NNodo);
      
      printf("Desea ingresar otra tarea?\n1.Si\n2.No\n");
        scanf("%d",&num);  
    }
    

    return 0;
}


Nodo * CrearListaVacia()
{

    return NULL;

}

Nodo *CrearNodo(Nodo* TareasPendientes, int cont)
{
   Nodo *NNodo = (Nodo*)malloc(sizeof(Nodo));

  if (TareasPendientes)
  {
   NNodo->T.TareaID = cont + 1000;
   printf("Ingrese duracion de la tarea: \n");
   scanf("%d",&NNodo->T.Duracion);
   printf("Ingrese descripcion de la tarea: \n");
   fflush(stdin);
   NNodo->T.Descripcion = (char*)malloc(50*sizeof(char));
   gets(NNodo->T.Descripcion);
   NNodo->Siguiente = NULL;

   
  }
  else{
   NNodo->T.TareaID = 1000;
   printf("Ingrese duracion de la tarea: \n");
   scanf("%d",&NNodo->T.Duracion);
   printf("Ingrese descripcion de la tarea: \n");
   NNodo->T.Descripcion = (char*)malloc(50*sizeof(char));
   gets(NNodo->T.Descripcion);
   NNodo->Siguiente = NULL;
        
  }
    
     return NNodo; 
    

}

void insertarAlInicio(Nodo **Start,Nodo *NNodo) 
{
   NNodo->Siguiente = *Start;
   *Start = NNodo;
    
}