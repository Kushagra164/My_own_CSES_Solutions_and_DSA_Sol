#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush
unordered_set<int> emp,usefull;

class Node{
    public:
        unordered_set<int> elements;
};

void buildSegTree(vector<int> &arr,vector<Node> &SegTree,int idx,int low,int high){
    if (low == high){
        SegTree[idx].elements.insert(arr[low]);
        return ;
    }
    int mid = (low+high)>>1;
    buildSegTree(arr,SegTree,(2*idx)+1,low,mid);
    buildSegTree(arr,SegTree,(2*idx)+2,mid+1,high);
    SegTree[idx].elements.insert(SegTree[(2*idx)+1].elements.begin(),SegTree[(2*idx)+1].elements.end());
    SegTree[idx].elements.insert(SegTree[(2*idx)+2].elements.begin(),SegTree[(2*idx)+2].elements.end());

    return ;
}

void query(vector<Node> &SegTree,int idx,int low,int high,int l,int r){
    if (low>r || high<l) return ;
    if (low>=l && high<=r) {
        usefull.insert(SegTree[idx].elements.begin(),SegTree[idx].elements.end());
        return ;
    }
    int mid = (low+high)>>1;
    query(SegTree,(2*idx)+1,low,mid,l,r);
    query(SegTree,(2*idx)+2,mid+1,high,l,r);
    return ;
}

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    rep(i,0,n)  cin >> arr[i];
    vector<Node> SegTree(4*n);
    buildSegTree(arr,SegTree,0,0,n-1);
    
    while(q--){
        int l,r;
        cin >> l >> r;
        usefull.clear();
        query(SegTree,0,0,n-1,l-1,r-1);
        cout << (int)usefull.size() << "\n";
    }
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}