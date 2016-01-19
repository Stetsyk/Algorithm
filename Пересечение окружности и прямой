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
double sqr(double a){
    return a * a;
}
bool fnd(double r, double a, double b, double c, vector<Point> & pt){
    double x0 = - (a * c) / (sqr(a) + sqr(b));
    double y0 = - (b * c) / (sqr(a) + sqr(b));
    if(c * c > sqr(r) * (sqr(a) + sqr(b)) + eps){
        return false;
    }
    else if(fabs(c * c > sqr(r) * (sqr(a) + sqr(b))) < eps){
        pt.push_back({x0, y0});
    }
    else{
        double d = sqr(r) - sqr(c) / (sqr(a) + sqr(b));
        double mult = sqrt(d / (sqr(a) + sqr(b)));
        pt.push_back({x0 + b * mult, y0 - a * mult});
        pt.push_back({x0 - b * mult, y0 + a * mult});
    }
    return true;
}
int main(){
    files;

    return 0;
}
