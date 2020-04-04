#include <cstring>
#include <iostream>
#include <limits.h>

#include "dynprog.h"
#define diagonal -10
#define up -20
#define left -30

using namespace std;


/*
* Bottom up implementation of Smith-Waterman algorithm
*/
void SW_bottomUp(char* X, char* Y, char** P, int** H, int n, int m){
	int i,j , p1,p2,p3 = 0;
		for (i =0; i<=n;i++){
			H[i][0] =0;
			P[i][0] = 0;
		}
		for (i = 0;i <=m;i++){
			H[0][i] = 0;
			P[0][i]=0;
		}
		for(i =1; i<=n;i++){
			for(j =1;j<=m;j++){
				if(X[i-1]==Y[j-1]){
					p1 = H[i-1][j-1]+2;
				}else{
					p1 = H[i-1][j-1]-1;
				}
				p2 = H[i-1][j] - 1;
				p3 = H[i][j-1] -1;
				H[i][j] = max(p1,p2,p3);
				if(H[i][j]==p1)
					P[i][j]= 'd';
				else{
					if(H[i][j]==p2){
						P[i][j] = 'u';
					}else{
						P[i][j] = 'l';
					}
				}
			}	
		}
}

/*
* Top-down with memoization implementation of Smith-Waterman algorithm
*/
void memoized_SW(char* X, char* Y, char** P, int** H, int n, int m){
	int** Visited= new int*[n+1];
	for(int i=0;i <=n;i++){
		Visited[i] = new int[m+1];
	}
	cout<<"Maximum Aliginment\t"<<memoized_SW_AUX(X,Y,P,H,Visited, n,m);
}

int memoized_SW_AUX(char* X, char* Y, char** P, int** H,int** Visited, int n, int m){
	int p1,p2,p3;
	if(n==0 || m==0)
		return 0;
	else{
		
		if(Visited[n][m]==1){
			return H[n][m];
		}
		
		Visited[n][m] = 1;
		
		if(X[n-1]==Y[m-1]){
			p1 = memoized_SW_AUX(X,Y,P,H,Visited, n-1,m-1)+2;
		}else{
			
			p1 = memoized_SW_AUX(X,Y,P,H,Visited, n-1,m-1)-1;
		}
		p2 = memoized_SW_AUX(X,Y,P,H,Visited, n-1,m)-1;
		p3 = memoized_SW_AUX(X,Y,P,H,Visited, n,m-1)-1;
		H[n][m] = max (p1,p2,p3);
		if(H[n][m]==p1)
					P[n][m]= 'd';
				else{
					if(H[n][m]==p2){
						P[n][m] = 'u';
					}else{
						P[n][m] = 'l';
					}
				}
		
		return H[n][m];

	}
}

int max(int x,int y, int z){
	if(x>=y && x >=z)
		return x;
	if(y>=x && y>=z )
		return y;
	if(z>=x && z>=y)
		return z;
}
/*
* Auxilary recursive function of top-down with memoization implementation of Smith-Waterman algorithm
*/


/*
* Print X'
*/
void print_Seq_Align_X(char* X, char** P, int n, int m){
	if(P[n][m]=='d'){
		print_Seq_Align_X(X, P, n-1, m-1);
		cout<<X[n-1];
	}
	else{
		if(P[n][m]=='l'){
			print_Seq_Align_X(X, P, n, m-1);
			cout<<"-";
		}
		else if(P[n][m]=='u')
		{
			print_Seq_Align_X(X, P, n-1, m);
			cout<<X[n-1];
		}
	}
}

/*
* Print Y'
*/
void print_Seq_Align_Y(char* Y, char** P, int n, int m){
	if(P[n][m]=='d'){
		print_Seq_Align_Y(Y, P, n-1, m-1);
		cout<<Y[m-1];
	}
	else{
		if(P[n][m]=='l'){
			print_Seq_Align_Y(Y, P, n, m-1);
			cout<<Y[m-1];

		}
		else if(P[n][m]=='u'){
			print_Seq_Align_Y(Y, P, n-1, m);
			cout<<'-';
		}
	}
}