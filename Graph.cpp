#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;

int graph1[N][N];

vector<int> graph2[N];

int main(){
	int n,e;
	cin>>n>>e;

	for(int i=0;i<e;i++){
		int v1,v2;
		cin>>v1>>v2;
		graph1[v1][v2]=1;
		graph1[v2][v1]=1;

		graph2[v1].push_back(v2);
		graph2[v2].push_back(v1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<graph1[i][j];
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(auto x:graph2[i]){
			cout<<x;
		}
		cout<<endl;
	}
	return 0;
}


// input 

/*
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/
