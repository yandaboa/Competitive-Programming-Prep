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

int N;
vvi blockedBy;
vector<pair<pair<int, int>, int>> northCows, eastCows;
vi northStops, eastStops;
vi numStopped;

int DFS(int a){
    if(numStopped[a]!=-1){
        return numStopped[a];
    }
    int sum = sz(blockedBy[a]);
    for (int i = 0; i < sz(blockedBy[a]); i++)
    {
        sum += DFS(blockedBy[a][i]);
    }
    numStopped[a] = sum;
    return sum;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char facing; cin >> facing; int x, y; cin >> x >> y;
        if(facing == 'N'){
            northCows.pb(mp(mp(x, y), i));
        } else {
            eastCows.pb(mp(mp(y,x), i));
        }
    }
    sort(all(northCows)); sort(all(eastCows));
    for (int i = 0; i < sz(eastCows); i++)
    {
        int temp = eastCows[i].f.s;
        eastCows[i].f.s = eastCows[i].f.f;
        eastCows[i].f.f = temp;
    }
    northStops.rsz(sz(northCows)); eastStops.rsz(sz(eastCows)); fill(all(northStops), -1); fill(all(eastStops), -1);
    for (int i = 0; i < sz(northCows); i++)
    {

        for (int j = 0; j < sz(eastCows); j++)
        {
            if(eastCows[j].f.s <= northCows[i].f.s){
                continue;
            }
            if(eastCows[j].f.s == northCows[i].f.s && eastCows[j].f.f == northCows[i].f.f){
                continue;
            }
            if(eastCows[j].f.f > northCows[i].f.f){
                continue;
            }
            if(eastCows[j].f.s - northCows[i].f.s > northCows[i].f.f - eastCows[j].f.f && eastStops[j] == -1){
                northStops[i] = j;
                break;
            } else if(eastCows[j].f.s - northCows[i].f.s < northCows[i].f.f - eastCows[j].f.f){
                eastStops[j] = i;
            }
        }
    }

    for(int i = 0; i < sz(northStops); i++){
        // cout << northStops[i] << " ";
    }

    blockedBy.rsz(N);
    for (int i = 0; i < sz(northStops); i++)
    {
        if(northStops[i] > -1){
            blockedBy[northStops[i] + sz(northCows)].pb(i);
        }
    }
    for (int i = 0; i < sz(eastStops); i++)
    {
        if(eastStops[i] > -1){
            blockedBy[eastStops[i]].pb(i + sz(northCows));
        }
    }
    // for(int i = 0; i < sz(blockedBy); i++){
    //     for(int j = 0; j < sz(blockedBy[i]); j++){
    //         cout << blockedBy[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    numStopped.rsz(N); fill(all(numStopped), -1);
    for (int i = 0; i < sz(numStopped); i++)
    {
        if(numStopped[i] == -1){
            DFS(i);
        }
    }
    vi realVals; realVals.rsz(N);
    for (int i = 0; i < sz(numStopped); i++)
    {
        if(i >= sz(northStops)){
            realVals[eastCows[i - sz(northStops)].s] = numStopped[i];
        } else {
            realVals[northCows[i].s] = numStopped[i];
        }
    }
    for(int i = 0; i < sz(realVals); i++){
        cout << realVals[i] << endl;
    }
    
    
}