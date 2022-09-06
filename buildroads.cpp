#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> g[N];

void dfs(int src,vector<int> &vis){
	vis[src]=1;
	for(auto x:g[src]){
		if(!vis[x]){
			dfs(x,vis);
		}
	}
}

int main(){
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> vis(n+1,0);
	vector<int> v;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,vis);
			v.push_back(i);
		}
	}
	cout<<v.size()-1<<endl;
	for(int i=0;i<v.size()-1;i++){
		cout<<v[i]<<" "<<v[i+1]<<endl;
	}
	return 0;
}