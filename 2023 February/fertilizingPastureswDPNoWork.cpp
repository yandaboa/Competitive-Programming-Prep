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

ll N, T, currTime;
ll totalSum;
vll costs; vb visited;
vvi paths;
vll subtreeLength, subtreeCost, subtreeSum;

ll BFS(int a){ //idek if this is a BFS I gotta go study more gold techniques bruh
    if(visited[a]){
        return 0;
    }
    visited[a] = true;
    ll cost = costs[a];
    int children = 0;
    multiset<pair<ll, int> > childCosts;
    for (int i = 0; i < sz(paths[a]); i++)
    {
        if(!visited[paths[a][i]]){
            children++;
            childCosts.insert(mp(subtreeSum[paths[a][i]], paths[a][i]));
        }
    }
    if(children == 0){
        subtreeCost[a] = cost;
        return cost;
    }
    ll counter = a == 0 ? 0 : 1;
    for(auto itr = childCosts.rbegin(); itr != childCosts.rend(); itr++){
        if(a == 0){
            // cout << (*itr).f << " " << (*itr).s << endl;
        }
        cost += (counter)*(*itr).f;
        cost += BFS((*itr).s);
        counter += 2 + subtreeLength[(*itr).s];
    }
    subtreeCost[a] = cost;
    return cost;
}

ll calcSums(int a){ //maybe return if there is already a sum if there are TLE errors
    if(visited[a]){
        return 0;
    }
    visited[a] = true;
    ll sum = costs[a];
    for (int i = 0; i < sz(paths[a]); i++)
    {
        sum += calcSums(paths[a][i]);
    }
    subtreeSum[a] = sum;
    return sum;
}

int calcLengths(int a){
    if(visited[a]){
        return 0;
    }
    visited[a] = true;
    int children = 0;
    for (int i = 0; i < sz(paths[a]); i++)
    {
        if(!visited[paths[a][i]]){
            children += 1 + calcLengths(paths[a][i]);
        }
    }
    subtreeLength[a] = 2*children;
    return children;
}

int main(){
    cin >> N >> T; costs.rsz(N); paths.rsz(N); visited.rsz(N); subtreeLength.rsz(N); subtreeSum.rsz(N); subtreeCost.rsz(N); totalSum = 0;
    //solve when T = 0 first
    for (int i = 1; i < N; i++)
    {
        ll connection, cost; cin >> connection >> cost; connection--;
        costs[i] = cost;
        paths[connection].pb(i);
        paths[i].pb(connection);
    }
    calcSums(0);
    fill(all(visited), false);
    calcLengths(0);
    // for(int i = 0; i < sz(subtreeLength); i++){
    //     cout << subtreeLength[i] << endl;
    // }
    fill(all(visited), false);
    cout << subtreeLength[0] << " " << BFS(0) << endl;
    // for(int i = 0; i < sz(subtreeCost); i++){
    //     cout << subtreeCost[i] << endl;
    // }
}