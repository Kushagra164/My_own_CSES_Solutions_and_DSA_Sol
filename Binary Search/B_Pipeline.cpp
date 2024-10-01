#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define int long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

bool isPossible(int n,int mid,int k){
    int mx = (2*k*mid)-(mid*mid) - mid + 2;
    mx = mx>>1LL;
    return n<=mx ? true : false;
}

void solve() {
    int n,k;
    cin >> n >> k;
    if (n == 1){
        cout << 0;
        return ;
    }
    else if (n <= k){
        cout << 1;
        return ;
    }
    int mx = ((k)*(k-1))>>1LL;
    mx++;
    if (n>mx) {
        cout << -1 ;
        return;
    }
    
    int low = 1,high = k-1,mid ;
    while(low<high){
        mid = (low+high)>>1LL;
        if (isPossible(n,mid,k)) high=mid;
        else low = mid+1;
    }
    cout << low ;

    return ;
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}