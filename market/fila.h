#ifndef FILA_H
#define FILA_H

typedef struct fila { cliente *filaCliente; } fila;

typedef struct cliente {
    int itens;
    struct cliente *prox;
} cliente;


#endif