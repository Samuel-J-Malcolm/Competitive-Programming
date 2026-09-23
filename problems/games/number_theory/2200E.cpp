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
    bool test = true;
    bool ones = true;
    for(auto& x: v){
        cin >> x;
    }
    bool g = true;

    rep(i,0,l-1){
        if(v[i] > v[i+1]){
            g= false;        
        }
        else{
        }
    }
    if(g){
        cout << "Bob\n";
        return;
    }
    for(auto& x: v){
        ll fac = 2;
        if(x == 1){
            continue;
        }
        bool div = false;
        while(fac*fac <= x){
            while(x % fac == 0){
                div = true;
                x /= fac;
            }
            if(div && x > 1){
                cout << "Alice\n";
                return;
            }
            else if(div){
                x = fac;
            }
            fac++;
        }
    }
    g = true;

    rep(i,0,l-1){
        if(v[i] > v[i+1]){
            cout << "Alice\n";
            return;
        }
    }

    cout << "Bob\n";
    

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
