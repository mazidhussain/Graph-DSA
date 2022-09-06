#include<bits/stdc++.h>
using namespace std;


#define int long long 
const int N=1e5+7;
vector<int> g[N];
bool flag;

void dfs(int src,vector<int> &color,int cr){
	color[src]=cr;
	if(!flag){
		return;
	}
	for(auto x:g[src]){
		if(color[x]==-1){
			dfs(x,color,1-cr);
		}
		else{
			if(color[x]==cr){
				flag=false;
				return;
			}
		}
	}
}
int32_t main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> color(n+1,-1);
	flag=true;
	for(int i=1;i<=n;i++){
		if(color[i]==-1){
			dfs(i,color,0);
		}
	}
	if(!flag){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			cout<<color[i]+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}