#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector<long long> arr, prefixSum;
map<long long, int> existingSums;
int arrSize;
int desiredSum;

int main(){
    cin >> arrSize >> desiredSum;

    arr.resize(arrSize);
    prefixSum.resize(arrSize + 1);
    for(int i = 0; i < arrSize; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    //build prefix sum
    existingSums[0] = 1;
    long long currSum = 0;
    long long numArrays = 0;
    for(int i = 1; i < arrSize + 1; i++){
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        currSum += arr[i - 1];
        // cout << currSum << " ";
        if(existingSums.count(currSum - desiredSum) > 0){
            numArrays += existingSums[currSum - desiredSum];
            // cout << currSum << " | " << currSum - desiredSum << " ";
        }
        // cout << prefixSum[i] << " ";
        if(existingSums.count(prefixSum[i]) >= 1){
            existingSums[prefixSum[i]]++;
        } else {
            existingSums[prefixSum[i]] = 1;
        }
    }
    // cout << endl;

    // // printing map gquiz1
    // map<long long, int>::iterator itr;
    // cout << "\nThe map gquiz1 is : \n";
    // cout << "\tKEY\tELEMENT\n";
    // for (itr = existingSums.begin(); itr != existingSums.end(); ++itr) {
    //     cout << '\t' << itr->first << '\t' << itr->second
    //          << '\n';
    // }

    // long long currSum = 0;
    // int numArrays = 0;
    // for(int i = 0; i < arr.size(); i++){
    //     currSum += arr[i];
    //     // cout << currSum << " ";
    //     if(existingSums.count(currSum - desiredSum) > 0){
    //         numArrays += existingSums[currSum - desiredSum];
    //         cout << currSum << " | " << currSum - desiredSum << " ";
    //     }
    // }
    // cout << endl;

    cout << numArrays;

}