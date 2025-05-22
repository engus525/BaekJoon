#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int a, b, n;
        cin >> a >> b >> n;
        int ans = 0;
        while (a <= n)
        {
            if (a < b) swap(a, b);
            int sum = a + b;
            b = a;
            a = sum;
            ans++;
        }
        cout << ans << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}