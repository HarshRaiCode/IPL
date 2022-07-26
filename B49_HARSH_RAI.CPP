#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<iostream>
#include<time.h>
using namespace std;

int i,j,num,num1;
void header()                     //FOR HEADING
{
	system("cls");
	cout<<"\n\n\n\t\t\t\t Indian Premier League Organiser";
	cout<<"\n\n\t\t  ---------------------------------------------------------------------";
	cout<<"\n";
}

void about()                          //FOR COPYRIGHT
{
	header();
	printf("\n MADE BY-: HARSH RAI");
	printf("\n REGISTRATION NUMBER-: 11801557");
	printf("\n SECTION-: K18CJ");
	printf("\n ROLL NUMBER-: 49");
	printf("\n GROUP-: 2");
	getch();
}
class data               
{
	 char name[30];
   	 int playercode;
	 int M1R;                   //FIRST MATCH RUN
	 int M2R;                   //SECOND MATCH RUN
	 int M3R;                   //THIRD MATCH RUN
	 int total_run;
public:
	data()
	{
		playercode=0;
		strcpy(name," ");
		M1R=0;
		M2R=0;
		M3R=0;
		total_run=0;
}



void enter_name_runs()     										  //TO TAKE ENTRY OF NEW RECORDS
{
	 cout<<"\nEnter player code(Integral) : ";
	 cin>>playercode;
	 cout<<"\nEnter player name : ";
	 cin>>name;
	 cout<<"\nFirst match run(s)    : ";
	 cin>>M1R;
	 cout<<"\nSecond match run(s)    : ";
	 cin>>M2R;
	 cout<<"\nThird match run(s)  : ";
	 cin>>M3R;
	total_runs();   //CALLING FUNCTION TOTAL RUNS
}

void show_record()           									   //TO DISPLAY THE RECORDS EXISTING IN THE FILE
	{
		cout<<"\nPlayer code          :"<<playercode;
 		cout<<"\nPlayer name          : "<<name;
 		cout<<"\nFirst match run(s)   : "<<M1R;
 		cout<<"\nSecond match run(s)  : "<<M2R;
 		cout<<"\nThird match run(s)   : "<<M3R;
 		cout<<"\nTotal run(s)         : "<<total_run;
}

void total_runs()                								   //CALCULATE TOTAL RUNS
{
	total_run=M1R+M2R+M3R;
}



int getplayercode()
{
	return playercode;
}



int gettotalruns()
{
	return total_run;
}


char* get_name()
{
	return name;
}

void modify_data()                 								  //TAKE DATA TO MODIFIFY EXISTING RECORD
{
	cout<<"\nEnter new data for modification :::::::: ";
	cout<<"\nEnter name:";
	cin>>name;
	cout<<"\nEnter First match run(s) : ";
	cin>>M1R;
	cout<<"\nEnter Second match run(s) : ";
	cin>>M2R;
	cout<<"\nEnter Third match run(s) : ";
	cin>>M3R;
	total_runs();
} 

};



class nameiple
{
	
public:
	
	char nameipl[100];
	nameiple()   
	{
		
		strcpy(nameipl,"");
	}
	
	void show_names()
	{
		cout<<"\n";
		puts(nameipl);
	}
};

	data d;                   //CREATING OBJECT OF CLASS DATA
	fstream file;
	fstream file1;
