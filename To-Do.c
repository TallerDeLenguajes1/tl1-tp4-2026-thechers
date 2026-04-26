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
void insertarAlFinal(Nodo *Start,Nodo *NNodo);
void mostrarTareas(Nodo *Start);
Nodo* eliminarTareas (Nodo **Start, int id);


int main() 
{
    int num,cont=0,id,num1;
    Nodo *TareasPendientes, *TareasRealizadas,*NNodo,*TareaExtraida;


    TareasPendientes = CrearListaVacia();
    TareasRealizadas = CrearListaVacia();

    printf("Desea ingresar una tarea?\n1.Si\n2.No\n");
    scanf("%d",&num);

    while (num != 2)
    {
    
      NNodo = CrearNodo(TareasPendientes,cont);
      
      if (TareasPendientes){
         insertarAlFinal(TareasPendientes,NNodo);
      }
       else{
        insertarAlInicio(&TareasPendientes,NNodo);
       }
        
    
      
      printf("Desea ingresar otra tarea?\n1.Si\n2.No\n");
      scanf("%d",&num);
        
        cont++;
    }
    
    mostrarTareas(TareasPendientes);

    printf("Ingrese el ID de la tarea a ser movida: ");
    scanf("%d", &id);

    TareaExtraida = eliminarTareas(&TareasPendientes,id);

    if (TareaExtraida)
    {
       if (TareasRealizadas)
       {
         insertarAlFinal(TareasRealizadas,TareaExtraida);
       }
       else
       {
        insertarAlInicio(&TareasRealizadas,TareaExtraida);
       }
        
    }

    mostrarTareas(TareasRealizadas);

    printf("Desea mover otra tarea?: \n1.Si\n2.No");
    scanf("%d", &num1);
    while (num1 != 2)
    {
       printf("Ingrese el ID de la tarea a ser movida: ");
        scanf("%d", &id);
        
        TareaExtraida = eliminarTareas(&TareasPendientes,id);

    if (TareaExtraida)
    {
       if (TareasRealizadas)
       {
         insertarAlFinal(TareasRealizadas,TareaExtraida);
       }
       else
       {
        insertarAlInicio(&TareasRealizadas,TareaExtraida);
       }
        
    }

     printf("Desea mover otra tarea?: \n1.Si\n2.No");
        scanf("%d", &num1);

    }
    
    mostrarTareas(TareasRealizadas);

    mostrarTareas(TareasPendientes);

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
   NNodo->T.Descripcion = (char*)malloc(50*sizeof(char));
   fflush(stdin);
   gets(NNodo->T.Descripcion);
   NNodo->Siguiente = NULL;

   
  }
  else{
   NNodo->T.TareaID = 1000;
   printf("Ingrese duracion de la tarea: \n");
   scanf("%d",&NNodo->T.Duracion);
   printf("Ingrese descripcion de la tarea: \n");
   NNodo->T.Descripcion = (char*)malloc(50*sizeof(char));
   fflush(stdin);
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

void insertarAlFinal(Nodo *Start,Nodo *NNodo)
{
    Nodo *aux = Start;

    while (aux->Siguiente)
    {
        aux = aux->Siguiente;
    }

    aux->Siguiente = NNodo;
    
}

void mostrarTareas(Nodo *Start)
{
    Nodo *aux = Start;
    while (aux)
    {
       printf("Tarea Nro. %d\n", aux->T.TareaID); 
       printf("Duracion de la tarea: %d\n", aux->T.Duracion);
       printf("Descripcion de la tarea: %s\n", aux->T.Descripcion);
        aux = aux->Siguiente;    
    }
    
}

Nodo* eliminarTareas (Nodo **Start, int id) 
{
    Nodo *aux = *Start;
    Nodo *auxAnt = NULL;

    while (aux && aux->T.TareaID != id)
    {
        auxAnt = aux;
        aux = aux->Siguiente;
    }

    if (aux)
    {
        if (aux == *Start)
        {
            *Start = aux->Siguiente;
        }
        else
        {
            auxAnt->Siguiente = aux->Siguiente;
        }
        aux->Siguiente = NULL;   
    }

    return aux;

}

