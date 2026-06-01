/*
Link: https://codeforces.com/problemset/problem/2008/E
Rating: 1500
Duration: 30m
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
using str = string;


// Constants
const ll INF  = 1e18;
const ll INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void solve()
{
    ll l;
    str s;
    cin >> l;
    cin >> s;
    set<char> chars;
    set<pair<char,char>> pairs;
    map<char,ll> freq;
    for(char c: s){
        chars.insert(c);
        freq[c]++;
    }
    for(char c: chars){
        for(char c1: chars){
            pairs.insert({c,c1});
        }
    }
    int minO = 1e6;
    bool firstPair = true;
    for(auto p: pairs){
        int ops = 0;
        if(l-freq[p.fi]-freq[p.se]-1>=minO){
            continue;
        }
        if(l % 2 == 0){
            rep(i,0,l){
                if(!((i%2 == 0 && p.fi == s[i]) || (p.se == s[i] && i % 2 == 1))){
                    ops++;
                }
                if(ops == minO){
                    break;
                }

            }
            minO = min(minO,ops);
        }
        else{
            int parity = 0;
            rep(j,0,l){
                ops = 0;
                str newS = s.substr(0,j);
                if(j != l-1){
                    newS += s.substr(j+1);
                }
      //          cout << newS << " ";
                rep(i,0,l-1){
                    if(!((i%2 == 0 && p.fi == newS[i]) || (p.se == newS[i] && i % 2 == 1))){
                        ops++;
                    }
                    if(ops == minO){
                        break;
                    }
                }
                minO = min(minO,ops);

            }
            
        }
    }
    cout << minO + l % 2<< "\n";


    

    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
