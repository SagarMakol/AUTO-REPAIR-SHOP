#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//*******************************************************
//  CLASS NAME : AUTOSHOP
//*******************************************************

class autoshop
{
    int carno;
    char custname[25];
    char prob[50];
    float costofprob;
  public:
    void getdata();
    void showdata();
    int retcarno();
}a;

//*******************************************************
//  FUNCTION TO GET DATA
//*******************************************************

void autoshop::getdata()
{
    
    int p;
    cout<<"**************************************************************";
    cout<<setw(50)<<"WELCOME\n";
    cout<<"**************************************************************";
    cout<<setw(40)<<"AUTO REPAIR SHOP";
    cout<<"\n Enter Car Number: ";
    cin>>carno;
    cout<<"\n Enter your Name: ";
    cin>>(custname);
    cout<<setw(45)<<"LIST OF PROBLEMS";
    cout<<"\nSelect the problem you are facing with your car : ";
    cout<<"\n1. Starting issue.";
    cout<<"\n2. Tyre puncture.";
    cout<<"\n3. Body Damaged.";
    cout<<"\n4. Creaking noise.";
    cout<<"\n5. Regular maintainence.";
    cout<<"\nENTER YOUR PROBLEM NUMBER : ";
    cin>>p;
    switch(p)
  {
    case 1:

        cout<<"Problem - Starting issue";
        cout<<"\nCharges - INR 400.00";
        strcpy(prob,"Starting issue");
        costofprob=400;
        break;
    case 2:
        cout<<"Problem - Tyre puncture.";
        cout<<"\nCharges - INR 100.00";
        strcpy(prob,"Tyre puncture");
        costofprob=100;
        break;
    case 3:
        cout<<"Problem - Body Damaged.";
        cout<<"\nCharges - INR 2000.00";
        strcpy(prob,"Body Damaged");
        costofprob=2000;
        break;
    case 4:
        cout<<"Problem - Creaking noise.";
        cout<<"\nCharges - INR 500";
        strcpy(prob,"Creaking noise");
        costofprob=500;
        break;
    case 5:
        cout<<"Problem - Regular maintainence.";
        cout<<"\nCharges - INR 1500.00";
        strcpy(prob,"Regular maintainence");
        costofprob=1500;
        break;
    default:
        cout<<"WRONG CHOICE";
        break;
  }
    ofstream outFile;
    outFile.open("userdata.dat",ios::binary|ios::app);
    outFile.write((char*)&a,sizeof(a));
    outFile.close();
    
}

//*******************************************************
//  FUNCTION TO SHOW DATA
//*******************************************************

void autoshop::showdata()
{
    
    cout<<setw(40)<<"Kindly check your details";
    cout<<"\nCar Number : "<<carno;
    cout<<"\nName : "<<custname;
    cout<<"\nProblem : "<<prob;
    cout<<"\nCharges : "<<costofprob;
    

}

//*******************************************************
//  FUNCTION TO RETURN CAR NUMBER
//*******************************************************

int autoshop::retcarno()
{
  return carno;
}

//*******************************************************
//  FUNCTION TO DISPLAY RECORDS
//*******************************************************

void display()
{
    ifstream inFile("userdata.dat",ios::binary);
    while(inFile.read((char *)&a,sizeof(a)))
    {
    //inFile.read((char *)&a,sizeof(a));
    a.showdata();
    }
    inFile.close();
}

//*******************************************************
//  FUNCTION TO DELETE RECORDS
//*******************************************************

void delete_record()
{
    
    int n,found=0;
    ifstream inFile;
    inFile.open("userdata.dat",ios::binary);
    ofstream outFile;
    outFile.open("temp.dat",ios::binary);
    cout<<"Enter Car No of record you want to delete :";
    cin>>n;
    while(inFile.read((char*)&a,sizeof(a)))
    {
    if(n!=a.retcarno())
        outFile.write((char*)&a,sizeof(a));
    }
    inFile.close();
    outFile.close();
    remove("userdata.dat");
    rename("temp.dat","userdata.dat");
    if(found!=0)
    cout<<"Record Deleted";
    else
    cout<<"Record does not exist";
}
//*******************************************************
//  FUNCTION TO COUNT NUMBER OF RECORDS
//*******************************************************

