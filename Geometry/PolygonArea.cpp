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
        cout << fixed <<  this -> x << endl << this -> y;
    }
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}
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
ll area2(vector<Point> pt){
    if(!pt.size()) return 0;
    ll res = 0;
    pt.push_back(pt[0]);
    for(int i = 0; i < (int)pt.size() - 1; ++i){
        res += (pt[i + 1].x - pt[i].x) * (pt[i + 1].y + pt[i].y);
    }
    pt.pop_back();
    return res;
}
int main(){
    files;
    vector<Point> pt;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        Point x;
        x.read();
        pt.push_back(x);
    }
    double ar = area2(pt);
    cout.precision(1);
    cout << fixed << fabs(ar) / 2 << endl;
    return 0;
}
