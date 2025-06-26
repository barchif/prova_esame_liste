/*
 * liste.c
 *
 *  Created on: 17 set 2021
 *      Author: Gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "liste.h"

/*******************************/
/* DEFINIZIONE MODULO "liste" */
/*******************************/

tipo_inf head(lista p) {
    return p->inf;
}

struct elem* search(lista l, tipo_inf v) {
    while (l != NULL) {
        if (compare(head(l), v) == 0)
            return l;
        else
            l = tail(l);
    }
    return NULL;
}

struct elem* new_elem(tipo_inf inf) {
     struct elem* p = ( struct elem*) malloc(sizeof( struct elem));
    if (p == NULL) {
        fprintf(stderr, "Errore allocazione memoria\n");
        exit(1);
    }
    copy(&(p->inf), inf);
    p->pun = NULL;
    p->prev = NULL;
    return p;
}

lista tail(lista p) {
    return p->pun;
}

lista prev(lista p) {
    return p->prev;
}

lista insert_elem(lista l, struct elem* e) {
    e->pun = l;
    if (l != NULL)
        l->prev = e;
    e->prev = NULL;
    return e;
}

lista delete_elem(lista l, struct elem* e) {
    if (l == e) {
        l = e->pun; // e è la testa della lista
    } else {
        e->prev->pun = e->pun;
    }

    if (e->pun != NULL) {
        e->pun->prev = e->prev;
    }

    free(e);
    return l;
}
