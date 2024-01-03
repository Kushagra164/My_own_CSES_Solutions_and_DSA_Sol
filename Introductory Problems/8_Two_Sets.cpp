#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void solve() {
    ll n;
    cin >> n;
    ll sum=(n*(n+1))/2;
    if (sum%2==0) cout << "YES"<< "\n";
    else {
        cout << "NO";
        return ;
    }
    sum=sum/2;
    vector<ll> f,l;
    for (ll i=n;i>=1;i--){
        if (sum>=i){
            f.pb(i);
            sum-=i;
        }
        else l.pb(i);
    }
    if (f.size()!=0) {
        cout << f.size() <<"\n";
        for (int i=f.size()-1;i>=0;i--) cout << f[i] << " ";
        cout << "\n";
    }
    if (l.size()!=0){
        cout << l.size() << "\n";
        for (int i=l.size()-1;i>=0;i--) cout << l[i] << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}