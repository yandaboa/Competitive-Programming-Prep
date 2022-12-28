#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <climits>
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

ll N, T;
vll machines;

bool works(ll a){
    ll toys = 0;
    for (int i = 0; i < sz(machines); i++)
    {
        toys += a/machines[i];
    }
    return toys >= T;
    
}

int main(){
    cin >> N >> T;
    machines.rsz(N); ll maxV;
    for (int i = 0; i < N; i++)
    {
        cin >> machines[i];
        maxV = max(maxV, machines[i]);
    }
    ll lo = 0, hi = maxV*T;
    while(lo < hi){
        ll mid = lo + ((hi - lo)/2);
        // cout << mid << endl;
        if(works(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo;
}