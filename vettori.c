#include <stdio.h>
#include <stdlib.h>

int main() {
    int voti[100], frequenze[13];
    int n, i, v, min, mass, somma, j, c, mass_freq, i_mass_freq;
    char buff[100];
    
    printf("Inserisci il numero di voti che vuoi inserire\n");
    fgets(buff, sizeof(buff), stdin);
    n = atoi(buff);
    
    if(n<=0 || n>100){
        printf("[ERRORE]");
        return 1;
    }
    
    
    //AQUISIZIONE DELL'ARRAY
    for(i=0; i<n; i++){
        printf("Inserisci il voto\n");
        fgets(buff, sizeof(buff), stdin);
        v = atoi(buff);
        if(v>=18 && v<=30) {
            voti[i]=v;
        }else{
            printf("Valore non valido\n");
            i--;
        }
    }

    //STAMPA DELL'ARRAY IN MODO INVERSO
    printf("[VALORI]\n");
    for(i=n-1; i>=0; i--){
        printf("%d\n", voti[i]);
    }
    
    //STAMPARE IL MINIMO, MASSIMO E MEDIA
    min = voti[0];
    mass = voti[0];
    somma = voti[0];
    for(i=1; i<n; i++){
        if(min > voti[i]){
            min = voti[i];
        }
        if(mass < voti[i]){
            mass = voti[i];
        }
        somma += voti[i];
    }
    printf("[MINIMO]\n");
    printf("%d\n", min);
    
    printf("[MASSIMO]\n");
    printf("%d\n", mass);
    
    printf("[MEDIA]\n");
    printf("%f\n", ((float)somma/n));
    
    //FREQUENZA DEI VOTI
    printf("[FREQUENZE]\n");
    for(j=0; j<13; j++){
        c = 0;
        for(i=0; i<n; i++){
            if(voti[i] == j+18){
                c++;
            }
        }
        printf("%d\n", c);
        frequenze[j] = c;
    }
    
    //MAX FREQUENZA
    printf("[MAXFREQ]\n");
    mass_freq = frequenze[0];
    i_mass_freq = 18;
    for(i=1; i<13; i++){
        if(mass_freq < frequenze[i]){
            mass_freq = frequenze[i];
            i_mass_freq = i+18;
        }
    }
    printf("%d\n", i_mass_freq);
    
    return 0;
}
