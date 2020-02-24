#ifndef __SORT_H__
#define __SORT_H__

/*
 * check functions
 */
bool check_sorted(char**, int, int);
int string_compare(char*, char *);
int string_compare_new(char*, char *, int, int);
void remove_ivector(char**, int);
/*
 * character sort
 */
// int string_compare(char*, char*);
// string_compare(char*, char *,int ,int);
void insertion_sort(char**, int, int);
void insertion_sort_digit(char**, int *, int, int, int);
void radix_sort_is(char**, int*, int, int);
void radix_sort_cs(char**, int*, int, int);
void counting_sort_digit(char** , int* ,char**, int*, int , int );
char** create_ivector(int, int);

#endif
