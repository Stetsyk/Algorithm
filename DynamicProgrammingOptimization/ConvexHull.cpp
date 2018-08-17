#include <bits/stdc++.h>
using namespace std;

class ConvexHull{
    typedef pair<long double, long double> Line;
    vector<Line> hull;
    vector<long double> intersect;
    bool isMax;
public:
    ConvexHull(bool isMax = 0) : isMax(isMax){}
    long double inter(const Line & l1, const Line & l2){
        return -1.0 * (l1.second - l2.second) / (l1.first - l2.first);
    }
    double eval(const Line & a, const long double x){
        return a.first * x + a.second;
    }
    long long find(long double x){
        auto pos = lower_bound(intersect.begin(), intersect.end(), x);
        if(isMax) return -eval(hull[pos - intersect.begin()], x);
        else return eval(hull[pos - intersect.begin()], x);
    }
    void insert(long double a, long double b){
        if(isMax){
            a = -a;
            b = -b;
        }
        Line current = {a, b};
        while(!intersect.empty()
            && inter(current, hull.back()) <= intersect.back()){
            hull.pop_back();
            intersect.pop_back();
        }
        if(!hull.empty())
            intersect.push_back(inter(current, hull.back()));
        hull.push_back(current);
    }
};

int main()
{

    return 0;
}
