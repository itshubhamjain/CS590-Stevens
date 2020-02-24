#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "sort.h"

/* 
 * HW 2 part
 */
int string_compare(char* s1, char *s2) {
  /*
   * We assume that s1 and s2 are non-null pointers
   */
  int i;

  i = 0;
  while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]))
    i++;

  if (s1[i] == s2[i])
    return 0;
  else {
    if (s1[i] < s2[i])
      return -1;
    else
      return 1;
  }
}

int string_compare_new(char* s1, char *s2, int d, int length) {
  /*
   * We assume that s1 and s2 are non-null pointers
   */
  // int i;
  // i = 0;
  if (length < d) {
    return 1;
  }
  // while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]))
  //   i++;

  if (s1[d] == s2[d])
    return 0;
  else {
    if (s1[d] < s2[d])
      return -1;
    else
      return 1;
  }
}
/*>>>*/

void insertion_sort_digit(char** A, int *A_len, int digit, int l, int r) {
  // cout<<"\nNot yet"<<digit;
  int i;
  char* key;
  int lengthkey;
  for (int j = l; j <= r; j++) {
    key = A[j];
    i = j - 1;
    lengthkey = A_len[j];
    while ((i >= l) && (string_compare_new(A[i], key, digit, A_len[i]) > 0)) {
      A[i + 1] = A[i];
      A_len[i + 1] = A_len[i];
      i = i - 1;
    }

    A[i + 1] = key;
    A_len[i + 1] = lengthkey;
  }
  // delete key;
}

void radix_sort_is(char** A, int* A_len, int n, int m) {
  int max_digit = 0;

  for (int i = 0; i < n; i++) {
    if (A_len[i] > max_digit)
      max_digit = A_len[i];
  }
  int j = max_digit;
  while (j >= 0) {

    insertion_sort_digit(A, A_len, j, 0, n - 1);

    j -= 1;
  }

  // }
}


void counting_sort_digit(char** A,int* A_len, char** B , int* B_len, int n, int d){

  int* c = new int[256];
  for(int i = 0; i <256; i++) {
      c[i] = 0;
  }
  
  for(int i=0; i <n; i++){
    if(A_len[i]-1>=d){
      ++c[A[i][d]];
    }
    else{
      ++c[0];
    }

  }
  for(int i = 1; i <255;i++){
    c[i] +=c[i-1];
  }

  for(int j = n-1;j >=0;--j){
    if(A_len[j]-1>=d){
        B[c[A[j][d]]-1] = A[j];
        B_len[c[A[j][d]]-1] = A_len[j];
        --c[A[j][d]];
    }
    else{
      B[c[0]-1] = A[j];
      B_len[c[0]-1] = A_len[j];
      c[0]--;
    }
  }
  for(int i = 0; i < n;i++){
    A[i] = B[i];
    A_len[i] =B_len[i];
  }
  delete[] c;
}


void radix_sort_cs(char** A, int* A_len, int n, int m) {
    char** B;
   B = new char*[n];
   int* B_len = new int[n];
 
  int j = m;
  while (j >= 0) {
    // std::cout<<"\nRunning for "<<j;
    counting_sort_digit(A, A_len, B, B_len, n, j);
    j -= 1;
  }
    delete[] B;
  delete[] B_len; 
}

// void insertion_sort(char** A, int l, int r)
// { 
//   int i;
//   char* key;

//   for (int j = l+1; j <= r; j++)
//     {
//       key = A[j];
//       i = j - 1;

//       while ((i >= l) && (string_compare(A[i], key) > 0))
//         {
//    A[i+1] = A[i];
//    i = i - 1;
//  }

//       A[i+1] = key;
//     }
// }

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */

bool check_sorted(char** A, int l, int r) {
  for (int i = l + 1; i < r; i++)
    if (string_compare(A[i - 1], A[i]) > 0)
      return false;
  return true;
}
void remove_ivector(char** temp, int m) {
  for (int i = 0; i < m; i++)
    delete[] temp[i];
  delete[] temp;
}

