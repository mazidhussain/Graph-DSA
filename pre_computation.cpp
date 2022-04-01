#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int> graph[N];
int subtree_sum[N],even_no_in_subTree[N];

void dfs(int vertex,int par=0){
	if(vertex%2==0){
		even_no_in_subTree[vertex]++;
	}
	subtree_sum[vertex]+=vertex;
	for(int child:graph[vertex]){
		if(child==par) continue;
		dfs(child,vertex);
		subtree_sum[vertex]+=subtree_sum[child];
		even_no_in_subTree[vertex]+=even_no_in_subTree[child];
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int v1,v2;
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<subtree_sum[i]<<" "<<even_no_in_subTree[i]<<endl;
	}
	return 0;
}

/*
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
*/