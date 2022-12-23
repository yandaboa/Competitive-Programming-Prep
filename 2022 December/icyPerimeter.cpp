#include <iostream>
#include <vector>
#include <limits>
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

int N, area, perim;
vector<vector<char> > grid;
vector<vector<bool> > visited;

void floodfill(int i, int j){
    if(i < 0 || i >= sz(grid)){
        perim++;
        return;
    }
    if(j < 0 || j >= sz(grid[i])){
        perim++;
        return;
    }
    if(grid[i][j] == '.'){
        perim++;
        return;
    }
    if(visited[i][j]){
        return;
    } else {
        visited[i][j] = true;
        area++;
        floodfill(i + 1, j); floodfill(i, j + 1); floodfill(i - 1, j); floodfill(i, j - 1);
    }
}


int main(){
    ifstream input("perimeter.in");
    ofstream output("perimeter.out");
    input >> N;
    grid.rsz(N);
    visited.rsz(N);
    for (int i = 0; i < N; i++)
    {
        grid[i].rsz(N);
        visited[i].rsz(N);
        for (int j = 0; j < N; j++)
        {
            input >> grid[i][j];
        }
    }

    multiset<pair<int, int> > blobs;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(!visited[i][j] && grid[i][j] == '#'){
                area = 0; perim = 0;
                floodfill(i, j);
                blobs.insert(mp(area, perim));
            }
        }
    }
    // for(auto a: blobs){
    //     cout << a.f << " " << a.s << endl;
    // }
    pair<int, int> largest = mp((*blobs.rbegin()).f, 0);
    auto a = *blobs.lower_bound(largest);
    output << a.f << " " << a.s;
}