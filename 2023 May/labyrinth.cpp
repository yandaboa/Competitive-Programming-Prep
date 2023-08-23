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
#include <stack>
#include <queue>
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

int n, m;

char grid[1000][1000], from[1000][1000];
bool visited[1000][1000];

int dx[4]{-1, 1, 0, 0}, dy[4]{0, 0, 1, -1};
char dir[4]{'U', 'D', 'R', 'L'};

string path;

void backwardTrav(int a, int b){
    
    if(from[a][b] == '.'){
        return;
    }
    path = from[a][b] + path;
    int ind;
    for (int i = 0; i < 4; i++)
    {
        if(dir[i] == from[a][b]){
            ind = i;
            break;
        }
    }
    
    int tdx = dx[ind]*-1, tdy = dy[ind]*-1;
    backwardTrav(a + tdx, b + tdy);
} 

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string str; cin >> str;

        for (int j = 0; j < m; j++)
        {
            grid[i][j] = str[j];
        }
    }

    int startx, starty, endx, endy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j] == 'A'){
                startx = i, starty = j;
            }
            if(grid[i][j] == 'B'){
                endx = i, endy = j;
            }
        }
    }

    queue<pair<pair<int, int>, char> > toExplore;
    toExplore.push(mp(mp(startx, starty), '.'));

    while(!toExplore.empty()){
        pair<pair<int, int>, char> curr = toExplore.front(); toExplore.pop();
        if(curr.f.f < 0 || curr.f.s < 0 || curr.f.f >= n || curr.f.s >= m){
            continue;
        }
        if(grid[curr.f.f][curr.f.s] == '#'){
            continue;
        }
        if(!visited[curr.f.f][curr.f.s]){
            visited[curr.f.f][curr.f.s] = true;
            from[curr.f.f][curr.f.s] = curr.s;
            for (int i = 0; i < 4; i++)
            {
                toExplore.push(mp(mp(curr.f.f + dx[i], curr.f.s + dy[i]), dir[i]));
            }
        }
    }
    if(visited[endx][endy]){
        path = "";
        backwardTrav(endx, endy);
        cout << "YES" << endl << path.size() << endl << path;
    } else {
        cout << "NO";
    }
}