#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string html;

void INPUT()
{
    IAMFAST
    getline(cin, html);
}

bool endMain(int idx)
{
    return html[idx + 1] == '/'
           && html[idx + 2] == 'm'
           && html[idx + 3] == 'a'
           && html[idx + 4] == 'i'
           && html[idx + 5] == 'n';
}

bool startTag(char c)
{
    return c == '<';
}

bool startDiv(int idx)
{
    return html[idx + 1] == 'd'
           && html[idx + 2] == 'i'
           && html[idx + 3] == 'v';
}

bool endDiv(int idx)
{
    return html[idx] == '<'
           && html[idx + 1] == '/'
           && html[idx + 2] == 'd'
           && html[idx + 3] == 'i'
           && html[idx + 4] == 'v'
           && html[idx + 5] == '>';
}

bool startP(int idx)
{
    return html[idx] == '<'
           && html[idx + 1] == 'p'
           && html[idx + 2] == '>';
}

bool endP(int idx)
{
    return html[idx] == '<'
           && html[idx + 1] == '/'
           && html[idx + 2] == 'p'
           && html[idx + 3] == '>';
}

void getTitle(int &idx)
{
    cout << "title : ";
    while(html[idx] != '"') idx++;
    idx++;

    string title = "";
    while(html[idx] != '"') title += html[idx++];

    // <p> 시작 지점으로 idx 옮겨주기
    idx += 2;

    cout << title << "\n";
}


void getP(int &idx)
{
    while(!endDiv(idx))
    {
        if(startP(idx)) idx += 3;

        string temp = "";
        while(!endP(idx))
        {
            if(html[idx] == '<')
            {
                while(html[idx] != '>') idx++;
                idx++;
                continue;
            }
            temp += html[idx++];
        }

        string p = "";
        for(int i = 0; i < temp.length(); i++)
        {
            if(i == 0 && temp[i] == ' ') while(temp[i] == ' ') i++;
            else if(temp[i] == ' ') while(temp[i+1] == ' ') i++;
            if(i > temp.length()-1) break;
            p += temp[i];
        }

        for(int i = 0; i < p.length(); i++)
        {
            if (i == p.length() - 1 && p[i] == ' ') break;
            cout << p[i];
        }
        cout << '\n';

        // </p> 끝으로 이동
        idx += 4;
    }
}

void SOLVE()
{
    for (int i = 0; i < html.length(); i++)
    {
        if (!startTag(html[i])) continue;

        if (endMain(i)) break;
        if (startDiv(i)) getTitle(i), getP(i);
    }
}

int main()
{
    INPUT();
    SOLVE();
}
