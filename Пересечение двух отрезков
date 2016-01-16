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
bool intersect1(double a, double b, double c, double d){
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    return max(a, c) <= min(b, d) + eps;
}
bool betw(double l, double r, double x){
    return min(l, r) <= x + eps && x <= max(l, r) + eps;
}
double det(double a, double b, double c, double d){
    return a * d - b * c;
}
bool intersect(Point a, Point b, Point c, Point d, Point & left, Point & right){
    if(!intersect1(a.x, b.x, c.x, d.x) || !intersect1(a.y, b.y, c.y, d.y)){
        return false;
    }
    Line m(a, b);
    Line n(c, d);
    double zn = det(m.a, m.b, n.a, n.b);
    if(fabs(zn) < eps){
        if(fabs(m.dist(c) > eps || n.dist(a) > eps)){
            return false;
        }
        if(b < a) swap(a, b);
        if(d < c) swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    }
    else{
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return betw(a.x, b.x, left.x)
                && betw(a.y, b.y, left.y)
                && betw(c.x, d.x, left.x)
                && betw(c.y, d.y, left.y);
    }
}
int main(){
    files;
    Point x, y, z, k;
    x.read();
    y.read();
    z.read();
    k.read();
    Point an1, an2;
    cout.precision(20);
    cout << fixed;
    if(intersect(x, y, z, k, an1, an2)){
        if(an1 == an2){
            an1.print();
        }
        else{
            an1.print();
            cout << endl;
            an2.print();
        }
    }
    else{
        cout << "Empty" << endl;
    }
    return 0;
}
