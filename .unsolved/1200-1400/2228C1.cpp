/*
Link:
Rating: 1374
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
    str a;
    int n;
    set<int> d;
    cin >> a;
    cin >> n;
    int maxd = -1;
    int mind = 11;
    int minn0 = 11;
    int in;
    rep(i,0,n){
        cin >> in;
        maxd = max(maxd,in);
        mind = min(mind,in);
        if(in != 0){
            minn0 = min(in,minn0);
        }
        d.insert(in);
    }
    vi digits;
    if(minn0 == 11){
        cout << a;
        return;
    }
    pii bounds = {0,minn0*10+mind};
    bool eq = true;
    for(char c: a){
        int x = c - '0';
        if(eq && d.count(x)){
            continue;
        }
        eq = false;
        digits.eb(x);
    }
    int ndiff = sz(digits);
     if(ndiff == 0){
        cout << 0 << "\n";
        return;
    }

    str s1 = a.substr(sz(a)-ndiff);
    ll num = stoll(s1);

   
    for(int i: d){
        if(i < digits[0] && i > bounds.fi){
            bounds.fi = i;
        }
        else if(i > digits[0] && i < bounds.se){
            bounds.se = i;
        }
    }
    pair<str,str> bounds1;
    bounds1.fi = to_string(bounds.fi);
    bounds1.se = to_string(bounds.se);
    rep(i,0,ndiff-1){
        bounds1.fi += to_string(maxd);
        bounds1.se += to_string(mind);
    }
    if(stoll(bounds1.fi) == 0 && !d.count(0)){
        bounds1.fi = to_string(mind);
    }
    cout << min(num - stoll(bounds1.fi),stoll(bounds1.se) - num) << "\n";
    cout << bounds1.fi << " " << bounds1.se << "\n";


    

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
