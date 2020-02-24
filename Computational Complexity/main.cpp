#include <cstdio>
#include <cstdlib>

#include "sort.h"
#include "timer.h"
#include "random_generator.h"

int main(int argc, char* argv[])
{
  random_generator rg;
  timer t,t_improved, t_merge;
  int n, m, d, a;
  
  if (argc > 1)
    { 
      m = atoi(argv[1]);
      m = (m < 1) ? 1 : m;
    }
  else
    {
      cout << "hw1: [m] [n] [direction]" << endl;
      cout << "[m]              size of the random integer vector array" << endl;
      cout << "[n]              dimension of integer vector array" << endl;
      cout << "[direction]      0: random" << endl;
      cout << "                 1: sorted" << endl;
      cout << "                 -1: reverse sorted" << endl;
      cout << endl;
      return 0;
    }

  if (argc > 2)
    {
      n = atoi(argv[2]);
      n = (n < 0) ? 0 : n;
    }
  else
    n = 0;

  if (argc > 3)
    d = atoi(argv[3]);
  else
    d = 0;

  int** input_array;
  int** input_array_improved;
    int** input_array_merge;

/*
 * create input array sorted/reverse sorted/random 
 * depending on program argument
 * -> input_array is allocated!
 */
  t.start();
  if (d == 0)
    input_array = create_random_ivector(n, m, true);
  else
    {
      if (d < 0)
  input_array = create_reverse_sorted_ivector(n, m);
      else
  input_array = create_sorted_ivector(n, m);
    }
  t.stop();

  cout << "Timer (generate): " << t << endl;

/*
 * output the first 20 elements for debugging purposes
 */
  for (int i = 0; (i < m) && (i < 20); i++)
    {
      cout << "[ ";
      for (int j = 0; j < n; j++)
  cout << input_array[i][j] << " ";
      cout << "]" << endl;
    }
  cout << endl;

/*
 * Do naiv insertion sort
 */
  cout << "Running insertion sort algorithm: " << endl;
  t.start();
  insertion_sort(input_array, n, 0, m-1);
  // merge_sort(input_array, n, 0, m-1);
  t.stop();

  cout << "Timer (sort): " << t << endl;
 
/*
 * check whether or not the algorithm sorted the array
 */
  if (check_sorted(input_array, n, 0, m-1))
    cout << "The output is sorted!" << endl;
  else
    cout << "ERROR: The output is not sorted!" << endl;

/*
 * output the first 20 elements for debugging purposes
 */
  for (int i = 0; (i < m) && (i < 20); i++)
    {
      cout << "[ ";
      for (int j = 0; j < n; j++)
  cout << input_array[i][j] << " ";
      cout << "]" << endl;
    }
  cout << endl;












t_improved.start();
  if (d == 0)
    input_array_improved = create_random_ivector(n, m, true);
  else
    {
      if (d < 0)
  input_array_improved  = create_reverse_sorted_ivector(n, m);
      else
  input_array_improved  = create_sorted_ivector(n, m);
    }
  t_improved.stop();

  cout << "Timer (generate): " << t_improved << endl;

/*
 * output the first 20 elements for debugging purposes
 */
  for (int i = 0; (i < m) && (i < 20); i++)
    {
      cout << "[ ";
      for (int j = 0; j < n; j++)
  cout << input_array_improved[i][j] << " ";
      cout << "]" << endl;
    }
  cout << endl;

/*
 * Do Improved insertion sort
 */
  cout << "Running Improved insertion sort algorithm: " << endl;
  t_improved.start();
  insertion_sort_im(input_array_improved, n, 0, m-1);
  t_improved.stop();

  cout << "Timer (sort): " << t_improved << endl;
 
/*
 * check whether or not the algorithm sorted the array
 */
  if (check_sorted(input_array_improved, n, 0, m-1))
    cout << "The output is sorted!" << endl;
  else
    cout << "ERROR: The output is not sorted!" << endl;

/*
 * output the first 20 elements for debugging purposes
 */
  for (int i = 0; (i < m) && (i < 20); i++)
    {
      cout << "[ ";
      for (int j = 0; j < n; j++)
  cout << input_array_improved[i][j] << " ";
      cout << "]" << endl;
    }
  cout << endl;




















    t_merge.start();
      if (d == 0)
        input_array_merge= create_random_ivector(n, m, true);
      else
        {
          if (d < 0)
      input_array_merge = create_reverse_sorted_ivector(n, m);
          else
      input_array_merge  = create_sorted_ivector(n, m);
        }
      t_merge.stop();

      cout << "Timer (generate): " << t_merge << endl;

    /*
     * output the first 20 elements for debugging purposes
     */
      for (int i = 0; (i < m) && (i < 20); i++)
        {
          cout << "[ ";
          for (int j = 0; j < n; j++)
      cout << input_array_merge[i][j] << " ";
          cout << "]" << endl;
        }
      cout << endl;

    /*
     * Do Improved insertion sort
     */
      cout << "Running Merge sort algorithm: " << endl;
      t_merge.start();
      merge_sort(input_array_merge, n, 0, m-1);
      t_merge.stop();

      cout << "Timer (sort): " << t_merge << endl;
     
    /*
     * check whether or not the algorithm sorted the array
     */
      if (check_sorted(input_array_merge, n, 0, m-1))
        cout << "The output is sorted!" << endl;
      else
        cout << "ERROR: The output is not sorted!" << endl;

    /*
     * output the first 20 elements for debugging purposes
     */
      for (int i = 0; (i < m) && (i < 20); i++)
        {
          cout << "[ ";
          for (int j = 0; j < n; j++)
      cout << input_array_merge[i][j] << " ";
          cout << "]" << endl;
        }
      cout << endl;



/*
 * free the allocated storage
 */
  remove_ivector(input_array, m);
 remove_ivector(input_array_improved, m);
   remove_ivector(input_array_merge, m);
  return 0;
}

