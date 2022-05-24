#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

typedef struct person
{
    char firstname[15];
    char lastname[15];
    char age[5];
}person;


void blank100();
void tenentry();
void displayten();
void updateentry();
void deleteRecord();

int main(){
    blank100();
    tenentry();
    displayten();
    updateentry();
    displayten();
    deleteRecord();
    displayten();
    return 0;
}

void blank100(){

    FILE *wfptr;
    if((wfptr = fopen("studentdata.dat","wb"))==NULL){
        cout<<"Error in opening file !";
        return;
    }

    person blankperson={"","","0"};
    
    for (int i = 0; i < 100; i++)
    {
        fwrite(&blankperson,sizeof(person),1,wfptr);
    }
    fclose(wfptr);
}

void tenentry(){
    FILE *wfptr;
    if((wfptr = fopen("studentdata.dat","wb"))==NULL){
        cout<<"Error in opening file !";
        return;
    }

    person p0={"shri","shinde","11"};
    person p1={"ganesh","fhinde","12"};
    person p2={"mahesh","gaikwad","13"};
    person p3={"ramesh","bagul","14"};
    person p4={"suresh","rane","15"};
    person p5={"rajesh","more","14"};
    person p6={"adi","gandhi","13"};
    person p7={"yogi","patil","12"};
    person p8={"uttam","bhide","11"};
    person p9={"tarak","gada","17"};

    fwrite(&p0,sizeof(person),1,wfptr);
    fwrite(&p1,sizeof(person),1,wfptr);
    fwrite(&p2,sizeof(person),1,wfptr);
    fwrite(&p3,sizeof(person),1,wfptr);
    fwrite(&p4,sizeof(person),1,wfptr);
    fwrite(&p5,sizeof(person),1,wfptr);
    fwrite(&p6,sizeof(person),1,wfptr);
    fwrite(&p7,sizeof(person),1,wfptr);
    fwrite(&p8,sizeof(person),1,wfptr);
    fwrite(&p9,sizeof(person),1,wfptr);

    fclose(wfptr);
}

void displayten(){
    FILE *rfptr;
    if((rfptr = fopen("studentdata.dat","rb"))==NULL){
        cout<<"Error in opening file !";
        return;
    }

    person toscreen={"","",""};
    cout<<"Last name\tFirst name\tage\n";
    cout<<"---------------------------------\n";
    for (int i = 0; i < 10; i++)
    {
        fread(&toscreen,sizeof(person),1,rfptr);
        cout<<toscreen.lastname<<"\t\t"<<toscreen.firstname<<"\t\t"<<toscreen.age<<endl;
    }
    fclose(rfptr);
}

void updateentry(){
    FILE*rpfptr;
    if((rpfptr = fopen("studentdata.dat","rb+"))==NULL){
        cout<<"Error in opening file !";
        return;
    }
    person newData = { "", "", "0" };
    printf("Enter existing lastName, firstName, newAge: ");
    char line[50];
    fgets(line, 50, stdin);
    char* token = strtok(line, ", \n");
    strcpy(newData.lastname, token);
    token = strtok(NULL, ", \n");
    strcpy(newData.firstname, token);
    token = strtok(NULL, ", \n");
    strcpy(newData.age, token);
    
    person search = { "", "", "0" };
    while (fread(&search, sizeof(person),1,rpfptr) && strcmp(search.lastname, newData.lastname)) {
    
    }
    if (strcmp(search.lastname, newData.lastname) == 0) {
        fseek(rpfptr, -1 * (int)sizeof(person), SEEK_CUR);
        fwrite(&newData, sizeof(person), 1, rpfptr);
    }
    else {
        puts("Record not found.\n");
    }
    fclose(rpfptr);   
}

void deleteRecord() {
    FILE* fPtr;
    if ((fPtr = fopen("studentdata.dat", "rb+")) == NULL) {
        puts("Error opening nameage.dat r+");
    }
 
    person userEntry = { "", "", "0" };
    printf("Delete existing lastName, firstName, age: ");
    char line[50];
    fgets(line, 50, stdin);
    char* token = strtok(line, ", \n");
    strcpy(userEntry.lastname, token);
    token = strtok(NULL, ", \n");
    strcpy(userEntry.firstname, token);
    token = strtok(NULL, ", \n");
    strcpy(userEntry.age, token);
 
    person search = { "", "", "0" };
    while (fread(&search, sizeof(person), 1, fPtr) && strcmp(search.lastname, userEntry.lastname)) {
 
    }
    if (strcmp(search.lastname, userEntry.lastname) == 0) {
        fseek(fPtr, -1 * (int)sizeof(person), SEEK_CUR);
        person blank = { "", "", "" };
        fwrite(&blank, sizeof(person), 1, fPtr);
    }
    else {
        puts("Record not found.\n");
    }
 
    fclose(fPtr);
}