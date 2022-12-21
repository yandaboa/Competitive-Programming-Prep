#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int N, K;
vector<vector<int> > arr;
vector<vector<long long> > prefSum;

long long recursive(int tri, int trj, int bli, int blj, bool forward){//topright, bottomleft
    if(tri == bli && trj == blj){
        return arr[tri - K][trj - K];
    } else {
        long long confine = prefSum[bli][trj] - prefSum[tri - 1][trj] - prefSum[bli][blj - 1] + prefSum[tri - 1][blj - 1];
        // cout << endl << "(" << tri << ", " << trj << "), (" << bli << ", " << blj << ") " << confine << endl;
        // cout << endl << forward;
        return forward ? confine - recursive(tri + 1, trj, bli, blj + 1, !forward) : confine - recursive(tri, trj - 1, bli - 1, blj, !forward);
    }
}

long long recursive2(int tli, int tlj, int bri, int brj, bool forward){//topright, bottomleft
    if(tli == bri && tlj == brj){
        return arr[tli - 1][tlj - 1];
    } else {
        long long confine = prefSum[bri][brj] - prefSum[bri][tlj - 1] - prefSum[tli - 1][brj] + prefSum[tli - 1][tlj - 1];
        // cout << forward << " ";
        // cout << endl << "(" << tli << ", " << tlj << "), (" << bri << ", " << brj << ") " << confine << endl;
        return forward ? confine - recursive2(tli, tlj + 1, bri - 1, brj, !forward) : confine - recursive2(tli + 1, tlj, bri, brj - 1, !forward);
    }
}


int main(){
    cin >> N >> K;

    //build array
    arr.resize(N + 2*K);
    for(int i = 0; i < arr.size(); i++){
        arr[i].resize(N + 2*K);
    }
    for(int i = K; i < N + K; i++){
        for (int j = K; j < N + K; j++)
        {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
        
    }

    //build prefix sum
    prefSum.resize(N + 2*K + 1);
    for (int i = 0; i < prefSum.size(); i++)
    {
        prefSum[i].resize(N + 2*K + 1, 0);
    }
    
    for (int i = K + 1; i < N + K + 1; i++)
    {
        for (int j = K + 1; j < N + K + 1; j++)
        {
            prefSum[i][j] = prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i -1][j - 1] + arr[i - 1][j - 1];
            // cout << prefSum[i][j] << " ";
        }
        // cout << endl;
    }

    // for (int i = 0; i < prefSum.size(); i++)
    // {
    //     for (int j = 0; j < prefSum[0].size(); j++)
    //     {
    //         cout << prefSum[i][j] << " ";

    //     }
    //     cout << endl;
    // }

    // cout << recursive2(5, 3, 7, 5, true); // why does the recursive for this problem not work
    cout << endl;
    int maxSum = 0;

    for (int i = K + 1; i < N + K + 1; i++)
    {
         for (int j = K + 1; j < N + K + 1; j++)
        {
            long long area = recursive(i, j + K, i + K, j, true);
            area+= recursive(i - K, j, i, j - K, false);
            area += recursive2(i - K, j, i, j + K, true);
            area += recursive2(i, j - K, i + K, j, false);
            area -= prefSum[i][j] - prefSum[i - K - 1][j] - prefSum[i][j - K - 1] + prefSum[i - K - 1][j - K - 1];
            area += prefSum[i - 1][j - 1] - prefSum[i - K - 1][j - 1] - prefSum[i - 1][j - K - 1] + prefSum[i - K - 1][j - K - 1];
            area -= arr[i - 1][j - 1];
            area -= prefSum[i + K][j + K] - prefSum[i - 1][j + K] - prefSum[i + K][j - 1] + prefSum[i - 1][j - 1];
            area += prefSum[i + K][j + K]- prefSum[i][j + K] - prefSum[i + K][j] + prefSum[i][j];
            cout << area << " ";
        }
        cout << endl;
    }
    
}