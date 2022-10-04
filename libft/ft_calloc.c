#include <stdlib.h>

void *ft_calloc(size_t nmemb, size_t size)
{
    size_t  *arr;
    int     i;

    i = 0;
    arr = (size_t *)malloc(sizeof(size));
    while (i < size)
    {
        arr[i] = '\0';
        i++;
    }
}

#include <stdio.h>
int main () {
   int i, n;
   int *a;

   printf("Number of elements to be entered:");
   scanf("%d",&n);

//    a = (int*)calloc(n, sizeof(int));
   a = (int*)ft_calloc(n, sizeof(int));
   printf("Enter %d numbers:\n",n);
   for( i=0 ; i < n ; i++ ) {
      scanf("%d",&a[i]);
   }

   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ ) {
      printf("%d ",a[i]);
   }
   free( a );
   
   return(0);
}