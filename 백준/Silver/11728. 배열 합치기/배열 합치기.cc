#include <iostream>
#include <vector>
using namespace std;

int n,m;
int A[1000001],B[1000001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> B[i];
}


void SOLVE()
{
    int pointA = 0, pointB = 0;

    while(pointA < n && pointB < m)
    {
        if(A[pointA] <= B[pointB])
        {
            cout << A[pointA++] << " ";
        }
        else cout << B[pointB++] << " ";
    }

    if(pointA < n)
        while(pointA < n)
            cout << A[pointA++] << " ";
    if(pointB < m)
        while(pointB < m)
            cout << B[pointB++] << " ";
}

int main()
{
    INPUT();
    SOLVE();
}