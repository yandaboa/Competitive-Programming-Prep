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

int N, M, largestComp, largestRoot, numComps;
vi parent, treeSize;

int find(int a){
    if(parent[a] != a){
        parent[a] = find(parent[a]);
    }
    return parent[a];
}

void join(int a, int b){
    int root1 = find(a);
    int root2 = find(b);
    
    if(root1 != root2){
        numComps--;
    } else {
        return;
    }
    if(treeSize[root1] < treeSize[root2]){
        parent[root1] = root2;
        treeSize[root2] += treeSize[root1];
        if(treeSize[root2] > largestComp){
            largestComp = treeSize[root2];
        }
    } else {
        parent[root2] = root1;
        treeSize[root1] += treeSize[root2];
        if(treeSize[root1] > largestComp){
            largestComp = treeSize[root1];
        }
    }
}

int main(){
    cin >> N >> M;
    parent.rsz(N); treeSize.rsz(N);
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        treeSize[i] = 1;
    }
    largestComp = 1;
    numComps = N;

    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        join(a, b);
        cout << numComps << " " << largestComp << endl;
    }
    
}