//*  *  *  *  *  *  *  *  *  *  CALCULATE HIGHEST RUN(s)  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
void highest()
{
	header();
	file.open("record.dat",ios::in|ios::binary);     //OPENING FILE RECORD IN INPUT TYPE AND IN BINARY MODE. 
	int post=0,tr=0,plr_code=0,run=0;

	file.read((char*)&d,sizeof(d));
	while(file)
	{
		run=d.gettotalruns();             //TO GET THE TOTALRUNS
 	if(run>tr)
 	{
	 	post=file.tellg();               //TO GET THE TOTALRUNS 
 		tr=run;
 	}
 	file.read((char*)&d,sizeof(d));
 	}file.close();
	file.open("record.dat",ios::in|ios::binary);
	file.seekg(post-sizeof(d)); 
	file.read((char*)&d,sizeof(d));
	cout<<"\n::::::::::Highest run getter data::::::::::";
	cout<<"\nHighest run(s) getter code     : "<<d.getplayercode();
	cout<<"\nHighest run getter player is   :  "<<d.get_name();	
	cout<<"\nPlayer total run(s) are        : "<<tr;
	float avg;
	avg=(tr)/3;                           //TO FIND THE AVERAGE OF THE RUNS
	cout<<"\n    Player average is              : "<<avg;
	file.close();
}
//*  *  *  *  *  *  *  *  *  *  *  *  INSERT NEW RECORD(s)  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
void insert()
{
	header();
	int i,no;
	file.open("record.dat",ios::in|ios::app|ios::binary);
	cout<<"\n           ::Entry of new record(s)::          ";
	cout<<"\nHow many record(s) you want to enter : ";
	cin>>no;
	for(i=1;i<=no;i++)
	{
		d.enter_name_runs();               //insert  records
		file.write((char*)&d,sizeof(d));
	}file.close();
}
//*  *  *  *  *  *  *  *  *  *  *  *  *  DISPLAY EXISTING RECORD(s)   *  *  *  *  *  *  *  *  *  *  *  *  *  *
void display()
{
	header();
	file.open("record.dat",ios::in|ios::binary);
	cout<<"\n|||||||||||||||||||||| Entered record(s) ||||||||||||||||||||||||";
	file.read((char*)&d,sizeof(d));
	while(file)
	{
		d.show_record();
		file.read((char*)&d,sizeof(d));
	}file.close();
}
//*  *  *  *  *  *  *  *  *  *  *  *  * SEARCH RECORD *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
void search()
{
	header();
	int p,r,srch=0;
	file.open("record.dat",ios::in|ios::binary);
	cout<<"\nEnter the player code to see his records : ";
	cin>>r;
	file.seekg(0);
	file.read((char*)&d,sizeof(d));
	while(file)
	{
		p=d.getplayercode();
		if(r==p)                 //TO MATCH THAT THE ENTERED CODE EXIST OR NOT
		 {
		 	d.show_record();
 			srch=1;            
  			break;
 		}
 		else
 		{
		 	file.read((char*)&d,sizeof(d));
 		}
	}file.close();
	if(srch==0)
	{
		cout<<"\nThere is no record which have this playercode .";
	}
}
//*  *  *  *  *  *  *  *  *  *  *  *  *  *  MODIFY DATA *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
void modify()
{
	header();
	int posi=0,got=0,dmd=0;
	cout<<"\nEnter the playercode whose record to be modified : ";
	cin>>dmd;
	int ifdata=1; 
	file.open("record.dat",ios::in|ios::out|ios::binary);
	posi=file.tellg();
 	while(file)
	{
		file.read((char*)&d,sizeof(d));
 		got=d.getplayercode();
   		if(dmd==got)
        {
			file.seekg(posi);
   			d.modify_data();
   			ifdata=2;
   			file.write((char*)&d,sizeof(d));
        	break;
        }
        posi=file.tellg();
	}
	file.close();
	if(ifdata==1)
	{
		cout<<"\n           Data not available for modification         ";
	}
}
//*  *  *  *  *  *  *  *  *  *  *  *  *  *  * DELETE RECORD*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
void delete_record()
{
	header();
	int pointer=0,remove_record=0,size=0,code_get=0;
	// size=sizeof(file);
 	cout<<"\n Enter the player code whose record is to be deleted : ";
 	cin>>remove_record;
 	file.open("record.dat",ios::in|ios::out|ios::binary);
 	file1.open("tempo.dat",ios::in|ios::out|ios::binary);
 	file.seekg(0);
 	while(file)
 	{
 		file.read((char*)&d,sizeof(d));
  		code_get=d.getplayercode();
  		if(remove_record==code_get)
  		{
			cout<<" ";
  		}
  		else
  		{
		   file1.write((char*)&d,sizeof(d));
  		}
	}
	file.close();
	file1.close();
	remove("record.dat");
	rename("tempo.dat","record.dat");
}
//*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
int player_menu()
{
	header();
	int choice;
	char ans='n';
	do
	{
		cout<<"\n=*=*=*=*=*=*=*=*=* PLAYER RECORD KEEPING MENU*=*=*=*=*=*=*=*=*=*";
		cout<<"\n 1.INSERT RECORD \n 2.DISPLAY RCEORD \n 3.SEARCH RECORD \n 4.MODIFY RECORD \n 5.HIGHEST RUNS \n 6.DELETE PREVIOUS ENTERED RECORD \n 7.EXIT  ";
		cout<<"\n Enter any one of the options : ";
		cin>>choice;

		switch(choice)
		{
			case 1: insert();
 					break;
 			case 2: display();
 					break;
 			case 3: search();
 					break;
 			case 4: modify();
 					break;
 			case 5: highest();
 					break;
 			case 6: delete_record();
 					break;
 			
			default: cout<<"\n Enter choice between 1 to 6 ";
		}
		cout<<"\n Do you want to choose any other option ? :(y/n): ";
		cin>>ans;
		system("cls");
	}while(ans=='y'||ans=='Y');

}


