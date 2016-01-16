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
        scanf("%I64d %I64d", &x, &y);
        this -> x = x;
        this -> y = y;
    }
    void print(){
        printf("%I64d %I64d", this -> x, this -> y);
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
ll sq_2(Point pt1, Point pt2, Point pt3){
    return ((pt2.x - pt1.x) * (pt3.y - pt1.y) - (pt3.x - pt1.x) * (pt2.y - pt1.y));
}
double sq(Point pt1, Point pt2, Point pt3){
    return ((pt2.x - pt1.x) * (pt3.y - pt1.y) - (pt3.x - pt1.x) * (pt2.y - pt1.y)) / 2.;
}
bool cw(Point pt1, Point pt2, Point pt3){
    return ((pt2.x - pt1.x) * (pt3.y - pt1.y) - (pt3.x - pt1.x) * (pt2.y - pt1.y)) < 0;
}
bool ccw(Point pt1, Point pt2, Point pt3){
    return ((pt2.x - pt1.x) * (pt3.y - pt1.y) - (pt3.x - pt1.x) * (pt2.y - pt1.y)) > 0;
}
bool collinear(Point pt1, Point pt2, Point pt3){
    return ((pt2.x - pt1.x) * (pt3.y - pt1.y) - (pt3.x - pt1.x) * (pt2.y - pt1.y)) == 0;
}
int main(){
    files;
    vector<Point> cur;
    for(int i = 0; i < 3; ++i){
        Point x;
        x.read();
        cur.push_back(x);
    }
    cout << cw(cur[0], cur[1], cur[2]) << endl;
    return 0;
}
