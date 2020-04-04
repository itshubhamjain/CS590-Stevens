#include "graph.h"
#include <set>
#include <iostream>
#include <queue>
using namespace std;

Graph::Graph(int no_nodes){
	if(no_nodes==0){
		cout<<"\nNodes should be atleast 1";
		return;
	}
	this->nodes = no_nodes;
	this->matrix = new int*[no_nodes];
	for(int i=0;i <no_nodes;i++){
		matrix[i] = new int[no_nodes];
		for(int j=0;j<no_nodes;j++){
			matrix[i][j]= 0;
		}
	}
}

Graph::Graph(int** AdjMatrix,int no_nodes){
	if(no_nodes==0){
		cout<<"\nNodes should be atleast 1";
		return;
	}
	this->nodes = no_nodes;
	this->matrix = new int*[no_nodes];
	for(int i=0;i <no_nodes;i++){
		matrix[i] = new int[no_nodes];
		for(int j=0;j<no_nodes;j++){
			matrix[i][j]= AdjMatrix[i][j];
		}
	}

}
Graph::~Graph(){
	for(int i =0;i<nodes;i++){
		delete matrix[i];
	}
	delete matrix;
}

bool Graph::set_edge(int x, int y, int z){
	if(x>0 && x < nodes){
		if(x>0 && x < nodes){
			matrix[x][y] = z;
			return true;
		}
		else{
			return false;
		}
	}else{
		return false;
	}
	
}

void Graph::dfs(int vertex, set<int>* visited){
	cout<<"  "<<vertex<<" ";
	visited->insert(vertex);
	for(int i=0;i<nodes;i++){
			if(matrix[vertex][i]!=0 && visited->count(i)==0){
				dfs(i,visited);
			}
		}
	
}


void Graph::dfs(){
	set<int>* visited = new set<int>;
	int source = 0;
	dfs(source,visited);
	for(int i=0;i<nodes;i++){
		if(visited->count(i)==0)
			dfs(i,visited);
	}
	delete visited;
}



void Graph::bfs(int source){
	set<int>* visited = new set<int>;
	bfs(source,visited);
	delete visited;
}

void Graph::bfs(int source, set<int>* visited){
	queue<int> Que;
	visited->insert(source);
	Que.push(source);
	while(!Que.size()==0){
		int temp = Que.front();
		Que.pop();
		for(int i=0;i<nodes;i++){
			if(matrix[temp][i]!=0 && visited->count(i)==0){
				Que.push(i);
				cout<<"  "<<i<<" ";
				visited->insert(i);
			}
		}
		
	}
}













