const int M=1e9+7;
void dfs(int vertex,int par,vector<int> graph[],vector<int> &subtree_sum,vector<int> &val){
    subtree_sum[vertex]+=val[vertex-1];
    for(auto child:graph[vertex]){
        if(child==par){
            continue;
        }
        dfs(child,vertex,graph,subtree_sum,val);
        subtree_sum[vertex]+=subtree_sum[child];
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    vector<int> graph[A.size()+1];
    vector<int> subtree_sum(A.size()+1,0);
    for(auto x:B){
        graph[x[0]].push_back(x[1]);
        graph[x[1]].push_back(x[0]);
    }
    dfs(1,0,graph,subtree_sum,A);
    long long  ans=0;
    for(int i=2;i<=A.size();i++){
        int p1=subtree_sum[i];
        int p2=subtree_sum[1]-p1;
        ans=max(ans,(p1*1LL*p2)%M);
    }
    return ans;

}
