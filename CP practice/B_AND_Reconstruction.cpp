#include <bits/stdc++.h>
#define repl(i,a,b) for(long long i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
typedef std::vector <int> vi;
typedef std::vector <long long> vll;
typedef std::vector <std::string> vs;
typedef std::vector <vi> vvi;
typedef std::vector <vll> vvl;
typedef std::vector <vs> vvs;
typedef std::pair <int, int> pi;
typedef std::pair <long long, long long> pll;
#define all(a) a.begin(),a.end()
#define debug(n) cout << #n << " : " << n << '\n'
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n'

#define MOD 1000000007

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n),arr1(n-1);
    rep(i,0,n-1) {
        cin >> arr1[i];
    }
    arr[0] = arr1[0];
    arr[n-1] = arr1[n-2];
    for (int i=1;i<n-1;i++){
        arr[i] = arr1[i-1]|arr1[i];
    }
    for (int i=1;i<n;i++){
        if ((arr[i]&arr[i-1]) != arr1[i-1]) {
            cout << -1 << "\n";
            return ;
        }
    }
    for (auto x:arr) cout << x << " ";
    cout << "\n";

    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Test; cin >> Test;
    while(Test--) {
        solve();
    }
    return 0;
}