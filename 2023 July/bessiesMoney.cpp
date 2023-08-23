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

int n;
vi coins(5);
set<int> combos;

void generateAll(vi cows, int a){
    if(a == 6){
        int sum = 0;
        for (int i = 0; i < a; i++)
        {
            sum += cows[i];
        }
        if(sum == n){
            int num = 0;
            for (int i = 0; i < a; i++)
            {
                num += cows[i]*pow(10, i);
            }
            combos.insert(num);
        }
        return;
        
    }
    vi localCoins(5);
    for (int i = 0; i < 5; i++)
    {
        localCoins[i] = coins[i];
    }
    for (int i = 0; i < a; i++)
    {
        localCoins[cows[i] - 1] -= 1;
    }
    
    for (int i = 0; i < 5; i++)
    {
        if(localCoins[i] > 0){
            cows[a] = i + 1;
            generateAll(cows, a + 1);
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        cin >> coins[i];
    }
    
    vi empty(6);
    generateAll(empty, 0);
    cout << combos.size();
}