#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore{
    int info;
    struct NoArvore *esq;
    struct NoArvore *dir;
}NoArv;

typedef struct Arvore{
    NoArv*raiz;
}Arv;


NoArv *CriaArvore(){
    return NULL;
}

//Função insere
//Ela recebe o numero e a arvore q ele sera colocado
//Aloca o espaço para o NO e ele recebe o valor q sera inserido
//verifica o valor dele e compara com a Raiz da arvore
//e vai percorrendo a arvore ate encontrar o local dele
NoArv * aux_insere(NoArv *no ,int num){
    int flag;
    NoArv *Pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->info = num;
    novo->esq = NULL;
    novo->dir = NULL;
    if(no == NULL)
    {
        return novo;
    }
    else
    {
        Pai =no;
        flag=0;
        while (flag == 0)
        {
            if(Pai->info < num)
            {
                if(Pai->dir == NULL)
                {
                    Pai->dir = novo;
                    flag=1;
                }
                else
                {
                    Pai = Pai->dir;
                }
            }
            else
            {
                if(Pai->info > num)
                {
                    if(Pai->esq == NULL)
                    {
                        Pai->esq = novo;
                        flag=1;
                    }
                    else
                    {
                        Pai = Pai->esq;
                    }
                }
            }
        }
    }
    return no;
}

void insere (Arv *Arvore,int num){
    Arvore->raiz = aux_insere(Arvore->raiz, num);
}

void verificaVazia(Arv*Arvore){
    if(Arvore->raiz == NULL){
        printf("Arvore Vazia");
    }
    printf("Arvore Nao esta Vazia");
}

void buscaeinsereValor(Arv *Arvore,int num){
    int flag = 0;
    NoArv *Pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->info = num;
    novo->esq = NULL;
    novo->dir = NULL;
    if(Arvore->raiz == NULL)
        Arvore->raiz = novo;
    else
    {
        Pai = Arvore->raiz;
        while(flag <= 1)
        {
            if(Pai->info < num)
            {
                if(Pai->dir == NULL)
                {
                    Pai->dir = novo;
                    printf("no inserido com sucesso");
                    flag =1;
                }
                else
                {
                    Pai = Pai->dir;
                }
            }
            else
            {
                    if(Pai->info >num)
                    {
                        if(Pai->esq == NULL)
                        {
                                Pai->esq = novo;
                                printf("no inserido com sucesso");
                                flag =1;
                        }
                        else
                        {
                            Pai = Pai->esq;
                        }
                    }
                    else
                    {
                        printf("Valor ja existe na Arvore");
                        flag=1;
                    }
            }
        }
    }
}

//numNodes(Arvore->raiz)
//função que conta a quantidade de nodes
int numNodes(NoArv * raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + numNodes(raiz->esq)+ numNodes(raiz->dir);

}



//MAIN
int main()

{

    printf("Hello world!\n");
    return 0;

}
