// Author: Imtiaj
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int nmax = 1e6 + 10;
vector<vector<int>> adj(nmax);
vector<int> parent(nmax);
bool visited[nmax];

void bfs(int u){
    visited[u] = true;

    queue<int> q;
    q.push(u);

    while(!q.empty()){
        int frnt = q.front();
        q.pop();

        for(auto v : adj[frnt]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            parent[v] = frnt;
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

        // For undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*for(int u = 1; u <= n; u++){
        if(visited[u]) continue;

        bfs(u);
    }*/
    bfs(1);

    vector<int> path;
    int current = n;

    if(visited[n]){
        while(current != 1){
        path.push_back(current);
        current = parent[current];
    }
        path.push_back(1);
        reverse(path.begin(), path.end());
        cout<<path.size()<<endl;
        for(auto node: path){
            cout<<node<<' ';
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
