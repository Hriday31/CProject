//Header files
#include <stdio.h>
#include <string.h>

//Declaring global variables
int columns=120;
int d,size;
int r;
char s[4],o;
FILE *f;
int p;
char newname[30];
int newdob;
int ppr;
char subject_code;
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
    int score_phy;
    int score_chem;
    int score_polsci;
    int score_psy;
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
    struct student s1[]={{14801,31122003,"Hriday Aggarwal",0,0,0,0,0},{14802,21032005,"Anandita",0,0,0,0,0}};
    
    for (int i=0;i<100;i++){
        if(r==s1[i].roll_no)
        {
            if(d==s1[i].dob){
                printf ( "\033[2J");
                gotoxy(0,0);
                pr("","~");
                char *z;
                
                pr("Welcome Back"," ");
                pr(("%s",&s1[i].name)," ");
                pr("","~");
                gotoxy(15,10);
                printf("Your Previous Scores are\n\n          Physical Education : %d\n          Physics : %d\n          Chemistry : %d\n          Political Science : %d\n          Psychology : %d\n",s1[i].score_pe,s1[i].score_phy,s1[i].score_chem,s1[i].score_polsci,s1[i].score_psy);
                gotoxy(25,10);
                printf("Enter Subject code:\n  A. Physical Education\n  B. Physics\n  C. Chemistry\n  D. Political Science\n  E. Psychology\n ");
                scanf("%c", &subject_code);
                printf ( "\033[2J");
                gotoxy(0,0);
                FILE *f;
                switch(ppr)
                {
                    case 'A' : f=fopen("PE.txt","r");
                    break;
                    case 'B' : f=fopen("PE.txt","r");
                    break;
                    case 'C' : f=fopen("PE.txt","r");
                    break;
                    case 'D' : f=fopen("PE.txt","r");
                    break;
                    case 'E' : f=fopen("PE.txt","r");
                    break;
                    default: printf("This is an invalid subject code.");
                             
                }

                
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
        else
        {
            printf("This record is not in the database.\n");
            printf("If you want to :\n go back to the previous page enter 1\n sign up as new student enter 2\n");
            scanf("%d",&p);
            switch(p)
            {
                case 1: {
                printf ( "\033[2J");
                goto p1;
                break;}
                case 2: {printf("Enter name : ");
                        scanf("%s",&newname);
                        printf("Enter you DOB : ");
                        scanf("%d",&newdob);
                        printf("\n");
                        size=sizeof(s1)/sizeof(s1[1]);
                        s1[size].roll_no=14801+size;
                        s1[size].dob=newdob;
                        strcpy(s1[size].name , newname);
                        s1[size].score_pe=0;
                        s1[size].score_phy=0;
                        s1[size].score_chem=0;
                        s1[size].score_polsci=0;
                        s1[size].score_psy=0;
                        printf ( "\033[2J");
                        gotoxy(20,0);
                        printf("Your roll number is : %d", s1[size]);
                        goto p1;
                        break;}
                default: goto p1;
            }
            
        }

    }
    while(1){}
}

//Function definations
void paper()
{
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
