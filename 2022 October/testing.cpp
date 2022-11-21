#include <iostream>
#include <vector>

using namespace std;

int main() {
        vector<int> temp2(10, 0);
        for(int j = 0; j < 10; j++){
            int curr;
            cin >> curr;
            temp2[curr] = j;
        }
}