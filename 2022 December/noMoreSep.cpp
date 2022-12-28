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
#define mp make_pair
//cin.tie(0)->sync_with_stdio(0);

int N, M;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    int index = 0;
    while(index < M){
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                cout << i + 1 << " " << j + 1 << endl;
                index++;
                if(index >= M){
                    return 0;
                }
            }
            
        }
        
    }

}