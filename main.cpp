#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<sstream>
#include <vector>
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
void  create_login_(int r)
{
    string re,pas;
    switch (r)
    {
        case 1:
        {
            //create account
    printf("Enter the Reg_No.\n");
    cin>>re;
    printf("Enter the Password.\n");
    cin>>pas;
    ofstream ad;
    ifstream ok;
    if(pas.length()>8)//password length
    {        
    ok.open(re);
    if(!ok.is_open())//ckecking file  is present or not
    {
    ad.open(re,ios::app);
    if(ad.is_open())//file created
    {
        ad<<pas;
        printf("Account created successfully\n");
       // return 1;//creating
    }
    else//unfortnutly no create
    {
        printf("Cannot create file\n");
    }
    }
    else//ckecking file  is present or not
    {
        printf("Reg.no  Invalid :/  \n");
    }
    }
    else//password length
    {
        printf("Password  is not Strong \n");
    }      
            ad.close();
            ok.close();
            //closeing
        }
            break;
      case 2:
      {   
      // email login
            char r;
           
            int ak,u=0;
            //vector<char>v;
            printf("Enter the Reg_No.\n");
    cin>>re;
    printf("Enter the Password.\n");
    cin>>pas;
     //string sl[];
    char s[pas.length()];
    char slk[pas.length()];
    for(int i=0;i<pas.length();i++)//for input value
    {
        slk[i]=pas[i];
    }
    /*for(int i=0;i<pas.length();i++)//for outputing value
    {
        cout<<slk[i];
    }5
     *
    cout<<endl;*/
    ifstream cjk;
    cjk.open(re);
    if(cjk.is_open())
    {
        
        while(cjk.good())
        {
            cjk.get(r);
            s[u]=r;
            u++;
        }
        /*cout<<"the value of read \n";
       for(int i=0;i<pas.length();i++)//for outputing 
    {
        cout<<s[i];
    }*/
        cout<<endl;
        int al=0;
        for(int i=0;i<pas.length();i++)
        {
            if(slk[i]==s[i])
            {
                al++;
            }
        }
        
        if(al==19)
        {
        printf("Login Successfully \n");
        string str;
        printf("Enter the Student name.\n");
        cin>>str;
        admin_view(str);
         }
        
        else
        {
            printf("Wrong Password >:(\n");
        }
    }
    else
    {
      printf("Account not found\n");
    }
    cjk.close();
    //closeing
    }
           break;
        default :
            printf("Enter the correct option\n");
    }
}
void stud::dispaly()
{
    printf("%d\t%d\t%s\t%d\n",reg,id,name,mark);
}

  void edit(string nma)

     {

         ostringstream txt;

         ifstream inp;

         inp.open(nma);

         if(inp.is_open())

         {

             txt<<inp.rdbuf();

             string str=txt.str();

           string file_found;

           string file_replace;

           cout<<"Enter the word or no. which you want  to replace with\n";

           cin>>file_found;

           cout<<"Enter the  the word or  no. with you want to replace \n";

           cin>>file_replace;

           size_t pos=str.find(file_found);

           str.replace(pos,string(file_found).length(),file_replace);

           inp.close();

           ofstream inff;

           inff.open(nma);

           inff<<str;

           inff.close();

           cout<<"\n Changes  Applied:)\n";

         }

         else

         {

           cout<<"\nFile Not Found:(\n";  

         }

     }
  void login(string str,string em)//Teacher Login System
{
    string email,password;
    printf("Welcome to ums login System-login\nEnter your ums email.id:\n");
    cin>>email;
    printf("Enter you password\n");
    cin>>password;
    if(email==em&&password.length()>8)
    {
        admin_view(str);
        edit(str);
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
                int okl;
                printf("2-Press (1):Create The account\n2-Press (2):Login\n");
                cin>>okl;
                create_login_(okl);
              //printf("Name   \tRef.no\tID\tMarks\n");
              //admin_view(nm);
              //login(nm,"anujrai04082002.0@gmail.com");
                break;
            case 3:
                printf("Welcome to Teacher Section\n");
                int optio[3];
                printf("3-Press (1):For see all Student\n3-Press (2):See Individual Student\n");//3-Press ()
                cin>>optio[0];
                if(optio[0]==1)
                {
                    admin_view("Student.txt");
                    printf("Want to edit some-thing :)\npress 1:For Edit:)\nPress 2:For Neutral:)\n");
                    cin>>optio[1];
                    if(optio[1]==1)
                    {
                        printf("Editor option :).......\n\n");
                    edit("Student.txt");
                    }
                    else if(optio[1]==2)
                    {
                        printf("Thank you :)\n");
                    }
                    else
                    {
                        printf("Please enter correct option :(\n");
                    }
                }
                else if(optio[0]==2)
                { 
                    printf("Enter the Student name.\n");
                    cin>>nm;
                     login(nm,"anuj.12013239@lpu.in");
                     
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