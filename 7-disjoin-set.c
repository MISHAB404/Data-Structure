#include<stdio.h>
#include<stdlib.h>
//structure to repressent an object in linked  representation
 typedef struct {
   int value;
   struct rep *repptr;//pointer to header node of list
   struct node *next;
 } node;
//structure to represent header node of linked representation
 typedef struct {
   node *head;
   node *tail;
 } rep;
//structure to store key and object node pointer
 typedef struct {
   int key;
   node *obj_node_ptr;
   struct nodaddr *next;
 }
  nodaddr;
  nodaddr *ndr=0; //list to store keys and objects node pointer
//function to create a set for an object
 void makeset(int a) {
//create a object node pointer
   nodaddr *t=(nodaddr*)malloc(sizeof(nodaddr));
//create a new set
   rep *newset=(rep*)malloc(sizeof(rep));
   node *n=(node*)malloc(sizeof(node));
// fill the values
   n->value=a;
   n->repptr=newset;
   n->next=0;
//initialize head and tail
   newset->head=newset->tail=n;
//to store object node pointer and key
   t->obj_node_ptr=n;
   t->key=a;
   t->next=ndr;
   ndr=t;
 }
//function to return pointer of the representative(header node)of the set containing x
 rep *find(int x) {
   nodaddr *t=ndr;
    while(t->key!=x && t!=0)
     t=t->next;
    return t->obj_node_ptr->repptr;
 }
//to find union of  two set  corresponding to objects given
 void unionset(int key1,int key2) {
   rep *set1,*set2;
   node *t1;
   set1=find(key1);
   set2=find(key2);
     if(set1==set2)
      printf("\n %d and %d belong to same set\n",key1,key2);
     else {
//changing the header pointer of object of set2 to that of set1
      t1=set2->head;
       while(t1!=0) {
        t1->repptr=set1;
        t1=t1->next;
 }
  set1->tail->next=set2->head;//see the tail of set1 and tail of set2
  set1->tail=set2->tail;
  free(set2);
  }
 }
//function to display set
 void display(int a) {
   rep *r;
   node *t;
   r=find(a);
   t=r->head;
   printf("\nset members containing %d :",a);
    while(t!=0) {
     printf(",%d",t->value); 
     t=t->next;
   }
 }
// Main Function
 void main() {
   int data,data1,data2,opt;
   do {
    printf("\n 1.Makeset \n 2.Findset \n 3.Unionset \n 4.Display \n 5.Exit \n Enter your option :");
    scanf("%d",&opt);
     switch(opt) {
       case 1: printf("\n Enter the data :");
               scanf("%d",&data);
   	       makeset(data);
               break;

       case 2: printf("\nEnter set value:");
   	       scanf("%d",&data);
   	       printf("\n Reference of set containing %d is %x",data,find(data));
               break;
        
       case 3: printf("\nEnter the first data:");
   	       scanf("%d",&data1);
   	       printf("\nEnter the second data:");
   	       scanf("%d",&data2);
   	       unionset(data1,data2);
 	       break;
 
       case 4: printf("\nEnter the data :");
               scanf("%d",&data);
               display(data);
               break;
 
       case 5: exit(0);

   }
 }
 while(1);
}
