#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <memory.h> // memset
#include <numeric>
#include <stack>
#include <sstream>
using namespace std;
/* –2,147,483,648 ~ 2,147,483,647 */

int n;
int list[1'000'001];
int ans[1'000'001];
stack<int> s;

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> list[i];
	}
	
}

void SOLVE()
{
	for (int i = n; i >= 1; i--)
	{
		while (!s.empty() && s.top() <= list[i])
			s.pop(); // 2. 오른쪽 원소부터 검사: top이 더 작으면 pop
		if (s.empty()) ans[i] = -1; // 3. 오른쪽 원소중 더 큰게 없으면 -1
		else if (s.top() > list[i]) ans[i] = s.top(); // 4. top이 더 크면 ans에 저장

		s.push(list[i]); // 1. i번째 원소 검사시 이후 원소는 모두 스택에 있음([i + 1]원소가 top)
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << " ";

}

int main()
{
	//system("mode con cols=60 lines=300 | title 아~너무쉽다");
	INPUT();

	SOLVE();
}