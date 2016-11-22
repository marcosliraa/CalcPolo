/* POLI - UPE
 * Grupo:
 * José Marcos de Lira Júnior
 *
 *
 * Programa que simula uma calculadora polonesa */


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX 80


typedef struct st_pilha{
    int c;          // numero que a calculadora receberá
    struct st_pilha *prox;  //poneiro que aponta para a proxima lista
}pilha;

void inserir(pilha **cabeca, int x);
void remover (pilha **cabeca, pilha *r);
void imprimir(pilha *cabeca);
int operacao(pilha **cabeca, char op);
pilha *buscarult(pilha *cabeca);   
int main(void)
{
    int k;
    pilha *l1=NULL, *b=NULL;
    printf("Calculadora Polonesa Reversa \n");
    char c[10]= "start";
    while (c[0] == 's')
    {
        while(c[0]!= '=')       //se o primeiro elemento da string for diferente de = entao:
        {
            printf("Digite: \n");
            gets(c);             //le o valor de c
            if(c[0]=='+' || c[0]=='-' || c[0]=='*' || c[0]=='/')       //se o valor digitado foi uma operação
            {
                operacao(&l1,c[0]);       //funcao que realiza a operação, onde l1 vai ser o cabeça e c[0] a operação desejada
                b=buscarult(l1);          //b apontará para o ultimo elemento de l1, pois b se iguala ao ponteiro que aponta para o ultimo elemento
                remover(&l1,b);          //remover o ultimo elemento da pilha l1
            }
            else
                if(c[0] == '=')
                    imprimir(l1);        // se o usuario digitar '=' então o programa irá imprimir a pilha
                else
                {
                    k=atoi(c);             //transforma o numero recebido de char para inteiro
                    inserir(&l1,k);      //insere na pilha l1  um novo elemento com c=k
                }
        }
    }
    return 0;
}


int operacao(pilha **cabeca, char op) /*funcao que ira calcular as operacoes('+','-','*','/')*/
{
    pilha *pl=*cabeca;  /*pl ira apontar  para onde o vetor recebido aponta*/
    pilha *plant=NULL;  /*plant recebe NULL*/
    while(pl->prox!=NULL)
    {
        plant=pl;   /*enquanto pl->prox!=NULL, ou seja, nao eh o ultimo termo*/
        pl=pl->prox;    /*avancamos plant para pl e pl para prox*/
    }
    switch(op)
    {
        case '+': /*se for +*/
            if(plant==NULL) /*Se o usuario so digitou 1 numero*/
                printf("Erro! Reinicie a calculadora e digite 2 numeros antes da operacao");
            else
                plant->c=((plant->c) + (pl->c)); /*Soma o inteiro do plant com o inteiro do pl e substitui em plant para que possamos dar um free no pl*/
            break;

        case '-':
            if(plant==NULL) /*esse if eh para colocarmos o numero negativo*/    
            {   plant=pl;   /*plant que era NULL aponta para onde pl aponta*/
                pl=malloc(sizeof(pilha));   /*cria um espaco na memoria com o tamanho pilha*/
                pl->c=1;    /*atribui um valor ao "espaco" inteiro de pl*/
                pl->prox=NULL;  /*aponta para NULL*/
                plant->c= -(plant->c);      /*plant ficara negativo*/
                plant->prox=pl;     /*o vetor de plant aponta para pl*/}
            else
                if(plant->c > pl->c)
                    plant->c= -((plant->c)-(pl->c)); /*se o numero for maior entao subtraimos e adicionamos o negativo*/
                else
                    plant->c=(pl->c - plant->c);    /*subtracao normal*/
            break;

        case '*':
            plant->c=(plant->c * pl->c);     /*multiplica e substitui em plant->c*/
            break;

        case '/':    
            plant->c=pl->c / plant->c;      /*divide e substitui em plant->c*/ 
            break;    
    }    
    return plant->c;
}

void inserir(pilha **cabeca, int x)
{
    pilha *pl=*cabeca;
    pilha *plant=NULL;
    while(pl!=NULL)                     
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


void remover (pilha **cabeca, pilha *r)
{
    pilha *pl=*cabeca;
    pilha *plant=NULL;
    if(r==NULL)       //se r não apontar para nada, ele não exite
        return;       //logo nao precisamos remover
    while(pl!=NULL && pl!=r )      //enquanto pl não é o ultimo nem é r
    {
        plant=pl;
        pl=pl->prox;
    }
    if(pl==NULL)     //se a lista é  vazia
        return;
    if(plant!=NULL)      //significa que possui um anterir a pl
        plant->prox=pl->prox;  //o anteior apontará para o proximo de pl
    free(pl);
    return;
}

void imprimir(pilha *cabeca)
{
    pilha *pl=cabeca;
    while(pl!=NULL)
    {
        printf("%d->",pl->c);     //imprime o valor inteiro de elemento
        pl=pl->prox;              //passa a apontar para o proximo elemento
    }
    printf("NULL\n");             // se nao possui nenhum elemento imprime a mensagem na tela
}

pilha *buscarult(pilha *cabeca)    //função que busca o ultimo elemento da pilha para ser excluido pela função remover
{
    pilha *pl=cabeca;      //pilha aponta para cabeça
    pilha *plant=NULL;     //plant recebe NULL
    while(pl->prox!=NULL)  //enquanto pl->prox não apontar para NULL, ou seja não for o último elemento da lista
    {
        plant=pl;             //plant avança para pl
        pl=pl->prox;         //pl avança para pl->prox
    }
    return pl;              //retorna pl, ou seja, retorna o último elemento da lista
}