void countrec()
{
  ifstream inFile;
  autoshop a;
  inFile.open("userdata.dat",ios::in|ios::binary);
  int num=0;
  inFile.seekg(0);
  while(inFile.read((char *)&a,sizeof(a)))
  {
    num++;
  }
  cout<<"Records in the file : "<<num;
  inFile.close();
  
}

//*******************************************************
//  FUNCTION TO LET ADMIN CHOOSE WHAT TO DO
//*******************************************************

void adminmenu()
{
  int q;
  char ch3;
  do
  {
    
    cout<<"What do you wish to do ?\n";
    cout<<"1. View Records\n";
    cout<<"2. Delete Records\n";
    cout<<"3. Count total records\n";
    cout<<"4. Exit to Main Menu";
    cin>>q;
    switch(q)
    {
        case 1:
            //Display all records
            cout<<setw(40)<<"\nList of records\n";
            display();
            break;
        case 2:
            //Delete record
            delete_record();
            break;
        case 3:
            //count records
            countrec();
            break;
        case 4:
            //sends user back to main menu
            break;
    }
     cout<<"\nWant to continue ?(Y/N)";
     cin>>ch3;
  }while(ch3=='y'||ch3=='Y');
}

//*******************************************************
//  CLASS NAME : ADMIN
//*******************************************************

class admin
{
  char user[20];
  char password[20];
     public:
  void checkinfo();
}am;

//*******************************************************
//  FUNCTION TO CHECK USERNAME AND PASSWORD
//*******************************************************

void admin::checkinfo()
{     // Get username and pass from user
    char ch2,chh,i;
    a:
    
    cout<<"Please enter your username\n";
    cin>>user;
    cout<<"\nPlease enter your password"<<endl;
    cin>>password;
    // for(i=0;i<6;i++)
    // {
    //     password[i]=getchar();
    //     cout<<'*';
    // }
    // password[i]='\0';
    //gets(password);
    // Now we compare user/password with one from file
    if((strcmp(user,"admin")==0)&&(strcmp(password,"qwerty")==0))
    {
        cout<<"\nSuccess, you are signed in!\n";
        adminmenu();
    }
    else
    {
        cout<<"\nUsername and/or password incorrect. Try again.\n";
        cout<<"Type E if you want to exit or R if you want to retry login\n";
        cin>>ch2;
        if(ch2=='e'||ch2=='E')
        {
            exit(0);
        }
        else if(ch2=='r'||ch2=='R')
        {
            goto a;
        }
    }
}

//*******************************************************
//  MAIN SCREEN
//*******************************************************

int main()
{
    mainmenu:
    char ch1;
    do
    {
    
    cout<<setw(45)<<"MAIN MENU";
    cout<<"\nSELECT WHAT YOU WANT FROM THE LIST BELOW :";
    cout<<"\n1. Customer Mode";
    cout<<"\n2. Administrator Access Mode";
    cout<<"\n3. Exit";
    cout<<"\nYour choice :";
    int i;
    cin>>i;
    switch(i)
    {
      case 1:
            a.getdata();
            a.showdata();
            break;
      case 2:
            am.checkinfo();
            break;
      case 3:
            cout<<"GOODBYE !";
            exit(0);
            break;
      default:
            cout<<"WRONG CHOICE";
            cout<<"\nWant to choose again ?(Y/N)";
            char q;
            cin>>q;
            if(q=='y'||q=='Y')
            {
             goto mainmenu;
            }
            else
            {
             cout<<"GOODBYE !";
             exit(0);
            }
     }
    cout<<"\nWant to continue ?(Y/N)";
    cin>>ch1;
    }while(ch1=='y'||ch1=='Y');
    return 0;
}


