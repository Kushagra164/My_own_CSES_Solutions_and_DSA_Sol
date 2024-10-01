#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

void dfs(vector<int> adj_list[],int node,set<pair<int,int>> &visited){
    for (auto child:adj_list[node]){
        if (visited.find({node,child}) == visited.end()){
            visited.insert({node,child});
            visited.insert({child,node});
            dfs(adj_list,child,visited);
        }
    }
    return ;
}

bool checkConnectedAndEven(vector<int> adj_list[],int n,set<pair<int,int>> &visited,int m){
    dfs(adj_list,1,visited);
    if (visited.size() != (2*m)) return false;
    for (int i=1;i<=n;i++){
        int sz = adj_list[i].size();
        if (sz&1) return false;
    }

    return true;
}

void dfs1(vector<int> adj_list[],vector<bool> &vis,set<pair<int,int>> &redEdges,int node){
    vis[node]=1;
    for (auto child:adj_list[node]){
        if (!vis[child]){
            redEdges.insert({node,child});
            redEdges.insert({child,node});
            dfs1(adj_list,vis,redEdges,child);
        }
    }
    return ;
}

void findEulerTour(vector<int> &order,vector<int> adj_list[],set<pair<int,int>> &redEdges,set<pair<int,int>> &visited,int node){
    order.push_back(node);
    set<pair<int,int>> CurrRedEdges;
    for (auto child:adj_list[node]){
        if (redEdges.find({node,child}) != redEdges.end()){
            CurrRedEdges.insert({node,child});
            continue;
        }
        if (visited.find({node,child}) != visited.end()) continue;
        visited.insert({node,child});
        visited.insert({child,node});
        findEulerTour(order,adj_list,redEdges,visited,child);
        return ;
    }
    for (auto redEdge:CurrRedEdges){
        if (visited.find(redEdge) == visited.end()){
            visited.insert(redEdge);
            visited.insert({redEdge.second,redEdge.first});
            if (redEdge.second == node) findEulerTour(order,adj_list,redEdges,visited,redEdge.first);
            else findEulerTour(order,adj_list,redEdges,visited,redEdge.second);    
            return ; 
        }
    }
    return ;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> adj_list[n+1];
    rep(i,0,m) {
        int node1,node2;
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
    set<pair<int,int>> visited;
    if (!checkConnectedAndEven(adj_list,n,visited,m)){
        cout << "IMPOSSIBLE\n";
        return ;
    }
    set<pair<int,int>> redEdges;
    vector<bool> vis(n+1,0);
    dfs1(adj_list,vis,redEdges,1);
    // for (auto edge:redEdges) cout << edge.first << " " << edge.second << "\n";
    vector<int> order;
    visited.clear();
    findEulerTour(order,adj_list,redEdges,visited,1);
    for (auto node:order) cout << node << " ";

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}