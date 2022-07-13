//Header files
#include <stdio.h>
#include <string.h>

//Declaring global variables
int columns=120;
char r[10],d[10];

//Initialising Functions
void pr();
void gotoxy();
void welcome();


//Main Function body
int main() 

{   
    system("cls"); 
    welcome();
    /*if r in s
        if d match dob 
            pg 2a
            goto pg 3
        else
            wrong pass
             goto pg1
    else
        pg 2b credentials saved  
        goto pg 3

    pg 3 paper 
        pg 4 
        print result
        add rsult of that paper to structure
        do you want to go back to home or exir*/
    while(1){};

}

//Function definations
void gotoxy(int row,int col)
{
    printf ( "\033[%d;%dH",row,col);
}
void welcome()//Page 1
{
    pr(" Welcome to Online Examination System ","~");
    pr(" Please Login using your Credentials "," ");
    gotoxy(27,0);
    pr("","~");
    gotoxy(10,10);
    printf("Enter Your Roll Number -");
    gotoxy(15,10);
    printf("Enter Your DOB(dd/mm/yyyy) -");
    gotoxy(10,50);
    gets(r);
    gotoxy(15,50);
    gets(d);  
}
void pr(char a[100],char b[1])//Function to print text in centre of screen
{
    int n;
    n=strlen(a);
    printf("\n");

    for (int x=0;x<((columns-n)/2)-2;x++)
    printf("%s",b);

    printf(">%s<",a);

    for (int x=0;x<((columns-n)/2)-2;x++)
    printf("%s",b);

    printf("\n");
}
