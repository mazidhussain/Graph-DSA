#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int> graph[N];
int vis[N];
int level[N];

void dfs(int vertex){
	queue<int> q;
	q.push(vertex);
	vis[vertex]=1;
	while(!q.empty()){
		int curr_vertex=q.front();
		q.pop();
		for(auto x:graph[curr_vertex]){
			if(!vis[x]){
				q.push(x);
				vis[x]=1;
				level[x]=level[curr_vertex]+1;
			}
		}
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
		cout<<level[i]<<endl;

	}
	return 0;
}