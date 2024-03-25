#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int speed, limit;

void INPUT()
{
    IAMFAST
    cin >> limit >> speed;
}

void solution()
{
    if (speed <= limit) cout << "Congratulations, you are within the speed limit!";
    else if (speed - limit <= 20) cout << "You are speeding and your fine is $100.";
    else if (speed - limit <= 30) cout << "You are speeding and your fine is $270.";
    else  cout << "You are speeding and your fine is $500.";
}

int main()
{
    INPUT();
    solution();
}