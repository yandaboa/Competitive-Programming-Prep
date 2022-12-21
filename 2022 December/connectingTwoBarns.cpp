//build graph, then run DFS and reach all points - build array of pairs
//each pair contains min and max number in connected component
//if 1 is part of component, start at max of that component, otherwise start at 1
//if N is part of component, end at min of that component, otherwise start at N
//iterate all other components, find min value of (minComponent - start)^2 + (end - maxComponent)^2
//be sure to also consider 2*((end - start)/2)^2

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

int T, minVal, maxVal;

void DFS(int a, vvi adjList, vb &visited){
    if(visited[a]){
        return;
    } else {
        // cout << a << " ";
        visited[a] = true;
        minVal = min(minVal, a);
        maxVal = max(maxVal, a);
        for (int i = 0; i < adjList[a].size(); i++)
        {
            DFS(adjList[a][i], adjList, visited);
        }
    }
}

int main(){
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        int N, M;
        ll dist = LONG_MAX;
        cin >> N >> M;
        vvi adjList;
        vb visited;
        vpi components;
        minVal = INT_MAX;
        maxVal = -1;

        adjList.rsz(N);
        visited.rsz(N);

        for (int j = 0; j < M; j++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adjList[a].pb(b);
            adjList[b].pb(a);
        }
        for (int j = 0; j < N; j++)
        {
            if(!visited[j]){
                // cout << endl;
                DFS(j, adjList, visited);
                // cout << endl;
                components.pb(mp(minVal, maxVal));
                minVal = INT_MAX;
                maxVal = -1;
            }
        }

        // cout << endl;

        // for (int j = 0; j < sz(components); j++)
        // {
        //     cout << components[j].f << " " << components[j].s << endl;
        // }
        
        
        sort(all(components));
        int start = components[0].s, end = components[sz(components) - 1].f;
        for (int i = 1; i < sz(components) - 1; i++)
        {
            dist = min(dist, ((ll)(components[i].s - start))*(components[i].s - start) + ((ll)(end - components[i].f))*(end - components[i].f));
        }
        dist = min(dist, ((ll)(end - start))*(end - start));
        cout << dist << endl;
        // dist = min(dist, pow((end - start)/2, 2));
        // cout << dist << endl;
    }
    
}