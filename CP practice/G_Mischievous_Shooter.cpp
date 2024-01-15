#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define rep(i,n) for(i=1;i<=n;i++)
#define ll long long
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x, y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int mod = 1'000'000'007;
//============================

int getans(vector<vi> &arr,int n,int m,int k){
    // 1 based idx;
    vector<vi> dia(n+2,vi(m+2,0)),suffix(n+2,vi(m+2,0)),temp(n+2,vi(m+2,0));
    for(int d=1;d<=n+m-1;d++){
        vi cd;
        cd.push_back(0);
        int i,j;
        for(i=min(d,n),j=max(1,d-n+1);i>=1 && j<=m;i--,j++){
            int s=cd.size();
            cd.push_back(arr[i][j]+cd[s-1]);
            if(j-k+1>=1) dia[i][j-k+1]=cd.back()-cd[max(s-k,0)];
        }
        for(int it=1;it<k;it++){
            int s=cd.size();
            cd.push_back(0+cd[s-1]);
            if(i>=1 && j-k+1>=1) dia[i][j-k+1]=cd.back()-cd[max(s-k,0)];
            i--,j++;
        }
        // deb(d);
        // for(auto v:cd) cout<<v<<" ";
        // cout<<endl;
    }
    int i,j;
    // rep(i,n){
    //     rep(j,m){
    //         cout<<dia[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    rep(i,n){
        for(j=m;j>=1;j--){
            suffix[i][j]=suffix[i][j+1]+arr[i][j];
        }
    }
    int ans=0;
    for(i=n;i>=1;i--){
        rep(j,m){
            int curr=suffix[i][j]-suffix[i][min(m+1,j+k)];
            curr=curr+temp[i+1][j]-dia[i+1][j];
            ans=max(ans,curr);
            temp[i][j]=curr;
        }
    }
    // rep(i,n){
    //     rep(j,m){
    //         cout<<dia[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // rep(i,n){
    //     rep(j,m){
    //         cout<<temp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    return ans;
}

void rotate(vector<vi> &arr,int &n,int &m){
    vector<vi> narr;
    int i,j;
    for(j=0;j<=m+1;j++){
        vi temp;
        for(i=n+1;i>=0;i--){
            temp.push_back(arr[i][j]);
        }
        narr.push_back(temp);
    }
    arr=narr;
    int x=m;
    m=n;
    n=x;
}

void solve(){
    int i,j,n,m,k;
    cin>>n>>m>>k;
    vector<vi> arr(n+2,vi(m+2,0));
    rep(i,n){
        rep(j,m){
            char c; cin>>c;
            if(c=='#') arr[i][j]=1;
        }
    }
    int ans=getans(arr,n,m,k+1);
    rep(i,3){
        rotate(arr,n,m);
        ans=max(ans,getans(arr,n,m,k+1));
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}