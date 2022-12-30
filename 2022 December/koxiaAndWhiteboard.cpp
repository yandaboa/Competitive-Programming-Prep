#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
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

int T;

int main(){
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M; cin>> N >> M;
        priority_queue<int> que;
        for (int i = 0; i < N; i++)
        {
            int a; cin>> a; que.push(-1*a);
        }
        for (int i = 0; i < M; i++)
        {
            int a; cin >> a;
            que.pop();
            que.push(a*-1);
        }
        ll sum = 0;
        while(!que.empty()){
            sum += que.top()*-1; que.pop();
        }
        cout << sum << endl;
    }
    
}