void first_innings(int i)
{
		
		if(i==0)
			printf("\n First Batsman");
		if(i==1)
			printf("\n Second Batsman");
		if(i==2)
			printf("\n Third Batsman");
		if(i==3)
			printf("\n Fouth Batsman");
		if(i==4)
			printf("\n Fifth Batsman");
		if(i==5)
			printf("\n Sixth Batsman");
		if(i==6)
			printf("\n Seventh Batsman");
		if(i==7)
			printf("\n Eighth Batsman");
		if(i==8)
			printf("\n Ninth Batsman");
		if(i==9)
			printf("\n Tenth Batsman");
	
}	

void first_innings2(int i)
{
		
		if(i==0)
			printf("\n First Batsman");
		if(i==1)
			printf("\n Second Batsman");
		if(i==2)
			printf("\n Third Batsman");
		if(i==3)
			printf("\n Fouth Batsman");
		if(i==4)
			printf("\n Fifth Batsman");
		if(i==5)
			printf("\n Sixth Batsman");
		if(i==6)
			printf("\n Seventh Batsman");
		if(i==7)
			printf("\n Eighth Batsman");
		if(i==8)
			printf("\n Ninth Batsman");
		if(i==9)
			printf("\n Tenth Batsman");
	
}
		
		int totalbat;
		int totalbat2;
		
void scoring()
{
	int bat=0;
		num=rand()%100;
		bat=rand()%num;
		cout<<bat;
		totalbat+=bat;	
	if(bat==7)
		printf("\n OUT!!!!!!!!!!!!");
		
}

void scoring2()
{
	int bat=0;
		num=rand()%100;
		bat=rand()%num;
		cout<<bat;
		totalbat2+=bat;	
	if(bat==7)
		printf("\n OUT!!!!!!!!!!!!");
		
}
	
void ining_start()
{
	header();
	for(i=0;i<10;i++)
	{
		first_innings(i);
		scoring();
		if(i==9)
			{
			cout<<"\n Whole team All Out Total score is : ";
			cout<<totalbat;}
		
	}
	getch();
}

void ining_start2()
{
	for(i=0;i<10;i++)
	{
		first_innings2(i);
		scoring2();
		if(i==9)
			{
			cout<<"\n Whole team All Out Total score is : ";
			cout<<totalbat2;}
		
	}

}


void second_innings()
{
	header();
	ining_start2();
	if(totalbat<totalbat2)
		printf("\n Second Team Wins");
	else
		printf("\n First Team Wins");
		
		getch();
}



