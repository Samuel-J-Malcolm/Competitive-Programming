#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        //exp & 1 means that 
        if (exp & 1) result = result * base;
        base = (base * base); //
        exp >>= 1; //divides by 2
    }
    return result;
}
int main(){

}