#include<iostream>
#include<fstream>
#include<cstring>
#define MAX 10
using namespace std;
class stud
{
    char  name[10];
    int reg;
    int mark;
    int id;
public:
    void inputing();
    void dispaly();
    friend void admin_view(string);
    void save()
    {
    ofstream file1,file2;
    file1.open("Student.txt",ios::app);
    file2.open(name,ios::app);
    
    //file1<<"Reg.No\tID\tName   \tMarks\n";
    if(file1.is_open()&&file2.is_open())
    {
          file1<<name<<"\t";
          file1<<reg<<"\t";
          file1<<id<<"\t";
          file1<<mark<<"\n";
          
          file2<<name<<"\t";
          file2<<reg<<"\t";
          file2<<id<<"\t";
          file2<<mark<<"\n";
    }
    else
    {
        printf("\nCannot open the file:/\n");
    }
    file1.close();
    file2.close();
}
    
};

void stud::inputing()
{
    printf("Enter the name :\n");
    cin>>name;
    printf("Enter the Reg.No :\n");
    scanf("%d",&reg);
    printf("Enter the Marks:\n");
    scanf("%d",&mark);
    printf("Enter the Id:\n");
    scanf("%d",&id);
}
void admin_view(string strd)
{
ifstream file2;
char cj;
file2.open(strd);
if(file2.is_open())
{
    printf("Name   \tRef.no\tID\tMarks\n");
    while (file2.good())
    {
        file2.get(cj);
        printf("%c",cj);
     }
}
else
{
    printf("\nFile Not Found\n");
}
file2.close();
}

void stud::dispaly()
{
    printf("%d\t%d\t%s\t%d\n",reg,id,name,mark);
}
void login(string str,string em)
{
    string email,password;
    printf("Welcome to ums login System-login\nEnter your ums email.id:\n");
    cin>>email;
    printf("Enter you password\n");
    cin>>password;
    if(email==em&&password.length()>8)
    {
        admin_view(str);
    }
    else
    {
        printf("\nPlease Enter the correct password and email\n");
    }
}
int main()
{
    stud op[MAX];
    int c;
    int s;
    string nm;
    
    do
    {
        printf("\nPress 1:Create Student account \nPress 2:Student Login \nPress 3:Teacher login \nPress 4: Admin View \nPress 5:Exit\n");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                printf("Enter the Total no of Student :\n");
    cin>>s;
    for(int i=0;i<s;i++)
    {
        op[i].inputing();      
    }
    for(int i=0;i<s;i++)
    {
    op[i].save();
    }
    
    printf("Reg.No\tID\tName\tMarks\n");
   // 
                 for(int i=0;i<s;i++)
                 {
                    op[i].dispaly();
                }
    
                break;
            case 2:
              printf("Enter the Student name.\n");
              cin>>nm;
              //printf("Name   \tRef.no\tID\tMarks\n");
              //admin_view(nm);
              login(nm,"anujrai04082002.0@gmail.com");
                break;
            case 3:
                printf("Welcome to Teacher Section\n");
                int optio[3];
                printf("3-Press (1):For see all Student\n3-Press (2):See Individual Student\n");//3-Press ()
                cin>>optio[0];
                if(optio[0]==1)
                {
                    admin_view("Student.txt");
                    //next edit the code()
                }
                else if(optio[0]==2)
                { 
                    printf("Enter the Student name.\n");
                    cin>>nm;
                     login(nm,"anuj.12013239@lpu.in");
                     //next edit the code()
                }
                else
                {
                    cout<<"Enter the correct option\n";
                }
                break;
           case 4:
               
                admin_view("Student.txt");       
                break;
            case 5:
                printf("\nThank you \n");
                break;
            default:
                printf("Plz Enter the correct option:\n ");
        }
    } while (c!=5);
return 0;    
}