#include <bits/stdc++.h>
using namespace std;

template <typename T, typename F>
int firstTrue(vector<T>& ls, auto x){
    bool check(auto in, auto x){
        return x >= n;
    }
    int sz = size(ls);
    int l = 0;
    int r = sz;
    while(r>l){
        int m = (l+r)/2;
        if(check(ls[m],x)){
            r = m
        }
        else{
            l = m+1;
        }
    }
    if(l == sz){
        return -1;
    }
    return l;
}

template <typename T, typename F>
int lastTrue(vector<T>& ls,auto x){
    bool check(auto in, auto x){
        return x >= in;
    }
    int sz = size(ls);
    int l = -1;
    int r = sz-1;
    while(r>l){
        int m = (l+r+1)/2;
        if(check(ls[m])){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    return l;
}

auto check = [&](int x) {
    int i;
    return (x) > i;
};