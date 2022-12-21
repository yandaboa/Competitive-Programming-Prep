#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <climits>

using namespace std;
#define pb push_back
#define rsz resize
#define f first
#define s second
#define mp make_pair
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi= vector<vector<int> >;
using vll = vector<long long>;
using vpi = vector<pair<int, int> >;

int N;
vll arr;
vvi adjList;

void DFS(){}

int main(){
    cin >> N;
    arr.rsz(N);
    int max = INT_MIN, maxInd = -1;
    ll mean = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        mean+=arr[i];
        if(arr[i] > max){
            max = arr[i];
            maxInd = i;
        }
    }
    mean/=N;

    adjList.rsz(N);
    for (int i = 0; i < N - 1; i++)
    {  
        int a;
        cin >> a;
        adjList[i].pb(a);
    }
    
    DFS(maxInd);
    
}