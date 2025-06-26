ISTRUZIONI DOXYGEN

- creare il doxyfile da terminale tramite 
    doxygen -g

- modificare il file doxyfile con le seguenti istruzioni:
    PROJECT_NAME           = "Nome Progetto"
    OUTPUT_DIRECTORY       = "cartella di destinazione"
    EXTRACT_ALL            = YES (per estrarre tutto il codice, anche quello non documentato)
    GENERATE_LATEX         = NO (per non generare il file .tex)


- per generare la documentazione, da terminale:
    doxygen Doxyfile

