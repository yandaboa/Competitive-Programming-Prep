#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <fstream>

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
vector<pair<ll, ll> > arr;

int main(){
    ifstream input("pairup.in");
    ofstream output("pairup.out");

    input >> N;
    for (int i = 0; i < N; i++)
    {
        ll occs, val;
        input >> occs >> val;
        arr.pb(mp(val, occs));
    }
    sort(all(arr));

    int lo = 0, hi = sz(arr) - 1;
    ll maxVal = 0;
    while(lo < hi){
        maxVal = max(maxVal, arr[lo].f + arr[hi].f);
        if(arr[lo].s > arr[hi].s){
            arr[lo].s -= arr[hi].s;
            hi--;
        } else if(arr[lo].s == arr[hi].s){
            lo++;
            hi--;
        } else {
            arr[hi].s -= arr[lo].s;
            lo++;
        }
    }
    output << maxVal;
}