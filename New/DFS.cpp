#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
bool vis[N];

void dfs(int node){
    vis[node] = true;
    cout<<node<<" ";
    for(auto child : g[node]){
        if(vis[child]) continue;
        dfs(child);
    }
}

int main(){
    
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int source;
    cin>>source;
    dfs(source);
}