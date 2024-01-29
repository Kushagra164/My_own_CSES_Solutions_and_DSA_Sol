#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

// Input: n,k
// Output: string containing the sequence

int ConvertToInt(string s,int n,int k){
    string temp = "";
    int n1=s.size();
    for (int i=n1-n;i<n1;i++){
        temp.pb(s[i]);
    }
    int num = 0;
    for (int i=0;i<n;i++){
        num += (temp[i]-'0')*(pow(k,n-1-i));
    }
    return num;
}

void solve() {
    int n,k,m;
    cin >> n >> k;
    m = pow(k,n);

    // Algo 
    // Start with 0 then try to increase the sequence
    // by adding the largest possible number to the sequence
    // if num is already visited then add lesser and so on to get the sequence

    // Worst Case Complexity is O(n*pow(k,n+1)) 

    vector<bool> vis(m,0);
    string ans = "";
    for (int i=0;i<n;i++){
        ans.pb('0');
    }
    vis[0]=1;
    for (int i=0;i<m-1;i++){
        for (int j=k-1;j>=0;j--){
            int num = ConvertToInt(ans+to_string(j),n,k);
            if (!vis[num]){
                ans = ans + to_string(j);
                vis[num]=1;
                break;
            }
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