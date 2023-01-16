#include <iostream>
using namespace std;
struct node{
     int ele;
     node *next;
     node *pre;
};
node *start=NULL;
//insertion from begining
void insert_beg(int data)
{
  node *temp=new node;
  temp->ele=data;
  if(start==NULL)
  {
    start=temp;
    temp->pre=temp->next=temp;
  }
  else{
    start->pre->next=temp;
    temp->pre=start->pre;
    temp->next=start;
    start->pre=temp;
     start=temp;
  }
  }
//insertion from end
void insert_end(int data)
{
  node *temp=new node;
  temp->ele=data;
  if(start==NULL)
  {
    start=temp;
    temp->pre=temp->next=temp;
  }
  else{
    temp->pre=start->pre;
    start->pre->next=temp;
    temp->next=start;
    start->pre=temp;
  }
}
//insertion from Middle
void insert_mid(int pos,int data)
{
   node *temp=new node;
  temp->ele=data;
  if(start==NULL && pos>2)
  {
    cout<<"You can only insert possition-1 because linked is empty"<<endl;
    return;
  }
  if(pos==1)
  {
    insert_beg(data);
    return;
  }
  
   node *t=start;
  int count=1;
  while(count!=pos-1)
  {
       if(t==start->pre)
         break;
      
       count++;
       t=t->next;
  }
  if(t->next==start->pre && count==pos-1)
  {
    insert_end(data);
    return;
  }
  if(count==pos-1)
  {
    t->next->pre=temp;
    temp->next=t->next;
    temp->pre=t;
    t->next=temp;
    } 
  else{
    cout<<"position not vaild"<<endl;
  }
}
//Remove from begining
void remove_beg()
{
  node *temp=start;
  if(start==NULL)
  {
    cout<<"Linked list is empty"<<endl;
  }
  else{
      start->next->pre=start->pre;
    start->pre->next=start->next;
    start=start->next;
     cout<<"Delete element is:"<<temp->ele<<endl;
    delete(temp);
  }
}
//Remove from End
void remove_end()
{
  node *temp=start;
  if(start==NULL)
  {
    cout<<"Linked list is empty"<<endl;
    return;
  }
  else{
    temp=start->pre;
    start->pre=temp->pre;
    temp->pre->next=start;
    cout<<"Delete element is:"<<temp->ele<<endl;
    delete(temp);
  }
}
//Remove from Middle
void remove_mid(int pos)
{
  if(start==NULL && pos>1)
  {
    cout<<"Linked list is empty"<<endl;
    return;
  }
  if(pos==1)
  {
    remove_beg();
    return;
  }
   node *t=start;
  int count=1;
  while(count!=pos)
  {
       if(t==start->pre)
         break;
      
       count++;
       t=t->next;
  }
  if(t->next==start->pre && count==pos-1)
  {
    remove_end();
    return;
  }
  if(count==pos)
  {
    t->pre->next=t->next;
    t->next->pre=t->pre;
    cout<<"delete element is:"<<t->ele<<endl;
    delete(t); 
  }
  else{
    cout<<"Position Out of range"<<endl;
  }
}
//Display
 void display()
  {
    node *temp=start;
    if(start==NULL)
    {
      cout<<"Linked list is empty"<<endl;
      return;
    }
    while(temp->next!=start)
      {
        cout<<temp->ele<<",";
        temp=temp->next;
      }
    cout<<temp->ele;
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
          cout<<"enter  position & num ";
          cin>>pos>>n;
          insert_mid(pos,n);
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
