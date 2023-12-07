// Author: IMTIAJ
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int nmax = 1e6 + 10;
vector<vector<int>> adj(nmax);
//vector<int> teams(nmax);
int visited[nmax] = {};

bool dfs(int u, int col){
    visited[u] = col;

    for(auto v : adj[u]){
        if(!visited[v]){
            if(visited[u] == 1){
                if(!dfs(v, 2)) return false;
            }
            else if(visited[u] == 2){
                if(!dfs(v, 1)) return false;
            }
        }
        else if(visited[v] == col) return false;
    }
    return true;
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

    bool flag = true;
    for(int u = 1; u <= n; u++){
        if(!visited[u]){
            flag = dfs(u, 1);
            if(!flag) break;
        }
    }

    if(flag){
        for(int i=1; i<=n; i++){
            cout<<visited[i]<<' ';
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }

    return 0;
}
