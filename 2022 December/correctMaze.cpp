#include <iostream>
#include <vector>
#include <limits>
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

int N, M, K, totFree;
set<pair<int, int> > vis;
vector<vb> visited;
vvi maze;

void ff(int a, int b){
    if(a < 0 || a >= N || b < 0 || b >= M || maze[a][b] == 0 || visited[a][b] || sz(vis) == totFree - K){
        return;
    }
    vis.insert(mp(a, b));
    visited[a][b] = true;
    ff(a + 1, b); ff(a, b + 1); ff(a - 1, b); ff(a, b - 1);
}

int main(){
    cin >> N >> M >> K;
    maze.rsz(N);
    totFree = 0;
    int a, b;
    visited.rsz(N);
    for (int i = 0; i < sz(maze); i++)
    {
        visited[i].rsz(M);
        maze[i].rsz(M);
        string str; cin >> str;
        for (int j = 0; j < sz(maze[i]); j++)
        {
            if(str[j] == '.'){
                maze[i][j] = 1;
                totFree++;
                a = i; b = j;
            } else {
                maze[i][j] = 0;
            }
        }   
    }
    ff(a, b);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(maze[i][j] == 0) {
                cout << "#";
            } else {
                if(vis.find(mp(i, j)) == vis.end()){
                    cout << "X";
                } else {
                    cout << ".";
                }
            }
        }
        cout << endl;
    }
    
}