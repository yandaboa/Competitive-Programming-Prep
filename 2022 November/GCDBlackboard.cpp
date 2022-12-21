#include <iostream>
#include <vector>

using namespace std;

long long GCD(long long a, long long b){
    if(b == 0) {
            return a;
    }
    else {
        return GCD(b, a % b);
    }
}

int numNumbers;
vector<long long> prefixSum, backPrefixSum, arr;

int main(){
    cin >> numNumbers;
    prefixSum.resize(numNumbers + 1);
    backPrefixSum.resize(numNumbers + 1);

    arr.resize(numNumbers);

    prefixSum[0] = 0;
    backPrefixSum[0] = 0;

    for(int i = 1; i < prefixSum.size(); i++){
        long long temp;
        cin >> temp;
        prefixSum[i] = GCD(prefixSum[i - 1], temp);
        arr[i - 1] = temp;
        // cout << arr[i - 1] << " " << prefixSum[i] << " | ";
    }
    // cout << endl;
    for(int i = 1; i < backPrefixSum.size(); i++){
        backPrefixSum[i] = GCD(arr[arr.size() - i], backPrefixSum[i - 1]);
        // cout << backPrefixSum[i] << " ";
    }

    long long greatest = -1;

    for(int i = 1; i < prefixSum.size(); i++){
        greatest = max(greatest, GCD(prefixSum[i - 1], backPrefixSum[backPrefixSum.size() - i - 1]));
    }
    cout << endl << greatest;
}