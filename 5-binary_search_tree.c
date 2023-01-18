#include<stdio.h>
#include<stdlib.h>
#define MAX 50
 
struct node
{
struct node *lchild;
int info;
struct node *rchild;
}*tmp,*par,*ptr;
 
 
struct node *root=NULL;
 
int main( )
{
struct node *insert(struct node *root, int ikey );
void inorder(struct node *);
void delete(int);
struct node *search(struct node *,int);
 
struct node *ptr;
int choice,k;
 
while(1)
{
printf("\n");
printf("1.Insert\n");
printf("2.Display\n");
printf("3.Delete\n");
printf("4.Search\n");
printf("5.Quit\n");
printf("\nEnter your choice : ");
scanf("%d",&choice);
 
switch(choice)
{
 
case 1:
printf("\nEnter the key to be inserted : ");
scanf("%d",&k);
root = insert(root, k);
break;
 
case 2:
printf("\n");
inorder(root);
printf("\n");
break;
 
case 3:
printf("\n");
printf("Enter a value to delete:");
scanf("%d",&k);
delete(k);
break;
 
case 4:
printf("\n");
printf("Enter the value to search:");
scanf("%d",&k);
search(root,k);
break;
 
case 5:
exit(1);
 
default:
printf("\nWrong choice\n");
                }//end of switch
        }//End of while
}
 
//function for inserting a value to tree
struct node *insert(struct node *root, int ikey)
{
       
 
ptr = root;
par = NULL;
 
while( ptr!=NULL)
{
par = ptr;
if(ikey < ptr->info)
ptr = ptr->lchild;
else if( ikey > ptr->info )
ptr = ptr->rchild;
else
{
printf("\nDuplicate key");
return root;
}
}
tmp=(struct node *)malloc(sizeof(struct node));
tmp->info=ikey;
tmp->lchild=NULL;
tmp->rchild=NULL;
if(par==NULL)
root=tmp;
else if( ikey < par->info )
par->lchild=tmp;
else
par->rchild=tmp;
return root;
}//end of insert
 
//inorder
void inorder(struct node *t)
{
if (t != (struct node *)0)
{
inorder(t->lchild);
printf(" %d ", t->info);
inorder(t->rchild);        
}
}
 
 
//fuction for deleting a data from bst
void delete(int item)
{
struct node *t1,*t2,*t3,*suepar,*sue;
t1=root;
while(t1!=NULL && t1->info !=item)//searching item for delete
{
t2=t1;
if(item>t1->info)
t1=t1->rchild;
else
t1=t1->lchild;
}
 
 
if(t1==NULL) //null tree
printf("item not found...\n");
else
{
if(t1->rchild==NULL && t1->lchild==NULL) //leaf node
{
if(t1!=root)
{
if(t2->info>item)
t2->lchild=NULL;
else
t2->rchild=NULL;
}
else
root=NULL;
}
else if(t1->lchild==NULL || t1->rchild == NULL) //one child
{
if(t1!=root)
{
if(item>t2->info)
t2->rchild=t1->lchild==NULL?t1->rchild:t1->lchild;
else
t2->lchild=t1->lchild==NULL?t1->rchild:t1->lchild;
}
else   //two child
{
if(root->rchild!=NULL)
root=root->rchild;
else
root=root->lchild;
}
}
else
{
suepar=t1;
sue=t1->rchild;
while(sue->lchild!=NULL)
{
suepar=sue;
sue=sue->lchild;
}
t1->info=sue->info;
if(sue->info<suepar->info)
suepar->lchild=sue->rchild;
else
suepar->rchild=sue->rchild;
t1=sue;
}
free(t1);
printf("item deleted....\n");
}
}
//function for search
struct node *search(struct node *root,int a)
{
if(root==NULL) //case of empty tree
printf("Item not found \n");
else if(root->info==a)
{
printf("Item found\n");
}
else
{
if(a>root->info)           //case of right subtree
return search(root->rchild,a);
else
return search(root->lchild,a);  //case of left subtree
}
}
