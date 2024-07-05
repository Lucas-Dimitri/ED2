#include <iostream>
#include <string>
#include <vector>

typedef struct avl
{
    std::string title;
    std::string developers;
    std::string publishers;
    std::string japan_release;
    std::string north_america_release;
    std::string PAL_region_release;
    int altura;
    int fb;
    struct avl *esq;
    struct avl *dir;
} avl;

int avl_atualiza_fb_altura(avl *arv)
{
    if (arv == NULL)
        return -1;

    int altEsq = avl_atualiza_fb_altura(arv->esq);
    int altDir = avl_atualiza_fb_altura(arv->dir);

    arv->altura = 1 + (altEsq > altDir ? altEsq : altDir);
    arv->fb = altDir - altEsq;

    return arv->altura;
}

void avl_rot_dir(avl **raiz)
{
    avl *u = *raiz;
    avl *v = u->esq;
    u->esq = v->dir;
    v->dir = u;
    *raiz = v;

    avl_atualiza_fb_altura(u);
    avl_atualiza_fb_altura(*raiz);
}

void avl_rot_esq(avl **raiz)
{
    avl *u = *raiz;
    avl *v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    *raiz = v;

    avl_atualiza_fb_altura(u);
    avl_atualiza_fb_altura(*raiz);
}

void rebalanceamento(avl **raiz)
{
    if (*raiz == NULL)
        return;

    avl *arv = *raiz;
    int fb = arv->fb;

    if (fb == 2)
    {
        if (arv->esq->fb == 1)
            avl_rot_dir(raiz);

        else if (arv->dir->fb == 1)
            avl_rot_esq(raiz);

        else if (arv->esq->fb == -1)
        {
            avl_rot_esq(&(arv->esq));
            avl_rot_dir(raiz);
        }

        else if (arv->dir->fb == -1)
        {
            avl_rot_dir(&(arv->dir));
            avl_rot_esq(raiz);
        }
    }
    else if (fb == -2)
    {
        if (arv->esq->fb == -1)
            avl_rot_dir(raiz);

        else if (arv->dir->fb == -1)
            avl_rot_esq(raiz);

        else if (arv->esq->fb == 1)
        {
            avl_rot_esq(&(arv->esq));
            avl_rot_dir(raiz);
        }

        else if (arv->dir->fb == 1)
        {
            avl_rot_dir(&(arv->dir));
            avl_rot_esq(raiz);
        }
    }

    rebalanceamento(&(arv->esq));
    rebalanceamento(&(arv->dir));
}

/*

avl *buscaavl(avl *r, int valor)
{
    if (r == NULL)
        return NULL;
    else if (r->info < valor)
        return buscaavl(r->esq, valor);
    else if (r->info > valor)
        return buscaavl(r->dir, valor);
    else
        return r;
}

*/

int main(void)
{
    
}