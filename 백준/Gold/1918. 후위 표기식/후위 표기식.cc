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

string expression;
stack<char> op;

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> expression;
}

// 연산자 우선순위 구별
bool isOp1(char c)
{
	if (c == '*' || c == '/') return true;
	else return false;
}
bool isOp2(char c)
{
	if (c == '+' || c == '-') return true;
	else return false;
}

void SOLVE()
{
	for (int i = 0; i < expression.length(); i++)
	{
		char ex = expression[i];

		/* 연산자 만난 경우 */
		if (isOp1(ex) || isOp2(ex))
		{
			// 스택이 빈 경우
			if (op.empty()) op.push(ex);
			// top이 ( 인 경우 stack push
			else if (op.top() == '(') op.push(ex);
			// top의 우선순위가 낮은 경우 push
			else if (isOp1(ex) && isOp2(op.top())) op.push(ex);
			// 나머지는 조건 따지며 출력.pop 반복후 push
			else
			{
				while (true)
				{
					// stack empty or ( 만나면 종료
					if (op.empty() || op.top() == '(') break;
					// 연산자 우선순위 따지기
					if (isOp1(ex) && (!op.empty() && isOp2(op.top()))) break;

					cout << op.top();
					op.pop();
				}
				op.push(ex);
			}
		}

		/* 피연산자 or 괄호 만난 경우 */
		else
		{
			// 피연산자 만나면 출력
			if (ex >= 'A' && ex <= 'Z') cout << ex;
			// 여는 괄호 ( 만나면 stack push
			else if (ex == '(') op.push(ex);

			// 닫는 괄호 ) 만나면 stack pop : top은 무조건 ( 이기때문
			else if (ex == ')')
			{
				while (op.top() != '(')
				{
					cout << op.top();
					op.pop();
				}
				op.pop();
			}
		}

	}
	
	// 남은 연산자 출력
	while (!op.empty())
	{
		cout << op.top();
		op.pop();
	}
}

int main()
{
	INPUT();

	SOLVE();
}