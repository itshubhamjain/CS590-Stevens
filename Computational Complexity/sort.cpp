#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "sort.h"
#include <math.h>
#include <limits>
using namespace std;

int ivector_length(int* v, int n)
{
  int sum;

  sum = 0;
  for (int i = 0; i < n; i++)
    sum += (v[i] < 0) ? -v[i] : v[i];

  return sum;
}

/*
* Improved insertion sort
*/

void insertion_sort_im(int **A, int n, int l, int r){
  // int *length ;
  int i;
    int lengthSample[r+1];
    int lengthofKey;
  for(i= l; i < r+1 ; i++){
    lengthSample[i] = ivector_length(A[i], n);
  }
  // cout<< "Printing LengthSample";
  // for(int i; i<r+1;i++){
  //   cout<<" "<<i<<" "<<lengthSample[i]<<"\n";
  // }
  // int i;
  int* key;

 for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;
      lengthofKey = lengthSample[j];

      while ((i >= l) && (lengthSample[i] > lengthofKey) )
        {
    A[i+1] = A[i];
    lengthSample[i+1] = lengthSample[i];
    i = i - 1;
  }
 
      A[i+1] = key;
   lengthSample[i+1] = lengthofKey;
    }

}

/*
 * insertion sort
 */

void insertion_sort(int** A, int n, int l, int r)
{
  int i;
  int* key;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;

      while ((i >= l) && (ivector_length(A[i], n) > ivector_length(key, n)))
        {
      A[i+1] = A[i];
      i = i - 1;
    }

      A[i+1] = key;
    }
}



void merge(int **A, int lengthSample[], int n, int l, int m, int r){


  int **temp = new int*[r-l+1];
  int tempLength[r-l+1];
  int i, j, k,count;
    i = l;
    k = 0;
    j = m + 1;
 

    while (i <= m && j <= r)
    {
        if (lengthSample[i] < lengthSample[j])
        {
            tempLength[k] = lengthSample[i];
            temp[k]= A[i];
            k++;
            i++;
        }
        else
        {
            tempLength[k] = lengthSample[j];
            temp[k] = A[j];
            //  for(count = 0;count<n;count++){
            //   temp[k][count] = A[j][count];
            // }
            k++;
            j++;
        }
    }
 

    while (i <= m)
    {
        tempLength[k] = lengthSample[i];
         temp[k] = A[i];
         // for(count = 0;count<n;count++){
         //      temp[k][count] = A[i][count];
         //    }
        k++;
        i++;
    }
 

    while (j <= r)
    {
        tempLength[k] = lengthSample[j];
        temp[k] = A[j];
         // for(count = 0;count<n;count++){
         //      temp[k][count] = A[j][count];
         //    }
        k++;
        j++;
    }

    for (i = l; i <= r; i++)
    {
        lengthSample[i] = tempLength[i-l];
        A[i] = temp[i-l];
         // for(count = 0;count<n;count++){
         //      A[i][count] = temp[i-l][count];
         //    }
    }

}


void merge_sort_1(int **A, int lengthSample[], int n, int l, int r){
  int m ;
  if(l < r){
    m = (l + r) / 2;
    merge_sort_1(A, lengthSample, n, l, m);
    merge_sort_1(A, lengthSample, n, m+1, r);
     merge(A, lengthSample, n , l, m,r);
  }

}




void merge_sort(int **A, int n, int l, int r){

int lengthSample[r+1];

 for(int i= l; i < r+1 ; i++){
    lengthSample[i] = ivector_length(A[i], n);
  }
  merge_sort_1(A,lengthSample,n,l,r);

  // cout<< "Printing LengthSample";
  // for(int i=l; i<r+1;i++){
  //   cout<<" "<<i<<" "<<lengthSample[i]<<"\n";
  // }
}






/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(int** A, int n, int l, int r)
{
  for (int i = l+1; i <= r; i++)
    if (ivector_length(A[i-1], n) > ivector_length(A[i], n))
      return false;
  return true;
}


/*
 * generate sorted/reverse/random arrays of type hw1type
 */
int** create_ivector(int n, int m)
{
  int** iv_array;

  iv_array = new int*[m];
  for (int i = 0; i < m; i++)
    iv_array[i] = new int[n];

  return iv_array;
}

void remove_ivector(int** iv_array, int m)
{
  for (int i = 0; i < m; i++)
    delete[] iv_array[i];
  delete[] iv_array;
}

int** create_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = (i+j)/n;

  return iv_array;
}

int** create_reverse_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = ((m-i)+j)/n;

  return iv_array;
}

int** create_random_ivector(int n, int m, bool small)
{
  random_generator rg;
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      {
	rg >> iv_array[i][j];
	if (small)
	  iv_array[i][j] %= 100;
	else
	  iv_array[i][j] %= 65536;
      }

  return iv_array;
}

