// #include <bits/stdc++.h>
// #define rep(i,a,b) for(int i = a; i < b; i++)
// #define ll long long
// #define pb push_back
// #define all(a) a.begin(),a.end()
// #define MOD 1000000007

// using namespace std;

// Code By Kush

// void solve() {
//     int n,k;
//     cin >> n >> k;
//     vector<pair<int,int>> arr(n);
//     rep(i,0,n) {
//         cin >> arr[i].first >> arr[i].second;
//     }
//     sort(arr.begin(),arr.end(),[&](pair<int,int> a,pair<int,int> b){
//         if (a.second == b.second) return a.first<b.first;
//         return a.second<b.second;
//     });
//     queue<int> q;
//     int ans = 0;
//     for (int i=0;i<n;i++){
//         if (q.size() < k){
//             q.push(i);
//             ans++;
//             continue;
//         }
//         int prev_idx = q.front();
//         if (arr[prev_idx].second <= arr[i].first){
//             q.pop();
//             q.push(i);
//             ans++;
//         }
//     }
//     cout << ans; 
//     return ;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     solve();
//     return 0;
// }
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)  // read start time, end time
		cin >> v[i].second >> v[i].first;
	sort(begin(v), end(v));  // sort by end time

	int maxMovies = 0;
	multiset<int> end_times;  // times when members will finish watching movies
	for (int i = 0; i < k; ++i) end_times.insert(0);

	for (int i = 0; i < n; i++) {
		auto it = end_times.upper_bound(v[i].second);
		if (it == begin(end_times)) continue;
		// assign movie to be watched by member in multiset who finishes at time
		// *prev(it)
		end_times.erase(--it);
		// member now finishes watching at time v[i].first
		end_times.insert(v[i].first);
		++maxMovies;
	}

	cout << maxMovies;
}