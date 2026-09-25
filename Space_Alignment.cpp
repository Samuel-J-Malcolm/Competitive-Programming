/*
Link: https://purdue.kattis.com/courses/CS211-CP1/2026-Spring/assignments/b2kt4p/problems/spacealignment
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
using vpll = vector<pll>;
using vpintint = vector<pintint>;
using vstr = vector<string>;

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


void solve(){
    ll m{}, n{}, k{}, x{}, inp{};
    bool b{};    str s;
    in(n);
    vector<vpll> v(n);
    in(s);
    x++;
    
    rep(i,1,n){
        in(s);
        if(s.back() == '}'){
            x--;
        }
        m = 0; //spaces
        k = 0; // tabs;
        for(char c: s){
            if(c == 's'){
                m++;
            }
            if(c == 't'){
                k++;
            }
        }
        v[x].push_back({m,k});
//        out(x," ",m," ",k,"\n");

        if(s.back() == '{'){
            x++;
        }
    }

    pll p1;
    ll depth1 = 0;
    for(auto& v1: v){
        if(depth1 == 0){
            depth1++;
            continue;
        }
        for(auto& p: v1){
            p1 = p;
            break;
        }
        if(p1.fi != -1){
            break;
        }
        depth1++;
    }


    bool spaceInit = false;
    bool tabInit = false;
    if(p1.fi != 0){
        spaceInit = true;
    }
    if(p1.se != 0){
        tabInit = true;
    }
    pll p2 = {-1,-1};
    ll depth = 0;
    for(auto& v1: v){
        if(depth == 0){
            depth++;
            continue;
        }
        for(auto& p: v1){
            if((p.fi == 0 && !spaceInit) || (p.se == 0 && !tabInit) || ((p.fi*depth1 == p1.fi*depth) && (p.se*depth1 == p1.se*depth)) ){
                continue;
            }
            p2 = p;
            break;
        }
        if(p2.fi != -1){
            break;
        }
        depth++;
        
    }
//    out(p2.fi," ",p2.se," ",depth,"\n");
    x = 0; //spaces per tab
    if(p2.fi != -1){
        x = -(depth*p1.fi-p2.fi*depth1)/(depth*p1.se-p2.se*depth1);
    }
    else{
        x = 1;
    }
//    out("!",p1.fi," ", p1.se,"\n");
//    out("!",p2.fi," ", p2.se, " ",depth, " ",x,"\n");
    ll ind = (p1.fi + x*p1.se)/depth1; 
    rep(i,0,n){
        for(auto& p: v[i]){
            if(p.fi+x*p.se != ind*i){
                out(-1);
                return;
            }
        }
    }
    out(x);
    
    
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
