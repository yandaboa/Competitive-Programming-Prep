#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>

using namespace std;

long long apples, minDiff, total;
vector<long long> appleArr;

void split(long long a, long long sum){
    // cout << sum;
    if(a == appleArr.size()){
        return;
    }
    minDiff = min(abs(total - sum - sum), minDiff);
    split(a + 1, sum);
    sum += appleArr[a];
    minDiff = min(abs(total - sum - sum), minDiff);
    split(a + 1, sum);
}

int main(){
    cin >> apples;
    minDiff = INT_MAX;
    total = 0;
    for(int i = 0; i < apples; i++){
        long long temp;
        cin >> temp;
        appleArr.push_back(temp);
        total += temp;
    }
    split(0, 0);
    cout << minDiff;
}