
#include <bits/stdc++.h>
using namespace std;

int main()
{

  string s;
  int j; // block number [1,...,7,8]
  // for first 16 char
  // lhlikkksgugolfil  - First half
  // krmpijknihmnhjju  - Second half
  // s="ffffffffffffffff"; j=1;
  // s="mkffffffffffffff"; j=2;
  // s="mkmgffffffffffff"; j=3;
  // s="mkmgmjffffffffff"; j=4;
  // s="mkmgmjltffffffff"; j=5;
  // s="mkmgmjltliffffff"; j=6;
  // s="mkmgmjltlimfffff"; j=7;
  // s="mkmgmjltlimfltff"; j=8;

  // for  second 16 char
  // s="ffffffffffffffff"; j=1;
  // s="lhffffffffffffff"; j=2;
  // s="lhlqffffffffffff"; j=3;
  // s="lhlqifffffffffff"; j=4;
  // s="lhlqififffffffff"; j=5;
  // s="lhlqifififffffff"; j=6;
  // s="lhlqififififffff"; j=7;
  s = "lhlqifififififff";
  j = 8;

  for (int i = 0; i <= 127; i++)
  {

    s[2 * j - 2] = 'f' + i / 16;
    s[2 * j - 1] = 'f' + (i % 16);
    cout << s << endl;
  }
  // lhlikkksgugolfilkrmpijknihmnhjju -- This is the decrypted one
}