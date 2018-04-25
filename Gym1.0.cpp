#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;

void MainMenu();
void Equipements();
void Add();
void Remove(char id2[]);
void Fees();
int Search(char ref[]);
char id2[20];
void Credit();
int Pack;

int main()
{
	cout<<"\t\t\tWELCOME TO GYM MANAGEMENT SYSTEM(V 1.6)\n";
	cout<<"\t\t\t--------------------------------------------------\n";
	int choice=0;
	p1:
	MainMenu();
	cin>>choice;
	switch(choice)
	{
		case 1:
			Equipements();
			goto p1;
		case 2:
			Add();
			goto p1;
		case 3:
			{
			int cnfm=0;
			cout<<"Enter ID to Delete from Database:";
	        cin>>id2;
			int isFound1=Search(id2);
			if(isFound1==1)
			{
	        cout<<"ID  Found:"<<id2;
	        cout<<"\nConfirm Delete(Yes=1 or No=0):";
	        cin>>cnfm;
	        if(cnfm==1)
	        {
	        cout<<"Deleting:"<<id2<<"....\n";
			Remove(id2);
			}
			else
			{
				cout<<"Not Deleting.";
			}
	        }
	        else
         	cout<<"Id not Found:";
            }
            
        
			goto p1;
		case 4:
			{
			cout<<"Enter ID to Search from Database:";
	        cin>>id2;
			int isFound1=Search(id2);
			if(isFound1==1)
	        cout<<"ID Found:"<<id2;
	        else
         	cout<<"Id not Found.";
            cout<<endl<<endl;
			goto p1;
			}
		case 5:
			Fees();
			goto p1;
		case 6:
			Credit();
		case 7:
			exit(0);
		default:
			cout<<"\nInvalid Details.Try Again!";
			goto p1;
			
	}				
						
}
void MainMenu()
{
	cout<<"\t\t\tMAIN MENU"<<endl;
	cout<<"\t\t\t1. About equipments"<<endl;
	cout<<"\t\t\t2. ADD members"<<endl;
	cout<<"\t\t\t3. Remove members\n";
	cout<<"\t\t\t4. Search Member\n";
	cout<<"\t\t\t5. Fee structure"<<endl;
	cout<<"\t\t\t6. Credit"<<endl;
	cout<<"\t\t\t7. Exit"<<endl;
	cout<<"\t\t\t\nenter your choice:";					
}
void Equipements()
{
	cout<<"\nWe are having these equipments:"<<endl;
	cout<<"1. bench press"<<endl;
	cout<<"2. abdominal bench"<<endl;
	cout<<"3. pull bar"<<endl;
}
void Add()
{	
	int age,weight,ch=0;
	char name[20],id[10],sex;
	ofstream f; 
    f.open ("text.txt",ios::app);
    cout<<"Enter 1 for Member:";
    cout<<"Enter 2 for Coach:";
    cin>>ch;
    if(ch==1)
    {
    	Fees();
    	cout<<"Enter Your Choice:";
    	cin>>Pack;
	}
    f<<ch<<"\t";
	cout<<"enter your details\n"<<endl;
	cout<<"Enter id:"<<endl;
	cin>>id;
	f<<id<<"\t";
	cout<<"Enter Name:"<<endl;
	cin>>name;
	f<<name<<"\t";
	cout<<"Enter age:"<<endl;
	cin>>age;
	f<<age<<"\t";
	cout<<"Enter weight:"<<endl;
	cin>>weight;
	f<<weight<<"\t";
	cout<<"Enter sex(M for Male F for Female):"<<endl;
	cin>>sex;
	f<<sex<<"\t";
	f<<Pack<<"\t\n";
	f.close();
	cout<<"\nFile Writing Succsessful";
	
	
}
int Search(char id2[])
{
   int ct=0;
	char tmp2[20];
    ifstream f("text.txt");
	
	while(f)
	{
		f>>tmp2;
		if(strcmp(tmp2,id2)==0)
		{
			ct++;
			break;
		}
	}
	f.close();
	return ct;	
}
void Remove(char ref2[])
{
	//cout<<ref2;
	int types,Tweight,Tage,TPack;
	char Tname[20],Tid[10],Tsex;
	ifstream f2("text.txt");
	ofstream wd("TempFile.txt",ios::app);
	while(!f2.eof())
	{
		f2>>types;
		f2>>Tid;
		f2>>Tname;
		f2>>Tage;
		f2>>Tweight;
		f2>>Tsex;
		f2>>TPack;
		int psn=f2.tellg();
		if(psn==-1)
		break;
		if(strcmp(ref2,Tid)!=0)
		{
		wd<<types;
		wd<<Tid;
		wd<<Tname;
		wd<<Tage;
		wd<<Tweight;
		wd<<Tsex;
		wd<<TPack;
		}
			
	}
	wd.close();
	f2.close();
	remove("text.txt");
	rename("TempFile.txt","text.txt");
	cout<<"File OverRiding Successful";

}
void Fees()
{
	cout<<"\n\nwe are offering three categories:"<<endl;
	cout<<"1.Platinum Rs:15,00"<<endl;
	cout<<"2.Gold     Rs:10,000"<<endl;
	cout<<"3.Silver   Rs:7,000"<<endl;
	
}
void Credit()
{
	cout<<"I would like to thank my Teacher Nistha Arora for Giving this wonderful topic to do this project.";
}

