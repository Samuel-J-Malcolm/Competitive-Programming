/*
Link: https://www.codechef.com/problems/CONN01
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
#define ps(x) printstruct(x); cout << "\n";
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

void solve(){
    int m,n,k,x,y,in;
    bool b;
    str s;
    vint groups;
    stack<int> q;
    int v,e;
    input(v,e);
    vector<bool> visited(v);
    vvint adj(v);
    rep(i,0,e){
        input(x,y);
        adj[x-1] .push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    rep(i,0,v){
        if(!visited[i]){
            groups.push_back({0});
        }
        else{
            continue;
        }
        q.push(i);
        while(sz(q) > 0){
            int t = q.top();
            for(int j: adj[t]){
                if(visited[j]){
                    continue;
                }
                else{
                    q.push(j);
                    visited[j] = true;
                    groups[sz(groups)-1]++;
                    break;
                }
            }
            if(t == q.top()){
                q.pop();
            }
        }
    }
    ll perms = 1;
    for(int i: groups){
        perms *=i;
        perms %= MOD;
    }
    out(sz(groups)," ",perms);

    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--){
        solve();
        out("\n");
    }
    return 0;
}
