#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cond(FILE *f){
    if(f==NULL){
        printf("\nError in finding the file...\n");
        exit(0);
    }
}

typedef struct{
    char item[256];
    int index;
}items;

void inp(FILE *f){
    // int index;
    char ch[256];
    // char arr[10000][256];
    items list[1000];
    int i=0;
    
    while(fgets(ch,sizeof(ch),f)!=NULL){
        int found =0;
        char *cmd = strtok(ch," \n");
        if (cmd!=NULL){
            for(int j=0;j<i;j++){
                if(strcmp(list[j].item,cmd)==0){
                    list[j].index++;
                    found++;
                }
            }

            if (found == 0) {
                strcpy(list[i].item, cmd);
                list[i].index = 1;
                i++;
            }
        }   
    }
    for(int l=0;l<i;l++){
        for(int m=0;m<i-1;m++){
            if(list[m].index<list[m+1].index){
                items temp = list[m];
                list[m] = list[m+1];
                list[m+1] = temp;
            }
        }
    }
    for(int k=0;k<10&&k<i;k++){
        printf("\n%s --> number of times:%d\n",list[k].item,list[k].index);
    }
}
int main(){
    char loc[100];
    snprintf(loc,sizeof(loc),"%s/.bash_history",getenv("HOME"));
    printf("%s",loc);
    FILE *f =  fopen(loc,"r");
    cond(f);
    inp(f);
    fclose(f);
}