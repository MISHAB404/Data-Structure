/// CIRCULAR QUEUE IMPLIMENTATION IN C
#include<stdio.h>
#include<stdlib.h>

#define SIZE 100


//-----------------------FUCTIONS------------------------------//

// function for insertion
int q[SIZE];
int rear = 0, front = 0; 

void insertq(int item)
{
    int r1 = rear;
    r1=(r1+1)%SIZE;

  if(r1==front)
    printf("\n Queue is full");
  else 
    {
    rear=r1;
    q[rear]=item;
    }
}

//--------------function for searching-----------------//
int searchq(int item)
{
   int t;
   t=front;
   if(front!=rear) // Queue is not empty
    {
     t=(t+1) % SIZE;
     while(q[t]!=item && t!=rear)
       {
        t=(t+1)%SIZE;
       }
     if(q[t]==item)
      return t+1;
     else 
      return 0;
    }
   else
    return 0;
}

//---------------fuction for deleting---------------//
int deleteq()
{
  if(rear==front)
   printf(" \n queue is empty");
  else
   front=(front+1)%SIZE;
  return q[front];
}

//-----------------Main Function-------------------//
void main()
{
  int item,opt,ans;
   do {
      printf("\n 1. Insert \n 2. Search \n 3. Delete \n 4. Exit \n");
      printf("\n ---- Enter Option : ");
      scanf("%d", &opt);

   switch(opt) {
      case 1 : printf("\n -- Enter The Data : ");
	       scanf("%d", &item);
	       insertq(item);
	       break;

      case 2 : printf("\n Enter The Number to Search : ");
 	       scanf("%d", &item);
	       ans = searchq(item);
	       if(ans == 0)
	        printf("\n (Item Not Found!)");
	       else
	        printf("\n Item Founded At %d Postion \n", ans);
	       break;

      case 3 : item = deleteq(item);
	       if(item == 1);
	        printf("\n Deleted : %d", item);
	       break;
      case 4 : exit(0);
               }
     }
 while(1);
}





