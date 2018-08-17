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
const int N = 100000 + 10;

struct Point
{
	long long x, y;
	void read() {
		int nx, ny;
		scanf("%d%d", &nx, &ny);
		x = nx; y = ny;
	}
	Point() {}
	Point(long long x, long long y) : x(x), y(y) {}
	Point operator - (const Point &that) const {
		return Point(x - that.x, y - that.y);
	}
	double abs() {
		return hypot(x, y);
	}
	long long det(const Point &that) const {
		return x * that.y - y * that.x;
	}
	Point rot90() {
		return Point(y, -x);
	}
};

int n, outH, inH;
long double ret;
long double vret;
long long varea;
long long maxArea;
long long maxH;
Point a[N];

int sign(long long x)
{
	return x < 0 ? -1 : x > 0;
}

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

void calcAns()
{
	scanf("%d%d", &outH, &inH);
	scanf("%d", &n);
	long double h = min(outH, inH);
	for (int i = 0; i < n; ++ i) {
		a[i].read();
		ret = min(ret, sqrt(a[i].x * a[i].x + a[i].y * a[i].y + h * h));
	}
	for(int i = 0; i < n; ++ i) {
		Point vec = (a[(i + 1) % n] - a[i]).rot90();
		if (sign(vec.det(a[i])) * sign(vec.det(a[(i + 1) % n])) <= 0) {
			long double dist = abs(a[i].det(a[(i + 1) % n]) / vec.abs());
			ret = min(ret, sqrt(dist * dist + h * h));
		}
	}

	int contain = 0;
	long long curArea = 0;
	for(int i = 0; i < n; ++ i) {
		Point u = a[i], v = a[(i + 1) % n];
		curArea += u.det(v);
		if (u.y <= v.y) swap(u, v);
		if (0 > u.y || 0 <= v.y) continue;
		contain ^= sign(v.det(u)) > 0;
	}
	if (curArea < 0) curArea = -curArea;
	if (maxArea < curArea) {
		maxArea = curArea;
		maxH = outH;
	}

	if (contain) {
		if (varea < 0 || varea > curArea) {
			varea = curArea;
			vret = inH;
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	ret = 1e100;
	vret = 1e100;
	varea = -1;
	maxArea = 0;
	for(int i = 0; i < n; ++ i) {
		calcAns();
	}
	if (varea < 0) {
		vret = maxH;
	}
	printf("%.16f\n", (double)min(ret, vret));
}

int main()
{
	solve();
	return 0;
}
