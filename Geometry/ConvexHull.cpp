#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#ifdef lyosha
#define files freopen("input.txt", "r", stdin);
#else
#define files //freopen("howmany.in","r",stdin); freopen("howmany.out","w",sdout);
#endif
using namespace std;
typedef long long ll;
double eps = 1e-9;
struct Point
{
    double x, y;
    void read(){
        ll x, y;
        cin >> x >> y;
        this -> x = x;
        this -> y = y;
    }
    void print(){
        cout << fixed <<  this -> x << " " << this -> y;
    }
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator - (const Point & that) const{
        return Point(x - that.x, y - that.y);
    }
    Point operator + (const Point & that) const{
        return Point(x + that.x, y + that.y);
    }
    bool operator < (const Point & that) const{
        return (x < that.x - eps || (fabs(x - that.x) < eps && (y < that.y - eps)));
    }
    bool operator == (const Point & that) const{
        return fabs(x - that.x) < eps && fabs(y - that.y) < eps;
    }
    double abs(){
        return hypot(y, x);
    }
};
struct Line
{
    double a, b, c;
    Line(): a(0), b(0), c(0){};
    void norm(){
        double tmp = hypot(a, b);
        if(fabs(tmp) > eps){
            a /= tmp;
            b /= tmp;
            c /= tmp;
        }
    }
    void read(){
        cin >> a >> b >> c;
    }
    Line(Point p, Point q){
        a = p.y - q.y;
        b = q.x - p.x;
        c = - a * p.x - b * p.y;
        norm();
    }
    double dist(Point pt){
        return fabs(a * pt.x + b * pt.y + c);
    }
};
double sq2(Point a, Point b, Point c){
    return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}
bool cw(Point a, Point b, Point c){
    return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) < 0;
}
bool ccw(Point a, Point b, Point c){
    return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) > 0;
}
void convex_hull(vector<Point> & pt){
    if(pt.size() < 2) return;
    sort(pt.begin(), pt.end());
    vector<Point> up, down;
    up.push_back(pt[0]);
    down.push_back(pt[0]);
    auto pt1 = pt[0];
    auto pt2 = pt.back();
    for(int i = 1; i < (int)pt.size(); ++i){
        if((i == (int)pt.size() - 1) || (cw(pt1, pt[i], pt2))){
            while(up.size() > 1 && !cw(up[up.size() - 2], up[up.size() - 1], pt[i])){
                up.pop_back();
            }
            up.push_back(pt[i]);
        }
        if((i == (int)pt.size() - 1) || (ccw(pt1, pt[i], pt2))){
            while(down.size() > 1 && !ccw(down[down.size() - 2], down[down.size() - 1], pt[i])){
                down.pop_back();
            }
            down.push_back(pt[i]);
        }
    }
    pt = up;
    for(int i = down.size() - 2; i > 0; --i){
        pt.push_back(down[i]);
    }
    return;
}
double sqr(double a){
    return a * a;
}
double dist(Point & a, Point & b){
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
int main(){
    files;
    vector<Point> vec;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        Point x;
        x.read();
        vec.push_back(x);
    }
    convex_hull(vec);
    double ans = 0;
    n = vec.size();
    for(int i = 0; i < n; ++i){
        ans += dist(vec[(i + 1) % n], vec[i]);
    }
    cout.precision(1);
    cout << fixed << ans << endl;
    return 0;
}
