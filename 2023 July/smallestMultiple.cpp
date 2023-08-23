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

int K;

int main(){
    cin >> K;
    vi dist(K, INFINITY);
    deque<int> q;

    dist[1] = 1;
    q.push_front(1);
    while(!q.empty()){
        int curr = q.front(); q.pop_front();
        
        int case1 = (curr * 10) % K;
        int case2 = (curr + 1) % K;
        if(dist[curr] < dist[case1]){
            dist[case1] = dist[curr];
            q.push_front(case1);
        }
        if(dist[curr] + 1 < dist[case2]){
            dist[case2] = dist[curr] + 1;
            q.push_back(case2);
        }
    }

    cout << dist[0];
}