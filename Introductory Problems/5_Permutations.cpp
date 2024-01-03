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
    if (n == 1){
        cout << 1;
        return ;
    }
    if (n<=3){
        cout << "NO SOLUTION";
        return ;
    }

    if (n == 4){
        cout << "3 1 4 2" ;
        return ; 
    }
    for (int i=1;i<=n;i+=2){
        cout << i << " ";
    }
    for (int i=2;i<=n;i+=2){
        cout << i << " ";
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}