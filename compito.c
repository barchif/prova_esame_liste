#include "tipo.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//prototipi
void agenda(lista* planner, tipo_inf a);
void stampa(lista planner);

int main(){
    FILE* planner = fopen("agenda.txt", "r"); //apro agenda.txt in lettura
    if(planner == NULL) return 1;

    //lettura del file
    char riga[200];
    int count_line = 1;

    tipo_inf appuntamento; 
    lista lista_appuntamenti = NULL;

    while(fgets(riga, 200, planner) != NULL){
        //printf("\n\nriga letto: %s", riga);
        size_t len = strlen(riga);
        if(len > 0 && riga[len-1] == '\n')
            riga[len-1] = '\0';

        if(count_line % 2 != 0){
            sscanf(riga, "%s %s %s", appuntamento.data, appuntamento.orarioInizio, appuntamento.orarioFine);
        } else{
            strcpy(appuntamento.descrizione, riga);
            agenda(&lista_appuntamenti, appuntamento);
            stampa(lista_appuntamenti);
        }

        count_line++;
    }



    if(fclose(planner) == EOF){
        fprintf(stderr, "\nERROR: chiusura del file avvenuta in maniera errata");
        exit(1);
    }

    return 0;
}



void agenda(lista* lista_appuntamenti, tipo_inf a){
    //controllo sui dati 
    lista cursor = *lista_appuntamenti;
    bool errore = false;

    while(cursor != NULL && !errore){
        if(compare(cursor->inf, a) == 0)
            errore = true; 
        cursor = cursor->pun;
    }

    if(errore)
        fprintf(stderr, "\tErrore: e' gia' previsto un appuntamento allo stesso orario e data di %s", a.descrizione);
    else
        *lista_appuntamenti = insert_elem(*lista_appuntamenti, new_elem(a));
}

void stampa(lista lista_appuntamenti){
    printf("\n\n\t\t\tSTAMPA DELL'AGENDA\n");
    lista cursor = lista_appuntamenti;

    if(cursor == NULL)
        printf("\nNon ci sono appuntamenti previsti in agenda");
    else{
        while (cursor != NULL){    
            tipo_inf elem = cursor->inf;
            printf("\n\t-%s, previsto dalle %s alle %s in data %s", 
                elem.descrizione, elem.orarioInizio, elem.orarioFine, elem.data);

            cursor = cursor->pun;
        }
    }

    printf("\n\n");
}