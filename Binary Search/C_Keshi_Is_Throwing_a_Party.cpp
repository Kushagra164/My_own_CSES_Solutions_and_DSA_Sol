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

bool isPossible(vector<pair<int,int>> &arr,int n,int mid){
    int y = 0;
    for (int i=0;i<n;i++){
        if (arr[i].second>=y && mid-y-1<=arr[i].first) y++;
        if (y == mid) return true; 
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    rep(i,0,n) {
        cin >> arr[i].first >> arr[i].second;
    }
    int low=1,high=n,mid,ans=1;
    while(low<high){
        mid = (low+high)>>1;
        if (isPossible(arr,n,mid)) {
            ans = mid;
            low = mid+1;
        }
        else high = mid;
    }
    if (isPossible(arr,n,low)) ans = low;
    cout << ans << "\n";
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