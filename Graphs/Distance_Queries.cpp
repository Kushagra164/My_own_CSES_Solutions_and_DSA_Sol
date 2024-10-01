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
 
        void dfs(int node,vector<int> adj_list[],int par,int currHeight){
            firstSeen[node] = eulerTour.size();
            eulerTour.push_back(node);
            heights.push_back(currHeight);
            for (auto child:adj_list[node]){
                if (child != par){
                    dfs(child,adj_list,node,currHeight+1);
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
        LCA(vector<int> adj_list[],int n){
            firstSeen.resize(n+1,-1);
            dfs(1,adj_list,0,1);
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
        int findDistance(int node1,int node2){
            int lca = query(node1,node2);
            return abs(heights[firstSeen[node1]]-heights[firstSeen[lca]])+abs(heights[firstSeen[node2]]-heights[firstSeen[lca]]);
        }
};
 
void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> adj_list[n+1];
    rep(i,0,n-1) {
        int node1,node2;
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
    LCA lca(adj_list,n);
    while(q--){
        int node1,node2;
        cin >> node1 >> node2;
        cout << lca.findDistance(node1,node2) << "\n";
    }
 
    return ;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}