#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <climits>
#include <string.h>
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
//cin.tie(0)->sync_with_stdio(0);

int L, N, rf, rb, diff;

int main(){
    ifstream input("reststops.in");
    ofstream output("reststops.out");
    input >> L >> N >> rf >> rb;
    diff = rf - rb;
    vpi restStops;
    restStops.pb(mp(0, 0));
    for (int i = 0; i < N; i++)
    {
        int pos, val; input >> pos >> val;
        restStops.pb(mp(pos, val));
    }
    ll totalTastiness = 0;
    vi biggestAfter; biggestAfter.rsz(sz(restStops));
    int largestInd = sz(restStops) - 1, largestVal = 0;
    for (int i = sz(restStops) - 1; i >= 0; i--)
    {
        if(restStops[i].s > largestVal){
            largestVal = restStops[i].s;
            largestInd = i;
        }
        biggestAfter[i] = largestInd;
    }
    // for (int i = 0; i < sz(biggestAfter); i++)
    // {
    //     cout << biggestAfter[i] << " ";
    // }
    int nextInd = 0, lastInd = 0;
    while(nextInd < sz(biggestAfter)){
        int currInd = biggestAfter[nextInd];
        ll temp = restStops[currInd].f - lastInd; lastInd = restStops[currInd].f;
        temp *= diff; temp *= restStops[currInd].s; totalTastiness += temp;
        nextInd = currInd + 1;
    }

    output << totalTastiness;
}