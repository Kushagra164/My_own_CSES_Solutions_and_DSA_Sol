// #include <bits/stdc++.h>
// #define repl(i,a,b) for(long long i = a; i < b; i++)
// #define rep(i,a,b) for(int i = a; i < b; i++)
// #define ll long long
// #define pb push_back
// typedef std::vector <int> vi;
// typedef std::vector <long long> vll;
// typedef std::vector <std::string> vs;
// typedef std::vector <vi> vvi;
// typedef std::vector <vll> vvl;
// typedef std::vector <vs> vvs;
// typedef std::pair <int, int> pi;
// typedef std::pair <long long, long long> pll;
// #define all(a) a.begin(),a.end()
// #define debug(n) cout << #n << " : " << n << '\n'
// #define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n'

// #define MOD 1000000007

// using namespace std;

// //Code By Kush

// // Ordered_set
// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>
// // using namespace __gnu_pbds;
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

// // ll primeornot(ll n) {
// //     ll rootn = sqrt(n);
// //     for (ll i = 2; i <= rootn; i++) if (n % i == 0) return 0;
// //     return 1;
// // }
// // int count_digit(int number) {
// //     return int(log10(number) + 1);             //log (number) to the base 10
// // }
// // bool number_is_power_of_2_or_not(int N){
// //     if (!(N&(N-1))) return true;
// //     return false;
// // }
// // bool count_set_bits(int n){
// //     return __builtin_popcount(n);
// // }
// // bool is_palindrome(string s,int fidx,int lidx){
// //      while(fidx<lidx){
// //          if (s[fidx]==s[lidx]){ 
// //              fidx++;
// //              lidx--;
// //          }
// //          else return false;
// //      }
// //      return true;
// // }
// // ll mpow(ll a, ll b) {
// //     ll ans = 1;
// //     a = a % MOD;
// //     while (b > 0) {
// //         if (b & 1) ans = (ans * a) % MOD;
// //         b = b >> 1;
// //         a = (a * a) % MOD;
// //     }
// //     return ans;
// // }
// // void find_factors(vector<int>&a,int n){
// //     int i;
// //     for (i = 1; i * i < n; i++) if (n % i == 0) a.pb(i);
// //     if (i - (n / i) == 1) i--;
// //     for (; i >= 1; i--) if (n % i == 0) a.pb(n/i);
// // }

// float solve() {
//     int n;
//     cin >> n;
//     vector<pair<int,int>> arr(n);
//     rep(i,0,n) {
//         cin >> arr[i].first >> arr[i].second;
//     }
//     float ans=FLT_MIN;
//     rep(i,0,n){
//         if (arr[i].second == 0) {
//             ans = (float)-1;
//             break;
//         }
//         ans = max(ans,(((float)(i+1))/((float)arr[i].second)));
//     }
//     if (ans == (float)-1) return (float)-1;
//     rep(i,1,n+1){
//         float val = (((float)i)/((float)ans)) ; 
//         if (val < (float)arr[i-1].first) return (float)-1;
//     }
//     return ans;

// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int Test,curr = 1; cin >> Test;
//     while(curr<=Test) {
//         cout << "Case #" << curr << ": " << solve() << "\n";
//         curr++;
//     }
//     return 0;
// }

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



using namespace std;

float solve(ifstream &fin) {
    int n;
    fin >> n;
    vector<pair<int,int>> arr(n);
    rep(i,0,n) {
        fin >> arr[i].first >> arr[i].second;
    }
    float ans = FLT_MIN;
    rep(i,0,n){
        if (arr[i].second == 0) {
            ans = (float)-1;
            break;
        }
        ans = max(ans,(((float)(i+1))/((float)arr[i].second)));
    }
    if (ans == (float)-1) return (float)-1;
    rep(i,1,n+1){
        float val = (((float)i)/((float)ans)); 
        if (val < (float)arr[i-1].first) return (float)-1;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("C:\\Users\\kusha\\My_own_CSES_Solutions_and_DSA_Sol\\subsonic_subway_input.txt");
    ofstream fout("C:\\Users\\kusha\\My_own_CSES_Solutions_and_DSA_Sol\\output.txt");

    if (!fin || !fout) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int Test, curr = 1;
    fin >> Test;

    while(curr <= Test) {
        fout << "Case #" << curr << ": " << solve(fin) << "\n";
        curr++;
    }

    // Close the files
    fin.close();
    fout.close();

    return 0;
}
