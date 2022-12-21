#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <string>

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

int N, T;

int main(){
    cin >> N;
    string garland;
    cin >> garland;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int changes;
        cin >> changes;
        char letr;
        cin >> letr;
        
        int left = 0, right = 0, maxLength = 0;
        while(left < N && right < N){
            while(right < N){
                if(garland[right] != letr){
                    if(changes == 0){
                        break;
                    }
                    changes--;
                }
                right++;
            }
            maxLength = max(maxLength, right - left);
            if(garland[left] != letr){
                changes++;
            }
            left++;
        }
        cout << maxLength << endl;
    }

}