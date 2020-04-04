#include <iostream>
#include <limits.h>
#include "graph.h"
#include "random_generator.h"

using namespace std;

int main(int argc, char* argv[])
{ 
    int n, m, w ;

    if (argc == 4)
    {
      n = atoi(argv[1]);
      if (n<2) {
          cout<<"No. of vertices should be more than 1"<<endl;
          return 0;
      }
      m = atoi(argv[2]);
      if (m<1) {
          cout<<"Edges has to be more than 1"<<endl;
          return 0;
      }
      if (m>( n*n - n)) {
          cout<<"Allowed Edges is n(n-1) for DAG"<<endl;
          return 0;
      }

      w = atoi(argv[3]);

    }
  else
    {
      cout << "hw6: [n] [m] [w]" << endl;
      cout << "[n]   Vertices" << endl;
      cout << "[m]   Edges " << endl;
      cout << "[w]   Weight from [-w,w]" << endl;
      cout << endl;
      return 0;
    }
    // n is vertices 
    // m is edges
    //w interval
      
    graph *G = new graph(n);

    G->random_graph(m,w);

    for(int i = 0;i <n;i++){
      for(int j = 0; j<n;j++){
        if(G->m_edge[i][j]==INT_MAX){
          cout<<"(--)\t";
          continue;
        }
        cout<<G->m_edge[i][j]<<"\t";
      }
      cout<<endl;
    }


  cout<<"Printing Floyd Marshall Output\n\n\n";
  G->floyd_marshall(G->m_edge,n);
    cout<<"Printing Bellman Ford Output\n\n\n";
  if(G->bellman_ford(G->m_edge, 0))
    cout<<"True";
  else
  cout<<"False";
delete G;  
  return 0;
}  
