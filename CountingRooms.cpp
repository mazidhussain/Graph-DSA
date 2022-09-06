#include<bits/stdc++.h>
using namespace std;
 
 
void dfs(vector<vector<char>> &arr,vector<vector<int>> &vis,int i,int j,int n,int m){
	if(i<0 or j<0 or i>=n or j>=m){
		return;
	}
	if(vis[i][j] or arr[i][j]=='#') return;
	vis[i][j]=1;
	dfs(arr,vis,i+1,j,n,m);
	dfs(arr,vis,i,j+1,n,m);
	dfs(arr,vis,i,j-1,n,m);
	dfs(arr,vis,i-1,j,n,m);
}
 
 
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>> arr(n,vector<char> (m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	vector<vector<int>> vis(n,vector<int> (m,0));
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]==0 and arr[i][j]=='.'){
				dfs(arr,vis,i,j,n,m);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}