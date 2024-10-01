#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

class DSU{
    public:
    vector<int> parent,nxt;
    
    DSU(int n){
        for (int i=0;i<=n;i++) {
            parent.push_back(i);
            nxt.push_back(i+1);
        }
    }
    int findRoot(int node){
        return parent[node] = (node == parent[node] ? node:findRoot(parent[node]));
    }
    void Union(int node1,int node2){
        int root1 = findRoot(node1);
        int root2 = findRoot(node2);
        if (root1 == root2) return ;
        if (root1 > root2) swap(root1,root2);
        parent[root2] = root1;

        return ;
    }
};

void solve() {
    int n,q,op,a,b;
    cin >> n >> q;

    DSU ds(n);
    while(q--){
        cin >> op >> a >> b;
        if (op == 1){
            ds.Union(a,b);
        }
        else if (op == 2){
            int temp ;
            for (int i=a;i<=b;i=temp){
                ds.Union(i,b);
                temp = ds.nxt[i];
                ds.nxt[i] = ds.nxt[b];
            }
        }
        else if (op == 3){
            int root1 = ds.findRoot(a);
            int root2 = ds.findRoot(b);
            if (root1 == root2) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}