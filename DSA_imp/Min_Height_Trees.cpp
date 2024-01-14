#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void solve() {
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // rep(i,0,n) {
    //     cin >> arr[i];
    // }
    char a = 'P'; 
    char b = 'x'; 
    char c = (a & b) + '*'; 
    char d = (a | b) - '-'; 
    char e = (a ^ b) + '+'; 
    printf("%c %c %c\n", c, d, e);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int test;
    // while(test--) solve();
    solve();
    return 0;
}