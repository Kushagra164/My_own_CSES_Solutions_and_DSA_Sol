#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

// Code By Kushagra Khare

struct Wall {
    int id;
    int x;
    int height;
    bool is_start;
};

class SkylineProblem {
   public:
    vector<vector<int>> getSkyline(
        const vector<vector<int>> &buildings) {
        vector<vector<int>> ans;

        vector<Wall> walls;
        for (int i = 0; i < buildings.size(); i += 1) {
            const auto &building = buildings[i];
            // left
            walls.push_back(Wall{.id = i,
                                 .x = building[0],
                                 .height = building[2],
                                 .is_start = true});
            // right
            walls.push_back(Wall{.id = i,
                                 .x = building[1],
                                 .height = building[2],
                                 .is_start = false});
        }

        sort(
            walls.begin(), walls.end(),
            [](const Wall &a, const Wall &b) -> bool { return a.x < b.x; });

        // key: id, priority: height
        const auto cmp = [](const pair<int, int> &a,
                            const pair<int, int> &b) -> bool {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>,
                            vector<pair<int, int>>, decltype(cmp)>
            pq(cmp);

        vector<bool> present(buildings.size(), false);

        int current_height = 0;

        int i = 0;
        while (i < walls.size()) {
            int current_x = walls[i].x;
            while (i < walls.size() && walls[i].x == current_x) {
                if (!walls[i].is_start) {
                    present[walls[i].id] = false;
                } else {
                    pq.push(make_pair(walls[i].id, walls[i].height));
                    present[walls[i].id] = true;
                }

                i += 1;
            }

            while (pq.size() > 0 && !present[pq.top().first]) {
                pq.pop();
            }

            if (pq.size() == 0) {
                ans.push_back({current_x, 0});
                current_height = 0;
            } else {
                int tmp_height = get<1>(pq.top());
                if (tmp_height != current_height) {
                    ans.push_back({current_x, tmp_height});
                    current_height = tmp_height;
                }
            }
        }

        return ans;
    }
};

//Code By Kush

void solve() {
    int no_buildings;
    cin >> no_buildings;
    vector<vector<int>> description(no_buildings,vector<int>(3));
    for (int i=0;i<no_buildings;i++){
        cin >> description[i][0] >> description[i][1] >> description[i][2];
    }
    SkylineProblem solution ;
    auto ans = solution.getSkyline(description);
    cout << "Boundaries are\n";
    for (auto vec:ans){
        cout << vec[0] << " " << vec[1] << "\n";
    }

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}