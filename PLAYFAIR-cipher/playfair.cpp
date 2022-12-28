#include <bits/stdc++.h>
using namespace std;

static char table[5][5];
static unordered_map<char, pair<int, int>> mp;

void maketable(string key)
{
    string str = "";
    for (char ch : key)
    {
        if (ch == 'J')
            ch = 'I';
        str += ch;
    }
    str += "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    unordered_set<char> used;
    string res = "";

    for (char ch : str)
    {
        if (used.find(ch) != used.end())
        {
            continue;
        }
        else
        {
            res += ch;
            used.insert(ch);
        }
    }
    int curr = 0;
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            table[i][j] = res[curr++];
            mp[table[i][j]] = make_pair(i, j);
        }
    }
}

void printtable()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

pair<char, char> getdecrypted(char ch1, char ch2)
{
    int x1 = mp[ch1].first, y1 = mp[ch1].second;
    int x2 = mp[ch2].first, y2 = mp[ch2].second;

    pair<char, char> res;
    if (x1 == x2)
    {
        res.first = table[x1][(y1 - 1 + 5) % 5];
        res.second = table[x1][(y2 - 1 + 5) % 5];
    }
    else if (y1 == y2)
    {
        res.first = table[(x1 - 1 + 5) % 5][y1];
        res.second = table[(x2 - 1 + 5) % 5][y1];
    }
    else
    {
        res.first = table[x1][y2];
        res.second = table[x2][y1];
    }
    return res;
}

int main()
{
    string key_word;
    cout << "Enter the keyword: ";
    getline(cin, key_word);
    string corrected_keyword = "";

    for (char ch : key_word)
    {
        if ('A' <= ch and ch <= 'Z')
        {
            corrected_keyword += ch;
        }
        else if ('a' <= ch and ch <= 'z')
        {
            corrected_keyword += (char)(ch - 'a' + 'A');
        }
    }
    maketable(corrected_keyword);
    string original = "DF ULYP XO CQD LFWC RUBHEDY, CQDYG LN XDYL EGIYIG LMP CQDYF.\nLYFNH HXPZ CQF YNILXKPB \"NDCB_AN_BBHCN\" PQ FQ CQPKZBK. OLC PMC\nUNUG YMB IPYDIDCQ OXY CMB LDZP AULHDFY. CX OALG RMB FWGI PMX\nBNTIP ZLSWS LFWFE PQ ZCYGY KIBAT XMNKI PMBYD.";
    string str = "";
    for (char ch : original)
    {
        if (ch <= 'Z' and ch >= 'A')
        {
            str += ch;
        }
    }

    int n = str.size();
    string res = "";
    int i = 0;
    while (i < n)
    {
        if (i == n - 1)
        {
            auto p = getdecrypted(str[i], 'X');
            res += p.first;
            i += 1;
        }
        else if (str[i] != str[i + 1])
        {
            auto p = getdecrypted(str[i], str[i + 1]);
            res += p.first;
            res += p.second;
            i += 2;
        }
        else if (str[i] == str[i + 1])
        {
            auto p = getdecrypted(str[i], 'X');
            res += p.first;
            i += 1;
        }
    }

    string final_string = "";
    int curr = 0;
    for (int i = 0; i < original.size(); i++)
    {
        if (original[i] <= 'Z' and original[i] >= 'A')
        {
            final_string += res[curr++];
        }
        else
        {
            final_string += original[i];
        }
    }

    // printtable();// use this to print the table

    cout << final_string << endl;
  
    return 0;
}
