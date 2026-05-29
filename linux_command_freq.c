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

void inp(FILE *f,FILE *f_w){
    // int index;
    char ch=fgetc(f);;
    while(ch!=EOF){
        fputc(ch,f_w);
        ch=fgetc(f);
        // printf("%c",ch);
    }
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