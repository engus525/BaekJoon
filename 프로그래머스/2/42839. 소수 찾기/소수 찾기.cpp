#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[8];
bool checked[10'000'000];
int answer = 0;
string numbers;
string str;

void check()
{
    int num = stoi(str);
    if (checked[num]) return;
    if (num < 2) return;
    
    bool isPrime = true;
    for (int i = 2; i * i <= num; i++)
    {
        if (!(num % i)) isPrime = false;
    }
    
    checked[num] = true;
    if (isPrime)
    {
        // cout << num << " is prime\n";
        answer++;
    }
}

void comb(int now)
{
    if (now == numbers.length() + 1) return;
    
    if (now) check();
    
    for (int i = 0; i < numbers.length(); i++)
    {
        if (visited[i]) continue;
        
        str += numbers[i];
        visited[i] = true;
        comb(now + 1);
        str.pop_back();
        visited[i] = false;
    }
    
}

int solution(string temp) {
    numbers = temp;
    
    comb(0);
    
    return answer;
}