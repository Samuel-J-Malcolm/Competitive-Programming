/*
Link: https://codeforces.com/contest/2232/problem/C1
Rating:
Platform:
Duration: 
*/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>


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
#define repn(i, a, b, c) for (ll i = (a); i >= (b); i-=c)

using str = string;

#define NO print("NO"); return;
#define YES print("YES"); return;

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


void solve()
{
    ll m,n,k,x;
    bool b;
    str s;
    cin >> n;
    cin >> k; //tables
    cin >> x; //seats per table
    cin >> s;
    ll ambiverts = 0;
    rep(i,0,n){
        if(s[i] == 'A'){
            ambiverts++;
        }
    }
    ll seatable;
    ll cTotal = 0;
    ll mTotal = 0;
    rep(i,0,min(ambiverts,k)+1){
        ll intro = i;
        ll extrovertSlots = 0;
        ll introvertSlots = k;
        rep(i,0,n){
            if(s[i] == 'I'){
                if(introvertSlots > 0){
                    introvertSlots--;
                    extrovertSlots += x-1;
                    cTotal++;
                }
                
            }
            else if((intro > 0 && s[i] == 'A' && introvertSlots > 0)){
                if(introvertSlots > 0){
                    introvertSlots--;
                    extrovertSlots += x-1;
                    cTotal++;
                    intro--;
                }
            }
            else{
                if(extrovertSlots > 0){
                    extrovertSlots--;
                    cTotal++;
                }

            }
        }
        mTotal  = max(cTotal,mTotal);
        cTotal = 0;
    }
    cout << mTotal;
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
    return 0;
}
