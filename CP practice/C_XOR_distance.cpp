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
#define debug(n) cout << #n << " : " << n << '\n'; 
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#define debug3(n1,n2,n3) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << "  " << #n3 << " : " << n3 << '\n';
#define MOD 1000000007

using namespace std;


int func(int a, int b, int r){
    int ans=0;
    int t = 0;
    int curr = -1;
    for(int i=60;i>=0;i--){
        int x = (a&(1ll<<i));
        int y = (b&(1ll<<i));
        if(x && y) continue;
        if(!x && !y) continue;
        // debug3(i,x,y);
        if(curr==-1){
            if(x && !y) curr = 1;
            if(!x && y) curr = 2;
            continue;
        }
        // debug2(i,curr);
        if((1ll<<i)>r) continue;
        if(curr==2){
            if(!x && y){
                t += (1ll<<i);
                r -= (1ll<<i);
            }
        }
        else{
            if(x && !y){
                t += (1ll<<i);
                r -= (1ll<<i);
            }
        }
    }
    // cout << "t:" << t << endl;

    return abs((a^t)-(b^t));
}

void solve() {
    int a,b,r; cin>>a>>b>>r;
    cout << min(func(a,b,r),func(b,a,r)) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Test; cin >> Test;
    while(Test--) {
        solve();
    }
    return 0;
}