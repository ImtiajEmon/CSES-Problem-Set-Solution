// Author: IMTIAJ
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
 
int n, m;
const int nmax = 1e3 + 10;
char grid[nmax][nmax]; // adj[1] = list of 1, adj[2] = list of 2
bool visited[nmax][nmax]; // keep trac wheather a node is visited or not
 
void dfs(int x, int y){
    visited[x][y] = true;
 
    if(x > 1 && !visited[x-1][y] && grid[x-1][y] != '#')
        dfs(x-1, y);
 
    if(x < n && !visited[x+1][y] && grid[x+1][y] != '#')
        dfs(x+1, y);
 
    if(y > 1 && !visited[x][y-1] && grid[x][y-1] != '#')
        dfs(x, y-1);
 
    if(y < m && !visited[x][y+1] && grid[x][y+1] != '#')
        dfs(x, y+1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin>>n>>m;
    
    FOR(i, 1, n){
        FOR(j, 1, m){
            cin>>grid[i][j];
        }
    }
 
    int ans = 0;
 
    FOR(i, 1, n){
        FOR(j, 1, m){
            if(grid[i][j] != '#' && !visited[i][j]){
                dfs(i, j);
                ans++;
            }
        }
    }
 
    cout<<ans<<endl;
    
    return 0;
}
