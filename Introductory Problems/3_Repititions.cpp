#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void solve() {
    string s;
    cin >> s;
    int cnt = 1;
    int n = s.size();
    for (int i=1;i<n;i++){
        int cnt_temp = 1;
        while(s[i] == s[i-1]) {
            cnt_temp++;
            i++;
        }
        cnt = max(cnt,cnt_temp);
    }
    cout << cnt ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}