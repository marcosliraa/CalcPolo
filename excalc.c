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





