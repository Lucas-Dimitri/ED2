#include <stdio.h>
#include <iostream>
#include <string>

int main()
{
    for (std::string i = "aaa"; i[0] < 102; i[0]++)
    {
        std::cout << i << std::endl;
    }
}

/*
    avl *newAVL = (avl *) malloc(sizeof(avl));
    newAVL->title = title;
    newAVL->developers = developers;
    newAVL->publishers = publishers;
    newAVL->japan_release = japan_release;
    newAVL->north_america_release = north_america_release;
    newAVL->PAL_region_release = PAL_region_release;
    newAVL->esq = NULL;
    newAVL->dir = NULL;

    avl *aux = raiz;

    if (raiz == NULL) raiz = newAVL;
    else
    {
        bool menor;
        while (true)
        {
            int comprimento = title.length();
            for (int i = 0; i < comprimento; i++)
            {
                if (title[i] < aux->title[i])
                {
                    menor = true;
                    break;
                }
                else if (title[i] > aux->title[i])
                {
                    menor = false;
                    break;
                }
            }

            if (menor)
            {
                if (aux -> esq == NULL) break;
                else aux = aux->esq;
            }
            else
            {
                if (aux -> dir == NULL) break;
                else aux = aux->dir;
            }
        }
        if (menor) aux->esq = newAVL;
        else aux->dir = newAVL;

        rebalanceamento(&raiz);
*/