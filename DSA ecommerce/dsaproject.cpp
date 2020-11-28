// ********************************   ADVERTISING AGENCY   ********************************************
#include <iostream>
#include<sstream>
#include<process.h>
#include <fstream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

struct node
{
	string brand, price, category,item,discount;
	node * link;
}*start;
void display();

node * create_node(string brand, string item, string category, string price,string discount)
{
    struct node *temp;
    temp = new(struct node);
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->brand = brand;
        temp->item=item;
        temp->category=category;
        temp->price=price;
        temp->discount=discount;
        temp->link = NULL;
        return temp;
    }
}

void insert_last(string brand, string item, string category, string price,string discount)
{

    struct node *temp, *p;
    temp = create_node(brand,item, category, price,discount);
    if (start == NULL)
    {
        start = temp;
        start->link = NULL;
    }
    else
    {
        p = start;
        start = temp;
        start->link = p;
    }

}


void makeList(char * Filename)
{
	ifstream f;
	f.open(Filename);
	while(!f.eof())
	{
		string brand, price, category,item,discount;
		struct node temp;
		string line="t";
		getline(f,line);
		brand=line;
		getline(f,line);
		item=line;
		getline(f,line);
		category=line;
		getline(f,line);
		price=line;
		getline(f,line);
		discount=line;
		getline(f,line);
		if(line=="*")
		{
			insert_last(brand,item, category, price,discount);
		}
	}
}

void sortByPriceLToH()
{

 struct node *a = NULL;
 struct node *b = NULL;
 struct node *c = NULL;
 struct node *e = NULL;
 struct node *tmp = NULL;

 while(e != start->link) {
 c = a = start;
 b = a->link;
  while(a != e) {
  	//aprice
  	int x=0,y=0;
  	for(int i=0;a->price[i]!='\0';i++)
	{
		x=x*10+(int)a->price[i]-48;
	}
	for(int j=0;b->price[j]!='\0';j++)
	{
		y=y*10+(int)b->price[j]-48;
	}
   if(x > y) {
    if(a == start) {
     tmp = b -> link;
     b->link = a;
     a->link = tmp;
     start = b;
     c = b;
    } else {
     tmp = b->link;
     b->link = a;
     a->link = tmp;
     c->link = b;
     c = b;
    }
   } else {
    c = a;
    a = a->link;
   }
   b = a->link;
   if(b == e)
    e = a;
  }
 }
}

void sortByPriceHToL()
{

   struct node *a = NULL;
 struct node *b = NULL;
 struct node *c = NULL;
 struct node *e = NULL;
 struct node *tmp = NULL;

 while(e != start->link) {
 c = a = start;
 b = a->link;
  while(a != e) {
  	//aprice
  	int x=0,y=0;
  	for(int i=0;a->price[i]!='\0';i++)
	{
		x=x*10+(int)a->price[i]-48;
	}
	//bprice
	for(int j=0;b->price[j]!='\0';j++)
	{
		y=y*10+(int)b->price[j]-48;
	}
   if(x < y) {
    if(a == start) {
     tmp = b -> link;
     b->link = a;
     a->link = tmp;
     start = b;
     c = b;
    } else {
     tmp = b->link;
     b->link = a;
     a->link = tmp;
     c->link = b;
     c = b;
    }
   } else {
    c = a;
    a = a->link;
   }
   b = a->link;
   if(b == e)
    e = a;
  }
 }


}

void sortByDiscount()
{

   struct node *a = NULL;
 struct node *b = NULL;
 struct node *c = NULL;
 struct node *e = NULL;
 struct node *tmp = NULL;


 while(e != start->link) {
 c = a = start;
 b = a->link;
  while(a != e) {
  	//adiscount
  	int x=0,y=0;
  	for(int i=0;a->discount[i]!='\0';i++)
	{
		x=x*10+(int)a->discount[i]-48;
	}
	//bdiscount
	for(int j=0;b->discount[j]!='\0';j++)
	{
		y=y*10+(int)b->discount[j]-48;
	}
   if(x < y) {
    if(a == start) {
     tmp = b -> link;
     b->link = a;
     a->link = tmp;
     start = b;
     c = b;
    } else {
     tmp = b->link;
     b->link = a;
     a->link = tmp;
     c->link = b;
     c = b;
    }
   } else {
    c = a;
    a = a->link;
   }
   b = a->link;
   if(b == e)
    e = a;
  }
 }
}


void sort(char * FileName)
{
	makeList(FileName);
	cout<<"\n\n\tChose the category for sorting...\n\t\t1.Price(low to high)\n\t\t2.Price(high to low)\n\t\t3.Discount";
	int i;
	cin>>i;
	switch(i)
	{
		case 1:
			sortByPriceLToH();
			break;

		case 2:
			sortByPriceHToL();
			break;

		case 3:
			sortByDiscount();
			break;

		default:
			cout<<"\n\t\twrong choice";
			break;
	}


}

