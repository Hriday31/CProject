//Header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Declaring global variables
int d,size,w=0,r,q=0,marks=0,k,newdob,columns=120;
FILE *f;
char newname[30],subject_code;

//Initialising Functions
void pr();
void gotoxy();
void welcome();
void paper();
void debug();
void displayrecord();

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

//Main Function body
int main() 
{   
    printf ( "\033[2J");
    system("cls");
    
    struct student s1[]={{14801,31122003,"Hriday Aggarwal",10,9,9,0,7},{14802,21032005,"Anandita",10,10,9,8,0},{14803,14122007,"Sabhyata",10,10,9,0,8}};
    size=sizeof(s1)/sizeof(s1[0]);
    p1:{welcome();}
    for (int i=0;i<(size);i++){
        if(r==s1[i].roll_no)
        { 
            if(d==s1[i].dob){
                p2:{printf ( "\033[2J");}
                gotoxy(0,0);
                pr("","~");
                pr("Welcome Back"," ");
                pr(("%s",&s1[i].name)," ");
                pr("","~");
                gotoxy(27,0);
                pr("","~");
                gotoxy(10,10);
                printf("Your Previous Scores are\n\n\tPhysical Education : %d\n\tPhysics : %d\n\tChemistry : %d\n\tPolitical Science : %d\n\tPsychology : %d\n",s1[i].score_pe,s1[i].score_phy,s1[i].score_chem,s1[i].score_polsci,s1[i].score_psy);
                gotoxy(20,10);
                p3 : {printf("Enter Subject code:\n\tA. Physical Education\n\tB. Physics\n\tC. Chemistry\n\tD. Political Science\n\tE. Psychology\n ");
                debug();
                
                gotoxy(20,35);
                scanf("%s", &subject_code);}
                printf ( "\033[2J");
                gotoxy(0,0);
                FILE *f;
                switch(subject_code)
                {
                    case 'A' : f=fopen("PE.txt","r");
                                paper(f);
                                s1[i].score_pe=marks;
                    break;
                    case 'B' : f=fopen("physics.txt","r");
                                paper(f);
                                s1[i].score_phy=marks;
                    break;
                    case 'C' : f=fopen("chem.txt","r");
                                paper(f);
                                s1[i].score_chem=marks;
                    break;
                    case 'D' : f=fopen("polsci.txt","r");
                                paper(f);
                                s1[i].score_polsci=marks;
                    break;
                    case 'E' : f=fopen("psych.txt","r");
                                paper(f);
                                s1[i].score_polsci=marks;
                    break;
                    default: 
                    {printf ( "\033[2J");
                    printf("This is an invalid subject code.");
                    goto p3;}
                             
                }
                
                   
                if(q==0){scanf("%d",&q);
                printf("%d",q);
                printf ( "\033[2J");
                goto p4;}
                }

            if(d!=s1[i].dob){
                printf ( "\033[2J");
                gotoxy(20,10);
                printf("Hello %s \n",s1[i].name);
                gotoxy(21,10);
                printf("You entered the wrong date of birth please try again");
                goto p1;
                }
        }



            printf ( "\033[2J");
            p4:{gotoxy(0,0);
                pr("Test Submitted Successfully","~");
            gotoxy(27,0);
            pr("","~");}
            gotoxy(10,0);
            printf("\nPhysical Education \t\t%d\n",s1[i].score_pe);
            printf("\nPhysics \t\t\t%d\n",s1[i].score_phy);
            printf("\nChemistry \t\t\t%d\n",s1[i].score_chem);
            printf("\nPolitical Science\t\t%d\n",s1[i].score_polsci);
            printf("\nPsychology\t\t\t%d\n",s1[i].score_psy);
            gotoxy(25,0);
            printf("\tIf you want to :\n\tGo back to tests page enter 1\n\tExit enter 2\t\t\t");
            scanf("%d",&k);
            switch(k)
            {
                case 1: {
                printf ( "\033[2J");
                goto p2;
                break;}
                case 2:{
			    exit(0);
			    break;}

			default:
			printf("\nINVALID CHOICE...\n");
            goto p4;
        }
    }
    while(1){}
}


//Function definations
void paper(FILE *f)
{
   
    char a,o,end;
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
    pr("Enter 1 to go to results","-");
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
void debug()
{char t;
scanf("%c",&t);
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