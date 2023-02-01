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

int N;
int main(){
    cin >> N;
    string pi = "314159265358979323846264338327";
    for (int i = 0; i < N; i++)
    {
        string str; cin >> str;
        int a = -1;
        for (int j = 0; j < sz(pi); j++)
        {
            if(pi[j] != str[j]){
                break;
            } 
            a = j;
        }
        cout << a + 1 << endl;
        
    }
    
}