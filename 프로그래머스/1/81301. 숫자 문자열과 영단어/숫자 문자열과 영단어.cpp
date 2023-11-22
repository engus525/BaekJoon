#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'z') answer += '0', i += 3;
        
        else if (s[i] == 'o') answer += '1', i += 2;
        
        else if (s[i] == 't' && s[i + 1] == 'w') answer += '2', i += 2;
        
        else if (s[i] == 't') answer += '3', i += 4;
        
        else if (s[i] == 'f' && s[i + 1] == 'o') answer += '4', i += 3;
        
        else if (s[i] == 'f') answer += '5', i += 3;
        
        else if (s[i] == 's' && s[i + 1] == 'i') answer += '6', i += 2;
        
        else if (s[i] == 's') answer += '7', i += 4;
        
        else if (s[i] == 'e') answer += '8', i += 4;
        
        else if (s[i] == 'n') answer += '9', i += 3;
        
        else answer += s[i];
        
    }
    
    return stoi(answer);
}