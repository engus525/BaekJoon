#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isBig(char c)
{
    return 'A' <= c && c <= 'Z';
}

bool isSmall(char c)
{
    return 'a' <= c && c <= 'z';
}

bool isPermitted(char c)
{
    return ('0' <= c && c <= '9') || c == '-' || c == '_' || c == '.'; 
}

string solution(string str) {
    string answer = "";
    
    //소문자 치환
    for (int i = 0; i < str.length(); i++)
        if (isBig(str[i])) str[i] = str[i] - 'A' + 'a';
    cout << str << '\n';
    
    //규정외 문자 제거
    string temp;
    for (int i = 0; i < str.length(); i++)
        if (isSmall(str[i]) || isPermitted(str[i]))
            temp += str[i];
    str = temp;
    cout << str << '\n';
    
    //마침표 연속 제거
    for (int i = 1; i < str.length(); i++)
        while (str[i] == '.' && str[i - 1] == '.')
            str.erase(i, 1);
    cout << str << '\n';
    
    //시작 끝  마침표 제거
    while (str.length() && str[0] == '.') str.erase(0, 1); 
    while (str.length() && str.back() == '.') str.pop_back();
    cout << str << '\n';
    
    //빈 문자라면 a 대입
    if (str == "") str = "a";
    
    //16자부터 자르기
    if (str.length() > 15) str = str.substr(0, 15);
    while (str.back() == '.') str.pop_back();
    cout << str << '\n';
    
    if (str.length() <= 2)
        while (str.length() <= 2)
            str += str.back();
    
    return str;
}