/* 
Link: $url$ 
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
 
ll maximum(vll& v){ 
    ll m = 0; 
    rep(i,0,sz(v)){ 
        m = max(v[i],m); 
    } 
    return m; 
} 
 
void solve(){ 
    ll m,n,k,x,in; 
    bool b; 
    str s; 
    input(n); 
    input(m); 
    vector<ll> v(n);     
    vvll test(20); 
    ll l = m; 
    set<ll> candidates; 
    rep(i,0,20){ 
        l /= 2; 
        if(l == 0){ 
            l = 1; 
        } 
        test[i].resize(l); 
    } 
    candidates.insert(1); 
    rep(i,0,n){ 
        input(v[i]); 
        if(v[i] % 2 == 0){ 
            candidates.insert(v[i] / 2); 
        } 
    } 
    rep(i,0,n){ 
        x = 2; 
        rep(j,0,20){
            set<int> tested; 
            for(ll k: candidates){
                if(k != 1 && k % (x/2) != 0 ){
                    continue;
                }
                if(k != 1){
                    k /= (x/2);
                }
                if(tested.count(k))
                if(k-1 >= test[j].size()){ 
                    continue; 
                } 
                if(x * k == v[i]){ 
                    test[j][k-1] += x; 
                } 
                else{ 
                    test[j][k-1] += min(x-1,v[i]/(k)); 
                } 
            } 
            tested.clear();
            x *= 2; 
        } 
    } 
    rep(i,0,min(m,20LL)){ 
        out(maximum(test[i])); 
        if(i != m-1){ 
            out(" "); 
        } 
    } 
    rep(i,20,m){ 
        out(test[19][0]); 
        if(i != m-1){ 
            out(" "); 
        } 
    } 
     
     
 
} 
 
int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    bool multi = true; 
    //multi = false; 
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
