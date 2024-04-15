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

vb toRemove;

int main() {
    string vowels = "aeouiy";
    string input;
    cin >> input;
    toRemove.rsz(sz(input));
    for(int i = 0; i < sz(input); i++){
        input[i] = (char)tolower(input[i]);
        for(int j = 0; j < sz(vowels); j++){
            if(vowels[j] == input[i]){
                toRemove[i] = true; 
            }
        }
    }
    string result = "";
    for (int i = 0; i < sz(input); i++)
    {
        if(!toRemove[i]){
            result += ".";
            result += input[i];
        }
    }
    cout << result;
    
}