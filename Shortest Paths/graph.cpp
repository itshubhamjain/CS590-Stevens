
#include "graph.h"
#include <list>
#include <iostream>

using namespace std;

/*
 * constructor/destructor
 */
 /*>>>*/

 graph::graph(int n)
{ /*<<<*/
  no_vert = (n > 0) ? n : 1; //number of nodes in the graph
  m_edge = new int *[no_vert];

  //Initializing the adjacency matrix with zeros
  for (int i = 0; i < no_vert; i++)
  {
    m_edge[i] = new int[no_vert];
  }

  initialize();
  // dist = new int[no_vert];
  // parent = new int[no_vert];
} 

graph::graph(int n, int m, int w)
{ /*<<<*/

  no_vert = (n > 0) ? n : 1;
  
/*
 * allocate adjacency matrix
 */
  weights = w;
  edges = m;
  m_edge = new int*[no_vert];
  for (int i = 0; i < no_vert; i++)
    m_edge[i] = new int[no_vert];

  initialize();
}

graph::~graph()
{ /*<<<*/ 
/*
 * delete nil element and all other allocated nodes
 */
  for (int i = 0; i < no_vert; i++)
    delete[] m_edge[i];
  delete[] m_edge;
} /*>>>*/


void graph::initialize()
{ /*<<<*/
/*
 * initialize adjacency matrix
 * -> use infinity to allow 0 weight edges
 */

  for (int i = 0; i < no_vert; i++)
    for (int j = 0; j < no_vert; j++)
      m_edge[i][j] = INT_MAX;

} /*>>>*/

void graph::permutation(int* perm, int n)
{ /*<<<*/
  random_generator rg;
  int p_tmp, p_pos;

  for (int i = 0; i < n; i++)
    perm[i] = i;
  
  for (int i = 0; i < n; i++)
    {
      rg >> p_pos;
      p_pos = (p_pos % (n - i)) + i;

      p_tmp = perm[i];
      perm[i] = perm[p_pos];
      perm[p_pos] = p_tmp;
    }
} /*>>>*/

bool graph::graph_complete(){
  int count = 0;
  for(int i =0; i < no_vert; i++)
    for (int j = 0; j < no_vert; j++)
      if (m_edge[i][j]!= INT_MAX)
        ++count;
  
  if(count==edges)
    return true;
  return false;
}
 void graph::random_graph(int m, int w){
  weights = w;
   edges =m;
  random_generator rg;

  int *vertex = new int[no_vert];
           
    // permutation(vertex, no_vert);

  // Weight intervals [-w,w]

  // int *vertex = new int[no_vert];
  // for(int i=0;i<no_vert;i++)
  //   cout<<vertex[i]<<"\n";

  int count = 0;
  while(true){
   
    if(count >= edges)
      break;
    permutation(vertex, no_vert);
    int i = 0;
    while (count < edges && i <=(no_vert - 2))
    {
      int vertex1 = vertex[i];
      int vertex2 = vertex[i + 1];
      if (m_edge[vertex1][vertex2] == INT_MAX)
      {
        int weight_r;
        rg >> weight_r;
        int w = weights;
        weight_r = -1* w + weight_r % (1+2 * w);
        m_edge[vertex1][vertex2] = weight_r;
        count++;
      }
      ++i;
    }
  }

  delete[] vertex;
}



void graph::output()
{ /*<<<*/
  cout << "[";
  for (int i = 0; i < no_vert; i++)
    {
      cout << "[\t";
      for (int j = 0; j < no_vert; j++)
	if (m_edge[i][j] == INT_MAX)
	  cout << "Inf\t";
	else
	  cout << m_edge[i][j] << "\t";
      cout << "]" << endl;
    }
  cout << "]" << endl;
} /*>>>*/
void graph:: init_single_source(int **G, int s){
  for(int i=0; i<no_vert;i++){
     distance[i] = INT_MAX;
    predecessor[i] = -1;
  }
   distance[s] = 0;
}

void graph::relax(int u,int v,int **w){
  if(distance[u]!=INT_MAX){
  if(distance[v]>distance[u]+w[u][v]){
    distance[v] = distance[u]+w[u][v];
    predecessor[v] = u;
  }
}
}

 bool graph::bellman_ford(int **G, int s){
distance = new int[no_vert];
predecessor = new int[no_vert];
init_single_source(G,s);

for(int i=0;i<no_vert-1;i++){
for(int j =0; j<no_vert;j++){
  for (int k = 0 ; k<no_vert;k++){
      if(m_edge[j][k]!=INT_MAX)
        relax(j,k,m_edge);
  }
}
}



cout<<"Distance Array from source "<< s<<endl;
for(int i = 0;i <no_vert;i++)
  cout<<distance[i]<<"\t";
cout<<endl;
for(int j =0; j<no_vert-1;j++){
  for (int k = 0 ; k<no_vert;k++){
      if(G[j][k]!=INT_MAX){
      if(distance[k]> distance[j]+m_edge[j][k])
        return false;
  }
  }
}
return true;
}

void graph::floyd_marshall(int **W,int n){
  int **D = new int*[n];
  int **test = new int*[n];
  for (int i = 0; i < n; i++){
    D[i] = new int[n];
    test[i] = new int[n];
  }
    for(int i=0;i <n;i++)
    for(int j = 0; j< n;j++){
      if(W[i][j]<INT_MAX and i!=j){
        test[i][j] = i;
        continue;
      }
      test[i][j] = INT_MAX;
    }
 
  for(int i=0;i <n;i++)
    for(int j = 0; j< n;j++){
      if(i==j){
        D[i][j] = 0;
        }else
      D[i][j] = W[i][j];
  }

  for(int k = 0; k< n;k++){
    for(int i=0;i <n;i++){
        for(int j= 0; j< n;j++){
          if(D[i][k]!=INT_MAX && D[k][j]!=INT_MAX)
            if(D[i][k]+D[k][j]<D[i][j]){
                D[i][j] =D[i][k]+D[k][j]; 
                test[i][j] = test[k][j];
            }
          }
      }
  }


  for(int i = 0;i <n;i++){
      for(int j = 0; j<n;j++){
        if(D[i][j]==INT_MAX){
          cout<<"(--)\t";
          continue;
        }
        cout<<D[i][j]<<"\t";
      }
      cout<<endl;
    }

  cout<<"Lets Print test Predecessor\n";
     for(int i = 0;i <n;i++){
      for(int j = 0; j<n;j++){
        if(test[i][j]==INT_MAX){
          cout<<"(--)\t";
          continue;
        }
        cout<<test[i][j]<<"\t";
      }
      cout<<endl;
    }

for (int i = 0; i < no_vert; i++)
    delete[] D[i];
  delete[] D;
  for (int i = 0; i < no_vert; i++)
    delete[] test[i];
  delete[] test;
}





