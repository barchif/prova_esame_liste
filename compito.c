#include "tipo.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototipi
void agenda(lista* planner, tipo_inf a);

int main(){
    FILE* planner = fopen("agenda.txt", "r"); //apro agenda.txt in lettura
    if(planner == NULL) return 1;

    //lettura del file
    char riga[200];
    char data[7];
    char orarioInizio[5];
    char orarioFine[5];
    int count_line = 1;

    tipo_inf appuntamento; 
    lista lista_appuntamenti = NULL;

    while(fgets(riga, 200, planner) != NULL){
        printf("\n\nriga letto: %s", riga);

        if(count_line % 2 != 0)
            sscanf(riga, "%s %s %s", appuntamento.data, appuntamento.orarioInizio, appuntamento.orarioFine);
        else{
            strcpy(appuntamento.descrizione, riga);
            agenda(&lista_appuntamenti, appuntamento);
        }

        

        count_line++;
    }



    if(fclose(planner) == EOF){
        fprintf(stderr, "\nERROR: chiusura del file avvenuta in maniera errata");
        exit(1);
    }

    return 0;
}



void agenda(lista* planner, tipo_inf a){
    if(planner == NULL){
        *planner = insert_elem(*planner, new_elem(a));
    } else{
        //controllo sui dati 
        lista cursor = *planner;
        while(cursor != NULL){
            
            



        }
    }

    
    



}