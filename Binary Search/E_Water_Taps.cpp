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

struct info{
    int mx_quantity;
    int temp;
};

static bool cmp(info &a,info &b){
    return a.temp<=b.temp;
}

bool isGreater(vector<info> &arrInfo,int WaterSum,int n,int AvgTemp){
    int initialSum = WaterSum;
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += (min(WaterSum,arrInfo[i].mx_quantity)*arrInfo[i].temp);
        WaterSum -= min(WaterSum,arrInfo[i].mx_quantity);
        if (WaterSum == 0) break;
    }
    return sum>=(AvgTemp*initialSum) ? false : true ;
}

bool isMatchingExactly(vector<info> &arrInfo,int WaterSum,int n,int AvgTemp){
    int initialSum = WaterSum;
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += (min(WaterSum,arrInfo[i].mx_quantity)*arrInfo[i].temp);
        WaterSum -= min(WaterSum,arrInfo[i].mx_quantity);
        if (WaterSum == 0) break;
    }

    return sum==(AvgTemp*initialSum) ? true : false ;
}

double findExact(vector<info> arrInfo,int WaterSum,int n,int AvgTemp){
    int initialSum = WaterSum;
    int sum = 0,last = 0;
    for (int i=0;i<n;i++){
        sum += (min(WaterSum,arrInfo[i].mx_quantity)*arrInfo[i].temp);
        int temp = arrInfo[i].mx_quantity;
        arrInfo[i].mx_quantity -= min(WaterSum,temp);
        WaterSum -= min(WaterSum,temp);
        last = i;
        if (WaterSum == 0) break;
    }
    if (arrInfo[last].mx_quantity == 0) {
        last++;
        if (last == n) return 0.0;
    }
    double ans = (double)(((double)(initialSum*AvgTemp-sum))/(double)(arrInfo[last].temp-AvgTemp));
    return ans+(double)initialSum;
}

void solve() {
    int n,T;
    cin >> n >> T;
    vector<info> arrInfo(n);
    int low = 0,mid,high=0,checkhigh;
    rep(i,0,n) {
        cin >> arrInfo[i].mx_quantity;
        high+= arrInfo[i].mx_quantity;
    }
    checkhigh = high;
    rep(i,0,n) cin >> arrInfo[i].temp;
    sort(arrInfo.begin(),arrInfo.end(),cmp);
    while(low<high){
        mid = (low+high)>>1;
        if (isGreater(arrInfo,mid,n,T)) low = mid+1;
        else high = mid;
    }
    double ans = 0;
    if (isMatchingExactly(arrInfo,low,n,T)) ans = double(low) ;
    else if (low != checkhigh) ans = findExact(arrInfo,low-1,n,T) ;
    
    cout << setprecision(15) << ans ;

    return ; 
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}