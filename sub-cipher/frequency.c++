#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream file;
    file.open("encrypted.txt", ios::out);

    if (!file)
    {
        cout << "Error in creating file!!!";
        return 0;
    }

    file << "omkf pi hdn cmgef icphsck .H krg vphqkc c,\n";
    file << "ic mco kqgf ioqag eo qfcmckf oq ficpihdn\n";
    file << "cm .Kg dcgeficu hfcm pi hdn cmklo uuncdgmc\n";
    file << "oqfc mc kfoq afihqfiokgq c!Fi cpgy cvkc yeg\n";
    file << "mfio kdck kha cokh kodjuck vn k fofvfo\n";
    file << "gqpojicmoqli opiyoa of kihsc nccqki oefc\n";
    file << "ynr2 juhpck. Fi c jhkklgm yok oMxr9V1x ya\n";
    file << "flofigvffic xvgfck. Fio kokfice";
    file.close();

    char ch;
    map<char, int> mp;
    int T = 0;
    fstream fin("encrypted.txt", fstream::in);
    while (fin >> noskipws >> ch)
    {
        if (ch >= '0' and ch <= '9' or !((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z')))
            continue;
        mp[tolower(ch)]++;
        T++;
    }

    map<char, float> mp2;

    for (auto p : mp)
    {
        mp2[p.first] = ((float)(p.second) * (100)) / T;
    }

    multimap<float, char> mp3;
    for (auto p : mp2)
    {
        mp3.insert({p.second, p.first});
    }

    for (auto p : mp3)
        cout << p.first << " : " << p.second << endl;
    return 0;
}