void display()
{
	system("cls");
	struct node *temp;
	char ch='y';
	int counter=0;
    if (start == NULL)
    {
        cout<<"\tThe file is Empty"<<endl;
        return;
    }
    temp = start;
    cout<<"\n\n";
    while (temp != NULL && ch=='y')
    {
    	counter++;
    	if (temp->brand==""){
		}
        else
		cout<<"\n\tbrand:"<<temp->brand<<"\n";
		cout<<"\titem:"<<temp->item<<"\n";
		cout<<"\tcategory:"<<temp->category<<"\n";
		cout<<"\tprice:"<<temp->price<<"\n";
		cout<<"\tdiscount:"<<temp->discount<<"\n";
		cout<<"\n\t* * * * * * * * * * * * * * * * * * * * * "<<endl<<endl;
        temp = temp->link;
        if(counter==2)
        {
        	counter=0;
        	cout<<"\n\tWould you like to see more products...y/n";
        	cin>>ch;
		}
    }
	if(temp==NULL)
    cout<<"\n\t\t\tno more products..."<<endl;
    system("cls");
}

class UserDetails
{
    string username,password;
public:
    string retUser()
    {
        return username;
    }
    string retPass()
    {
        return password;
    }
    void getUserName()
    {
        fflush(stdin);
        cout<<"\n\tEnter Username:";
        getline(cin,username);
    }
    void getPassword()
    {
        fflush(stdin);
        cout<<"\n\tEnter Password:";
        getline(cin,password);
    }
};

int loginFunction()
{
    UserDetails u;
    char regUser;
    cout<<"\n\n\t\tWELCOME\n";
    cout<<"\n\t\tLOGIN TO GET ACCESS TO THE BEST DEALS...\n";
    cout<<"\n\t\tAre you a registered user?          (y/n)   ";
    cin>>regUser;
    system("cls");
    if(regUser=='y' || regUser=='Y')
    {
        string usr,ptr;
        int found =0;
        ifstream filin;
        filin.open("LoginDetails",ios::in);  // in - read mode
        u.getUserName();
        u.getPassword();
        string STRING="jdjj", STRING2="df";
        while(!filin.eof()) // To get you all the lines.
        {
            getline(filin,STRING); // Saves the line in STRING.
            getline(filin,STRING2);
            if((STRING.compare(u.retUser())==0) && (STRING2.compare(u.retPass())==0))
            {
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n\n\n    \t\t    YOU HAVE SUCCESSFULLY LOGGED IN!\n";
                found=1;
                break;
            }
        }
        if(found==0)
        {
            cout<<"\n\tRECORD NOT FOUND....";
            return -1;
        }
        filin.close();
        return 0;
    }
    else
    {
        ofstream filout;
        char ptr[20];
        filout.open("LoginDetails", ios::out | ios::app);
        u.getUserName();
        u.getPassword();
        filout<<u.retUser();
        filout<<endl<<u.retPass();
        filout<<endl<<'*'<<endl;
        filout.close();
        return 1;
    }
}
void ReadFile(char * FileName)
{
    fstream fin;
    char ch='y';
    string str;
    int counter=0;
    fin.open(FileName,ios::in);
        while((!fin.eof()) && (ch=='y' || ch=='Y'))
        {
            h:
            while(counter<12)
            {
                counter++;
            getline(fin,str);
            if(str.compare("*")==0)
                cout<<endl<<"\t* * * * * * * * * * * * * * * * * * * * *"<<endl<<endl;
            else
                cout<<"\t"<<str<<endl;
            }
            cout<<"\n\tShow More??............(y/n)";
            cin>>ch;
            if(ch=='y' || ch=='Y')
               {
                   counter=0;
                   goto h;
               }
            else
            {
            	char c;
            	cout<<"\n\tWould you like to sort the products??";
            	cin>>c;

            	if(c=='y' || c=='Y')
            	{
            		system("cls");
            		sort(FileName);
            		display();
				}
			}
        }
        system("cls");
        fin.close();
}
void TakeChoice()
{
    a:
    system("cls");
    int counter=0;
    char ch='y';
    fstream fin;
    int choice;
    system("cls");
    cout<<"\n\n\tNOW ENTER YOUR INTERESTS SO WE CAN FILTER THE BEST DEALS FOR YOU...";
    cout<<endl<<endl<<"\n\t1.ELECTRONICS\n\t2.BOOKS AND MEDIA\n\t3.SPORTS\n\t4.AUTO\n\t5.CLOTHING AND ACCSESORIES\n\t6.EXIT"<<endl;
    cin>>choice;
    system("cls");
    string str;
    char t;
    switch(choice)
    {
    case 1:

        ReadFile("Electronics");
        break;

    case 2:

        ReadFile("booksAndMedia");
        break;

    case 3:

        ReadFile("sports");
        break;

    case 4:

        ReadFile("auto");
        break;

    case 5:

        ReadFile("clothesAccessories");
        break;

    case 6:
    	system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   EXITING.....\n\n\n\n\n\n\n\n\n\n\n";
    	exit(0);
        break;

    default:
        cout<<"\n\tWrong Choice...Enter Again\n";
        getch();
        goto a;
        break;
    }
}

int main()
{
    int t;
    char c;
    X:
    t=loginFunction();
    getch();
    if(t==1)
    	{
    		system("cls");
        	goto X;
        }
    else if (t==-1)
        return 0;
    Y:
    TakeChoice();
    cout<<"\n\tWOULD YOU LIKE TO CONTINUE LOOKING AT THE DEALS....\n";
    cin>>c;
    if(c=='y' || c=='Y')
        goto Y;
        else
		{
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tEXITING.....\n\n\n\n\n\n\n\n\n\n\n";
		}
}
