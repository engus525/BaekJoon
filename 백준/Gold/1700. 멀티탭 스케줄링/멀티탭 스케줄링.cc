#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // cpp
using namespace std;

int n, k;

int sequence[101]{ 0, };
int hole[101]{ 0, };
bool connected[101]{ false, };

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int product; cin >> product;
        sequence[i] = product;
    }
}


void SOLVE()
{
    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        int product = sequence[i];

        // Already Connected
        if (connected[product]) continue;
        
        // Hole if Left
        bool isLeft = false;
        for (int j = 0; j < n; j++)
        {
            if (!hole[j])
            {
                isLeft = true;
                hole[j] = product;
                connected[product] = true;
                break;
            }
        }
        if (isLeft) continue;

        // No hole -> Find the product will not use for longest time
        ans++;

        int P = 0; // Product's num that will be plugged out.
        int H = 0; // Hole's index that will be plugged out.
        int longestTime = -1; // if Init with 0, it may pass 'if' statement.
        for (int j = 0; j < n; j++)
        {
            int temp = 0;
            for (int l = i + 1; l < k; l++)
            {
                // j'th hole's product's time
                if (hole[j] == sequence[l]) break;
                temp++;
            }
            
            if (longestTime < temp)
            {
                longestTime = temp;
                P = hole[j];
                H = j;
            }
        }
        // Plug the procuct in
        connected[P] = false;
        connected[product] = true;
        hole[H] = product;


    }

    cout << ans;
}


int main()
{
    INPUT();

    SOLVE();

}