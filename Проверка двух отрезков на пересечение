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
struct Point
{
    long long x, y;
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
        return (x < that.x || (x == that.x && (y < that.y)));
    }
    bool operator == (const Point & that) const{
        return (x == that.x && y == that.y);
    }
    double abs(){
        return hypot(y, x);
    }
};
ll sgn(ll a){
    if(a > 0) return 1;
    if(a < 0) return -1;
    return 0;
}
ll area(Point pt1, Point pt2, Point pt3){
    return ((pt2.x - pt1.x) * (pt3.y - pt1.y) - (pt3.x - pt1.x) * (pt2.y - pt1.y));
}
ll intersect1(ll a, ll b, ll c, ll d){
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}
bool intersect(Point a, Point b, Point c, Point d){
    return intersect1(a.x, b.x, c.x, d.x)
            && intersect1(a.y, b.y, c.y, d.y)
            && ((sgn(area(a, c, b)) * sgn(area(a, d, b))) <= 0)
            && ((sgn(area(c, a, d)) * sgn(area(c, b, d))) <= 0);
}
int main(){
    files;
    Point x[4];
    for(int i = 0; i < 4; ++i){
        x[i].read();
    }
    if(intersect(x[0], x[1], x[2], x[3])){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
