#define size 10
#include<stdio.h>
#include<stdlib.h>

struct node
 {
  int data;
  struct node *left,*right;
 };
struct node * start=NULL;
void main() 
 {
  struct node* search(int);
  void delete(int); 
  void insert(int);
  int data,option;
  struct node *t;
  printf("-----------------------DOUBLY LINKED LIST-----------------------\n");
   do
    {
     printf("\n 1 --- Insert \n 2 --- Search \n 3 --- Delete \n 4 --- Exit \n");
     printf("\n Enter your option : ");
     scanf("%d",&option);
   switch(option)
    {
     case 1:printf("\n - Enter the data : ");
            scanf("%d",&data);
            insert(data);
            break;

     case 2:printf("\n - Enter the data to search : ");
            scanf("%d",&data);
            t=search(data);
             if(t==(struct node*)0)
               printf("\n ( !!!ITEM NOT FOUND!!! )\n");
             else
               printf("\n ( ITEM FOUND )\n");
            break;

     case 3:printf("\n - Enter the item to delete : ");
            scanf("%d",&data);
            delete(data);
            printf("\n ( %d is Deleted )",data);
            printf("\n");
            break;

     case 4:exit(1);
    } // this end of switch
   }
while(1);
 }

//function to insertion

void insert(int data)
 {
  struct node *t;
  t=(struct node*)malloc(sizeof(struct node));
  t->data=data;
   if(start==(struct node*)0)
     t->left=t->right=(struct node*)0;
   else
    {
     t->left=(struct node*)0;
     t->right=start;
     start->left=t;
    }
  start=t;
 }

//function to Search

struct node* search(int data)
 {
  struct node *t=start;
   while(t!=(struct node*)0 && t->data!=data)
    {
     t=t->right;
    }
  return t;
 }

//function to Deletion

void delete(int data)
 {
  struct node *t;
  t=search(data);
   if(t==0)
    printf("\n ( !!!NOT FOUND DATA!!! )\n");
   else
    {
     if(t==start) //case of first node
      {
        if(t->right==(struct node*)0)
        start=(struct node*)0; //one and only one node
     else
       {
        t->right->left=t->left; //remove 1st node ,more than one node
        start=t->right;
       }
      }

     else if(t->right==(struct node*)0) // case of last node
       {
        t->left->right=t->right;
       }
   else//case of inter node
    {
     t->left->right=t->right;
     t->right->left=t->left;
    }
free(t);
   }
 }

