#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define int long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

class info{
    public:
        int startDay;
        int endDay;
        int reward;
};

static bool cmp(info &a,info &b){
    if (a.startDay == b.startDay) return a.endDay <= b.endDay ;
    return a.startDay < b.startDay;
}

int findNxt(vector<info> &arr,int idx){
    int left = idx+1,right = (int)arr.size()-1,mid;
    while(left<right){
        mid = (left+right)>>1;
        if (arr[mid].startDay > arr[idx].endDay) right = mid;
        else left = mid+1;
    }
    if (arr[idx].endDay >= arr[left].startDay) return (int)arr.size();
    // cout << "idx: " << idx << " left: " << left << " right: " << right << " mid: " << mid << "\n";
    return left;                                        
}

int func(vector<info> &arr,int idx,vector<int> &dp){
    if (idx == (int)arr.size()) return 0;
    if (dp[idx] != -1) return dp[idx];
    int notpick = func(arr,idx+1,dp);
    int nxt_idx = findNxt(arr,idx);
    int pick = arr[idx].reward + func(arr,nxt_idx,dp);
    return dp[idx] = max(pick,notpick);
}

void solve() {
    int n;
    cin >> n;
    vector<info> arr(n);
    rep(i,0,n) {
        cin >> arr[i].startDay >> arr[i].endDay >> arr[i].reward;
    }
    sort(arr.begin(),arr.end(),cmp);
    vector<int> dp(n,-1);
    cout << func(arr,0,dp);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}