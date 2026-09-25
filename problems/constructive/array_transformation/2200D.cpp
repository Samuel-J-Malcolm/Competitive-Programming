/*
Link:
Rating:
*/

#include <bits/stdc++.h>
using namespace std;


using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;

using vi  = vector<int>;
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
#define sz(x)   (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using str = string;


// Constants
const ll INF  = 1e18;
const int INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void solve()
{
    int l;
    cin >> l;
    vi v(l);
    pii p;
    cin >> p.fi;
    cin >> p.se;
    ll pl = p.se-p.fi;
    ll mn = INF32;
    ll minIdx = 0;
    ll ploc = l; 
    rep(i,0,l){
        cin >> v[i];
        if(p.fi <= i && p.se > i){
            if(v[i] < mn){
                mn = v[i];
                minIdx = i-p.fi;
            }
        }
    }
    rep(i,0,p.fi){
        if(v[i] > mn){
            ploc = i;
            break;
        }
    }
    if(ploc == l){
        rep(i,p.se,l){
            if(ploc == l && v[i] > mn){
                ploc = i;
                break;
            }
        }
    }
    str portal = "";
    rep(i,0,l){
        if(p.fi <= i && p.se > i){
            ll idx =  (i - p.fi  + minIdx) % pl;
            if(idx < 0){
                idx += pl;
            }
            portal += to_string(v[ p.fi + idx]);
            if(i != l){
                portal += " ";
            }
        }
    }
    rep(i,0,l){
        if(i == ploc){
            cout << portal;
        }

        if(i == p.fi){
            i = p.se-1;
            if(i == ploc){
                cout << portal;
            }

            continue;
        }
        else{
            cout << v[i];
            if(i != l-1 || ploc == l){
                cout << " ";
            }
        }
        
    }
    if(l == ploc){
        cout << portal;
    }

    cout << "\n";
    

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
