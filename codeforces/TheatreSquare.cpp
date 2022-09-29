#include <iostream>
using namespace std;

int main()
{
    long long n, m, a;
    cin >> n >> m >> a;
    long long nside, mside;
    if(n%a == 0){
        nside = n/a;
    } else {
        nside = n/a + 1;
    }
    if(m%a == 0){
        mside = m/a;
    } else {
        mside = m/a + 1;
    }
    cout << mside*nside << endl;
    return 0;
}

//passed