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
#include <stack>
#ifdef lyosha
#define files freopen("input.txt", "r", stdin);
#else
#define files //freopen("howmany.in","r",stdin); freopen("howmany.out","w",sdout);
#endif
using namespace std;
typedef long long ll;
double eps = 1e-9;
const int N = 100005;
vector<ll> calc(vector<pair<ll, ll> > pt){
    vector<pair<ll, pair<bool, ll> > > npt;
    npt.resize(2 * pt.size());
    for(int i = 0; i < (int)pt.size(); ++i){
        npt[i + i] = {pt[i].first, {0, i} };
        npt[i + i + 1] = {pt[i].second, {1, i} };
    }
    sort(npt.begin(), npt.end());
    vector<bool> cover;
    cover.assign(pt.size(), false);
    stack<int> st;
    vector<ll> ans;
    for(auto cur : npt){
        if(cur.second.first == 0){
            st.push(cur.second.second);
        }
        else{
            if(!cover[cur.second.second]){
                ans.push_back(cur.first);
                while(!st.empty()){
                    cover[st.top()] = true;
                    st.pop();
                }
            }
        }
    }
    return ans;
}
int main(){
    //files;
    vector<pair<ll, ll> > tmp;
    tmp.push_back({1, 3});
    tmp.push_back({2, 4});
    tmp.push_back({5, 10});
    auto out = calc(tmp);
    for(auto it : out){
        cout << it << endl;
    }
    return 0;
}
