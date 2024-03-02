#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

struct Player
{
    ll x;
    ll y;
    ll movs;
    ll finalY;
    Player(ll x, ll y, ll movs) : x(x), y(y), movs(movs)
    {
    }

    void setFinalY(bool goRight, ll w)
    {
        finalY = goRight ? min(w, y + movs) : max(1LL, y - movs);
    }
};

void solve()
{
    ll h, w, ya, xa, yb, xb;
    cin >> h >> w >> xa >> ya >> xb >> yb;

    if (xb <= xa)
    {
        cout << "Draw" << endl;
        return;
    }

    bool aliceCanWin = (xb - xa) % 2 == 1;

    Player alicePlayer = Player(xa, ya, (xb - xa) / 2);
    Player bobPlayer = Player(xb, yb, (xb - xa - 1) / 2);

    Player losingPlayer = aliceCanWin ? bobPlayer : alicePlayer;
    Player winningPlayer = aliceCanWin ? alicePlayer : bobPlayer;

    bool goRight = (losingPlayer.y > winningPlayer.y);

    losingPlayer.setFinalY(goRight, w);
    winningPlayer.setFinalY(goRight, w);

    bool draw = abs(losingPlayer.finalY - winningPlayer.finalY) > 1;

    cout << (draw ? "Draw" : (aliceCanWin ? "Alice" : "Bob")) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}