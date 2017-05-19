#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome_pilota[50];
    char team_pilota[50];
    int punteggio;
} Pilota;

/*
* Dato un array di piloti e il nome del pilota ritorna il suo indice all'interno dell'array
*/
int getIndex(Pilota *piloti, char *nome_pilota) {
    int i;
    int index = -1;
    for(i=0; i<sizeof(piloti); i++){
        if(strcmp(piloti[i].nome_pilota, nome_pilota) == 0) {
            index = i;
        }
    }
    
    return index;
}

/*
* Dato un array di indici dei piloti col miglior punteggio ritorna il nome del pilota primo in
* ordine alfabetico
*/

char *getNomePilota(Pilota *piloti, int *index_piloti){
    int i;
    char nome_pilota[50];
    strcpy(nome_pilota, piloti[index_piloti[0]].nome_pilota);
    for(i=0; i<sizeof(index_piloti), i++){
        if(strcmp(nome_pilota, piloti[index_piloti[i]].nome_pilota) < 0){
            strcpy(nome_pilota, piloti[index_piloti[i]].nome_pilota);
        }
    }
    
    return nome_pilota;
}

int main(int argc, char *argv[]) {
    FILE *f;
    int punteggi[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    Pilota piloti[20];
    
    int i=0;
    int j=0;
    int z=0;
    int punteggio = 0;
    int index_pilota = 0;
    int punteggio_alto = 0;
    int index_pilota_alto = 0;
    
    int *index_piloti_alti;
    
    char buffer_file[50];
    char buffer_pilota[50];
    char buffer_team[50];
    
    if(argc != 2){
        printf("Numero dei parametri errato");
        return 1;
    }
    
    f = fopen(argv[1], "r");
    printf("[NUMERO_GARE]\n");
    while(fgets(buffer_file, sizeof(buffer_file), f) != NULL){
        i++;
    }
    printf("%d\n", i/20);
    fclose(f);
    
    /*
    *   Parser del file per calcolare i punteggi
    */
    f = fopen(argv[1], "r");
    
    //Inizializzazione dell'array di pitoli
    for(z=0; z<20; z++){
        fgets(buffer_file, sizeof(buffer_file), f);
        sscanf(buffer_file, "%s %s", buffer_pilota, buffer_team);
        if(z<10){
            punteggio = punteggi[z];
        }else{
            punteggio = 0;
        }
        strcpy(piloti[z].nome_pilota, buffer_pilota);
        strcpy(piloti[z].team_pilota, buffer_team);
        piloti[z].punteggio = punteggio;
    }
    
    //Conteggio dei punti sulle restanti gare
    for(j=0; j<i-1; j++) {
        for(z=0; z<20; z++){
            fgets(buffer_file, sizeof(buffer_file), f);
            sscanf(buffer_file, "%s %s", buffer_pilota, buffer_team);
            index_pilota = getIndex(piloti, buffer_pilota);
            if(z<10){
                punteggio = punteggi[z];
            }else{
                punteggio = 0;
            }
            piloti[index_pilota].punteggio += punteggio;
        }
    }
    
    //Ricerca del punteggio migliore
    for(z=0; z<20; z++){
        if(punteggio_alto < piloti[z].punteggio){
            punteggio_alto = piloti[z].punteggio;
        }
    }
    j = 0;
    for(z=0; z<20; z++){
        if(punteggio_alto == piloti[z].punteggio){
            index_pilota_alto[j] = z;
        }
    }
    printf("%s %d\n", piloti[index_pilota_alto].nome_pilota, punteggio_alto);
    
    /*
    for(z=0; z<20; z++){
        printf("%s %s %d\n", piloti[z].nome_pilota, piloti[z].team_pilota, piloti[z].punteggio);
    }
    */
    
    fclose(f);
    
    return 0;   
}
