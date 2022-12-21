#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int N, K;
vector<int> arr, org;

int main(){
    ifstream input("swap.in");
    ofstream output("swap.out");
    input >> N >> K;

    for(int i = 1; i <= N; i++){
        arr.push_back(i);
        org.push_back(i);
    }

    int low1, high1, low2, high2;
    input >> low1 >> high1 >> low2 >> high2;
    low1--;
    high1--;
    low2--;
    high2--;

    int cycles = 0;

    do{
        cycles++;
        for (int j = low1; j <= (low1 + high1)/2; j++)
        {
            int temp = arr[j];
            arr[j] = arr[high1 - j + low1];
            arr[high1 - j + low1] = temp;
        }
        for (int j = low2; j <= (low2 + high2)/2; j++)
        {
            int temp = arr[j];
            arr[j] = arr[high2 - j + low2];
            arr[high2 - j + low2] = temp;
        }
    } while(arr != org);

    for(int x = 0; x < K%cycles; x++){
        for (int j = low1; j <= (low1 + high1)/2; j++)
        {
            int temp = arr[j];
            arr[j] = arr[high1 - j + low1];
            arr[high1 - j + low1] = temp;
        }
        // for (int y = 0; y < arr.size(); y++)
        // {
        //     cout << arr[y] << " ";
        // }
        
        for (int j = low2; j <= (low2 + high2)/2; j++)
        {
            int temp = arr[j];
            arr[j] = arr[high2 - j + low2];
            arr[high2 - j + low2] = temp;
        }
    }

    cout << cycles << endl;

    for(int i = 0; i < arr.size(); i++){
        output << arr[i] << endl;
    }

    output.close();
    input.close();
}