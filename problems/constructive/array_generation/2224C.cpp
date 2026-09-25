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
    str s1,s2;
    cin >> l;
    cin >> s1;
    cin >> s2;
    pii m1 = {0,0};
    rep(i,0,l){
        char c1 = s1[i];
        char c2 = s2[i];
        if(c1 == c2){
            if(c1 == '('){
                m1.fi += 1;
                m1.se += 1;
            }else{
                m1.fi -= 1;
                m1.se -= 1;
            }
            
        }
        if(c1 != c2){
            if(m1.se == m1.fi){
                m1.se--;
                m1.fi++;
            }
            else{
                m1.se++;
                m1.fi--;
            }
        }
        if(m1.fi < m1.se){
            cout << "ERR";
        }
        if(m1.se < 0){
            cout << "NO\n";
            return;
        }    
        
    }
    if(m1.se == 0 && m1.fi == 0){
            cout << "YES\n";
            return;
        }    
    cout << "NO\n";

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
