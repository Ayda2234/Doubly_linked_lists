#include <stdio.h>
#include <stdlib.h>
#define N 50
  struct student{
    int Num ;
    char name[N];
    char firstName[N];
    int N_algo ;
    int N_bdd ;
}S;
struct student S ;
int search (int N_search){
    FILE*file ;
    file = fopen("file.txt","r");
    do
    {
    fscanf(file,"%d , %s ,%s ,%d , %d\n",&S.Num,&S.name,&S.firstName,&S.N_algo,&S.N_bdd);
    fflush(stdin);//libirer lespace memoire
    if (S.Num == N_search){
        fclose(file);
        return 1 ;
    }
    }while(!feof(file));

    fclose(file);
    return -1;
    }

void add_student(){
    FILE* file;
    int num ;
    file = fopen("file.txt","at+");
    printf("\n enter the ID of the new student :  ");
    scanf("%d",&num);
    //fflush(stdin);
    while (search(num)== 1){
        printf("\n this number has already exist ");
        printf("enter the number of the student ");
        scanf("%d",&num);}
    S.Num=num;
    printf("\n give the name of the student ");
    scanf("%s",&S.name);
    fflush(stdin);
    printf("\n give the firstname of the student ");
    scanf("%s",&S.firstName);
    fflush(stdin);
    printf("\n give the mark of algo of the student ");
    scanf("%d",&S.N_algo);
    fflush(stdin);
    printf("\n give the mark of BDD of the student ");
    scanf("%d",&S.N_bdd);//fflush(stdin);
fprintf(file,"%d , %s ,%s ,%d , %d\n",S.Num,S.name,S.firstName,S.N_algo,S.N_bdd);
fclose(file);
}
void research(){
int num_R ;// the number to search
printf("\n enter the number of the student you wanna search about ");
scanf("%d",&num_R);
FILE* file ;
file = fopen("file.txt","r");// ouvrir le fichier en mode lecture
do {
    fscanf(file,"%d , %s ,%s ,%d , %d \n",&S.Num,&S.name,&S.firstName,&S.N_algo,&S.N_bdd);
     if (num_R == S.Num){
        printf("\n  ------- information about the student -------- \n \n ");
        printf(" \n the ID of the student :\t %d " ,S.Num);
        printf(" \n the name of the student:\t %s " ,S.name);
        printf(" \n the firstname of the student :\t %s " ,S.firstName);
        printf(" \n the mark of algorithm of the student :\t %d " ,S.N_algo);
        printf(" \n the mark of te data base of the student :\t %d " ,S.N_bdd);
     }
}while(!feof(file));

fclose(file);
}

void delet_student(){
    char comfirme ;
    int num_delet ;
    printf("\n enter the Id of the student that you wanna delele");
    scanf("%d",&num_delet);
    fflush(stdin);
    if (search(num_delet)==1){
        printf("\n Are you sure that you wanna delet this student Y/N");
        scanf("%c",&comfirme);
        fflush(stdin);
        if (comfirme == 'Y'){
            FILE*f ,*file;
            file = fopen("file.txt","r");
            f = fopen("temp.txt","a");
            do {
                fscanf(file,"%d , %s ,%s ,%d , %d \n",&S.Num,&S.name,&S.firstName,&S.N_algo,&S.N_bdd);
                if (num_delet != S.Num){
                        fprintf(f,"%d , %s ,%s ,%d , %d \n",S.Num,S.name,S.firstName,S.N_algo,S.N_bdd);}}
            while (!feof(file));
            fclose(f);
            fclose(file);
            remove("file.txt");// remove c'est une fonction predifini en c
            rename("temp.txt","file.txt");
            printf("\n the student is deleted with success");}
            }
            else{
            printf("\n this id doesn't exist ");}}
void modify_student(){
    char comfirm ;
    int num_modify;
    printf("\n enter the Id of the student that you wanna modify");
    scanf("%d",&num_modify);
    fflush(stdin);
    if (search(num_modify)==1){
        printf("\n Are you sure that you wanna modify this student Y/N");
        scanf("%c",&comfirm);
        fflush(stdin);
        if (comfirm == 'Y'){
            FILE*f ,*file;
            file = fopen("file.txt","r");
            f = fopen("temp.txt","a");
            do {
                fscanf(file,"%d , %s ,%s ,%d , %d\n",&S.Num,&S.name,&S.firstName,&S.N_algo,&S.N_bdd);
                if (num_modify == S.Num){
                 S.Num = num_modify;
                 printf("\n give the name of the student ");
                 scanf("%s",&S.name);
                 printf("\n give the firstname of the student ");
                 scanf("%s",&S.firstName);
                 printf("\n give the mark of algo of the student ");
                 scanf("%d",&S.N_algo);
                 printf("\n give the mark of BDD of the student ");
                 scanf("%d",&S.N_bdd);
} fprintf(f,"%d , %s ,%s ,%d , %d \n",S.Num,S.name,S.firstName,S.N_algo,S.N_bdd);
            }while(!feof(file));
            fclose(f);
            fclose(file);
            remove("file.txt");
            rename("temp.txt","file.txt");
            printf("student information modified with success");}}
        else{
            printf("\n the id you wanna modify doesn't exist and modification canceled");}}

void show_list()
{
    FILE* file;
    file = fopen("file.txt","r");
    printf("\n The list of all the student : \n \n");
    printf("ID\t Name\t Firstname\t Algo_mark\t BDD_mark \n");
    do {
        fscanf(file,"%d , %s ,%s ,%d , %d\n",&S.Num,&S.name,&S.firstName,&S.N_algo,&S.N_bdd);
        fflush(stdin);
        printf("%d ",S.Num);
        printf("%s\t  ",S.name);
        printf("%s\t\t",S.firstName);
        printf("%d\t\t",S.N_algo);
        printf("%d\t\t\t",S.N_bdd,"\n");
    }while(!feof(file));
    fclose(file);
    }

void main(){


    FILE* file = NULL;

    file = fopen("file.txt", "r+");
    char comfirmation ;

    int c=1;
     while(c != 0)
    {
        printf(" \n \n_______ the availabe operations in my project are ________\n\n");
        printf(" >>1<< Add a student to the list \n\n");
        printf(" >>2<< search a student from the available list \n\n");
        printf(" >>3<< delete a student from the list  \n\n");
        printf(" >>4<< Modify a student already exist in the list \n\n");
        printf(" >>5<< show the holl list \n\n");
        printf(" >>6<< quit student to the list \n\n");

        printf("enter the nuber of the operation you wanna verify :");
        scanf("%d",&c);

        switch(c){
        case 0 : break;
        case 1:add_student();
        break;
        case 2 :research();
        break;
        case 3 :delet_student();
        break;
        case 4 :modify_student();
        break;
        case 5 :show_list();
        break;
        }
}//fflush(stdin);
printf("Do you wanna continue !!\n choose Y/N\n");
scanf("%c",&comfirmation);
fflush(stdin);
}






