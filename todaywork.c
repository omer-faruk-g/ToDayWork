#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i=0;
void menu(){
    printf("---------------------------------------------------------------\n");
    printf("---------------------------ToDayWork---------------------------\n");
    printf("1.Gorev ekle\n2.Listeyi listele\n4.cikis\n");
    printf("---------------------------------------------------------------\n\n");
}
int dutyAdd(char* ptr){
    char path[200];
    FILE* fptr;
    sprintf(path, "C:\\Users\\HP\\Desktop\\database\\log%d.txt",i);
    fptr = fopen(path, "a");
    if(fptr == NULL){
        printf("\nDon't see file.\n");
        return -1;
    }
    fprintf(fptr,"%s",ptr);
    fclose(fptr);
    return 0;
}
int dutyList(){
    char list[1000];
    char path[200];
    FILE* fptr;
    sprintf(path,"C:\\Users\\HP\\Desktop\\database\\log%d.txt",i);
    fptr = fopen(path, "r");
    if(fptr == NULL){
        printf("\nDon't see file.\n");
        return -1;
    }
    while(fgets(list, sizeof(list), fptr) != NULL){
        printf("\n%s",list);
    }
    return 0;
}
int ii(){
    int max = 0;
    int n= 0;
    FILE* fptr;
    fptr = fopen("C:\\Users\\HP\\Desktop\\database\\i.txt", "r");
    while(fscanf(fptr,"%d",&n)== 1){
        max = n;
    }
    fclose(fptr);
    fptr = fopen("C:\\Users\\HP\\Desktop\\database\\i.txt", "w");
    n = max + 1;
    fprintf(fptr,"%d",n);
    i = n;
    fclose(fptr);
}
int main(){
    int answer=0;
    char messages[1000];
    ii();
    while(answer !=4){
        menu();
        printf("Secimin: ");
        scanf("%d", &answer);
        getchar();
        switch(answer){
        case 1:
            printf("Goreviniz: ");
            fgets(messages,1000,stdin);
            if(dutyAdd(messages) == 0){
                printf("Sucsessful.\n");
            }
            break;
        case 2:
            dutyList();
            break;
        case 4:
            printf("Bye\n");
            return 0;
            break;
        }

}
}
