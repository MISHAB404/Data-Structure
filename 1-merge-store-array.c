
// program for store 2 sorted arrays and merges them
// --------------------------------------------------------------------

#include <stdio.h>
void main()
{ // opening of main

// variable declearation 
int arr1[20], // array 1 and its value 20 given from user 
    arr2[20], // array 2 and its value 20 given from user
    arr3[40], // merging array 1 and array 2 (arr[20] + arr[20] = arr[40])
    m,        // 'm' for store first array element from user, 
    n;        // 'n' for store second array element from user 

void read_array(int[], int); // read array decleration
void print_array(int[], int); // print array decleration
void merge(int[], int[], int[], int, int); // merge 2 array decleration


// array 1 from user

printf("Enter number of elements  in first array (1 to 20): "); // number of first array elements(from user)
 scanf("%d", &m); // and store it to m variable 
printf("Enter some numbers in non-decreasing order: "); // enter some numbers to store to first array (from user)
 read_array(arr1, m); // function calling for first array m & arr1[20]

// array 2 from user

printf("Enter number of elements  in second array (1 to 20): "); // number of second array elements(from user)
 scanf("%d", &n); // and store it to n variable 
printf("Enter some numbers in non-decreasing order: "); // enter some numbers to store to second array (from user)
 read_array(arr2, n); // function calling for first array n & arr2[20]

merge(arr1, arr2, arr3, m, n); // fuction calling for merge those arrays
 printf("merged array is : "); // printing merged array
 print_array(arr3, m+n); // printing merged array

} // closing of main

//-----------------------------------------Fuction-------------------------------------------------------------

// fuction for reading given array from user //

void read_array(int a[], int n)
{
 int i;	
  for(i=0;i<n;++i)
    scanf("%d",&a[i]);
}

// fuction for printing output of array //

void print_array(int arr[], int n)
{
int i;
  for(i=0;i<n;i++)
    printf("%d ,", arr[i]);
  return;
}

// fuction for merging the given 2 arrays //

void merge(int a[], int b[], int c[], int m, int n)
{
 int i,j,k;
  i=j=k=0;
 while(i<m && j<n)
    if(a[i]<b[j]) 
    {
       c[k] = a[i];
       i=i+1;
       k=k+1;
    } 
    else 
    {
       c[k]=b[j];
       j=j+1;	
       k=k+1;       
    }
 while(i<m)
  c[k++] = a[i++];
 while(j<n)
  c[k++] = b[j++];

}







