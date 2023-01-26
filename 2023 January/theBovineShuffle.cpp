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
vector<int16_t> adjList;
vb visited, inCycle;

void makeCycle(int a, bool first){
    if(inCycle[a] && first){
        return;
    }
    if(inCycle[a]){
        return;
    } else {
        inCycle[a] = true;
        makeCycle(adjList[a], false);
    }
}

void DFS(int a){
    if(visited[a]){
        if(inCycle[a]){
            return;
        }
        makeCycle(a, true);
    } else {
        visited[a] = true;
        DFS(adjList[a]);
    }
}

int main(){
    ifstream input("shuffle.in");
    ofstream output("shuffle.out");
    input >> N; visited.rsz(N); adjList.rsz(N); inCycle.rsz(N);
    for (int i = 0; i < N; i++)
    {
        int a; input >> a; a--;
        adjList[i]= a;
    }
    for (int i = 0; i < N; i++)
    {
        if(!visited[i]){
            DFS(i);
        }
    }
    int always = 0;
    for (int i = 0; i < sz(inCycle); i++)
    {
        if(inCycle[i]){
            always++;
        }
    }
    output << always;
    
}