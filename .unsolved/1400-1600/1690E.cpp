/*
Link: https://codeforces.com/problemset/problem/1690/E
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
#define repi(i,a,b) for (ll i = (a); i > (b); i--)
using str = string;

void printstruct(auto& s){
    cout << "(";
    for(auto c: s){
        cout << c << " ";
    }
    cout << ")";
    cout << "\n";
    
}

// Constants
const ll INF  = 1e18;
const ll INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void solve()
{
    ll l;
    ll n;
    cin >> l;
    cin >> n;
    vi v(n);
    int sum = 0;
    ll in; 

    rep(i,0,l){
        cin >> in;
        v[in % n]++;
        sum += (in / n);
    }
  //  printstruct(v);
    v[0] = v[0] % 2;
    
    rep(d,0,n-1){
        rep(j,1,n){
        //    cout << v[j] << " ";
            if(v[j] == 0){
                continue;
            }

            int idx = (n-j+d) % n;
       //     cout << idx << " ";
            if(j + idx < n){
              //  cout << "!";
                continue;
            }
            if(v[idx] == 0){
                continue;
            }
            int m = min(v[j],v[idx]); // n-i+j % n
            if(idx == j){
                m /= 2;
            }

            v[j] -= m;
            v[idx] -= m;
            sum += m;
            if(v[j] == 0){
                break;
            }
        }
    }
    cout << sum;

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
