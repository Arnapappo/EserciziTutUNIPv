#include<stdio.h>

int string_len(char *str) {
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}

int main(int argc, char *argv[]) {
    
    char *path;
    int pos_dot = -1;
    int pos_last_slash = -1;
    int k, i;
    int path_len;
    
    if(argc < 2){
        printf("Numero di parametri errato\n");
        return 1;
    }
    
    path = argv[1];
    path_len = string_len(path);
    
    // CONTROLLO DEL PATH SE ASSOLUTO O RELATIVO
    printf("[TIPO]\n");
    if(path[0] == '/'){
        printf("assoluto\n");
    }else{
        printf("relativo\n");
    }
    
    //IDENTIFICAZIONE DELL'ESTENSIONE, BASENAME, DIRNAME
    k = path_len -1;
    while(path[k] != '/' && k>=0){
        if(path[k]=='.'){
            pos_dot = k;
        }
        k--;
    }
    
    pos_last_slash = k;
    printf("[DIRNAME]\n");
    
    if(pos_last_slash != -1){
        for(i = 0; i < path_len; i++){
            if(i == pos_last_slash){
                printf("\n[BASENAME]\n");
                i++;
            }
            printf("%c", path[i]);
        }
        printf("\n");
    }else{
        printf("[BASENAME]\n");
        printf("%s\n", path);
    }
    

    printf("[ESTENSIONE]\n");
    if(pos_dot != -1){
        for(i = pos_dot + 1; i < path_len; i++){
            printf("%c", path[i]);
        }
    }else{
        printf("nessuna");
    }
    
    printf("\n");
    return 0;
}
