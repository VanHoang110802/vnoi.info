#include <iostream>

using namespace std;

int main()
{
    long long n, S;
    cin >> n >> S;
    cout << n * (n + 1) / 2 - S;
    return 0;
}
