/*
Link: https://codeforces.com/contest/2252/problem/D
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
    int idx = 0;
    for(auto c: s){
        cout << c;
        idx++;
        if(idx != sz(s)){
            cout << " ";
        }
        
    }    
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
    vll v(n);
    vll post_sub(n);
    post_sub[0] = -1;
    post_sub[n-1] = -1;
    rep(i,0,n){
        input(v[i]);
    }
    ll max_sub = 0;
    rep(i,1,n-1){
        if((v[i-1]+v[i+1]) % 2 == 0){
            post_sub[i] = v[i]*2-v[i+1]-v[i-1];
            max_sub = max(max_sub,post_sub[i]);
        }
    }
    ll maxi;
    while(max_sub > 0){
        max_sub = 0;
        rep(i,1,n-1){
            if(post_sub[i] > 0){
                maxi = i;
                max_sub = post_sub[i];
                break;
            }
        }
        if(max_sub <= 0){
            break;
        }
        v[maxi] -= max_sub;
        if(post_sub[maxi+1] != -1){
            post_sub[maxi+1] -= post_sub[maxi];
        }
        if(post_sub[maxi-1] != -1){
            post_sub[maxi-1] -= post_sub[maxi];
        }
        post_sub[maxi] = v[maxi]*2-v[maxi+1]-v[maxi-1];
    }
    printstruct(v);
    

    

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
