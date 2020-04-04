#ifndef __AM_GRAPH_H__
#define __AM_GRAPH_H__

#include <limits.h>
#include "random_generator.h"
    
class graph
{
  protected:

    int		no_vert;
    int weights;
    int edges;


  public:
      int**	m_edge;
      int *distance;
      int *predecessor;
    graph(int,int,int);
    graph(int);
    ~graph();

    void random_graph(int, int);
    void relax(int,int,int**);
  void init_single_source(int** , int );
    int get_no_of_vertices()
      { return no_vert; }
  bool bellman_ford(int **, int);
    void output();
    void floyd_marshall(int**, int);
    bool graph_complete();
  protected:
    void initialize();
    void permutation(int*, int);
};



#endif












// void graph::floyd_warshall()
// { /*<<<*/
//   int **D = new int *[no_vert];
//   int **P = new int *[no_vert];

//   for (int i = 0; i < no_vert; i++)
//   {
//     D[i] = new int[no_vert];
//     P[i] = new int[no_vert];
//   }

//   for (int i = 0; i < no_vert; i++)
//     for (int j = 0; j < no_vert; j++)
//     {
//       if (i != j && m_edge[i][j] < INT_MAX)
//       {
//         P[i][j] = i;
//       }
//       else
//       {
//         P[i][j] = INT_MAX;
//       }
//     }

//   for (int i = 0; i < no_vert; i++)
//     for (int j = 0; j < no_vert; j++)
//       if (i != j)
//         D[i][j] = m_edge[i][j];
//       else
//         D[i][j] = 0;

//   for (int k = 0; k < no_vert; k++)
//   {
//     for (int i = 0; i < no_vert; i++)
//     {
//       for (int j = 0; j < no_vert; j++)
//       {
//         if (D[i][k] != INT_MAX && D[k][j] != INT_MAX)
//         {
//           if (D[i][k] + D[k][j] < D[i][j])
//           {
//             D[i][j] = D[i][k] + D[k][j];
//             P[i][j] = P[k][j];
//           }
//         }
//       }
//     }
//   }

//   //Print the shortest path matrix D^(n)
//   cout << "Floyd-Warshall: Shortest Distance Matrix:" << endl;
//   output_matrix(D);
//   cout << "Floyd-Warshall: Predecessor Matrix:" << endl;
//   output_matrix(P);

//   //Deallocating memory
//   for (int i = 0; i < no_vert; i++)
//   {
//     delete[] D[i];
//     delete[] P[i];
//   }
//   delete[] D;
//   delete[] P;

// }