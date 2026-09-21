/*
Link: https://cses.fi/problemset/task/1667/
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

void printstruct(const vll& s){
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


void printstruct(const vector<string>& s){
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

vector<int> search1(int n, vvint& v,int start, int end){
    vector<int> parent(n,-1);
    vector<bool> visited(n,false);
    vint path;
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i: v[cur]){
            if(visited[i]){
                continue;
            }
            visited[i] = true;
            parent[i] = cur;
            
            if(i == end){
                while(i != start){
                    path.push_back(i);
                    i = parent[i];
                }
                path.push_back(start);
                reverse(all(path));
                return path;
            }
            q.push(i);
        }
    }
    return {};
}


void solve(){
    ll m,n,k,x1,x2,inp;
    bool b;
    str s;
    in(n);
    in(m);
    vvint v(n);
    pintint p;
    rep(i,0,m){
        in(p.fi,p.se);
        v[p.fi-1].push_back(p.se-1);
        v[p.se-1].push_back(p.fi-1);
    }
    vint path = search1(n,v,0,n-1);
    if(sz(path) == 0){
        out("IMPOSSIBLE");
        return;
    }
    s = "";
    rep(i,0,sz(path)){
        s += to_string(path[i]+1) + " ";
    }
    s.pop_back();
    out(sz(path),"\n");
    out(s);
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
