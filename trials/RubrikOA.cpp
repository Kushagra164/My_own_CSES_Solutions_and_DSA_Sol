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
    int sum = 0;
    int lazy_update = 0;
    vector<int> cnt_bits;
};

void buildSegTree(vector<int> &arr,vector<Node> &SegTree,int idx,int low,int high){
    if (low == high){
        SegTree[idx].sum = arr[low];
        SegTree[idx].cnt_bits.resize(32,0);
        for (int i=0;i<32;i++){
            if ((arr[low]>>i)&1) SegTree[idx].cnt_bits[i]++;
        }
        return ;
    }
    int mid = (low+high)>>1;
    buildSegTree(arr,SegTree,(2*idx)+1,low,mid);
    buildSegTree(arr,SegTree,(2*idx)+2,mid+1,high);
    SegTree[idx].sum = SegTree[(2*idx)+1].sum + SegTree[(2*idx)+2].sum;
    SegTree[idx].cnt_bits.resize(32,0);
    for (int i=0;i<32;i++) SegTree[idx].cnt_bits[i] = SegTree[(2*idx)+1].cnt_bits[i] + SegTree[(2*idx)+2].cnt_bits[i];
    return ; 
}

void update(vector<Node> &SegTree,int idx,int low,int high,int l,int r,int z){
    if (low == high && low>=l && low<=r){
        SegTree[idx].sum = SegTree[idx].sum^SegTree[idx].lazy_update^z;
        for (int i=0;i<32;i++){
            if ((SegTree[idx].sum>>i)&1) SegTree[idx].cnt_bits[i]=1;
        }
        SegTree[idx].lazy_update=0;
        return ;
    }
    if (low>r || high<l) return ;
    if (low >=l && high<=r){
        // update lazy
        z ^= SegTree[idx].lazy_update;
        SegTree[idx].lazy_update = 0;
        SegTree[(2*idx)+1].lazy_update ^= z;
        SegTree[(2*idx)+2].lazy_update ^= z;
        // update sum
        int sz = high-low+1;
        int num = 1;
        SegTree[idx].sum=0;
        for (int i=0;i<32;i++){
            if (!((z>>i)&1)){
                SegTree[idx].sum += (num*SegTree[idx].cnt_bits[i]);
            }
            else if ((z>>i)&1){
                SegTree[idx].sum += (num*(sz-SegTree[idx].cnt_bits[i]));
                SegTree[idx].cnt_bits[i] = sz - SegTree[idx].cnt_bits[i];
            }
            num *= 2;
        }
        return ;
    }
    int mid = (high+low)>>1;
    z ^= SegTree[idx].lazy_update;
    SegTree[idx].lazy_update = 0;
    update(SegTree,(2*idx)+1,low,mid,l,r,z);
    update(SegTree,(2*idx)+2,mid+1,high,l,r,z);
    SegTree[idx].sum = SegTree[(2*idx)+1].sum + SegTree[(2*idx)+2].sum;
    for (int i=0;i<32;i++) SegTree[idx].cnt_bits[i] = SegTree[(2*idx)+1].cnt_bits[i] + SegTree[(2*idx)+2].cnt_bits[i];
    return ;
}

int query(vector<Node> &SegTree,int idx,int low,int high,int l,int r){
    if (low == high && low>=l && low<=r){
        if (SegTree[idx].lazy_update == 0) return SegTree[idx].sum;
        SegTree[idx].sum = SegTree[idx].sum^SegTree[idx].lazy_update;
        for (int i=0;i<32;i++){
            if ((SegTree[idx].sum>>i)&1) SegTree[idx].cnt_bits[i]=1;
        }
        SegTree[idx].lazy_update=0;
        return SegTree[idx].sum;
    }
    if (l>high || low>r) return 0;
    if (low>= l && high<=r){
        if (SegTree[idx].lazy_update == 0) return SegTree[idx].sum;
        // update lazy
        int z = SegTree[idx].lazy_update;
        SegTree[idx].lazy_update = 0;
        SegTree[(2*idx)+1].lazy_update ^= z;
        SegTree[(2*idx)+2].lazy_update ^= z;
        // update sum
        int sz = high-low+1;
        int num = 1;
        SegTree[idx].sum=0;
        for (int i=0;i<32;i++){
            if (!((z>>i)&1)){
                SegTree[idx].sum += (num*SegTree[idx].cnt_bits[i]);
            }
            else if ((z>>i)&1){
                SegTree[idx].sum += (num*(sz-SegTree[idx].cnt_bits[i]));
                SegTree[idx].cnt_bits[i] = sz - SegTree[idx].cnt_bits[i];
            }
            num *= 2;
        }
        return SegTree[idx].sum;
    }
    int mid = (low+high)>>1;
    if (SegTree[idx].lazy_update){
        SegTree[(2*idx)+1].lazy_update ^= SegTree[idx].lazy_update;
        SegTree[(2*idx)+2].lazy_update ^= SegTree[idx].lazy_update;
        SegTree[idx].lazy_update=0;
    }
    return query(SegTree,(2*idx)+1,low,mid,l,r)+query(SegTree,(2*idx)+2,mid+1,high,l,r);
}

void solve() {
    int n,q;
    cin >> n;
    vector<int> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }
    vector<Node> SegTree(4*n);
    buildSegTree(arr,SegTree,0,0,n-1);
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if (type == 1){
            int l,r;
            cin >> l >> r;
            cout << query(SegTree,0,0,n-1,l-1,r-1) << "\n";
        }
        else{
            int l,r,z;
            cin >> l >> r >> z;
            update(SegTree,0,0,n-1,l-1,r-1,z);
        }
    }

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}