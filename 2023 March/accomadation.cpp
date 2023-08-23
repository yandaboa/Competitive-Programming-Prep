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

int main(){
    cin >> N >> M;
    int minAccom = 0, maxAccom = 0;
    for (int i = 0; i < N; i++)
    {
        vi arr;
        string str; cin >> str;
        for (int i = 0; i < M; i++)
        {
            arr.pb(str[i] - '0');
        }
        int l = 0, r = 1;
        int numDoubleMin = M/4, numDoubleMax = M/4, numSingleMin = M/2, numSingleMax = M/2;
        while(r < sz(arr) && l < sz(arr)){
            if(numSingleMin == 0 || (arr[r] == 1 && arr[l] == 1 && numDoubleMin != 0)){
                numDoubleMin--;
                minAccom+= max(arr[l], arr[r]);
                l = r + 1;
                r = l + 1;
                if(r == sz(arr) && l < sz(arr)){
                    minAccom += arr[l];
                }
            } else {
                numSingleMin--;
                minAccom += arr[l];
                l++; r++;
                if(r == sz(arr)){
                    minAccom += arr[l];
                }
            }
        }
        l = 0, r = 1;
        while(r < sz(arr) && l < sz(arr)){
            if(numSingleMax == 0 || (arr[r] + arr[l] < 1 && numDoubleMax != 0)){
                maxAccom+= max(arr[l], arr[r]);
                numDoubleMax--;
                l = r + 1;
                r = l + 1;
                if(r == sz(arr) && l < sz(arr)){
                    maxAccom += arr[l];
                }
            } else {
                numSingleMax--;
                maxAccom += arr[l];
                l++; r++;
                if(r == sz(arr)){
                    maxAccom += arr[l];
                }
            }
        }
        
    }
    cout << minAccom << " " << maxAccom << endl;

    
}