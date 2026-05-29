#include <stdio.h>
#include <string.h>
int main(){
    char usr[50];
    printf("Please enter you username...:");
    // scanf(" %s",usr);
    fgets(usr,sizeof(usr),stdin);
    usr[strcspn(usr,"\n")]=0;
    // char loc[100] = ("/home/%s/.bash_history",usr);
    char loc[100];
    char us[10]="/home";
    char us1[20]= ".bash_history";
    snprintf(loc,sizeof(loc),"%s/%s/%s",us,usr,us1);
    printf("%s",loc);
    FILE *f =  fopen(loc,"r");

    fclose(f);
}