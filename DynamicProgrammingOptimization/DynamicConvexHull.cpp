#include <bits/stdc++.h>
using namespace std;

class ConvexHullDynamic{
    typedef long long coef_t;
    typedef long long coord_t;
    typedef long long val_t;
    struct Line{
        coef_t a, b;
        double left_x;
        coord_t val;
        bool type;
        Line(coef_t a=0, coef_t b=0) : a(a), b(b), left_x(-INFINITY), val(0), type(false) {}
        val_t eval(coord_t x) const{
            return a * x + b;
        }
        friend bool paralel(const Line & a, const Line & b){
            return a.a == b.a;
        }
        friend double inter(const Line & a, const Line & b){
            if(paralel(a, b)) return INFINITY;
            return -1.0 * (a.b - b.b) / (a.a - b.a);
        }
        bool operator < (const Line & line) const{
            if(line.type == false) return this -> a > line.a;
            return this -> left_x < line.val;
        }
    };
    set<Line> hull;
    bool isMax;
public:
    bool hasNext(set<Line>::iterator it){
        return it != hull.end() && next(it) != hull.end();
    }
    bool hasPrev(set<Line>::iterator it){
        return it != hull.begin();
    }
    bool irrelevant(set<Line>::iterator it){
        return hasPrev(it) && hasNext(it) &&
        (inter(*prev(it), *next(it)) < inter(*prev(it), *it));
    }
    set<Line>::iterator updBorder(set<Line>::iterator it){
        if(!hasPrev(it)) return it;
        Line tmp(*it);
        double lef = inter(tmp, *prev(it));
        it = hull.erase(it);
        tmp.left_x = lef;
        it = hull.insert(it, tmp);
        return it;
    }
    ConvexHullDynamic(bool isMax) : isMax(isMax){}
    val_t find(coord_t x){
        if(hull.empty()){
            if(isMax){
                return -INFINITY;
            }
            else{
                return INFINITY;
            }
        }
        Line q;
        q.val = x;
        q.type = true;
        set<Line>::iterator it = hull.lower_bound(q);
        --it;
        if(isMax) return -it->eval(x);
        else return it->eval(x);
    }
    void insert(coord_t a, coord_t b){
        if(isMax){
            a = -a;
            b = -b;
        }
        Line l3(a, b);
        set<Line>::iterator it = hull.lower_bound(l3);
        if(it != hull.end() && paralel(*it, l3)){
            if(it -> b <= b) return;
            it = hull.erase(it);
        }
        it = hull.insert(it, l3);
        if(irrelevant(it)){
            hull.erase(it);
            return;
        }
        while(hasNext(it) && irrelevant(next(it)))
            hull.erase(next(it));
        while(hasPrev(it) && irrelevant(prev(it)))
        hull.erase(prev(it));
        it = updBorder(it);
        if(hasNext(it)) updBorder(next(it));
    }

};
ConvexHullDynamic t(0);
int main()
{

    return 0;
}
