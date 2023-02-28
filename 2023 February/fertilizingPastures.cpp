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

void BFS(int a){ //idek if this is a BFS I gotta go study more gold techniques bruh
    if(visited[a]){
        return;
    }
    // cout << a << " " << currTime << endl;
    visited[a] = true;
    ll temp = currTime; temp *= costs[a];
    totalSum += temp;
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
        return;
    }
    for (auto i = childCosts.rbegin(); i != childCosts.rend(); i++)
    {  
        currTime++;
        BFS((*i).s);
        currTime++;
    }
    return;
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
    cin >> N >> T; costs.rsz(N); paths.rsz(N); visited.rsz(N); subtreeLength.rsz(N); subtreeSum.rsz(N); subtreeCost.rsz(N); totalSum = 0; currTime = 0;
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
    BFS(0);
    cout << currTime << " " << totalSum << endl;
    // for(int i = 0; i < sz(subtreeCost); i++){
    //     cout << subtreeCost[i] << endl;
    // }
}