/*
Link: https://atcoder.jp/contests/abc469/tasks/abc469_d
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


int bw(unsigned long long x) {
    return x == 0 ? 0 : 64 - __builtin_clzll(x);
}

// Constants
const ll INF  = 1e18;
const ll INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void printstruct(auto& s){
    cout << "(";
    for(auto c: s){
        cout << c << " ";
    }
    cout << ")";
    cout << "\n";
    
}

#ifdef LOCAL
#define ps(x) printstruct(x) << "\n"
#else
#define ps(x)
#endif

template<typename... Args>
void input(Args&... args) {
    ((cin >> args), ...);
}

template<typename... Args>
void out(const Args&... args) {
    ((cout << args), ...);
}

bool intersects1(pll p1, pll p2){
    if(p1.fi == p2.first){
        return true;
    }
    if(p1.se == p2.se){
        return true;
    }
    if(p1.fi == p2.se){
        return true;
    }
    if(p1.se == p2.fi){
        return true;
    }
    return false;
}

void solve(){
    ll m,n,k,x,y,in;
    bool b;
    str s;
    input(n);
    input(m);
    pll p1;
    pll p2;
    set<ll> poss;
    set<pll> pairs;
    input(p1.fi);
    input(p1.second);
    input(p2.fi);
    input(p2.second);
    pairs.insert({p1.first,p2.first});
    pairs.insert({p1.first,p2.second});
    pairs.insert({p1.second,p2.first});
    pairs.insert({p1.second,p2.second});
    if(p1.first == p2.first){
        poss.insert(p1.first);
    }
    if(p1.first == p2.second){
        poss.insert(p1.first);
    }
    if(p1.second == p2.first){
        poss.insert(p2.first);
    }
    if(p1.second == p2.second){
        poss.insert(p2.second);
        
    }
    set<pll> removals;
    set<ll> removals1;
    ll removedPrev = -1;
    rep(i,0,m-2){
        input(p1.fi);
        input(p1.second);
        if(sz(poss) == 1){
            if(p1.fi != *poss.begin()){
                pairs.insert({p1.second,*poss.begin()});
            }
            else{
                pairs.insert({p1.first,*poss.begin()});
            }
            
        }
        for(const auto& p: pairs){
            if(!intersects1(p,p1)){
                removals.insert(p);
            }
        }
        for(pll p: removals){
            pairs.erase(p);
        }
        for(ll p: poss){
            if(p1.fi != p && p1.se != p){
                removals1.insert(p);
                if(!pairs.count({p1.fi,p})){
                    pairs.insert({p,p1.fi});
                }
                if(!pairs.count({p1.se,p})){
                    pairs.insert({p,p1.se});
                }
                for(ll j1: poss){
                    if(j1 != p){
                        if(!pairs.count({j1,p})){
                            pairs.insert({p,j1});
                        }
                    }
                }
            }
        }
        for(ll p: removals1){
            poss.erase(p);
        }
        removals.clear();
        removals1.clear();

        
    }
    
    x = 0;
    for(pll p: pairs){
        if(!(poss.count(p.first) || poss.count(p.second))){
            x++;
        }
    }
    if(sz(poss) == 1){
        x += n-1;
    }
    if(sz(poss) == 2){
        x += 2*n-3;
    }
    out(x);

    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    //cin >> t;
    while (t--){
        solve();
        out("\n");
    }
    return 0;
}
