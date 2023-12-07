// Author: IMTIAJ
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int nmax = 1e6 + 10;
vector<vector<int>> adj(nmax);
vector<int>path;
int parent[nmax] = {};
int visited[nmax] = {};

void dfs(int u){
    visited[u] = 1;
    for(auto v: adj[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
        else if(parent[u] != v){ //checking cycle
            if(path.size() == 0){
                path.push_back(v);
                path.push_back(u);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs(i);
        if(path.size() != 0) break;
    }

    if(path.size() != 0){
        int start = path[1];
        int stop = path[0];

        while (start != stop){
            start = parent[start];
            path.push_back(start);
        }
        cout<<path.size()<<endl;
        for(auto node: path){
            cout<<node<<' ';
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }


    return 0;
}
