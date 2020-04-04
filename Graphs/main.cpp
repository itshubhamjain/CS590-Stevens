#include "graph.h"

int main()
{
	
	int no_nodes = 12;
	int **Adjmatrix = new int*[no_nodes];
	for(int i=0;i < no_nodes;i++){
		Adjmatrix[i] = new int[no_nodes];
		for(int j=0; j< no_nodes;j++)
			Adjmatrix[i][j] = 0 ;
	}
	Adjmatrix[0][3] = 1;
	Adjmatrix[1][2] = 1;
	Adjmatrix[1][3] = 1;
	Adjmatrix[3][0] = 1;
	Adjmatrix[3][1] = 1;
	Adjmatrix[3][4] = 1;
	Adjmatrix[4][2] = 1;
	Adjmatrix[4][3] = 1;
	Adjmatrix[4][6] = 1;
	Adjmatrix[5][8] = 1;
	Adjmatrix[6][7] = 1;
	Adjmatrix[7][5] = 1;
	Adjmatrix[7][8] = 1;
	Adjmatrix[7][10] = 1;
	Adjmatrix[8][5] = 1;
	Adjmatrix[9][11] = 1;
	Adjmatrix[10][9] = 1;
	Adjmatrix[11][10] = 1;
	
	Graph *G;
	G =new Graph(Adjmatrix,no_nodes);
	G->dfs();
}
