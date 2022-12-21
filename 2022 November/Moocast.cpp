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
using vll = vector<long long>;
using vb = vector<bool>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

using namespace std;

int N;
vector<vi> adjList;
vector<pi> cowPos;
vi cowStrength;
vb visited;

int sumVisited;

void DFS(int a){
    if(visited[a]){
        return;
    } else {
        visited[a] = true;
        sumVisited++;
        for(int i = 0; i < adjList[a].size(); i++){
            DFS(adjList[a][i]);
        }
    }
}

int main(){
    ifstream input("moocast.in");
    ofstream output("moocast.out");
    input >> N;
    adjList.rsz(N);
    visited.rsz(N);
    for(int i = 0, x, y, p; i < N; i++){
        input >> x >> y >> p;
        cowPos.pb(mp(x, y));
        cowStrength.pb(p);
    }

    for (int i = 0; i < sz(cowPos); i++)
    {
        for (int j = 0; j < sz(cowPos); j++)
        {
            double distance = sqrt(pow(cowPos[i].f - cowPos[j].f, 2) + pow(cowPos[i].s - cowPos[j].s, 2));
            // cout << distance << endl;
            if(j != i && distance <= cowStrength[i]){
                adjList[i].pb(j);
            }
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << i << ":" << endl;
    //     for (int j = 0; j < adjList[i].size(); j++)
    //     {
    //         cout << adjList[i][j] << " ";
    //     }
    //     cout << endl;
        
    // }
    


    sumVisited = 0;
    int maxVisited = 0;
    for (int i = 0; i < N; i++)
    {
        DFS(i);
        fill(all(visited), false);
        maxVisited = max(maxVisited, sumVisited);
        sumVisited = 0;

    }
    output << maxVisited;
    
}