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
        float x,y;
        Point(){
            this->x=0;
            this->y=0;
        }

        Point(float i,float j){
            this->x = i;
            this->y = j;
        }
};

class OneCentre{
    private:
        vector<Point> giv_points;
        int no_points;

        float findEucledianDistance(Point a,Point b){
            float dis_x = (float)((a.x-b.x)*(a.x-b.x))+(float)((a.y-b.y)*(a.y-b.y));
            dis_x = sqrtf(dis_x);
            return dis_x;
        }

    public:
        Point Centre;
        float Radius = FLT_MAX;
        

        OneCentre(vector<Point> &points){
            this->giv_points = points;
            this->no_points = points.size();
            findOneCentre();
        }

        void findOneCentre(){
            // Algorithm 1 to find 1 Centre
            // Choose two points out of lenC2 possibilities and 
            // Check whether their midpoint is 1 centre or not.

            for (int first=0;first<no_points-1;first++){
                for (int second=first+1;second<no_points;second++){
                    auto check = is1Centre(first,second);
                    if (check.first && check.second.second < Radius){
                        Centre = check.second.first;
                        Radius = check.second.second;
                    }
                }
            }
        }

        pair<bool,pair<Point,float>> is1Centre(int idx1,int idx2){
            Point point1 = giv_points[idx1];
            Point point2 = giv_points[idx2];
            float x = (float)(point1.x + point2.x)/2;
            float y = (float)(point1.y + point2.y)/2;

            Point midpoint(x,y); 
            float radius = findEucledianDistance(midpoint,point1);
            
            // Check whether all points are inside this centre or not
            for (int idx=0;idx<no_points;idx++){
                if (idx == idx1 || idx == idx2) continue;
                float dis = findEucledianDistance(midpoint,giv_points[idx]);
                if (dis <= radius) continue;
                else{
                    return {false,{midpoint,radius}};
                }
            }
            return {true,{midpoint,radius}};
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

    OneCentre* solution = new OneCentre(giv_points);
    cout << "1 Centre is (" << solution->Centre.x << "," << solution->Centre.y << ")\n";
    cout << "Radius is " << solution->Radius << "\n";
    
    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--) solve();
    return 0;
}