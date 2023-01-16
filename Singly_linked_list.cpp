#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
  int ele;
  node *next;
};
 node *start=NULL;
node *tail=NULL;

//insert from beg
void insert_beg(int data)
{
  node *temp=new node;
  temp->ele=data;
  if(start==NULL){
    start=temp;
    tail=start;
    temp->next=NULL;
  }else{
    temp->next=start;
    start=temp;
    
  }
}

// insert from end
void insert_end(int data)
{
  node *temp=new node;
  temp->ele=data;
  if(start==NULL){
    start=temp;
    tail=temp;
    temp->next=NULL;
  }else{
    tail->next=temp;
    tail=tail->next;
    temp->next=NULL;
  }
}


// insert from middle
void insert_mid(int data,int pos)
{
  if(start==NULL && pos>1)
  {
    cout<<"you can only insert at position-1 because linked list empty"<<endl;
    return;
  }  
  if(pos==1)
  {
    insert_beg(data);
    return;
    }
  int count=1;
   node *t=start;
    while(count!=pos-1){
      if(t->next==NULL)
        break;
      t=t->next;
      count++;
    }
  if(t->next==NULL && count==pos-1){
    insert_end(data);
    return;
  }
   if(count==pos-1){
    node *temp=new node;
    temp->ele=data;
    temp->next=t->next;
    t->next=temp;
    }else{
     cout<<"position is outof range"<<endl;
    }
}

//delete from beg
void remove_beg(){
  if(start==NULL)
  {
    cout<<"list is empty"<<endl;
  }
  else
  {
    node *temp=start;
    start=start->next;
    delete(temp);
  } 
}
//delete for end
void remove_end(){
  if(start==NULL)
  {
    cout<<"list is empty"<<endl;
  }
    else
  {
    node *temp=start;
    while(temp->next!=tail)
      { 
        temp=temp->next;
      } 
    cout<<"Delete element="<<tail->ele<<endl;
    tail=temp;
     temp=temp->next;
    tail->next=NULL;
     delete(temp);
}
}

//Remove from middle
void remove_mid(int pos)
{
    if(pos==1)
    {
      remove_beg();
      return;
    }
  int count=1;
  node *t=start;
   while(count!=pos-1) 
     {
       if(t->next==NULL)
         break;
       t=t->next;
         count++;
     }  
  if(t->next==NULL && count==pos-1)
  {
    remove_end();
    return;
  }
 if(count==pos-1)
 {
    node *t2=t->next;
   t->next=t2->next;
   delete(t2);
  }
  }
// display element
void display()
{
  node *temp=start;
  while(temp!=NULL){
    cout<<temp->ele<<" ,";
    temp=temp->next;
  }
  cout<<endl;
}
int main(){
  
   int n;
  int pos;
  while(true){
      
      cout<<"1: insert_beg"<<endl;
      cout<<"2 :insert_end"<<endl;
      cout<<"3 :insert_middle"<<endl;
      cout<<"4 :Delete_beg"<<endl;
      cout<<"5 :Delete_end"<<endl;
    cout<<"6:Delete_middle"<<endl;
    cout<<"7:Display"<<endl;
       int choice;
      cout<<"enter choice"<<endl;
      cin>>choice;
      switch(choice){
        case 1:
          cout<<"enter num :";
          cin>>n;
          insert_beg(n);
          break;  
        case 2:
          cout<<"enter num :";
          cin>>n;
          insert_end(n);
          break; 
        case 3:
          cout<<"enter num & position";
          cin>>n>>pos;
          insert_mid(n,pos);
          break; 
        case 4:
           remove_beg();
        break;
        case 5:
           remove_end();
        break;
        case 6:
          cout<<"Enter Position:"<<endl;
          cin>>pos;
           remove_mid(pos);
        break;
        case 7:
        display();
        break;
        default:
        exit(1);
        
      }
    }
}
