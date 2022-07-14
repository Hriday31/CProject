//Header files
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

//Declaring global variables
int columns=120;
int d,size,w=0;
int r,q;
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
void displayrecord();
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
    system("cls");
    
    struct student s1[]={{14801,31122003,"Hriday Aggarwal",0,0,0,0,0},{14802,21032005,"Anandita",0,0,0,0,0},{14803,21032005,"Anandita",0,0,0,0,0}};
    p1:
    {welcome();}
    size=sizeof(s1)/sizeof(s1[0]);
    printf("%d size  ",size);
    for (int b=0;b<(size);b++){printf("%d ",s1[b].roll_no);}
    for (int i=0;i<(size);i++){printf("\n%d",s1[i].roll_no);
        if(r==s1[i].roll_no)
        {   w=1;
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
                debug();
                scanf("%s", &subject_code);
                printf ( "\033[2J");
                gotoxy(0,0);
                FILE *f;
                switch(subject_code)
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
                paper(f);
                scanf("%d",&q);
                printf("%d",q);   
                if(q==1){
                printf ( "\033[2J");
                goto p4;}
                }

            if(d!=s1[i].dob){
                //system("cls");
                printf ( "\033[2J");
                gotoxy(20,0);
                printf("Hello %s \n",s1[i].name);
                printf("You entered the wrong Dob\nPlease try again");
                goto p1;
                }
        }}
        if(w==0)
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
            };

        //p4
        p4:{
            void displayrecord(){
	system("cls");

	printf("\nPhysical Education \t\t%d\n",s1[size].score_pe);
                printf("\nPhysics \t\t%d\n",s1[size].score_phy);
                printf("\nChemistry \t\t%d\n",s1[size].score_chem);
                printf("\nPolitical Science\t\t%d\n",s1[size].score_polsci);
                printf("\nPsychology\t\t%d\n",s1[size].score_psy);

	printf("\n\n\n\t");
} displayrecord();

            int k;
        printf("If you want to :\n go back to login page enter 1\n enter 2\n");
            scanf("%d",&k);
            switch(k)
            {
                case 1: {
                printf ( "\033[2J");
                goto p1;
                break;}
                case 2:{
                // exit
			    exit(0);
			    break;}

			default:
			printf("\nINVALID CHOICE...\n");
        }

    } 
            
            
            
        }

    
    while(1){}
}

//Function definations
void paper(FILE *f)
{
   
    char a,o,end;
    int marks=0,q=0;
    pr("TEST STARTS","*");
    
    while(a!='|')
    {   

        a=getc(f);
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
    
    pr("TEST ENDS","*");
    pr("enter 1 to go to results"," ");
    debug();
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

