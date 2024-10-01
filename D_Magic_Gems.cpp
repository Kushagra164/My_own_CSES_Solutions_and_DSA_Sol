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
    int n,m;
    cin >> n >> m;
    if (n<m){
        cout << 1 ;
        return;
    }
    useAgain.resize(m,vector<int>(m,0));
    vector<vector<int>> A(m,vector<int>(m,0));
    A[0][0]=1;
    A[0][m-1]=1;
    for (int i=1;i<m;i++) A[i][i-1]=1;
    auto ansVec = findMatrixMult(A,n-m+1,m);
    int ans = 0;
    for (int i=0;i<m;i++) ans = (ans+ansVec[0][i])%MOD;
    cout << ans ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}