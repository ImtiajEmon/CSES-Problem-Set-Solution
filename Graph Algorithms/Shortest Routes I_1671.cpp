#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int nmax = 1e6 + 10;
const lli inf = 1e18 + 10;
vector<pair<lli, lli>> adj[nmax]; // adj[i] = list of neighbour of i with cost
// pair(cost, node)
lli dist[nmax];

void dijkstra(int source, int n){
    // make all distance to infinity
    for(int i = 1; i <= n; i++)
        dist[i] = inf;

    dist[source] = 0;

    priority_queue< pair<lli, lli> , vector<pair<lli, lli>> , greater<pair<lli, lli>> > pq; // (cost, node)

    pq.push({0, source});

    while(!pq.empty()){
        lli cost = pq.top().first;
        lli u = pq.top().second;

        pq.pop();

        if(dist[u] != cost) continue;

        for(auto q: adj[u]){
            lli neighbour = q.second;
            lli neighbour_cost = q.first;

            if(cost + neighbour_cost < dist[neighbour]){

                dist[neighbour] = cost + neighbour_cost;
                pq.push({dist[neighbour], neighbour});
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
        lli a, b, c;
        cin>>a>>b>>c;

        // For directed graph
        adj[a].push_back({c, b}); // or adj[u].push_back(make_pair(v, c));
    }

    dijkstra(1, n); // dijkstra(source, number of node)

    for(int i = 1; i<=n; i++){
        cout<<dist[i]<<' ';
    }

    return 0;
}
