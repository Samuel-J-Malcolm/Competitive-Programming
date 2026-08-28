/*
Link: https://atcoder.jp/contests/abc470/tasks/abc470_c
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

void solve(){
    ll m,n,k,x,in;
    bool b;
    str s;
    input(n);
    input(m);
    set<int> g1 = {};
    vector<int> v(n);
    int xor1 = 0;
    rep(i,0,m){
        input(k);
        if(k == 1){
            input(k);
            xor1 ^= v[k];
            v[k]++;
            xor1 ^= v[k];
            g1.insert(k);
        }
        else{
            vector<int> erases;
            for(int j: g1){
                xor1 ^= v[j];
                v[j]--;
                xor1 ^= v[j];
                if(v[j] == 0){
                    erases.push_back(j);
                }
            }
            for(int j: erases){
                g1.erase(j);
            }
        }
        out(xor1,"\n");
    }
    
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    //cin >> t;
    while (t--){
        solve();
        //out("\n");
    }
    return 0;
}
