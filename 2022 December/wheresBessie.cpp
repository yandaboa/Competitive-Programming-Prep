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

int N;
vector<vector<char> > grid;
vector<vb> visited;
vector<pair<pair<int, int>, pair<int, int> > > PCLs;


void check(int lowX, int lowY, int highX, int highY){
    int comps = 0;
    set<char> colors;
    for(int i = lowX; i < highX; i++){
        for (int j = lowY; j < highY; j++)
        {
        
        }
        
    }
}

int main(){
    cin >> N;
    visited.rsz(N);
    grid.rsz(N);
    for (int i = 0; i < N; i++)
    {
        visited[i].rsz(N);
        grid[i].rsz(N);
        string str; cin >> str;
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = str[j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            for (int a = 0; a < N; a++)
            {
                for (int b = a; b < N; b++)
                {
                    check(i, j, a, b);
                }
                
            }
            
        }
        
    }
    
    
} 