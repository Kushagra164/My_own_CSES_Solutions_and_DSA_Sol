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

class DSU{
    vector<int> parent,extra,points;
    public:
        DSU(int n){
            for (int i=0;i<=n;i++) {
                parent.push_back(i);
                extra.push_back(0);
                points.push_back(0);
            }
        }
        int findPar(int node) {
            return parent[node] == node ? node : findPar(parent[node]);
        }
        void Union(int node1,int node2){
            int root1 = findPar(node1);
            int root2 = findPar(node2);
            if (root1 == root2) return ;
            if (root1 > root2) swap(root1,root2);
            parent[root2] = root1;
            extra[root2] = points[root1];

            return ;
        }
        void addValue(int node,int value){
            int root = findPar(node);
            points[root] += value;
            return ;
        }
        int getValue(int node){
            int val = points[node];
            if (parent[node] == node) return val;
            val += getValue(parent[node]) - extra[node];
            return val;
        }
};

void solve() {
    int n,q;
    cin >> n >> q;
    DSU ds(n);
    while(q--){
        string op;
        cin >> op;
        if (op == "add"){
            int node,value;
            cin >> node >> value;
            ds.addValue(node,value);
        }
        else if (op == "join"){
            int node1,node2;
            cin >> node1 >> node2;
            ds.Union(node1,node2);
        }
        else {
            int node;
            cin >> node;
            cout << ds.getValue(node) << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}