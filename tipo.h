#ifndef TIPO_H
    #define TIPO_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct{
        char data[7];
        char orarioInizio[5];
        char orarioFine[5];
        char descrizione[50];
    } tipo_inf;

    int compare(tipo_inf value1, tipo_inf value2);
    void copy(tipo_inf* destination, tipo_inf value);



#endif