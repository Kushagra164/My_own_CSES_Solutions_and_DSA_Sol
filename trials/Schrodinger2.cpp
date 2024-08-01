#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void TryFill(int x,int y,vector<vector<int>> &mat,int mx,int w,int h){
    for (int i=x;i<min(w,i+mx);i++) mat[i][y] = i-x;
    for (int j=y;j<min())
}

bool canFill(int w,int h,int n,int mx){
    vector<vector<int>> mat(h,vector<int>(w,-1));
    bool ans = false; 
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            Tryfill(i,j,mat,mx,w,h);
            ans = ans|canFill2(mat,w,h,n-1,mx);
            fill(mat.begin(),mat.end(),-1);
        }
    }
    return ans;
}

int findMinDistance(int w,int h,int n){
    if (n>=(h*w)) return 0;
    int low = 1,high = 14,mid;
    // vector<vector<int>> mat(h,vector<int> (w,-1));
    while(low<high){
        mid = (low+high)>>1;
        if (canFill(w,h,n,mid)) high = mid;
        else low = mid+1;
    }
    return low;
}

void solve() {
    int w,h,n;
    cin >> w >> h >> n;
    cout << findMinDistance(w,h,n) ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}