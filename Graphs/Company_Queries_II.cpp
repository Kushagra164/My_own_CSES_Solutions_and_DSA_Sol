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
                SegTree[idx] = eulerTour[low];
                return ;
            }
            int mid = (low+high)>>1;
            buildSegTree((2*idx)+1,low,mid);
            buildSegTree((2*idx)+2,mid+1,high);
            SegTree[idx] = min(SegTree[(2*idx)+1],SegTree[(2*idx)+2]);
            return ;
        }

        int querySeg(int idx,int low,int high,int l,int r){
            if (l>high || r<low) return INT_MAX;
            if (low>=l && high<=r) return SegTree[idx];
            int mid = (low+high)>>1;
            return min(querySeg((2*idx)+1,low,mid,l,r),querySeg((2*idx)+2,mid+1,high,l,r));
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
            return querySeg(0,0,sz_eulerTour-1,firstSeen[node1],firstSeen[node2]);
        }
};

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> adj_list[n+1];
    rep(i,2,n+1) {
        int node;
        cin >> node;
        adj_list[node].push_back(i);
        adj_list[i].push_back(node);
    }
    LCA lca(adj_list,n);
    while(q--){
        int node1,node2;
        cin >> node1 >> node2;
        cout << lca.query(node1,node2) << "\n";
    }

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}