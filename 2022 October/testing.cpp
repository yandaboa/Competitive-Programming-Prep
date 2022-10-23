#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int n, k, size, biggest = 0;
    fin >> n;
    vector<int> nums(n);
    for(int k = 0; k < n; k++) {
        fin >> nums[k];
    }
    for(int i = 0; i < n; i++) {
        int max = 0;
        for(int j = 0; j < n; j++) {
            if(nums[i]+k > nums[j]) {
                max++;
            }
        }
        if(max > biggest) {
            biggest = max + 1;
        }
    }
    fout << biggest;
}