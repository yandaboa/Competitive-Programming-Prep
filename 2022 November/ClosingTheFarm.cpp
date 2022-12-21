#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <fstream>
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

using namespace std;

void setIO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
}

int N, M;
vector<vi> adjList;
vector<bool> visited, closed;

void DFS(int a){
    if(visited[a]){
        return;
    } else {
        visited[a] = true;
        for (int i = 0; i < sz(adjList[a]); i++)
        {
            if(!closed[adjList[a][i]]){
                DFS(adjList[a][i]);
            }
        }
    }
}

int main(){
    ifstream input("closing.in");
    ofstream output("closing.out");

    setIO();
    input >> N >> M;
    adjList.rsz(N);
    closed.rsz(N);
    visited.rsz(N);
    for(int i = 0, a, b; i < M; i++){
        input >> a >>b;
        adjList[a - 1].pb(b - 1);
        adjList[b - 1].pb(a - 1);
    }

    bool connected = true;
    DFS(0);
    for(int j = 0; j < N; j++){
        if(!visited[j] && !closed[j]){
            connected = false;
        }
    }
    if(connected){
            output << "YES" << endl;
    } else {
        output << "NO" << endl;
    }
    

    for (int i = 0, closure; i < N - 1; i++)
    {
        input >> closure;
        closed[closure - 1] = true;
        connected = true;
        fill(all(visited), false);
        for (int j = 0; j < N; j++)
        {
            if(!closed[j]){
                DFS(j);
                break;
            }
        }

        for(int j = 0; j < N; j++){
            if(!visited[j] && !closed[j]){
                connected = false;
            }
        }
        if(connected){
            output << "YES" << endl;
        } else {
            output << "NO" << endl;
        }
        
    }
    


}