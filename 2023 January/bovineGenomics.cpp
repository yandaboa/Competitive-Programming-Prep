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

int N, M;
vector<string> spotty, plain;
int valid;

void checkValid(int& a, int& b, int& c){
    vi isSpotty; isSpotty.rsz(193, -1);
    map<char, int> conversionMap; conversionMap['A'] = 0; conversionMap['C'] = 1; conversionMap['G'] = 2; conversionMap['T'] = 3;
    for (int i = 0; i < sz(spotty); i++)
    {
        int val = conversionMap[spotty[i][a]] + 4*conversionMap[spotty[i][b]] + 16*conversionMap[spotty[i][c]];
        isSpotty[val] = i;
    }
    for (int i = 0; i < sz(plain); i++)
    {
        int val = conversionMap[plain[i][a]] + 4*conversionMap[plain[i][b]] + 16*conversionMap[plain[i][c]];
        if(isSpotty[val] != -1){
            cout << a << " " << b << " " << c << " " << isSpotty[val] << " " << i << endl;
            return;
        }
    }
    valid++;
}

int main(){
    ifstream input("cownomics.in");
    ofstream output("cownomics.out");
    input >> N >> M; valid = 0;
    for (int i = 0; i < N; i++)
    {
        string str; input >> str;
        spotty.pb(str);
    }
    for (int i = 0; i < N; i++)
    {
        string str; input >> str;
        plain.pb(str);
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            for (int b = j + 1; b < M; b++)
            {
                checkValid(i, j, b);
            }
        }
    }
    output << valid;
}