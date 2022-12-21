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
vi cities, towers;

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

    // for (int i = 0; i < sz(towers); i++)
    // {
    //     cout << towers[i] << " ";
    // }
    
    // cout << endl;

    int maxDiff = INT_MIN;
    for (int i = 0; i < sz(cities); i++)
    {
        int lo = 0, hi = sz(towers) - 1;
        while(lo < hi){
            int mid = (lo + hi)/2;
            if(towers[mid] > cities[i]){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        maxDiff = max(maxDiff, min(abs(cities[i] - towers[lo]), abs(cities[i] - towers[max(0, lo - 1)])));
    }

    cout << maxDiff;
    
    
}