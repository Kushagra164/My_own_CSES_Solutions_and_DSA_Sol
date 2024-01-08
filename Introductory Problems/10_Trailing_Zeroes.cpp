#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007
 
using namespace std;
 
//Code By Kush
 
void solve() {
    int n;
    cin >> n;
    if (n<=4) {
        cout << 0;
        return ;
    }
    ll cnt=0;
    for (int i=5;i<=n;i=i*5){
        cnt+=(n/i);
    }
    cout << cnt ;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}