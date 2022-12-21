#include <iostream>
#include <vector>
#include <limits>
#include <climits>
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
using vpi = vector<pair<int, int> >;
using vll = vector<long long>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

int N;

vector<vector<long long> > dist;
vpi coords;
vector<vb> adjMatrix;
int visited = 0;
vector<bool> vis;

void buildMatrix(ll M){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(dist[i][j] <= M){
                adjMatrix[i][j] = true;
            }
        }
    }
    
}

void DFS(int a){
    
    if(vis[a]){
        return;
    } else {
        // cout << a << " ";
        visited++;
        vis[a] = true;
        for (int i = 0; i < N; i++)
        {
            if(adjMatrix[a][i]){
                DFS(i);
            }
        }
    }
}

int main(){
    ifstream input("moocast.in");
    ofstream output("moocast.out");
    input >> N;
    adjMatrix.rsz(N);
    vis.rsz(N);
    for (int i = 0; i < N; i++)
    {
        adjMatrix[i].rsz(N);
    }
    
    for (int  i = 0; i < N; i++)
    {
        double x, y;
        input >> x >> y;
    
        coords.pb(mp(x, y));
    }

    dist.rsz(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist[i].pb(pow(coords[i].f - coords[j].f, 2) + pow(coords[i].s - coords[j].s, 2));
            // cout << dist[i][j] << " ";
        }
        // cout << endl;
    }
    

    long long hi = pow(25000, 2), lo = 0;
    while(lo < hi){
        ll mid = (lo + hi)/2;
        // cout << mid << " ";
        buildMatrix(mid);
        visited = 0;
        fill(all(vis), false);
        DFS(0);
        for (int i = 0; i < N; i++)
        {
            fill(all(adjMatrix[i]), false);
        }
        
        if(visited == N){
            // cout << "true" << endl;
            hi = mid;
        } else {
            // cout << endl;
            lo = mid + 1;
        }
    }
    output << lo;
    input.close();
    output.close();
    
}