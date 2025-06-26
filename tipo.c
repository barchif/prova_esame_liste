#include "tipo.h"

//confronta la data e l'orario di inizio di due appuntamenti
int compare(tipo_inf value1, tipo_inf value2){
    if(strcmp(value1.data, value2.data) == 0 && 
        strcmp(value1.orarioInizio, value2.orarioInizio) == 0) //se sono lo stesso appuntamento
        return 0;   
    return -1;
}

void copy(tipo_inf* destination, tipo_inf value){
    /*strcpy(destination->data, value.data);
    strcpy(destination->descrizione, value.descrizione);
    strcpy(destination->orarioFine, value.orarioFine);
    strcpy(destination->orarioInizio, value.orarioInizio);*/
    *destination = value;
}