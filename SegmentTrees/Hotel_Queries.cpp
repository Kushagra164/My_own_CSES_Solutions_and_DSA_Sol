#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void buildSegTree(vector<int> &SegTree,vector<int> &arr,int idx,int low,int high){
    if (low == high){
        SegTree[idx] = arr[low];
        return ;
    }
    int mid = (low+high)>>1;
    buildSegTree(SegTree,arr,(2*idx)+1,low,mid);
    buildSegTree(SegTree,arr,(2*idx)+2,mid+1,high);
    SegTree[idx] = max(SegTree[(2*idx)+1],SegTree[(2*idx)+2]);
    return ; 
}

int query(vector<int> &SegTree,int idx,int low,int high,int val){
    int ans = 0;
    if (SegTree[idx] < val) return ans;
    if (low == high){
        SegTree[idx] -= val;
        return low+1;
    }
    int mid = (low+high)>>1;
    if (SegTree[(2*idx)+1] >= val) ans = query(SegTree,(2*idx)+1,low,mid,val);        
    else ans = query(SegTree,(2*idx)+2,mid+1,high,val);
    SegTree[idx] = max(SegTree[(2*idx)+1],SegTree[(2*idx)+2]);
    return ans;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    rep(i,0,n) cin >> arr[i];
    vector<int> SegTree(4*n);
    buildSegTree(SegTree,arr,0,0,n-1);
    while(m--){
        int val;
        cin >> val;
        cout << query(SegTree,0,0,n-1,val) << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}