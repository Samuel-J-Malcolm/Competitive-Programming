/*


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
    int l = 0;
    cin >> l;
    vll a(l);
    vll v(l);
    for(auto&x: a){
        cin >> x;
    }
    ll m = -1e11;
    int count = 1;
    rep(i,0,l){
        cin >> v[i];
        v[i] = a[i] - v[i];
        if(v[i] > m){
            count = 1;
            m = v[i];
        }
        else if(v[i] == m){
            count++;
        }
        
    }
    cout << count << "\n";
    rep(i,0,l){
        if(v[i] == m){
            cout << i+1 << " ";
        }
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
