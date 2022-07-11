//Header files
#include <windows.h>
#include <stdio.h>
#include <string.h>

//Declaring global variables
int columns, rows;

//Initialising Functions
void winsize();
void pr();

//Main Function body
int main() 

{   system("cls");
    winsize();
    pr("Welcome to Online Examination System","~");
    pr("Please Login using your Credentials"," ");
    
    while(1){};

}

//Function definations
void pr(char a[100],char b[1])//Function to print text in centre of screen
{
    int n;
    n=strlen(a);
    printf("\n");

    for (int x=0;x<((columns-n)/2)-2;x++)
    printf("%s",b);

    printf("> %s <",a);

    for (int x=0;x<((columns-n)/2)-2;x++)
    printf("%s",b);

    printf("\n");
}

void winsize()//Function to find window width and height 
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}