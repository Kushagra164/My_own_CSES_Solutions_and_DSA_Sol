#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void parseInput(int n,vector<int> adj_list[]){
    string input;
    cin >> input;
    
    int idx=0;
    for(int i=0;i<n-1;i++){
        while(input[idx]!='{') idx++;
        string node1 = "";
        idx++;
        while(input[idx]!=','){
            node1.push_back(input[idx]);
            idx++;
        }
        int nodeU = stoi(node1);
        
        string node2 = "";
        idx++;
        while(input[idx]!='}'){
            node2.push_back(input[idx]);
            idx++;
        }
        int nodeV = stoi(node2);

        adj_list[nodeU].push_back(nodeV);
        adj_list[nodeV].push_back(nodeU);
        idx++;
    }   

    return ;
}

vector<int> ApplyPeelingAlgo(int n,vector<int> adj_list[]){
    if(n==1) return {0};
    vector<int>indegree(n,0);
    for (int i=0;i<n;i++){
        indegree[i] = adj_list[i].size();
    }
    vector<int>res;
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==1) q.push(i);
    }
    while(q.empty()==false)
    {
        int sz=q.size();
        // res.empty();
        res.clear();
        for(int i=0;i<sz;i++)
        {
            auto curr=q.front();
            q.pop();
            res.push_back(curr);
            for(auto x:adj_list[curr])
            {
                indegree[x]--;
                if(indegree[x]==1) q.push(x);
            }
        }
    }
    return res;
}

void solve() {

    // n denotes number of vertices
    int n;
    cin >> n;
    vector<int> adj_list[n];
    
    parseInput(n,adj_list);

    vector<int> soln = ApplyPeelingAlgo(n,adj_list);

    // vector<int> soln2 = ApplyCentroidDecomposition(n,adj_list);

    cout << "{";
    if (soln.size() == 1){
        cout << soln[0] ;
    }
    else{
        cout << soln[0] << "," << soln[1];
    }
    cout << "}";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}