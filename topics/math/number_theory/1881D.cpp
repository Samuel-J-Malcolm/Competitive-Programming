/*
Link: https://codeforces.com/contest/1881/problem/D
Rating: 900
Duration: X
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

// Constants
const ll INF  = 1e18;
const int INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void solve()
{
    int l;
    cin >> l;
    map<int,int> factors;
    int tot = 0;
    rep(i,0,l){
       int input;
       cin >> input;
       int c = 2;
       while(input > 1){
        if(input % c == 0){
            factors[c]++;
            tot++;
            if(factors[c] == l){
                tot -= l;
                factors[c] = 0;
            }
            input /= c;
        }
        else{
            c++;
        }
        if(c>1000){
            c = input;
        } 
       } 
    }
    if(tot == 0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

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
