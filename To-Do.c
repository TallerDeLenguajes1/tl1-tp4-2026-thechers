#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
} Tarea;

typedef struct Nodo{
Tarea T;
struct Nodo *Siguiente;
} Nodo;

Nodo* CrearListaVacia();
Nodo* CrearNodo(Nodo *TareasPendientes,int cont);
void insertarAlInicio(Nodo **Start,Nodo *NNodo);
void insertarAlFinal(Nodo *Start,Nodo *NNodo);
void mostrarTareas(Nodo *Start);
Nodo* extraerTareas (Nodo **Start);
void mostrarNodo(Nodo *Start1, Nodo *Start2);
void liberarMemoria(Nodo **Start);


int main() {
    srand(time(NULL));
    int num,contPend=0,id,num1;
    Nodo *TareasPendientes, *TareasRealizadas,*NNodo,*TareaExtraida;


    TareasPendientes = CrearListaVacia();
    TareasRealizadas = CrearListaVacia();

    printf("Desea ingresar una tarea a pendientes?\n1.Si\n2.No\n");
    scanf("%d",&num);

    while (num != 2) {
    
      NNodo = CrearNodo(TareasPendientes,contPend);
      
      if (TareasPendientes) {
         insertarAlFinal(TareasPendientes,NNodo);
      }
       else {
        insertarAlInicio(&TareasPendientes,NNodo);
       }
         
      printf("Desea ingresar otra tarea a pendientes?\n1.Si\n2.No\n");
      scanf("%d",&num);
        
        contPend++;
    }
    
    

    printf("Desea mover una tarea?: \n1.Si\n2.No");
    scanf("%d", &num1);

    while (num1 != 2) {
       
        TareaExtraida = extraerTareas(&TareasPendientes);

    if (TareaExtraida) {
       if (TareasRealizadas) {
         insertarAlFinal(TareasRealizadas,TareaExtraida);
       }
       else {
        insertarAlInicio(&TareasRealizadas,TareaExtraida);
       }
        
    }

    
     printf("Desea mover otra tarea?: \n1.Si\n2.No");
        scanf("%d", &num1);

    }

    mostrarTareas(TareasPendientes);
    mostrarTareas(TareasRealizadas);


    mostrarNodo(TareasPendientes,TareasRealizadas);

    liberarMemoria(&TareasPendientes);
    liberarMemoria(&TareasRealizadas);


    return 0;
}


Nodo * CrearListaVacia()
{

    return NULL;

}

Nodo *CrearNodo(Nodo* Start, int cont)
{
   Nodo *NNodo = (Nodo*)malloc(sizeof(Nodo));

  if (Start) {
   NNodo->T.TareaID = cont + 1000;
   NNodo->T.Duracion = 10 + rand() % 91;
   printf("Ingrese descripcion de la tarea: \n");
   NNodo->T.Descripcion = (char*)malloc(50*sizeof(char));
   fflush(stdin);
   gets(NNodo->T.Descripcion);
   NNodo->Siguiente = NULL;

  }

  else {
   NNodo->T.TareaID = 1000;
   NNodo->T.Duracion = 10 + rand() % 91;
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

    while (aux->Siguiente) {
        aux = aux->Siguiente;
    }

    aux->Siguiente = NNodo;
    
}

void mostrarTareas(Nodo *Start)
{
    Nodo *aux = Start;
    while (aux) {
       printf("Tarea Nro. %d\n", aux->T.TareaID); 
       printf("Duracion de la tarea: %d\n", aux->T.Duracion);
       printf("Descripcion de la tarea: %s\n", aux->T.Descripcion);
        aux = aux->Siguiente;    
    }
    
}

Nodo* extraerTareas (Nodo **Start) 
{
    int id;
    Nodo *aux = *Start;
    Nodo *auxAnt = NULL;

    printf("Ingrese el ID de la tarea a ser movida: ");
    scanf("%d", &id);

    while (aux && aux->T.TareaID != id) {
        auxAnt = aux;
        aux = aux->Siguiente;
    }

    if (aux) {
        if (aux == *Start) {
            *Start = aux->Siguiente;
        }
        else {
            auxAnt->Siguiente = aux->Siguiente;
        }
        aux->Siguiente = NULL;   
    }

    return aux;

}

void mostrarNodo(Nodo *Start1, Nodo *Start2)
{
    int id,num;
    char *palClave;
    Nodo *aux = Start1;
    Nodo *aux2 = Start2;

    printf("Ingrese el metodo de busca: \n1.ID\n2.Palabra Clave\n");
    scanf("%d", &num);

    switch (num) {
    case 1:
        printf("Ingrese un ID para buscar: \n");
        scanf("%d", &id);

        while (aux && aux->T.TareaID != id) {
            aux = aux->Siguiente;
        }

        if (aux) {
            printf("Tarea Nro. %d\n", aux->T.TareaID); 
            printf("Duracion de la tarea: %d\n", aux->T.Duracion);
            printf("Descripcion de la tarea: %s\n", aux->T.Descripcion);
            printf("TAREA PENDIENTE..");
        }
        
        else {
            while (aux2 && aux2->T.TareaID != id) {
            aux2 = aux2->Siguiente;
            }
        
            if (aux2) {
            printf("Tarea Nro. %d\n", aux2->T.TareaID); 
            printf("Duracion de la tarea: %d\n", aux2->T.Duracion);
            printf("Descripcion de la tarea: %s\n", aux2->T.Descripcion);
            printf("TAREA REALIZADA..");
            }
            else {
                printf("No se encontro el ID ingresado");
            }

        }
    
        break;
    
    case 2:
        palClave = (char*)malloc(50 * sizeof(char));
        printf("Ingrese una palabra: \n");
        fflush(stdin);
        gets(palClave);

        while(aux && strstr(aux->T.Descripcion,palClave) == NULL){

                aux = aux->Siguiente;
  
        }
        
        if (aux)
        {
           printf("Tarea Nro. %d\n", aux->T.TareaID); 
           printf("Duracion de la tarea: %d\n", aux->T.Duracion);
           printf("Descripcion de la tarea: %s\n", aux->T.Descripcion);
           printf("TAREA PENDIENTE..");
        }
        else {
           
            while(aux2 && strstr(aux2->T.Descripcion,palClave) == NULL){

                aux2 = aux2->Siguiente;
  
            }
            
            if (aux2) {
            printf("Tarea Nro. %d\n", aux2->T.TareaID); 
            printf("Duracion de la tarea: %d\n", aux2->T.Duracion);
            printf("Descripcion de la tarea: %s\n", aux2->T.Descripcion);
            printf("TAREA REALIZADA..");
            }

            else{
                printf("No se encontraron coincidencias...");
            }
        }
        
                    

    }

        free (palClave);

}

void liberarMemoria(Nodo **Start){

    Nodo *nodoExtraido;
    Nodo *auxAnt;

         while(*Start) {
             auxAnt = *Start;
             *Start = auxAnt->Siguiente;

            if (auxAnt) {
                
                printf("Liberando lista... \n");
                *Start = auxAnt->Siguiente;

                auxAnt->Siguiente = NULL;

                nodoExtraido = auxAnt;

                if(nodoExtraido){
                    free(nodoExtraido->T.Descripcion);
                    free(nodoExtraido);
                } 
            }           
    }
}