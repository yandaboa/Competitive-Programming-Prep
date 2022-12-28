#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
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
set<int> st;
vi arr;

int main(){
    ifstream input("highcard.in");
    ofstream output("highcard.out");
    cin.tie(0)->sync_with_stdio(0);
    input >> N;
    for (int i = 1; i <= 2*N; i++)
    {
        st.insert(i);
    }
    arr.rsz(N);
    for (int i = 0; i < N; i++)
    {
        int a; input >> a;
        arr[i] = a;
        st.erase(a);
    }

    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        auto itr = st.upper_bound(arr[i]);
        if(itr != st.end()){
            counter++;
            st.erase(*itr);
        }
    }
    output << counter;
    
}