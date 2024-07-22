//computer science data structure and algorithm airline reservation system project
#include<iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
using namespace std;
struct cu{//cu= customers data
string name;
int age;
int id;
 cu* next;
};
cu* head=NULL;

void insert(string name,int age,int id)
{
    cu* temp=new cu;
temp->name=name;
temp->age=age;
temp->id=id;
temp->next=NULL;
if (head==NULL) 
{
    head=temp;
    
temp->next=NULL;
}else{
 temp->next=head;
   head=temp;
      
}
}
void remove(int id)//removing a customer from linked list
{
cu* temp= head;
 while (temp!=NULL && !(temp->id==id)){
    temp=temp->next;

 }
 if (temp==NULL){
    cout<<" NO SUCH DATA EXIST "<<endl;
 }else if (temp->id==id){
    cout<<"--------------------"<<endl;
	cout<<"Name: "<<temp->name<<endl;
    cout<<"Age: "<<temp->age<<endl;
    cout<<"ID: "<<temp->id<<endl;
    
    cout<<"--------------------"<<endl;
    cout<<"Do You Want to Remove This Data? "<<endl;
	cout<<"Enter (1) To Remove:"<<endl;
    cout<<"Enter (0) To keep on:"<<endl;
    int answer;
    cin>>answer;
    if(answer!=0 && answer!=1){
        cout<<"!!!!!Error!!!!!"<<endl;
    }
    if (answer==1){
        delete temp;
        if(temp==NULL){
            cout<<"****Delete Success****"<<endl;
        }
    }else if (answer==0){
cout<<endl;
    }
 }
}

void display()
{ HANDLE col;
col =  GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(col, 2);
    for(int j=0;j<15;j++){
        cout<<"-";
    }
cout<<endl;
}
void display2(){
    for(int j=0;j<15;j++){
        cout<<"*";
    }
cout<<endl;
}
void Search1(string name)//search from data using name
{
 cu* temp= head;
 while (temp!=NULL && !(temp->name==name)){
    temp=temp->next;

 }
 if (temp==NULL){
    cout<<" NO SUCH DATA "<<endl;
 }else if (temp->name==name){
    display();
    cout<<"Name: "<<temp->name<<endl;
    cout<<"Age: "<<temp->age<<endl;
    cout<<"ID: "<<temp->id<<endl;
    display();
 }
}


void Search(int id)//search from data using id
{
 cu* temp= head;
 while (temp!=NULL && !(temp->id==id)){
    temp=temp->next;

 }
 if (temp==NULL){
    cout<<" NO SUCH DATA "<<endl;
 }else if (temp->id==id){
    display();
    cout<<"Name: "<<temp->name<<endl;
    cout<<"Age: "<<temp->age<<endl;
    cout<<"ID: "<<temp->id<<endl;
    display();
 }
}

void sort()
{
	cu *key,*ptr;
	string nn;
	int l,k;
	key=head;
	while(key->next!=NULL)
	{ 
        ptr=key->next;
	while(ptr!=NULL){
		if(key->id > ptr->id){
			nn=key->name;
			l=key->age;
			k=key->id;
			
			key->name=ptr->name;
			key->age=ptr->age;
			key->id=ptr->id;
			
			ptr->name=nn;
			ptr->age=l;
           ptr->id=k;
		}
		ptr=ptr->next;
	}key=key->next;
}

}
void displaylinkedlist(){
	cu* temp=head;
	while(temp!=NULL){
		cout<<"Name:  "<<temp->name<<endl;
cout<<"Id:  "<<temp->id<<endl;
cout<<"Age:  "<<temp->age<<endl;
temp=temp->next;		
	}
	cout<<" ";
}
int main(){
  int f;
  int x;
string name;
   do{ j:
    
cout<<"   <<       <<====== Airline Resarvation System ======>>       >>"<<endl;
display();
cout<<"Enter (1) to Register a New Customer "<<endl;
cout<<"Enter (2) to Search a  Customer Information"<<endl;
cout<<"Enter (3) to Delete a Customer data"<<endl;
cout<<"Enter (4) to Sort  Customer data "<<endl;
cout<<"Enter (5) to check  Customer data is sorted: "<<endl;
display();

cin>>x;
switch(x){
    case 1:
    int age;
    int id;
   
     cout<<"Enter Your first name:   ";
    cin>>name; 
    cout<<"Enter Your age:   ";
    cin>>age;
    cout<<"Enter your id:   ";
    cin>>id;
    display2();
    cout<<"Is your name :"<<name<<endl;
	cout<<"  age: "<<age<<endl;
	cout<<" id: "<<id<<endl;
	 display2();
    cout<<"Enter (1) to Conform"<<endl;
    cout<<"Enter (2) to Change"<<endl;
   
    int y;
    cin>>y;
    if(y==1){
    insert(name ,age ,id);
    }else if(y==2){
    	system ("CLS");
        goto j;
    }else{
    cout <<"!!!!ERROR!!!!"<<endl;}
    system ("CLS");
    cout<<"^^^Register success^^^^^"<<endl;
    cout<<"Enter (2) To Exit:"<<endl;
    cout<<"Enter (0) To Continue"<<endl;
    break;
     case 2: system ("CLS");
	 cout<<"Enter (n) to search for customer using name:"<<endl;
     cout<<"Enter (i) to search for customer using id number:"<<endl;
     char z;
     cin>>z;
     system ("CLS");
     if(z=='n'){
        cout<<"Enter customer Name:   ";
        cin>>name;
        Search1(name);
        goto j;
     }else if (z=='i'){
     system ("CLS");
     cout <<"Enter your id to Search a Customer :";
     int d;
     cin>>d;
     Search(d);
     goto j;
     }else
     cout<<"!!invalid!!"<<endl;
    break;
    case 3://delete the customer
cout<<"Enter  id to remove customer data:";
int e;
cin>>e;
remove(e);
goto j;
    break;
  case 4:
  
  sort();
cout<<"<<<<<<<<<< sorted success >>>>>>>>>>>>"<<endl;
goto j;
    break;
case 5: 
	displaylinkedlist();
	break;
    default:cout<<"ERROR!!!!"<<endl;
    break;
   
}

    cin>>f;
    
}while(f!=2);
	system ("CLS");
    return 0;
}
//developed for c++ project 2nd year     
// Biniyam Girma