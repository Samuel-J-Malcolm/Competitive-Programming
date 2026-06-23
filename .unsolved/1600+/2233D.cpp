/*
Rating:
Platform:
Duration: 
*/

#include <bits/stdc++.h>
using namespace std;


using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pii = pair<ll, ll>;
using pll = pair<ll, ll>;

using vi  = vector<ll>;
using vll = vector<ll>;
using vvi = vector<vi>;
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
using str = string;

#define print(a) cout << a;
#define println(a) cout << a << "\n";
#define NO print("NO"); return;
#define YES print("YES"); return;


// Constants
const ll INF  = 1e18;
const ll INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

bool check(vll& v){
    set<ll> prevComplete;
    rep(i,1,sz(v)){
        if(v[i] != v[i-1]){
            if(prevComplete.count(v[i])){
                return false;
            }
            else{
                prevComplete.insert(v[i-1]);
                
            }
        }
    }
    return true;
}

void swap(vll& v,pll p){
    ll temp = v[p.fi];
    v[p.fi] = v[p.se];
    v[p.se] = temp;
}

bool checkswap(vll& v,pll p){
    swap(v,p);
    bool b = check(v);
    swap(v,p);
    return b;
}


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
    ll l;
    cin >> l;
    vi v(l);
    rep(i,0,l){
        cin >> v[i];
    }
    pll swap1 = {-1,-1};
    pll swap2 = {-1,-1};
    pll swap3 = {-1,-1};
    pll swap4 = {-1,-1};
    pll swap5 = {-1,-1};
    pll swap6 = {-1,-1};

    map<int,pll> pos;
    set<ll> prevComplete;
    pos[v[0]].fi = 0;
    ll e = -1;
    rep(i,1,l){
        if(v[i] != v[i-1]){
            if(prevComplete.count(v[i])){
                swap1 = {max(pos[v[i]].fi-1,0LL),i};
                swap2 = {min(pos[v[i]].se+1,l-1),i};
                swap3 = {i-1,pos[v[i]].fi};
                swap4 = {min(i+1,l-1),pos[v[i]].fi};
                swap5 = {i,pos[v[i-1]].fi};
                while(i < l && v[i] == v[i+1]){
                    i++;
                }
                swap6 = {min(i+1,l-1),pos[v[i-1]].fi};

                break;
            }
            else{
                prevComplete.insert(v[i-1]);
                pos[v[i-1]].se = i-1;
                pos[v[i]].fi = i;
           //     gBegin = i;
            }
        }
    }
    
    if(check(v) || checkswap(v,swap1) || checkswap(v,swap2) || checkswap(v,swap3) || checkswap(v,swap4) || checkswap(v,swap5) || checkswap(v,swap6)){
        YES
    }
    NO

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
