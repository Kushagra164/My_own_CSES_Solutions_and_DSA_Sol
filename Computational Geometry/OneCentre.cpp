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
        
        // Utilities 
        float findEucledianDistance(Point a,Point b){
            float dis_x = (float)((a.x-b.x)*(a.x-b.x))+(float)((a.y-b.y)*(a.y-b.y));
            dis_x = sqrtf(dis_x);
            return dis_x;
        }

        bool is1Centre(Point midpoint,float radius){
            
            // Check whether all points are inside this centre or not
            for (int idx=0;idx<no_points;idx++){
                float dis = findEucledianDistance(midpoint,giv_points[idx]);
                if (dis <= radius) continue;
                else{
                    return false;
                }
            }
            return true;
        }

        pair<bool,pair<Point,float>> findCircumCentre(int idx1,int idx2,int idx3){
            Point p1 = giv_points[idx1];
            Point p2 = giv_points[idx2];
            Point p3 = giv_points[idx3];

            float a = findEucledianDistance(p1,p2);
            float b = findEucledianDistance(p1,p3);
            float c = findEucledianDistance(p2,p3);

            // Check if three points are non collinear
            if (a+b == c || b+c == a || a+c == b) return {false,{p1,0.0}};

            // Calculating the radius of the circumscribed circle using triangle sides
            float radius =  (a * b * c) / (sqrtf((a + b + c) * (b + c - a) * (c + a - b) * (a + b - c)));

            // Calculating the coordinates of the center of the circumscribed circle (x, y)
            float d = 2 * (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
            float xp = ((p1.x * p1.x + p1.y * p1.y) * (p2.y - p3.y) + (p2.x * p2.x + p2.y * p2.y) * (p3.y - p1.y) + (p3.x * p3.x + p3.y * p3.y) * (p1.y - p2.y)) / d;
            float yp = ((p1.x * p1.x + p1.y * p1.y) * (p3.x - p2.x) + (p2.x * p2.x + p2.y * p2.y) * (p1.x - p3.x) + (p3.x * p3.x + p3.y * p3.y) * (p2.x - p1.x)) / d;

            Point CircumCentre(xp,yp);
            return {true,{CircumCentre,radius}};
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
                    Point point1 = giv_points[first];
                    Point point2 = giv_points[second];
                    float x = (float)(point1.x + point2.x)/2;
                    float y = (float)(point1.y + point2.y)/2;

                    Point midpoint(x,y); 
                    float radius = findEucledianDistance(midpoint,point1);
                    bool check = is1Centre(midpoint,radius);
                    if (check && radius < Radius){
                        Centre = midpoint;
                        Radius = radius;
                    }
                }
            }

            // Algorithm 2 to find 1 Centre
            // Choose three points out lenC3 possibilities and
            // Check whether their circumcentre is 1 centre or not

            for (int first=0;first<no_points-2;first++){
                for(int second = first+1;second<no_points-1;second++){
                    for (int third = second+1;third<no_points;third++){
                        // if (isCollinear(first,second,third)) continue;
                        auto circumcentre = findCircumCentre(first,second,third);
                        if (circumcentre.first && is1Centre(circumcentre.second.first,circumcentre.second.second) && circumcentre.second.second < Radius){
                            Centre = circumcentre.second.first;
                            Radius = circumcentre.second.second;
                        }
                    }
                }
            }
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