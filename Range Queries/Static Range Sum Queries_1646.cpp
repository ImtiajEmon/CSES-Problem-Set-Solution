#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int nmax = 1e6+10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin>>n>>q;

    lli pref_sum[n+10] = {};
    for(int i=1; i<=n; i++){
        int num; cin>>num;
        pref_sum[i] = num + pref_sum[i-1];
    }

    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<pref_sum[b] - pref_sum[a-1]<<endl;
    }

    return 0;
}