void chart()               //TO SCHEDULE THE GAME
{
	system("cls");
	j=8;
	cout<<"\n\n\n\t\t\t\t Indian Premier League Organiser";
	cout<<"\n\n\t\t  ---------------------------------------------------------------------";
	for(i=1;i<9;i++)
	{
		printf("\n\t\t\tDAY %d\n",i);
		
    	num = rand()%j;
		num1 = rand()%j; 
		if(num==0)
		 cout<<"\t\t\tteam"<<num<<" vs. team"<<num1;
		 if(num==1)
		 cout<<"\t\t\tteam"<<num<<" vs. team"<<num1;
		 if(num==2)
		 cout<<"\t\t\tteam"<<num<<" vs. team"<<num1;
		 if(num==3)
		 cout<<"\t\t\tteam"<<num<<" vs. team"<<num1;
		 if(num==4)
		 cout<<"\t\t\tteam"<<num<<" vs. team"<<num1;
		 if(num==5)
		 cout<<"\t\t\tteam"<<num<<" vs. team"<<num1;
		 if(num==6)
		 cout<<"\t\t\tteam"<<num<<" vs. team"<<num1;
		 if(num==7)
		 cout<<"\t\t\tteam"<<num<<" vs. team"<<num1;
		 if(num==8)
		 cout<<"\t\t\tteam"<<num<<" vs. team"<<num1;
		 
		 if(num==num1)
		  cout<<"\t\tPaired with self";
	}
	getch();
}

void pro()
{
	header();
	file.open("record.dat",ios::in|ios::binary);
	cout<<"\n\t\t\t|||||||||||||||||||||| Entered record(s) ||||||||||||||||||||||||";
	file.read((char*)&d,sizeof(d));
	while(file)
	{
		d.show_record();
		file.read((char*)&d,sizeof(d));
	}file.close();
	getch();
}

int minn;
char a[100];
nameiple nmo;

void insert2()
{
	int i,no;
	file.open("record4.dat",ios::out|ios::in|ios::app|ios::binary);
	cout<<"\n           ::Entry of new record(s)::          ";
	cout<<"\nHow many record(s) you want to enter : ";
	cin>>no;
	for(i=1;i<=no;i++)
	{
		gets(nmo.nameipl);
		file.write((char*)&d,sizeof(nmo));
	}file.close();
}

void displayipl()
{
	file.open("record4.dat",ios::in|ios::binary);
	cout<<"\n|||||||||||||||||||||| Entered record(s) ||||||||||||||||||||||||";
	file.read((char*)&d,sizeof(nmo));
	while(file)
	{
		nmo.show_names();
		file.read((char*)&d,sizeof(nmo));
	}file.close();
}

void todayteam()
{
	cout<<"\n Enter the Players name";
	
	insert2();
	displayipl();
		
}



void match()
{
	ining_start();
	second_innings();
	
}
 
void iplstart()
{
	int jkl=0;
	chart();
	for(jkl=0;jkl<18;jkl++)          //TOTAL NUMBER OF MATCHES ARE 17
	{
		match();
	}
}


void graph()
{
		cout<<"\n\n\n\t\t\t\t Indian Premier League Organiser";
		cout<<"\n\n\t\t  ---------------------------------------------------------------------";
		cout<<"\n\t\t\t1. Player Profile";
		cout<<"\n\t\t\t2. About Us";
		cout<<"\n\t\t\t3. Update Players Profile";
		cout<<"\n\t\t\t4. Lets Start The IPL";
		cout<<"\n\t\t\t5. Exit";
		cin>>minn;
		if(minn==1)
			pro();
		if(minn==2)
			about();
		if(minn==3)
			player_menu();
		if(minn==4)
			iplstart();
		if(minn==5)
			exit(0);	
		
		
}

int func()
{
	graph();
}

int main()
{
	func();
	
	return 0;
}

