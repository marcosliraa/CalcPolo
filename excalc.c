/* POLI - UPE
 * Grupo:
 * José Marcos de Lira Júnior
 *
 *
 * Programa que simula uma calculadora polonesa */


#include <stdlib.h>
#include <stdio.c>
#include <math.c>

#define MAX 80;


typedef struct st_pilha{
    int c;          // numero que a calculadora receberá
    struct st_pilha *prox;  //poneiro que aponta para a proxima lista
}pilha;


int main()
{
    char o;

    printf("\n\nEste programa simula uma calculadora polonesa. Para calcular digite os numeros um de cada vez e por fim o sinal('+','-','*','/') da operacao. \n")







}

int c=0;
float x[MAX];

void push(float u)
{
    if(c==MAX)          
    {   printf("Capacidade de armazenamento da pilha excedida.");
        return 0;
    }
    else
        x[c]= u;
    c++;
}

void pop()
{
    if(c==0)          
    {   printf("A pilha esta vazia.");
        return 0;
    }
    c--;
}

inserir(pilha **cabeca, int x)
{
    pilha *pl=*cabeca;
    pilha *plant=NULL;
    while(pl!=NULL)                     //laço ja comentado
    {
        plant=pl;
        pl=pl->prox;
    }
    pl=malloc(sizeof(pilha));           //aloca um espaço na memória
    pl->c=x;                  //parte inteira do elemento n recebe x
    pl->prox=NULL;            //ponteiro do elemento n aponta para NULL
    if(plant!=NULL)          //se existe anterior, ou seja se exite mais de 1 elemento na lista
        plant->prox=pl;      //elemento(n-1) aporta para pl
    else
        *cabeca=pl;         //se plant=NULL então a pilha so tem 1 elemento por isso cabeca recebe pl
}


