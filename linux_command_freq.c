#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cond(FILE *f){
    if(f==NULL){
        printf("\nError in finding the file...\n");
        exit(0);
    }
    else{
        printf("\nFile found successfully\n");
    }
}

typedef struct{
    char item[256];
    int index;
}items;

void inp(FILE *f,FILE *f_w){
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
        printf("index:%d,name:%s\n",list[l].index,list[l].item);
    }
    // printf("found:%d",found);

}



int main(){
    char usr[50];
    printf("Please enter you username...:");
    fgets(usr,sizeof(usr),stdin);
    usr[strcspn(usr,"\n")]=0;
    char loc[100];
    char us[]="/home";
    char us1[]= ".bash_history";
    snprintf(loc,sizeof(loc),"%s/%s/%s",us,usr,us1);
    printf("%s",loc);
    FILE *f =  fopen(loc,"r");
    FILE *f_w = fopen("freq.txt","w");
    cond(f);
    inp(f,f_w);
    fclose(f);
    fclose(f_w);
}