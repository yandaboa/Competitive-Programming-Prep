#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("shell.in");
    ofstream fout("shell.out");

    int n;
    fin >> n;
    int sum1, sum2;
    int a, b, g;
    vector<int> points(3);
    vector<int> shells;
    shells.push_back(1);
    shells.push_back(2);
    shells.push_back(3);
    for(int i = 0; i < n; i++){
        fin >> a >> b >> g;
        
        swap(shells[a-1], shells[b-1]);
        points[shells[g - 1] - 1]++;
    }

    sum1 = max(points[0], points[1]);
    sum2 = max(sum1, points[2]);
    fout << sum2;
}