#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+7;
vector<int> g[N];

int32_t main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> vis(n+1,0);
	vector<int> preState(n+1);
	for(int i=1;i<=n;i++) preState[i]=i;
	queue<int> q;
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(auto x:g[t]){
			if(!vis[x]){
				preState[x]=t;
				vis[x]=1;
				q.push(x);
			}
		}
	}
	if(vis[n]==0){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		vector<int> steps;
		steps.push_back(n);
		while(n!=1){
			steps.push_back(preState[n]);
			n=preState[n];
		}
		reverse(steps.begin(),steps.end());
		cout<<steps.size()<<endl;
		for(auto x:steps){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}