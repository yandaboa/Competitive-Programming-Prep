#include <iostream>
#include <vector>
using namespace std;

void af(int a){
    a++;
    cout << a;
}

int main(){
    int num = 6;
    cout << num;
    af(num);
    cout << num;
}