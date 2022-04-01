#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int> graph[N];
int par[N];

void dfs(int vertex,int p=-1){
	par[vertex]=p;
	for(int child:graph[vertex]){
		if(child==p) continue;
		dfs(child,vertex);
	}
}

vector<int> path_find(int v){
	vector<int> ans;
	while(v!=-1){
		ans.push_back(v);
		v=par[v];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;++i){
		int v1,v2;
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	dfs(1);

	int x,y;
	cin>>x>>y;
	vector<int> path_x=path_find(x);
	vector<int> path_y=path_find(y);
	int min_lenght=min(path_y.size(),path_x.size());
	int lca=-1;
	for(int i=0;i<min_lenght;i++){
		if(path_y[i]==path_x[i]){
			lca=path_x[i];
		}
		else{
			break;
		}
	}
	cout<<lca<<endl;
	return 0;
}