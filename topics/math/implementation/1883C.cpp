/*

    Link: https://codeforces.com/contest/1883/problem/C

    Duration: X

    Rating: 1000
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
    int n = 1;
    cin >> n;
    int k=1;
    cin >> k;
    int max = 4;
    int x = 0;
    if(k == 2){
        rep(i,0,n){
            cin >> x;
            max = min(max,x % 2);
        }
    }
    if(k == 3){
        rep(i,0,n){
            cin >> x;
            max = min(max,3 - (x % 3));
            if((x % 3) == 0){
                max = 0;
            }
        }
    }
    if(k == 5){
        rep(i,0,n){
            cin >> x;
            max = min(max,5 - (x % 5));
            if((x % 5) == 0){
                max = 0;
            }
        }
    }
    if(k == 4){
        int num = 0;
        rep(i,0,n){
            cin >> x;
            max = min(max,4 - (x % 4));
            if(x % 4 == 2){
                num++;
                if(num > 1){
                    max = 0;
                }
                
            }
            if((x % 4) == 0){
                max = 0;
            }
        }
        if(max == 3 && n > 1){
            max = 2;
        }
        if(max == 2 && num >= 1 && n >= 2){
            max = 1;
        }
    }
    cout << max << "\n";


    

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
