/*
Link: https://codeforces.com/contest/2233/problem/C
Rating:
Platform:
Duration: 
*/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>


typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pintint = pair<int, int>;
using pintl = pair<int, ll>;
using pll = pair<ll, ll>;

using vint  = vector<int>;
using vll = vector<ll>;
using vvint = vector<vint>;
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

#define NO print("NO"); return;
#define YES print("YES"); return;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif


// Constants
const ll INF  = 1e18;
const ll INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

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
int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
 
	vector<int> pref_open(n + 1);
	vector<int> pref_close(n + 1);
 
	for (int i = 0; i < n; i++){
		pref_open[i + 1] = pref_open[i] + (s[i] == '(');
		pref_close[i + 1] = pref_close[i] + (s[i] == ')');
	}
 
	int total_close = pref_close[n];
 
	int pos = n;
	for (int i = 0; i < n; i++){
		if (pref_open[i] + total_close - pref_close[i] <
			pref_open[pos] + total_close - pref_close[pos]){
				pos = i;
		}
	}
 
	string ans(n, '0');
	for (int i = 0; i < pos; i++){
		if (k > 0 && s[i] == '('){
			ans[i] = '1';
			k--;
		}
	}
	for (int i = pos; i < n; i++){
		if (k > 0 && s[i] == ')'){
			ans[i] = '1';
			k--;
		}
	}
 
	cout << ans;
}

// 1
// 0

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
