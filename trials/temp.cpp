#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush
bool cmp(vector<int> &a,vector<int> &b){
    return a[1]<=b[1];
}

void buildTemp(int val1,int val2,map<int,vector<int>> &fwd,map<int,vector<int>> &ret,vector<vector<int>> &temp){
    auto vec1 = fwd[val1];
    auto vec2 = ret[val2];

    for (int num:vec1){
        // cout << num << "\n";
        for (int num1:vec2){
            // cout << num1 << "\n";
            temp.push_back({num,num1});
        }
    }
}

vector<vector<int>> routePairs(int maxTravelDist,vector<vector<int>> forwardRouteList,vector<vector<int>> returnRouteList){
    sort(forwardRouteList.begin(),forwardRouteList.end(),cmp);
    sort(returnRouteList.begin(),returnRouteList.end(),cmp);
    int sz1 = forwardRouteList.size(),sz2 = returnRouteList.size();
    map<int,vector<int>> fwd,ret;
    vector<int> fwdVal,retVal;
    int val = forwardRouteList[0][1];
    fwd[val] = {forwardRouteList[0][0]};
    fwdVal.push_back(val);
    for (int i=1;i<sz1;i++){
        if (forwardRouteList[i][1] == val){
            fwd[val].push_back(forwardRouteList[i][0]);
        }
        else {
            val = forwardRouteList[i][1];
            fwd[val] = {forwardRouteList[i][0]};
            fwdVal.push_back(val);
        }
    }
    val = returnRouteList[0][1];
    ret[val] = {returnRouteList[0][0]};
    retVal.push_back(val);
    for (int i=1;i<sz2;i++){
        if (returnRouteList[i][1] == val){
            ret[val].push_back(returnRouteList[i][0]);
        }
        else {
            val = returnRouteList[i][1];
            ret[val] = {returnRouteList[i][0]};
            retVal.push_back(val);
        }
    }
    int first = fwdVal.size()-1;
    int second = 0;
    vector<vector<int>> mxpair;
    int mx = 0;
    while(first>=0 && second<sz2){
        int sum = fwdVal[first]+retVal[second]; 
        if ( sum > maxTravelDist){
            first--;
        }
        else {
            if (sum > mx){
                mx = sum;
                mxpair.clear();
                buildTemp(fwdVal[first],retVal[second],fwd,ret,mxpair);
                // cout << mx << "\n";
            }
            else if (sum == mx){
                buildTemp(fwdVal[first],retVal[second],fwd,ret,mxpair);
            }
            second++;
        }
    }
    sort(mxpair.begin(),mxpair.end());
    return mxpair;

}

void solve() {
    int mxTravelDist;
    cin >> mxTravelDist;
    int n1,n2;
    cin >> n1 >> n2;
    vector<vector<int>> forward,retur;
    for (int i=0;i<n1;i++){
        int id,val;
        cin >> id >> val;
        forward.push_back({id,val});
    }
    for (int i=0;i<n2;i++){
        int id,val;
        cin >> id >> val;
        retur.push_back({id,val});
    }
    auto ans = routePairs(mxTravelDist,forward,retur);
    for (auto vec:ans){
        for (int num:vec) cout << num << " " ;
        cout << "\n";
    } 
}

signed main() {
    solve();
    return 0;
}