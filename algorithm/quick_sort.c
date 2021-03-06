//快速排序算法，递归实现
#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int p, int r);
void print_arr(int A[], int length);

static void swap(int A[], int i, int j)
{
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

void quick_sort(int A[], int p, int r)
{
    int q;
    if(p >= r)
    {
	return;
    }
    q = partition(A, p, r);
    quick_sort(A, p, q-1);
    quick_sort(A, q+1, r);
}

int partition(int A[], int p, int r)
{
    int x;
    int i,j;
    // x is the pivot
    x = A[r];
    i = p -1;
    for (j = p; j <= r-1; j++)
    {
	if (A[j] <= x)
	{
	    i++;
	    swap(A, i, j);
	}
    }
    // the A[i+1] >= x = A[r]
    swap(A, i+1, r);
    print_arr(A, r-p+1);
//    exit(EXIT_FAILURE);
    return i+1;
}
void print_arr(int A[], int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
	printf("%3d\n", A[i]);
    }
}

/* int main(void) */
/* { */
/*     int A[] = {1, 3, 5, 2, 9, 100, 6, 7, 10, 11,11,1, 3,2, 97}; */
/*     int length = length(A); */
/*     printf("the length of array A is: %d\n", length); */
/*     quick_sort(A, 0, length - 1); */
/*     print(A, length); */
/* } */

