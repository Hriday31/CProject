//Header files
#include <stdio.h>
#include <string.h>

//Declaring global variables
int columns=120;
int d;
int r;
char s[4],o;
FILE *f;
//Initialising Functions
void pr();
void gotoxy();
void welcome();
void paper();
void debug()
{
    char t;
    scanf("%c",&t);
}

struct student{
    int roll_no;
    int dob;
    char name[30];
    int score_pe;
    int score_hm;
    int score_chem;
    int score_eng;
    int score_eco;
};


//printf ( "\033[2J");
//Main Function body
int main() 

{   
    
printf ( "\033[2J");
    //system("cls");
    p1:
    {
    welcome();}
    struct student s1[100]={{001,31122003,"Hriday Aggarwal",0,0,0,0,0},{002,21032005,"Anandita",0,0,0,0,0}};
    for (int i=0;i<100;i++){
        if(r==s1[i].roll_no)
        {
            if(d==s1[i].dob){
                printf ( "\033[2J");
                gotoxy(0,0);
                pr("","~");
                char *z;
                
                pr("Welcome Back"," ");
                pr(("%s",s1[i].name)," ");
                pr("","~");
                gotoxy(15,10);
                printf("Your Previous Scores are\n\n          Physical Education : %d\n          Hindustani Music : %d\n          Economics : %d\n          English Core : %d\n          Chemistry : %d\n",s1[i].score_pe,s1[i].score_hm,s1[i].score_eco,s1[i].score_eng,s1[i].score_chem);
                gotoxy(25,10);
                printf("Enter Subject code(PE/HM/CHEM/ENG/ECO) : ");
                scanf("%s",s);
                printf ( "\033[2J");
                gotoxy(0,0);
                paper();
                }

            else{
                //system("cls");
                printf ( "\033[2J");
                gotoxy(20,0);
                printf("Hello %s \n",s1[i].name);
                printf("You entered the wrong Dob\nPlease try again");
                goto p1;
                }
        }

    }
    while(1){}
}

//Function definations
void paper()
{
    FILE *f;
    f=fopen("PE.txt","r");
    char a,o;
    int marks=0;
    
    while(a!='|')
    {   a=getc(f);
            
        if (a=='~')
        {   debug();
            a=getc(f);
            printf("\nEnter option : ");
            scanf("%c",&o);
            
            if (a==o)
            {   marks++;
                //printf("y");
                continue;
            }continue;
            
        }
        else if(a=='|'){break;}
        else{
            printf("%c",a);
        }
        continue;
    }
    printf("%d",marks);
}


void gotoxy(int row,int col)
{
    printf ( "\033[%d;%dH",row,col);
}
void welcome()//Page 1
{   gotoxy(0,0);
    pr(" Welcome to Online Examination System ","~");
    pr(" Please Login using your Credentials "," ");
    gotoxy(27,0);
    pr("","~");
    gotoxy(10,10);
    printf("Enter Your Roll Number -");
    gotoxy(15,10);
    printf("Enter Your DOB(ddmmyyyy) -");
    gotoxy(10,50);
    scanf("%d",&r);
    gotoxy(15,50);
    scanf("%d",&d);  
}
void pr(char a[100],char b[1])//Function to print text in centre of screen
{
    int n;
    n=strlen(a);
    printf("\n");

    for (int x=0;x<((columns-n)/2);x++)
    printf("%s",b);

    printf("%s",a);

    for (int x=0;x<((columns-n)/2);x++)
    printf("%s",b);

    printf("\n");
}
