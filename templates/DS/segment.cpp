#include <bits/stdc++.h>
using namespace std;




struct segment {
    using intype = int;
    using outtype = pair<int,int>;

    int n;
    vector<outtype> t;
    outtype defaultv = pair(INT_MIN,0);
    segment(int l){
        n=l;
        t.assign(4*n,defaultv);
    }
    outtype combine(outtype l,outtype r){
        if(l.first == r.first){
            return pair(l.first,l.second+r.second);
        }
        else{
            return(max(l,r));
        }
    }
    outtype single(intype v){
        return pair(v,1);
        //return (outtype) v;
    }
    outtype eval(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return defaultv;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return combine(eval(v*2, tl, tm, l, min(r, tm)),eval(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    void build(intype a[]) { build(a, 1, 0, n-1); }
    outtype eval(int l, int r) { return eval(1, 0, n-1, l, r); }

    public: void build(intype a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = single(a[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2],t[v*2+1]);
        }
    }
};
