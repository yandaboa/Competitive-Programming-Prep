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

int N, M;
vb flightTraveled;
vector<set<pair<pair<int, int>, int > > > airports;
vi flightDest;
vi layovers;
vi fastestArrival;

void DFS(int a, int time){
    if(time >= fastestArrival[a]){
        return;
    } else {
        fastestArrival[a] = time;
    }
    if(!(a == 0 && time == 0)){
        time += layovers[a];
    }
    //write binary search myself if this doesnt work ig
    auto itr = airports[a].lower_bound(mp(mp(time, 0), 0));
    for(auto b = itr; b != airports[a].end(); b++){
        pair<pair<int, int>, int> flight = *b;
        if(!flightTraveled[flight.s]){
            flightTraveled[flight.s] = true;
            DFS(flightDest[flight.s], flight.f.s);
        }
    }
}

int main(){
    cin >> N >> M;
    flightTraveled.rsz(M); fastestArrival.rsz(N); airports.rsz(N); layovers.rsz(N); flightDest.rsz(M); fill(all(fastestArrival), INT_MAX);

    for (int i = 0; i < M; i++)
    {
        int from, ft, dest, dt; cin >> from >> ft >> dest >> dt; from--; dest--;
        airports[from].insert(mp(mp(ft, dt), i));
        flightDest[i] = dest;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> layovers[i];
    }
    DFS(0, 0);
    for (int i = 0; i < sz(fastestArrival); i++)
    {
        if(fastestArrival[i] == INT_MAX){
            cout << -1 << endl;
            continue;
        }
        cout << fastestArrival[i] << endl;
    }
}