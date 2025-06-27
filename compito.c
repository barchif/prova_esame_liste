#include "tipo.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//prototipi
void agenda(lista* planner, tipo_inf a);
void stampa(lista planner);
void quanti(lista agenda, tipo_inf a);

int main(){
    FILE* planner = fopen("agenda.txt", "r"); //apro agenda.txt in lettura
    if(planner == NULL) return 1;

    //lettura del file
    char riga[200];
    int count_line = 1;

    tipo_inf appuntamento; 
    lista lista_appuntamenti = NULL;

    while(fgets(riga, 200, planner) != NULL){
        printf("\nriga letta: %s", riga);
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

    //verifico quanti appuntamenti ci sono prima di un appuntamento
    //"210919 1400 1430 Pranzo"
    tipo_inf appuntamento_prova = {
        .descrizione = "Pranzo", 
        .data = "210919", 
        .orarioFine = "1430", 
        .orarioInizio = "1400"
    };
    quanti(lista_appuntamenti, appuntamento_prova);

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

    //inserisco l'appuntamento in ordine in base alla data
    if(cursor == NULL) *lista_appuntamenti = insert_elem(*lista_appuntamenti, new_elem(a));
    else{
        bool inserito = false; //indica se l'elemento è stato inserito
        lista last_node_considered = NULL; //utlimo elementi della lista considerato, serve per inserire l'appuntamento in coda alla lista

        while(cursor != NULL && !errore && !inserito){
            if(compare(cursor->inf, a) == 0) //se è giè presente un'attività nella stessa data e orarioInizio...
                errore = true; 
            else{
                //*lista_appuntamenti = insert_elem(*lista_appuntamenti, new_elem(a));
                if(strcmp(cursor->inf.data, a.data) > 0){ //a va inserito prima di cursor
                    lista ptr_a = new_elem(a);
                    ptr_a->pun = cursor;
                    ptr_a->prev = cursor->prev; //importante per evitare che rimanga null
                    
                    //se il nuovo elemento deve essere inserito in testa...
                    if(cursor->prev == NULL){
                        *lista_appuntamenti = ptr_a;
                    } else{
                        cursor->prev->pun = ptr_a;
                    }

                    //cursor ha come precedente l'appuntamento a 
                    cursor->prev = ptr_a;
                    inserito = true;
                }

                //else --> se la data di a è > cursor, vuol dire che a deve essere inserito successivamente
            }

            last_node_considered = cursor; //aggiorno l'ultimo nodo considerato
            cursor = cursor->pun;
        }

        //se l'appuntamento non è mai stato inserito, vuol dire che andava per ultimo 
        if(!inserito && !errore){
            lista ptr_a = new_elem(a);
            last_node_considered->pun = ptr_a;
            ptr_a->prev = last_node_considered; //importante per evitare rimanga NULL
        }
    }
    
    if(errore)
        fprintf(stderr, "\tErrore: e' gia' previsto un appuntamento allo stesso orario e data di %s", a.descrizione);
        
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

void quanti(lista lista_appuntamenti, tipo_inf a){
    //scorro la lista per contare il numero di attiità precedenti e successive ad A nello stesso giorno 
    int precedenti = 0;
    int successivi = 0; 

    //scorro la lista
    lista cursor = lista_appuntamenti;
    while(cursor != NULL){
        //valuto la data dell'attività considerata
        if(strcmp(cursor->inf.data, a.data) == 0){ //se sono la stessa data
            //verifico di non star considerando l'attività a
            if(compare(cursor->inf, a) == -1){
                //valuto l'orario
                int esito = strcmp(cursor->inf.orarioInizio, a.orarioInizio);
                if(esito < 0)
                    precedenti++;
                else if(esito > 0)
                    successivi++;

                //else --> non conto quell'attività 
            }

            //else -> non considero l'attività a
        }

        //else --> se non sono nella stessa data non conteggio nulla

        cursor = cursor->pun;
    }

    //stampo i risultati calcolari
    printf("%d appuntamento/i prima e %d dopo\n", precedenti, successivi);
}