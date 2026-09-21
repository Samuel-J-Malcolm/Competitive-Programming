/*
Link: https://open.kattis.com/problems/quantumsuperposition
Rating:
Platform:
Duration: 
*/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include <iomanip>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pintint = pair<int, int>;
using pintl = pair<int, ll>;
using pll = pair<ll, ll>;

using vint  = vector<int>;
using vll = vector<ll>;
using vvint = vector<vint>;
using vvll = vector<vll>;

// Macros
#define pb    push_back
#define eb    emplace_back
#define mp    make_pair
#define fi    first
#define se    second
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)   (ll)(x).size()
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define repp(i, a, b, c) for (ll i = (a); i < (b); i+=c)
#define repn(i, a, b, c) for (ll i = (a); i > (b); i-=c)

using str = string;
#include <bit> // Required for bit operations

#define NO cout << ("No"); return;
#define YES cout << ("Yes"); return;

#ifdef LOCAL
#define dbg(x) cout << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif

#define outr(x) out(x); return;

int bw(unsigned long long x) {
    return x == 0 ? 0 : 64 - __builtin_clzll(x);
}

// Constants
const ll INF  = 1e18;
const ll INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void printstruct(const vll& s){
    for(auto& c: s){
        cout << c << " ";
    }
    cout << ("\n");    
}

void printstruct(const vector<string>& s){
    for(auto& c: s){
        cout << c << " ";
    }
    cout << ("\n");    
}

void printstruct(const vint& s){
    for(auto& c: s){
        cout << c << " ";
    }
    cout << ("\n");    
}



#ifdef LOCAL
#define ps(x) printstruct(x) << "\n"
#else
#define ps(x)
#endif

template<typename... Args>
void in(Args&... args) {
    ((cin >> args), ...);
}

template<typename... Args>
void out(const Args&... args) {
    size_t n = 0;
    ((cout << args), ...);
}

template<typename... Args>
void outs(const Args&... args) {
    size_t n = 0;
    ((cout << args << (++n != sizeof...(args) ? " " : "")), ...);
}

int max(vint v){
    int m = numeric_limits<int>::min();
    for(int i: v){
        m = max(i,m);
    }
    return m;
}

int min(vint v){
    int m = numeric_limits<int>::max();
    for(int i: v){
        m = min(i,m);
    }
    return m;
}

ll max(vll v){
    ll m = numeric_limits<ll>::min();
    for(ll i: v){
        m = max(i,m);
    }
    return m;
}

ll min(vll v){
    ll m = numeric_limits<ll>::max();
    for(ll i: v){
        m = min(i,m);
    }
    return m;
}

vector<int> pathsizes(int n,vvint v,int s,int e){
    vector<int> pathsizes;
    vector<unordered_set<int>> done(n); 
    queue<pintint> q;
    q.push({s,0});
    if(s == e){
        return {0};
    }
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        for(auto& adj: v[node.fi]){
            if(adj == e){
                pathsizes.push_back(node.se+1);
            }
            else if(!done[adj].count(node.se+1)){
                q.push({adj,node.se+1});
                done[adj].insert(node.se+1);
            }
        }
    }
    return pathsizes;
}

void solve(){
    ll e1,e2,v1,v2 = 0;
    int i1,i2;
    bool b;
    str s;
    in(v1);
    in(v2);
    in(e1);
    in(e2);
    vvint u1(v1-1);
    vvint u2(v2-1);
    rep(i,0,e1){
        in(i1);
        in(i2);
        u1[i1-1].push_back(i2-1);
    }
    
    rep(i,0,e2){
        in(i1);
        in(i2);
        u2[i1-1].push_back(i2-1);
    }
    auto s1 = pathsizes(v1,u1,0,v1-1);
    auto s2 = pathsizes(v2,u2,0,v2-1);
    vector<bool> valid(2001);
    for(int i: s1){
        for(int j: s2){
            if(i+j <= 2000){
                valid[i+j] = true;
            }
        }
    }
    int q;
    in(q);
    rep(i,0,q){
        in(i1);
        if(valid[i1]){
            out("Yes\n");
        }
        else{
            out("No\n");
        }
        
    }
    
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool multi = true;
    multi = false;
    ll t = 1;
    if(multi){
        cin >> t;
    }
    
    while (t--){
        solve();
        if(multi){
            out("\n");
        }
    }
    return 0;
}
