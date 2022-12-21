#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

int N, K;
vector<vi> adjList;
set<int> inCycle;
vector<bool> visited;

void DFS(int a, vi soFar){
    if(visited[a]){
        return;
    } else {
        visited[a] = true;
        soFar.pb(a);
        for (int i = 0; i < adjList[a].size(); i++)
        {
            vi::iterator itr = find(all(soFar), adjList[a][i]);
            if(soFar.end()!=itr){
                for (vi::iterator j = itr; j != soFar.end(); ++j)
                {
                    inCycle.insert(*j);
                }
            } else {
                DFS(adjList[a][i], soFar);
            }
        }
        
    }
}

int main(){
    cin >> N >> K;
    visited.rsz(N);
    adjList.rsz(N);
    for (int  i = 0, a, b, score1, score2; i < K; i++)
    {
        cin >> a >> b >> score1 >> score2;
        if(score1 > score2){
            adjList[a - 1].pb(b - 1);
        } else {
            adjList[b - 1].pb(a - 1);
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << endl << i << endl;
    //     for (int j = 0; j < adjList[i].size(); j++)
    //     {
    //         cout << adjList[i][j] << " ";
    //     }
    //     cout << endl;
        
    // }
    

    for (int i = 0; i < N; i++)
    {
        fill(all(visited), false);
        vi empty;
        DFS(i, empty);
    }

    // cout << endl << "in a cycle: ";
    // for (int a : inCycle){
    //     cout << a<< " ";
    // }
    
    cout << inCycle.size();
}