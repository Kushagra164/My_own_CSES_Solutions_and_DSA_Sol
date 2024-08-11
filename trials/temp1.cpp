#include <bits/stdc++.h>
using namespace std;

class DSU{
    public:
        vector<int> parent;
        int no_components;

        DSU(int n){
            no_components = n;
            for (int i=0;i<=n;i++) parent.push_back(i);
        }

        int findRoot(int node){
            if (parent[node] == node) return node;
            return parent[node] = findRoot(parent[node]);
        }

        void Union(int node1,int node2){
            int root1 = findRoot(node1);
            int root2 = findRoot(node2);
            if (root1 == root2) return ;
            if (root2>root1) swap(root1,root2);
            parent[root2] = root1;
            no_components--;
            return ; 
        }
};

bool cmp(vector<int> &a,vector<int> &b){
    return a[2]>=b[2];
}

int solve(int n,vector<vector<int>> &edges) {
    sort(edges.begin(),edges.end(),cmp);
    priority_queue<int,vector<int>,greater<int>> pq;
    long long ans = 0;
    DSU ds(n);
    for (int i=0;i<n-1;i++){
        int root1 = ds.findRoot(edges[i][0]);
        int root2 = ds.findRoot(edges[i][1]);
        if (root1 == root2) ans += 1LL*edges[i][2];
        else ds.Union(root1,root2);
    }
    return ans;
}

signed main() {
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        vector<vector<int>> edges(n-1,vector<int> (3));
        for (int i=0;i<n-1;i++){
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }
        cout << solve(n,edges) << "\n";
    }
    return 0;
}