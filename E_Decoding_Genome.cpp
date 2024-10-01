#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define int long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

vector<vector<int>> useAgain;

vector<vector<int>> multiply(vector<vector<int>> &A,vector<vector<int>> &B,int m){
    for (int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            useAgain[i][j]=0;
            for (int k=0;k<m;k++){
                useAgain[i][j] = (useAgain[i][j] + ((A[i][k]*B[k][j])%MOD))%MOD;
            }
        }
    }
    return useAgain;
}

vector<vector<int>> findMatrixMult(vector<vector<int>> &A,int pow,int m){
    if (pow == 1) return A;
    auto temp = findMatrixMult(A,(pow>>1),m);
    temp = multiply(temp,temp,m);
    if (pow&1) temp = multiply(temp,A,m);
    return temp;
}

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> A(m,vector<int>(m,1));
    useAgain.resize(m,vector<int>(m,0));
    map<char,int> mp;
    for (int i=0;i<26;i++) mp['a'+i] = i;
    for (int i=0,j=26;i<26;i++,j++) mp['A'+i] = j;
    while(k--){
        string s;
        cin >> s;
        int i = mp[s[0]];
        int j = mp[s[1]];
        A[i][j]=0;
    }
    if (n == 1){
        cout << m ;
        return ;
    }
    auto temp = findMatrixMult(A,n-1,m);
    int ans = 0;
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            ans = (ans+temp[i][j])%MOD;
        }
    }
    cout << ans ;
    return;
}

signed main() {
    solve();
    return 0;
}