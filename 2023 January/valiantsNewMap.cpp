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

int T;
int N, M;

struct Point {
    int val;
    int x;
    int y;
};

bool operator<(const Point& a, const Point& b){
    if(a.val == b.val){
        if(a.x == b.x){ return a.y < b.y;}
        return a.x < b.x;
    }
    return a.val < b.val;
}

bool works(int a, vector<vi>& city){
    //implement this with prefix sum at one point
    vector<vi> prefSum; prefSum.rsz(sz(city) + 1);
    for (int i = 0; i < sz(prefSum); i++)
    {
        prefSum[i].rsz(sz(city[0]) + 1);
    }
    fill(all(prefSum[0]), 0);
    for (int i = 1; i < sz(prefSum); i++)
    {
        prefSum[i][0] = 0;
        for (int j = 1; j < sz(prefSum[i]); j++)
        {
            prefSum[i][j] = prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1];
            prefSum[i][j] += city[i - 1][j - 1] >= a ? 1: 0;
            // cout << prefSum[i][j] << " ";
        }
        // cout << endl;
    }
    for (int i = a; i < sz(prefSum); i++)
    {
        for (int j = a; j < sz(prefSum[i]); j++)
        {
            int sum = prefSum[i][j] - prefSum[i - a][j] - prefSum[i][j - a] + prefSum[i - a][j - a];
            if(sum == pow(a, 2)){
                return true;
            }
        }
    }
    return false;
    
    
    
}

int main(){
    cin >> T;
    while(T){
        cin >> N >> M;
        vector<vector<int> > city; city.rsz(N);
        // set<Point> pts;
        for (int i = 0; i < N; i++)
        {
            city[i].rsz(M);
            for (int j = 0; j < M; j++)
            {
                cin >> city[i][j];
            }
        }
        int lo = 1, hi = min(N, M);
        while(lo < hi){
            int mid = (lo + hi + 1)/2;
            if(works(mid, city)){
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo << endl;
        // works(3, city);
        T--;
    }
}