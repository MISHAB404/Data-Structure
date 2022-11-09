#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

//function for push operation
struct node *sp = (struct node *)0;
void push(int item)
{
  struct node *t;
  t=(struct node*)malloc(sizeof(struct node));
  t->data=item;
  t->next=sp;
  sp=t;
  return;
}

// function for pop operation
int pop(int *status)
{
  struct node * t;
  int item;
   if(sp==(struct node *)0)
     {
     * status = 0;
     printf("----Stack is empty!----");
     }
   else 
    {
     item = sp->data;
     t=sp;
     sp=sp->next;
     free(t);
     * status = 1;
     return item;
    }
}

// function for searching operaton
int search(int item)
{
  struct node * t = sp;
   while(t!=(struct node *)0)
    {
     if(t->data==item)
      return 1;
     t=t->next;
    } 
   return 0;
}

// Main Function
void main()
{
  int item, opt, ans, status;
   do 
    {
     printf("\n 1.Push \n 2.Pop \n 3.Search \n 4.Exit \n");
     printf("\n Enter Option : ");
     scanf("%d", &opt);

   switch(opt) 
     {
      case 1 : printf("\n --Enter Data : ");
	       scanf("%d", &item);
               push(item);
	       break;	
      case 2 : item = pop(&status);
               if(status!=0)
	       printf("\n ------Deleted %d \n", item);
	       break;
      case 3 : printf("\n Enter Number To Search : ");
               scanf("%d", &item);
	       ans = search(item);
                if(ans==0)
                  printf("\n ----Item Not Found---- \n");
                else 
                  printf("\n ---Item Founded At %d Postion---\n", ans);
               break;
      case 4 : exit(0);
     }
    }
while(1);
}



