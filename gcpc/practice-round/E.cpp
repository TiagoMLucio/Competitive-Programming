#include "bits/stdc++.h"
using namespace std;

#define int long long int

char flipH(char c)
{
    switch (c)
    {
    case 'b':
        return 'd';
    case 'd':
        return 'b';
    case 'p':
        return 'q';
    case 'q':
        return 'p';
    }

    return 'x';
}

char flipV(char c)
{
    switch (c)
    {
    case 'b':
        return 'p';
    case 'd':
        return 'q';
    case 'p':
        return 'b';
    case 'q':
        return 'd';
    }
    return 'y';
}

signed main()
{
    string s, t;
    cin >> s >> t;

    int n = s.size();

    int h = 0, v = 0;

    for (auto c : t)
    {
        switch (c)
        {
        case 'h':
            h++;
            break;
        case 'v':
            v++;
            break;
        case 'r':
            v++;
            h++;
            break;
        default:
            cout << "error" << endl;
            return 1;
        }
    }

    // cout << "h=" << h << ", v=" << v << endl;

    h %= 2;
    v %= 2;

    if (h == 1)
    {
        for (int i = 0; i < n / 2; i++)
            swap(s.at(i), s.at(n - 1 - i));
        for (int i = 0; i < n; i++)
            s.at(i) = flipH(s.at(i));
    }

    if (v == 1)
        for (int i = 0; i < n; i++)
            s.at(i) = flipV(s.at(i));

    cout << s << endl;

    return 0;
}