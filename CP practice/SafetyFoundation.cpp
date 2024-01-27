#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

bool isPossible(int n,int m,vector<int> &arr,priority_queue<int> &pq,int mid){
    vector<int> curr(n,0);
    for (int i=0;i<n;i++){
        int tp = pq.top();
        pq.pop();
        if(tp+curr[i]>=mid){
            int x = tp+curr[i]-mid;
            if(i<n-1 && arr[i]<=tp+curr[i]){
                curr[i+1] = x;
            }
            else return true;
        }
        else{
            return false;
        }
        
    }
}

int solve(int N,int M,vector<int> A,vector<int> B){
    int low = 0,high = 1e9,mid;
    // sort(B.begin(),B.end(),greater<int>());
    priority_queue<int> pq;
    for (int i=0;i<M;i++){
        pq.push(B[i]);
    }
    int ans = 0;
    while(low<=high){
        mid = (low+((high-low)>>1));
        if (isPossible(N,M,A,pq,mid)) {
            low = mid+1;
            ans = mid;
        }
        else {
            high = mid-1;
        }
    }
    return ans;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> arr(n),brr(m);
    rep(i,0,n) {
        cin >> arr[i];
    }
    rep(i,0,m){
        cin >> brr[i];
    }
    cout << solve(n,m,arr,brr);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}