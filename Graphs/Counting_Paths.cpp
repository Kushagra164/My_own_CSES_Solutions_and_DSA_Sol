#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

class LCA{
        vector<int> heights,eulerTour,firstSeen,SegTree;
 
        void dfs(int node,vector<int> adj_list[],int currHeight){
            firstSeen[node] = eulerTour.size();
            eulerTour.push_back(node);
            heights.push_back(currHeight);
            heightVsNode[currHeight].push_back(node);
            for (auto child:adj_list[node]){
                if (child != parent[node]){
                    parent[child] = node; 
                    dfs(child,adj_list,currHeight+1);
                    eulerTour.push_back(node);
                    heights.push_back(currHeight);
                }
            }
            return ;
        }
 
        void buildSegTree(int idx,int low,int high){
            if (high == low){
                SegTree[idx] = low;
                return ;
            }
            int mid = (low+high)>>1;
            buildSegTree((2*idx)+1,low,mid);
            buildSegTree((2*idx)+2,mid+1,high);
            int height1 = heights[SegTree[(2*idx)+1]];
            int height2 = heights[SegTree[(2*idx)+2]];
            if (height1<height2) SegTree[idx] = SegTree[(2*idx)+1];
            else SegTree[idx] = SegTree[(2*idx)+2];
            return ;
        }
 
        int querySeg(int idx,int low,int high,int l,int r){
            if (l>high || r<low) return INT_MAX;
            if (low>=l && high<=r) return SegTree[idx];
            int mid = (low+high)>>1;
            int idx1 = querySeg((2*idx)+1,low,mid,l,r);
            int idx2 = querySeg((2*idx)+2,mid+1,high,l,r);
            if (idx1 == INT_MAX) return idx2;
            if (idx2 == INT_MAX) return idx1;
            int height1 = heights[idx1];
            int height2 = heights[idx2];
            if (height1<height2) return idx1;
            return idx2;
        }
 
    public:
        vector<int> parent;
        vector<vector<int>> heightVsNode;
        LCA(vector<int> adj_list[],int n){
            firstSeen.resize(n+1,-1);
            parent.resize(n+1,0);
            heightVsNode.resize(n);
            dfs(1,adj_list,1);
            int sz_eulerTour = eulerTour.size();
            SegTree.resize(4*sz_eulerTour);
            buildSegTree(0,0,sz_eulerTour-1);
        }
        int query(int node1,int node2){
            if (firstSeen[node2] < firstSeen[node1]) swap(node1,node2);
            int sz_eulerTour = eulerTour.size();
            int idx = querySeg(0,0,sz_eulerTour-1,firstSeen[node1],firstSeen[node2]);
            return eulerTour[idx];
        }
};

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> adj_list[n+1];
    int node1,node2;
    for(int i=1;i<=n-1;i++) {
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
    
    LCA lca(adj_list,n);
    vector<int> vals(n+1,0);
    
    for (int i=0;i<m;i++){
        cin >> node1 >> node2;
        vals[node1]++;
        vals[node2]++;
        int lc = lca.query(node1,node2);
        // cout << node1 << " " << node2 << " " << lc <<"\n";
        vals[lc]--;
        if (lc != 1) vals[lca.parent[lc]]--;
    }
    // cout << "works\n";
    // Up traversal
     
    vector<bool> vis(n+1,0);
    for (int i=n-1;i>=0;i--){
        for (int j=0;j<lca.heightVsNode[i].size();j++){
            int node = lca.heightVsNode[i][j];
            vis[node]=1;
            for (auto child:adj_list[node]) if (!vis[child]) vals[child]+=vals[node];
        }
    }

    for (int i=1;i<=n;i++) cout << vals[i] << " ";
    
}

signed main() {
    solve();
    return 0;
}