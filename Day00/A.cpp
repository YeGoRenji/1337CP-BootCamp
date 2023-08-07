#include <iostream>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int nb;
    while(n--)
    {
        cin >> nb;
        cout << ((nb >= 0) ? nb + 2 : nb) << ' ';
    }
    cout << endl;
}