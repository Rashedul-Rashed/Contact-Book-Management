#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 1000

typedef struct
{
    char firstName[20];
    char lastName[20];
    char contactNo[20];
}Contact;
Contact allContacts[MAX_SIZE];
Contact c;

int currentSize = 0;

void newContact()
{
    if(currentSize == MAX_SIZE) {
        puts("Error: Book is Full!");
        return;
    }
    Contact c;
    printf("Enter First Name:- ");
    gets(c.firstName);
    strlen(c.firstName)
    printf("Enter Last Name:- ");
    gets(c.lastName);
    printf("Enter Number:- ");
    gets(c.contactNo);

    allContacts[currentSize] = c;
    ++currentSize;
}

void writeToFile()
{
    FILE *file;

    file = fopen("contacts.txt","w");
    fputs("",file);
    fclose(file);

    file = fopen("contacts.txt","a");
    int i;
    for(i=0; i<currentSize; i++)
    {
        fputs(allContacts[i].firstName,file);
        fputs(allContacts[i].lastName,file);
        fputs(allContacts[i].contactNo,file);
    }
}

int readFromFile()
{
    FILE *file;
    file = fopen("contacts.txt","r");
    if(file==NULL)
        printf("Not file\n");
    else
    {
        while(!feof(file)){
            fgets(c.firstName,20,file);
            fgets(c.lastName, 20, file);
            fgets(c.contactNo, 20, file);
            allContacts[currentSize] = c;
            currentSize++;
        }
    }
    return currentSize;
}

void display()
{
    int i;
    Contact c;
    for(i=0; i<currentSize-1; i++)
    {
        c = allContacts[i];
        printf("First Name: %s",c.firstName);
        printf("Last Name: %s",c.lastName);
        printf("Contact No: %s",c.contactNo);
    }
}

void uiPrint()
{
    printf("#############################\n");
    printf("####### Contact Menu  #######\n");
    printf("#### 1. Add Contact      ####\n");
    printf("#### 2. Show Contact     ####\n");
    printf("#### 3. Clear Screen     ####\n");
    printf("#### 4. Exit             ####\n");
    printf("#############################\n");
    printf("Reply: ");
}

int main()
{
    readFromFile();
    uiPrint();
    int n = 1;
    while(1){
        scanf("%d",&n);
        getchar();
        switch(n)
        {
        case 1:
            newContact();
            system("cls");
            uiPrint();
            break;
        case 2:
            display();
            break;
        case 3:
            system("cls");
            uiPrint();
            break;
        case 4:
            writeToFile();
            return 0;
            break;
        default :
            system("cls");
            uiPrint();
            break;
        }
    }

    return 0;
}
