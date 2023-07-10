#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int a, b, c;

void INPUT()
{
    IAMFAST
}

void solution()
{
    while (cin >> a >> b >> c)
    {
        if (a + b + c == 0) break;
        
        if(a+b+c - max(max(a,b),c) <= max(max(a,b),c)) cout << "Invalid\n";
        else if (a == b && b == c) cout << "Equilateral\n";
        else if ((a == b && b != c) ||
                 (b == c && c != a) ||
                 (a == c && b != c))
            cout << "Isosceles\n";
        else if (a != b && b != c && c != a) cout << "Scalene\n";
    }
}

int main()
{
    INPUT();
    solution();
}