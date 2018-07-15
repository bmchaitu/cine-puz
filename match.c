#include<stdio.h>
#include<malloc.h>
struct node{
int num;
struct node *prev,*next;
};
struct node *start=NULL;
struct node *create(struct node *start)

{ 
  int data;
  struct node *temp,*newnode;

 data=1; 
  while(data<101)
 {

    if(start==NULL)
  {
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->num=data;
    newnode->next=newnode;
    newnode->prev=newnode;
    temp=newnode;
    start=newnode;
  }
  else
{
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->num=data;
  temp->next=newnode;
  newnode->prev=temp;
  start->prev=newnode;
  newnode->next=start;
  temp=newnode;
}
 data++;
 }
 return start;
}
struct node *display(struct node *start)

{ 
  struct node *ptr,*ptr1,*ptr2; 
 ptr=start;
 while(ptr->next!=ptr)
 {
  ptr1=ptr->next;
  ptr2=ptr1->next;
  ptr2->prev=ptr;
  ptr->next=ptr2;
  free(ptr1);
  ptr=ptr->next;

 }
 printf("the number:%d",ptr->num);
return start;
}

void main()
{
 
 
 start=create(start);
 start=display(start);

}
  
   
