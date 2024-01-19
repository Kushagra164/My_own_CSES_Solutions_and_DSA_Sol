#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

int BinaryToInt(string s,int n){
    string temp = "";
    int n1=s.size();
    for (int i=n1-n;i<n1;i++){
        temp.pb(s[i]);
    }
    int num = 0;
    for (int i=0;i<n;i++){
        if (temp[i] == '1'){
            num += (1<<(n-1-i));
        }
    }
    return num;
}

void solve() {
    int n,m;
    cin >> n;
    m = (1<<n);
    // Algo 1
    // Start with 0 then try to increase the sequence
    vector<bool> vis(m,0);
    string ans = "";
    for (int i=0;i<n;i++){
        ans.pb('0');
    }
    vis[0]=1;
    for (int i=0;i<m-1;i++){
        int num1 = BinaryToInt(ans+"1",n);
        int num0 = BinaryToInt(ans+"0",n);
        if (!vis[num1]){
            ans.pb('1');
            vis[num1]=1;
        }
        else{
            if (vis[num0]) break;
            ans.pb('0');
            vis[num0]=1;
        }
    }
    cout << ans;

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}