//I'm such a failure for not realizing the proper solution earlier tbh.

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

int N, M, K, startX, startY;
vvi maze;
vector<vb> visited;
vector<pair<int, int> > toRemove;
vector<pair<int, int> > resort;

int ff(int a, int b){
    if(a < 0 || a >= N || b < 0 || b >= M || maze[a][b] == 0 || maze[a][b] == 1){
        return 1;
    }
    if(visited[a][b]){
        return 0;
    }
    visited[a][b] = true;
    int sum = 0; sum += ff(a + 1, b); sum += ff(a, b + 1); sum += ff(a - 1, b); sum += ff(a, b - 1);
    if(sum == 3){
        toRemove.pb(mp(a, b));
    } else if (sum == 2){
        resort.pb(mp(a, b));
    }
    return 0;
    
}

void find(){
    for (int i = 0; i < sz(maze); i++)
    {
        for (int j = 0; j < sz(maze[i]); j++)
        {
            if(maze[i][j] == 2){
                startX = i, startY = j;
                break;
            }
        }
        
    }
    
}

bool tryIt(int a, int b){
    // cout << a << " " << b << " " << K << endl;
    maze[a][b] = 1;
    resort.pop_back();
    K--;
    for (int i = 0; i < sz(visited); i++)
    {
        fill(all(visited[i]), false);
    }
    find();
    ff(startX, startY);
    for (int i = 0; i < sz(visited); i++)
    {
        fill(all(visited[i]), false);
    }
    if(sz(toRemove) > 0){
        return true;
    } else {
        return false;
    }
}

void allResorts(){
    for(int i = sz(resort) - 1; i > - 1; i--){
        if(tryIt(resort[i].f, resort[i].s)){
            return;
        }
    }
}

void remove(){
    while(sz(toRemove) == 0){
        allResorts();
    }
    int index = 0;
    while(K > 0 && sz(toRemove) != 0){
        maze[toRemove[index].f][toRemove[index].s] = 1;
        // cout << toRemove[index].f << " " << toRemove[index].s << " " << K << endl;
        K--;
        index++;
    }
    toRemove.clear();
}

int main(){
    cin >> N >> M >> K;
    maze.rsz(N);
    visited.rsz(N); int a, b;
    for (int i = 0; i < sz(maze); i++)
    {
        maze[i].rsz(M);
        visited[i].rsz(M);
        string str; cin >> str; 
        for (int j = 0; j < sz(str); j++)
        {
            if(str[j] == '#'){
                maze[i][j] = 0;
            } else {
                maze[i][j] = 2;
                startX = i, startY = j;
            }
        }
    }

    while(K > 0){
        ff(startX, startY);
        remove();
        find();
        for (int i = 0; i < sz(visited); i++)
        {
            fill(all(visited[i]), false);
        }
        
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(maze[i][j] == 2){
                cout << ".";
            } else if(maze[i][j] == 1){
                cout << "X";
            } else {
                cout << "#";
            }
        }
        cout << endl;
    }
    
    
}