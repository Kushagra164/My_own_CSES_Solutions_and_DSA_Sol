#include <bits/stdc++.h>
#define repl(i,a,b) for(long long i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define int long long
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
    int n,m;
    cin >> n >> m;
    // vector<int> arr1(n),arr2(m);
    multiset<int> mst1,mst2;
    rep(i,0,n) {
        int x;
        cin >> x;
        mst1.insert(x);
    }
    rep(i,0,m){
        int y;
        cin >> y;
        mst2.insert(y);
    }
    int ans = 0;
    while(mst1.size()>0){
        auto itr1 = mst1.begin();
        int n1 = *itr1;
        auto itr2 = mst1.rbegin(); 
        int n2 = *itr2;
        auto itr3 = mst2.begin();
        int m1 = *itr3;
        auto itr4 = mst2.rbegin(); 
        int m2 = *itr4;

        if (abs(m2-n1)>=abs(m1-n2)){
            ans += abs(m2-n1);
            mst1.erase(itr1);
            mst2.erase(mst2.find(m2));
        }
        else{
            ans += abs(m1-n2);
            mst1.erase(mst1.find(n2));
            mst2.erase(itr3);
        }
    }
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