//Header files
#include <stdio.h>
#include <string.h>

//Declaring global variables
int columns=120;

//Initialising Functions
void pr();
void gotoxy();


//Main Function body
int main() 

{   char r[10],d[10];
    system("cls");
    pr("Welcome to Online Examination System","~");
    pr("Please Login using your Credentials"," ");
    gotoxy(78,0);
    pr("","~");
    gotoxy(10,10);
    printf("Enter Your Roll No.-");
    gotoxy(15,10);
    printf("Enter Your DOB(dd/mm/yyyy)-");
    gotoxy(10,35);
    gets(r);
    gotoxy(15,44);
    gets(d);
    
    printf("%s",r);
    
    while(1){};

}

//Function definations
void gotoxy(int row,int col)
{
    printf ( "\033[%d;%dH",row,col);
}
void pr(char a[100],char b[1])//Function to print text in centre of screen
{
    int n;
    n=strlen(a);
    //printf("\n");

    for (int x=0;x<((columns-n)/2)-2;x++)
    printf("%s",b);

    printf("> %s <",a);

    for (int x=0;x<((columns-n)/2)-2;x++)
    printf("%s",b);

    printf("\n");
}
