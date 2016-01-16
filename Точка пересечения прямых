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
        cout << this -> x << " " << this -> y;
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
        return (x < that.x + eps || (fabs(x - that.x) < eps && (y < that.y + eps)));
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
    void norm(){
        double tmp = hypot(a, b);
        a /= tmp;
        b /= tmp;
        c /= tmp;
    }
    void read(){
        cin >> a >> b >> c;
    }
    double dist(Point pt){
        norm();
        return fabs(a * pt.x + b * pt.y + c);
    }
};
double det(double a, double b, double c, double d){
    return a * d - b * c;
}
bool intersect(Line n, Line m, Point & pt){
    double zn = -det(n.a, n.b, m.a, m.b);
    if(abs(zn) < eps)
        return false;
    pt.x = det(n.c, n.b, m.c, m.b) / zn;
    pt.y = det(n.a, n.c, m.a, m.c) / zn;
    return true;
}
int main(){
    files;
    Line x, y;
    Point pt;
    x.read();
    y.read();
    cout.precision(20);
    cout << fixed;
    if(intersect(x, y, pt))
        pt.print();
    return 0;
}
