// Author: IMTIAJ
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
 
const int nmax = 1e5 + 10;
//vector<int> adj[nmax]; // adj[1] = list of 1, adj[2] = list of 2
vector<vector<int>> adj(nmax); // line 9 & 10 are same
vector<int> paths;
bool visited[nmax]; // keep trac wheather a node is visited or not
 
void dfs(int u){
    visited[u] = true;
 
    for(auto v : adj[u]){
        if(visited[v]) continue;
        dfs(v);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int nodes, edges;
    cin>>nodes>>edges;
 
    for(int i = 0; i < edges; i++){
        int u, v;
        cin>>u>>v;
 
        adj[u].push_back(v);
        adj[v].push_back(u);
 
    }
 
    for(int u = 1; u <= nodes; u++){
        if(visited[u]) continue;
        paths.push_back(u);
        dfs(u);
    }
 
    cout<<paths.size()-1<<endl;
    for(int i=0; i<paths.size()-1; i++){
        cout<<paths[i]<<" "<<paths[i+1]<<endl;
    }
 
    return 0;
}
