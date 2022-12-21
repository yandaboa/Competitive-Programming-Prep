#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi= vector<vector<int> >;
using vll = vector<long long>;
using vpi = vector<pair<int, int> >;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

int N;

ll shortest(ll from, ll to){
    ll counter = 0;
    while(from >= to*2){
        if(from%2 == 0){
            from/=2;
        } else {
            from--;
        }
    }
    
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vi reduced;
        ll a, b;
        cin >> a >> b;
        ll temp = a;
        while(temp > 0){
            if(temp%2 == 0){
                temp /= 2;
            } else {
                temp++;
            }
            reduced.pb(temp);
        }
        ll minVal = LONG_MAX;
        for (int i = 0; i < sz(reduced); i++)
        {
            minVal = min(minVal, shortest(b, reduced[i]));    
        }
        
    }
    
}