#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
bool vis[N];
int level[N];
vector<int> g[N];

void bfs(int node){
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while(!q.empty()){
        int visit = q.front();
        cout<<visit<<" ";
        q.pop();
        for(auto u:g[visit]){
            if(!vis[u]){
                q.push(u);
                vis[u] = true;
                level[u] = level[visit] + 1;
            }
        }
    }
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int source; cin>>source;
    bfs(source);


}