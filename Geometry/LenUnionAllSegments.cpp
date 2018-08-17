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
ll segment_union_length (vector<Point> a){
    if(!a.size()) return 0;
    sort(a.begin(), a.end());
    ll res = 0;
    ll mx = a[0].x;
    for(int i = 0; i < (int)a.size(); ++i){
        if(a[i].x > mx){
            mx = a[i].y;
            res += mx - a[i].x;
        }
        else{
            if(a[i].y > mx){
                res += a[i].y - mx;
                mx = a[i].y;
            }
        }
    }
    return res;
}
int main(){
    files;
    int n;
    cin >> n;
    vector<Point> cur;
    for(int i = 0; i < n; ++i){
        Point x;
        x.read();
        cur.push_back(x);
    }
    cout << segment_union_length(cur) << endl;
    return 0;
}
