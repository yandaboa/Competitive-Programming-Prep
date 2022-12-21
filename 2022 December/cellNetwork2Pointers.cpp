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

int N, M;
vll cities, towers;

int main(){
    cin >> N >> M;
    cities.rsz(N);
    towers.rsz(M);

    for (int i = 0; i < N; i++)
    {
        cin >> cities[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> towers[i];
    }

    int cit = 0, tow = 0;
    ll maxDist = LONG_MIN;
    while(cit < sz(cities)){
        ll minDist = LONG_MAX;
        // cout << cit << ": ";
        while(tow < sz(towers) && towers[tow] < cities[cit]){
            // cout << tow << " ";
            minDist = min(abs(towers[tow] - cities[cit]), minDist);
            tow++;
        }
        minDist = min(abs(towers[min(sz(towers) - 1, tow)] - cities[cit]), minDist);
        if(tow > 0){
            tow--;
        }
        maxDist = max(minDist, maxDist);
        // cout << endl;
        cit++;
    }
    cout << maxDist;
    
    
}