#include <bits/stdc++.h>
using namespace std;
  string ASCII = "";
  string ASCIIstr = "";
string findPassword()
{
  string ans = "";
  string s = "mkmgmjltlimfmhmplhlqifififififif";
  for (int i = 0; i < 16; i++)
  { ASCIIstr += s[2*i];
    ASCIIstr += s[2*i+1];
    ASCIIstr += "  ";
    int x = 16 * (s[2 * i] - 'f') + (s[2 * i + 1] - 'f');
    ASCII += (" " + to_string(x));
    ans += (char)x;
  }
  return ans;
}

int main()
{
  string ans = findPassword();
  cout << "\tASCII :\t\t" << ASCII << endl;
  cout << "\tDecypted Pairs:   " << ASCIIstr << endl;
  cout << "\tPassword: " << ans << endl;
  cout << "\tPassword after removing padding: " << ans.substr(0, 10) << endl;
}
