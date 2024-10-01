#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

// bool isConsistent(vector<string> expressions){
//     map<char,int> mp;
//     int timer = 0;
//     for (string s:expressions){
//         if (mp.find(s[0]) == mp.end()){
//             mp[s[0]] = timer;
//             timer++;
//         }
//         if (mp.find(s[2]) == mp.end()){
//             mp[s[2]] = timer;
//             timer++;
//         }
//     }
//     int n = mp.size();
//     vector<int> adj_list[n];
//     for (string s:expressions){
//         int node1 = mp[s[0]];
//         int node2 = mp[s[2]];
//         adj_list[node1].push_back(node2);
//     }
//     queue<int> q; 
//     vector<int> indegree(n, 0); 
//     for(int i = 0;i<n;i++) {
//         for(auto it: adj_list[i]) {
//             indegree[it]++; 
//         }
//     }
    
//     for(int i = 0;i<n;i++) {
//         if(indegree[i] == 0) {
//             q.push(i); 
//         }
//     }
//     vector<int> topo;
//     while(!q.empty()) {
//         int node = q.front(); 
//         q.pop(); 
//         topo.push_back(node);
//         for(auto it : adj_list[node]) {
//             indegree[it]--;
//             if(indegree[it] == 0) {
//                 q.push(it); 
//             }
//         }
//     }
//     if (topo.size() == n) return 1;
//     return 0;
// }

int minNumberOfLights(vector<int> A,int P){
    int n = A.size();

	vector<long long> dp(n + 1,INT_MAX);
	multiset<long long> mins, vals;
	mins.insert(0);
	vector<vector<long long>> del(n);
    dp[n]=0;
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = 1 +  dp[i + 1];
		if (i + P + 1 <= n) mins.erase(mins.find(dp[i + P + 1]));
		for (auto it : del[i]) vals.erase(vals.find(it));
		if (!vals.empty()) dp[i] = min(dp[i], *vals.begin());
		if (A[i] == 1) {
			long long val = (mins.empty() ? 0 : *mins.begin())  + 1;
			dp[i] = min(dp[i], val);
			vals.insert(val);
			if (i - P >= 0) del[i - P ].push_back(val);
		}
		mins.insert(dp[i]);
	}
    return dp[0];
}

void solve() {
    int n,P ;
    cin >> n >> P;
    vector<int> A(n);
    for (int i=0;i<n;i++) cin>>A[i];
    cout << minNumberOfLights(A,P);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}