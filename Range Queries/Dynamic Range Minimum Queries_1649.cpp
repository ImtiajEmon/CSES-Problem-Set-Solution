#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int nmax = 1e6+10;
lli seg_tree[4*nmax];
lli arr[nmax];

void build(int node_id, int l, int r){
    if(l == r){   //Base case
        seg_tree[node_id] = arr[l];
        return;
    }

    int mid = (l+r)/2;
    build(node_id*2, l, mid); //Left part
    build(node_id*2+1, mid+1, r); //Right Part

    seg_tree[node_id] = min(seg_tree[node_id*2], seg_tree[node_id*2+1]);
    return;
}

void update(int node_id, int l, int r, int idx, int val){
    if(l == r){ //base case or leaf node
        seg_tree[node_id] = val;
        return;
    }
    int mid = (l+r)/2;
    if(idx <= mid) //left child
        update(node_id*2, l, mid, idx, val);
    else
        update(node_id*2+1, mid+1, r, idx, val);

    seg_tree[node_id] = min(seg_tree[node_id*2], seg_tree[node_id*2+1]);
    return;
}

lli query(int node_id, int l, int r, int a, int b){
    //case1: range (l, r) is fully inside of given range(a,b)
    if(a <= l && b >= r) return seg_tree[node_id];
    //case 2: range (l, r) is fully outside of given range(a,b)
    else if(b < l || a > r) return 1e10+100; ///return big num bcz we need min
    //case 3: partially outside & inside
    else{
        int mid = (l+r)/2;
        lli left_val = query(node_id*2, l, mid, a, b);
        lli right_val = query(node_id*2+1, mid+1, r, a, b);
        return min(left_val, right_val);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    ///Now we build the segment tree by build function; Time = O(n)
    build(1, 1, n);

    while(q--){
        int type; cin>>type;
        if(type == 1){
            int k, u; cin>>k>>u;
            update(1, 1, n, k, u);
        }
        else{
            int a, b; cin>>a>>b;
            cout<<query(1, 1, n, a, b)<<endl;
        }
    }

    return 0;
}
