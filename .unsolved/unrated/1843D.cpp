/*
Link: https://codeforces.com/problemset/problem/1843/D
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

#define NO cout << ("NO"); return;
#define YES cout << ("YES"); return;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif


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

vvll adj;
vll parent;

void dfs(ll p,ll nparent){
    for(ll c: adj[p]){
        if(c == nparent){
            continue;
        }
        parent[c] = p;
        dfs(c,p);
    }
}

void solve(){
    adj.clear();
    parent.clear();
    ll m,n,k,x,input;
    bool b;
    str s;
    cin >> n;
    adj.resize(n+1);
    parent.resize(n+1);
    vll leaves(n+1);
    rep(i,0,n-1){
        cin >> m;
        cin >> k;
        adj[m].push_back(k);
        adj[k].push_back(m);
    }
    dfs(1,0);
    rep(i,2,n+1){
        if(sz(adj[i] ) != 1){
            //cout << "!" << i;
            continue;
        }
        ll j = i;
        leaves[i]++;
        while(parent[j] != 1){
            j = parent[j];
            leaves[j]++;
        }
        leaves[1]++;
    }
    //printstruct(parent);

    //printstruct(leaves);
    cin >> n;
    
    rep(i,0,n){
        cin >> m;
        cin >> k;
        cout << leaves[k] * leaves[m] << "\n";
    
    }
    leaves.clear();

    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--){
        solve();
        //cout << "\n";
    }
    return 0;
}
