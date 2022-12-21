#include <iostream>
#include <vector>
#include <limits>
#include <climits>
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

int K, M, N;
vi enemCows, validPlacements;
vpi patches;
vpi intervals;

int main(){

    cin >> K >> M >> N;

    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        patches.pb(mp(a, b));
    }
    sort(all(patches));

    enemCows.rsz(M);
    for (int i = 0; i < M; i++)
    {  
       cin >> enemCows[i]; 
    }
    sort(all(enemCows));
    for (int i = 0; i < sz(patches); i++)
    {
        int lo = 0, hi = enemCows.size() - 1;
        while(lo < hi){
            int mid = (lo + hi)/2;
            if(enemCows[mid] < patches[i].f){
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        int dist = min(abs(patches[i].f - enemCows[lo]), abs(patches[i].f - enemCows[max(0, lo - 1)]));
        intervals.pb(mp(patches[i].f - dist, patches[i].f + dist));
        // cout << endl << intervals[i].f << " " << intervals[i].s;
    }
    
    int lastMax = intervals[0].s;
    int currSum = intervals[0].f != intervals[0].s ? patches[0].s : 0; 
    for (int i = 1; i < sz(intervals); i++)
    {
        if(intervals[i].f < lastMax){
            if(intervals[i].s != intervals[i].f){
                currSum += patches[i].s;
            }
        } else {
            validPlacements.pb(currSum);
            lastMax = intervals[i].s;
            currSum = intervals[i].f != intervals[i].s ? patches[i].s : 0;
        }
    }
    validPlacements.pb(currSum);

    sort(all(validPlacements));
    
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        // cout << endl << validPlacements[validPlacements.size() - 1 - i];
        sum += validPlacements[validPlacements.size() - 1 - i];
    }
    cout << sum;
    
}