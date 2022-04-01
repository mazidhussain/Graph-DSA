#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
bool vis[N];

vector<int> graph[N];

bool dfs(int vertex,int par){
	vis[vertex]=true;
	bool isLoopExists=false;
	for(int child:graph[vertex]){
		if(vis[child] and child==par){
			continue;
		}
		if(vis[child]) return true;
		isLoopExists |= dfs(child,vertex);
	}
	return isLoopExists;
}

int main(){
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int v1,v2;
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	bool isLoopExist=false;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		if(dfs(i,0)){
			isLoopExist=true;
			break;
		}`
	}
	cout<<isLoopExist<<endl;

	return 0;
}