#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int size[N];

void make(int v){
	parent[v]=v;
	size[v]=1;

}
int find(int v){
	if(v==parent[v]) return v;
	return parent[v]=find(parent[v]);
}

void Union(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		if(size[a]<size[b]){
			swap(a,b);
		}
		parent[b]=a;
		size[a]+=size[b];
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>> edges;
	for(int i=0;i<m;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		edges.push_back({wt,{x,y}});
	}
	sort(edges.begin(),edges.end());
	for(int i=1;i<=n;i++) make(i);
	int total=0;
	for(auto edge:edges){
		int w=edge.first;
		int u=edge.second.first;
		int v=edge.second.second;
		if(find(u)==find(v)) continue;
		Union(u,v);
		cout<<u<<" "<<v<<endl;
		total+=w;
	}
	cout<<total<<endl;
	return 0;
}