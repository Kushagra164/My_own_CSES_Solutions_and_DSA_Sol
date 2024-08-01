#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void buildSegTree(vector<int> &arr,vector<pair<long long,int>> &SegTree,int low,int high,int idx){
    if (high == low){
        SegTree[idx] = {1LL*arr[low],0};
        return ;
    }
    int mid = (high+low)>>1;
    buildSegTree(arr,SegTree,low,mid,(2*idx)+1);
    buildSegTree(arr,SegTree,mid+1,high,(2*idx)+2);
    SegTree[idx].first = SegTree[(2*idx)+1].first + SegTree[(2*idx)+2].first;
    SegTree[idx].second = 0;

    return ;
}

void update(vector<pair<long long,int>> &SegTree,int idx,int low,int high,int l,int r){
    if (l>high || r<low ) return ;
    if (low>=l && high<=r) {
        SegTree[idx].second++;
        return ;
    }
    int mid = (low+high)>>1;
    update(SegTree,(2*idx)+1,low,mid,l,r);
    update(SegTree,(2*idx)+2,mid+1,high,l,r);
    SegTree[idx].second++;

    return ;
}

long long findQuerySum(vector<pair<long long,int>> &SegTree,int idx,int low,int high,int l,int r){
    if (l>high || r<low) return 0;
    if ()
}

vector<long long> RangeSumDigits(int n,vector<int> &arr,int Q,vector<vector<int>> &Queries){
    vector<pair<long long,int>> SegTree(4*n);
    buildSegTree(arr,SegTree,0,n-1,0);
    vector<long long > ans;
    for (int i=0;i<Q;i++){
        if (Queries[i][0] == 1){
            update(SegTree,0,0,n-1,Queries[i][1]-1,Queries[i][2]-1);
        }
        else if (Queries[i][0] == 2){
            ans.push_back(findQuerySum(SegTree,0,0,n-1,Queries[i][1]-1,Queries[i][2]-1));
        }
    }
    return ans;
}

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<vector<int>> queries(q,vector<int>(3));
    rep(i,0,n) {
        cin >> arr[i];
    }
    rep(i,0,q){
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    auto ans = RangeSumDigits(n,arr,q,Queries);
    for (auto x:ans) cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}