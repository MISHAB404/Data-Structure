#include<stdio.h>
#include<stdlib.h>
//Dijkstras single source shortest path algorithm
#define INFINITY 9999
#define SIZE 10
int main()
{
int cost[SIZE][SIZE],distance[SIZE],pred[SIZE];
int visited[SIZE],count,mindist,nextnode,i,j;
int startnode,n;
//pred[] stores the predecessor of each node
//count gives the number of nodes seen so far
printf("Enter no. of vertices:");
scanf("%d",&n);
printf("\nEnter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{ scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=INFINITY;
}
printf("\nEnter the starting node:");
scanf("%d",&startnode);
//initialize pred[],distance[] and visited[]
for(i=0;i<n;i++)
{
distance[i]=cost[startnode][i];
pred[i]=startnode;
visited[i]=0;
}
distance[startnode]=0;
visited[startnode]=1;
count=1;
while(count<n-1)
{
 mindist=INFINITY;
//nextnode gives the node at minimum distance
for(i=0;i<n;i++)
if(distance[i]<mindist&&!visited[i])
{
mindist=distance[i];
nextnode=i;
}	
//check if a better path exists through nextnode			
visited[nextnode]=1;
for(i=0;i<n;i++)
if(!visited[i])
if(mindist+cost[nextnode][i]<distance[i])
{ distance[i]=mindist+cost[nextnode][i];
pred[i]=nextnode;
}
count++;
}
 
//print the path and distance of each node
for(i=0;i<n;i++)
if(i!=startnode)
{ printf("\nDistance of node%d=%d",i,distance[i]);
printf("\nPath=%d",i);
j=i;
do
{
 j=pred[j];
printf("<-%d",j);
}
while(j!=startnode);
}
}
