#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

class Node{
    public:
        int no_ranges;
        map<int,int> mp;
};

// int findConsecutive(set<int> &st){
//     int cnt=0;
//     int prev = -1;
//     for (auto num:st){
//         if (num!= (prev+1))cnt++;
//         prev = num;
//     }
//     return cnt;
// }

void buildSegTree(vector<int> &a,vector<Node> &SegTree,int idx,int low,int high){
    if (low == high){
        SegTree[idx].no_ranges = 1;
        SegTree[idx].nums.insert(a[low]);
        return ;
    }

    int mid = ((low+high)>>1);
    buildSegTree(a,SegTree,(2*idx)+1,low,mid);
    buildSegTree(a,SegTree,(2*idx)+2,mid+1,high);
    SegTree[idx].nums = SegTree[(2*idx)+1].nums;
    SegTree[idx].nums.insert(SegTree[(2*idx)+2].nums.begin(),SegTree[(2*idx)+2].nums.end());
    SegTree[idx].no_ranges = findConsecutive(SegTree[idx].nums);

    return ;
}

int query(vector<int> &SegTree,int idx,int low,int )

int get_ans(int n,vector<int> &a,int q,int two,vector<vector<int>> &queries){
    vector<Node> SegTree(4*n);
    buildSegTree(a,SegTree,0,0,n-1);

    int cnt=0;
    for (int i=0;i<q;i++){
        cnt += query()
    }
    // for (int i=0;i<(4*n);i++){
    //     cout << i << " " << SegTree[i].no_ranges << "\n";
    // }
    // int cnt=0;
    // for (int i=0;i<q;i++){
    //     set<int> st;
    //     for (int j=queries[i][0];j<=queries[i][1];j++){
    //         st.insert(a[j]);
    //     }
    //     cnt+=findConsecutive(st);
    // }
    // return cnt;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    vector<vector<int>> queries;
    for (int i=0;i<q;i++){
        vector<int> a(2);
        cin >> a[0] >> a[1];
        queries.pb(a);
    }
    cout << get_ans(n,arr,q,2,queries);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}