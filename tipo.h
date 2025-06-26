#ifndef TIPO_H
#define TIPO_H

typedef struct{
    char data[7];
    char orarioInizio[5];
    char orarioFine[5];
    char descrizione[50];
} tipo_inf;

int compare(tipo_inf, tipo_inf);
void copy(tipo_inf*, tipo_inf);
tipo_inf new_tipoInf(char*, char*, char*, char*);
void print(tipo_inf);



#endif