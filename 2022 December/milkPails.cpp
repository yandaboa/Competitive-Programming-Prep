#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <fstream>
#include <climits>
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

int X, Y, K, M, minDiff;
vector<vector<vector<bool> > > bucket;

void floodfill(int a, int b, int moves){
    if(moves > K){
        return;
    }
    if(a < 0 || a > X || b < 0 || b > Y){
        return;
    }
    if(bucket[a][b][moves]){
        return;
    } else {
        minDiff = min(abs(M - a - b), minDiff);
        bucket[a][b][moves] = true;
        floodfill(min(a + b, X), max(b - (X - a), 0), moves + 1);
        floodfill(max(a - (Y - b), 0), min(a + b, Y), moves + 1);
        floodfill(0, b, moves + 1);
        floodfill(a, 0, moves + 1);
        floodfill(X, b, moves + 1);
        floodfill(a, Y, moves + 1);
    }
}

int main(){
    ifstream input("pails.in");
    ofstream output("pails.out");
    input >> X >> Y >> K >> M;
    bucket.resize(X + 1);
    for (int i = 0; i < sz(bucket); i++)
    {
        bucket[i].rsz(Y + 1);
        for (int j = 0; j < sz(bucket[i]); j++)
        {
            bucket[i][j].rsz(K + 1);
        }
    }
    minDiff = INT_MAX;
    floodfill(0, 0, 0);
    output << minDiff;
}