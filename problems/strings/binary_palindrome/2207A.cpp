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
    vi v;
    int l;
    str s;
    cin >> l;
    cin >> s;
    int cur = 0;
    bool prev0 = true;
    bool prev00 = true; 
    rep(i,0,l){
        if(s[i] == '0'){
            if(prev00){
                int a = 1;
            }
            else if(prev0){
                v.emplace_back(cur-1);
                cur = 0;

                prev00 = true;
            }
            else{
                prev0 = true;
                cur++;
            }
        }
        else{
            prev0 = false;
            prev00 = false;
            cur++;
        }
    }
    if(prev00){
        int a = 1;
    }
    else if(prev0){
        v.emplace_back(cur-1);
    }
    else{
        v.emplace_back(cur);

    }
    int min = 0;
    int max = 0;
    for(int i: v){
        min += (i+2) / 2;
        max += i;
    }
    cout << min << " " << max << "\n";
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
