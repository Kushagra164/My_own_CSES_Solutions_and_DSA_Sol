#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

/*
Q) Given a set of points find a centre point and radius such that the circle made 
   through this would enclose all the given points and this circle should have minimum 
   perimeter.
*/

class Point{
    public:
        int x,y;
        Point(int i,int j){
            this->x = i;
            this->y = j;
        }
};

void solve() {

    // n represents number of points
    int n;
    cin >> n;

    // Store given points
    vector<Point> giv_points(n);
    rep(i,0,n) {
        cin >> giv_points[i].x >> giv_points[i].y;
    }

    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}