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
    map<char,int> mp;
    for (int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    int cnteven=0,cntodd=0;
    char x;
    string ans,ans1;
    for (auto i:mp){
        if((i.second)%2==0) {
            cnteven++;
            for (int j=0;j<i.second/2;j++) ans.pb(i.first);
        }
        else {
            cntodd++;
            x=i.first;
        }    
    }
    if (cntodd>1) {
        cout << "NO SOLUTION";
        return ;
    }
    ans1=ans;
    reverse(ans1.begin(),ans1.end());
    for (int i=0;i<mp[x];i++) ans.pb(x);
    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}