#include <iostream>
using namespace std;
struct node{
int ele;
node *pre;
node *next;
};
node *start=NULL;
node *tail=NULL;
void insert_beg(int data)
{
   node *temp=new node;
  temp->ele=data;
   if(start==NULL)
   {
     start=tail=temp;
     temp->pre=temp->next=NULL;
   }
  else{
    start->pre=temp;
    temp->next=start;
    start=temp;
  }
}
// insert from end
void insert_end(int data)
{
   node *temp=new node;
  temp->ele=data;
   if(start==NULL)
   {
     start=tail=temp;
     temp->pre=temp->next=NULL;
   }
     else{
       tail->next=temp;
       temp->pre=tail;
       temp->next=NULL;
       tail=temp;
     }
}
void insert_mid(int data,int pos)
{
  if(start==NULL && pos>1)
  {
    cout<<"you can only insert at position-1 because linked is empty"<<endl;
    return;
  } 
     if(pos==1)
     {
       insert_beg(data);
       return;
     }
  int count=1;
  node *t=start;
  while(count!=pos-1)
    {
      if(t->next==NULL)
        break;
      count++;
      t=t->next;
    }
  if(t->next==NULL && count==pos-1)
  {
    insert_end(data);
      return;
  }
  if(count==pos-1)
  {
      node *temp=new node;
    temp->ele=data;
       temp->pre=t;
       temp->next=t->next;
       t->next->pre=temp;
        t->next=temp;
  }
  else{
     cout<<"Out of range"<<endl;
  }
}
//delete from begning
void remove_beg()
{
  if(start==NULL)
  {
     cout<<"linked list is empty"<<endl;
  }
  else{
      node *temp;
    temp=start;
    start=start->next;
    start->pre=NULL;
    delete(temp);
  }
}
// delete from end
void remove_end()
{
  if(start==NULL)
  {
     cout<<"linked list is empty"<<endl;
  }
  else{
      node *temp;
    temp=tail;
    tail=tail->pre;
    tail->next=NULL;
    delete(temp);
  }
}
// remove from middle
void remove_mid(int pos)
{
  if(start==NULL && pos>1)
  {
    cout<<"linked list is empty"<<endl;
    return;
  }
  if(pos==1)
  {
    remove_beg();
    return;
  }
  node *temp=start;
  int count=1;
  while(count!=pos-1)
    {
      if(temp->next==NULL)
        break;
      count++;
      temp=temp->next;
    }
  if(temp->next==NULL && count==pos-1)
  {
    remove_end();
    return;
  } 
  if(count==pos-1){
  temp=temp->next;
  temp->pre->next=temp->next;
   temp->next->pre=temp->pre;
    delete(temp);
  }
  else{
    cout<<"out of range"<<endl;
  }
}
void display()
{
  node *temp;
  temp=start;
  while(temp!=NULL)
    {
      cout<<temp->ele<<" ,";
      temp=temp->next;
    }
  cout<<endl;
}
int main()
{
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
