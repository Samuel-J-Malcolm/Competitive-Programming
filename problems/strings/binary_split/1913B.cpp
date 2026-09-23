
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    string x;
    cin >> x;
    
    vector<int> required_zeros;
    int l = 0;
    int ones = 0;
    required_zeros.push_back(ones);
    for (char i:x){
        if(i == '1'){
            ones++;
        }
        l++;
        required_zeros.push_back(ones);
    }
    int zeros = l-ones;
    for(int i = 0;i <=l;i++){
       // cout << i << " " << zeros << " "<< required_zeros[l-i]<< "\n";
        if((zeros - i == required_zeros[l-i] and zeros>=i) or (l-zeros - i == (l-i)-required_zeros[l-i] and ones>=i)){
            cout << i;
            break;
        }
        if(i == l){
            cout << i;
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
