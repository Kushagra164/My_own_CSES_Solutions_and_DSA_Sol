#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define nl << '\n' 
#define sp << " " <<
#define forn(i,n)  for(int i=0;i<n;i++) 
#define all(x)         (x).begin(),(x).end()
#define debug(n) cout << #n << " : " << n << '\n'; 
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#define debug3(n1,n2,n3) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << "  " << #n3 << " : " << n3 << '\n';
#define gkick for(int i=1;i<=t;i++) googlekick(i);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

const int M = 1e9+7;

void solve(){
    int h,w,xa,ya,xb,yb; 
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if(xa>=xb){
        cout << "Draw" nl; 
        return;
    }
    int diff = abs(xa-xb);
    int x;
    int steps = (diff+1)/2;
    if(steps<abs(ya-yb)){
        cout << "Draw" nl;
        return;
    }
    int st = steps;
    steps -= abs(ya-yb);
    if(diff%2){
        if(ya<=yb){
            x = w-yb;
        }
        else x = yb-1;
        if(min(x,st-1)<=steps){
            cout << "Alice" nl;
        }
        else{
            cout << "Draw" nl;
        }
    }
    else{
        if(ya<=yb){
            x = ya-1;
        }
        else x = w-ya;
        if(min(x,st)<=steps){
            cout << "Bob" nl;
        }
        else{
            cout << "Draw" nl;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int t=1;
    cin >>t;

    while(t--)solve();

       
    return 0;
}