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
// First resize the useAgain vector to the size of the matrix

int findPow(int num,int pow){
    num %= MOD;
    int res = 1;
    while (pow > 0) {
        if (pow & 1)
            res = (res*num) % MOD;
        num = (num*num) % MOD;
        pow >>= 1;
    }
    return res;
}

void solve() {
    int n,f1,f2,f3,c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    vector<vector<int>> A(3,vector<int> (3,1));
    useAgain.resize(3,vector<int>(3,0));
    A[1][1]=0;
    A[1][2]=0;
    A[2][0]=0;
    A[2][2]=0;
    auto temp = findMatrixMult(A,n-3,3);
    int x = temp[0][0];
    int y = temp[0][1];
    int z = temp[0][2];
    // cout << x << y << z;
    int c_pow = ((3*x)%MOD + (2*y)%MOD + z - n + MOD)%MOD;
    int ans1 = findPow(c,c_pow);
    int ans2 = findPow(f3,x);
    int ans3 = findPow(f2,y);
    int ans = findPow(f1,z);
    cout << (((ans1*ans2)%MOD)*((ans*ans3)%MOD))%MOD << "\n";

    return ;  
}

signed main() {
    solve();
    return 0;
}

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

//Code By Kush

// Ordered_set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

// ll primeornot(ll n) {
//     ll rootn = sqrt(n);
//     for (ll i = 2; i <= rootn; i++) if (n % i == 0) return 0;
//     return 1;
// }
// int count_digit(int number) {
//     return int(log10(number) + 1);             //log (number) to the base 10
// }
// bool number_is_power_of_2_or_not(int N){
//     if (!(N&(N-1))) return true;
//     return false;
// }
// bool count_set_bits(int n){
//     return __builtin_popcount(n);
// }
// bool is_palindrome(string s,int fidx,int lidx){
//      while(fidx<lidx){
//          if (s[fidx]==s[lidx]){ 
//              fidx++;
//              lidx--;
//          }
//          else return false;
//      }
//      return true;
// }
// ll mpow(ll a, ll b) {
//     ll ans = 1;
//     a = a % MOD;
//     while (b > 0) {
//         if (b & 1) ans = (ans * a) % MOD;
//         b = b >> 1;
//         a = (a * a) % MOD;
//     }
//     return ans;
// }
// void find_factors(vector<int>&a,int n){
//     int i;
//     for (i = 1; i * i < n; i++) if (n % i == 0) a.pb(i);
//     if (i - (n / i) == 1) i--;
//     for (; i >= 1; i--) if (n % i == 0) a.pb(n/i);
// }

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }
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