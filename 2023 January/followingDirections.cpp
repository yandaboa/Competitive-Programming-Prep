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

int N, Q;
vvi cowGrid;
vector<vector<char> > cows;
ll total;

ll makeGrid(){
    ll tot = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(cows[i][j] == 'D'){
                if(i == N - 1){
                    tot += cowGrid[i][j]*cowGrid[i + 1][j];
                    continue;
                }
                cowGrid[i + 1][j] += cowGrid[i][j];
            } else {
                if(j == N - 1){
                    tot += cowGrid[i][j]*cowGrid[i][j + 1];
                    continue;
                }
                cowGrid[i][j + 1] += cowGrid[i][j];
            }
        }
    }
    return tot;
    
}

void DFS(int x, int y, int val){
    if(x >= N || y >= N){
        return;
    }
    cowGrid[x][y] += val;
    if(cows[x][y] == 'D'){
        DFS(x + 1, y, val);
    } else {
        DFS(x, y + 1, val);
    }
}

void solve(int x, int y){
    if(cows[x][y] == 'D'){
        cows[x][y] = 'R';
        DFS(x + 1, y, -1*cowGrid[x][y]);
        DFS(x, y + 1, cowGrid[x][y]);
    } else {
        cows[x][y] = 'D';
        DFS(x, y + 1, -1*cowGrid[x][y]);
        DFS(x + 1, y, cowGrid[x][y]);
    }
}

void sum(){
    total = 0;
    for (int i = 0; i < N; i++)
    {
        if(cows[i][N - 1] == 'R'){
            total += cowGrid[i][N - 1]*cowGrid[i][N];
        }
    }
    for (int i = 0; i < N; i++)
    {
        if(cows[N - 1][i] == 'D'){
            total += cowGrid[N - 1][i]*cowGrid[N][i];
        }
    }
    
}

//remember that when the input is given for switching signs, 1 needs to be subtracted from x and y for indexing
int main(){
    cin >> N; cowGrid.rsz(N + 1); cows.rsz(N);
    for (int i = 0; i < N; i++)
    {
        cowGrid[i].rsz(N + 1);
        fill(all(cowGrid[i]), 1);
        cows[i].rsz(N);
        string str; cin >> str;
        for (int j = 0; j < sz(str); j++)
        {
            cows[i][j] = str[j];
        }
        cin >> cowGrid[i][N];
        // cout << "done" << endl;
    }
    cowGrid[N].rsz(N + 1); fill(all(cowGrid[N]), 1);
    for (int i = 0; i < N; i++)
    {
        cin >> cowGrid[N][i];
    }
    total = makeGrid();
    cout << total << endl;
    // for (int i = 0; i < sz(cowGrid); i++)
    // {
    //     for (int j = 0; j < sz(cowGrid); j++)
    //     {
    //         cout << cowGrid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int x, y; cin >> x >> y; x--; y--;
        solve(x, y);
        sum();
        cout << total << endl;
    }
}