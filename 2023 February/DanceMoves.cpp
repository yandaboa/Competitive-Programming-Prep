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

int N, K;
vector<set<int> > positions;
vi arr, newPlace, numPositions;
vb visited;
set<int> inComp;

void DFS(int a){
    if(visited[a]){return;}
    visited[a] = true;
    inComp.insert(a);
    DFS(newPlace[a]);
}

void count(){
    set<int> pos;
    for (auto i = inComp.begin(); i != inComp.end(); i++)
    {
        for (auto a = positions[*i].begin(); a != positions[*i].end(); a++)
        {
            pos.insert(*a);
        }
    }
    for (auto i = inComp.begin(); i != inComp.end(); i++)
    {
        numPositions[*i] = sz(pos);
    }
    inComp.clear();
}

int main(){
    cin >> N >> K;
    arr.rsz(N); positions.rsz(N);
    for (int i = 0; i < sz(arr); i++)
    {
        arr[i] = i;
        positions[i].insert(i);
    }
    for (int i = 0; i < K; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        positions[arr[a]].insert(a);
        positions[arr[b]].insert(b);
    }
    // for (int i = 0; i < sz(positions); i++)
    // {
    //     for (auto j = positions[i].begin(); j != (positions[i].end()); j++)
    //     {
    //         cout << *j << " ";
    //     }
    //     cout << endl;   
    // }

    newPlace.rsz(N);
    for (int i = 0; i < sz(arr); i++)
    {
        newPlace[arr[i]] = i;
    }
    // for (int i = 0; i < sz(newPlace); i++)
    // {
    //     cout << newPlace[i] << " ";
    // }
    visited.rsz(N); numPositions.rsz(N);
    for (int i = 0; i < sz(visited); i++)
    {
        if(!visited[i]){
            DFS(i);
            count();
        }
    }
    for (int i = 0; i < sz(numPositions); i++)
    {
        cout << numPositions[i] << endl;
    }
    
    
}