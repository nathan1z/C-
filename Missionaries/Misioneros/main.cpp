


#include <iostream>

using namespace std;
int ans = 0;
int m1[10] = { -2,0,-1,0,-1,1,1,0,2,0 };
int m2[10] = { 0,-2,0,-1,-1,1,0,1,0,2 };
int path[100];
bool visit[4][4][4][4][2]; // 0 : l2r   1 : r2l
void dfs(int x1, int y1, int x2, int y2, int lastm1, int lastm2, int step)
{
    if (x1 == 0 && y1 == 0 && x2 == 3 && y2 == 3)
    {
        ans++;
        cout << "respuesta " << ans << " :" << endl;
        for (int i = 1; i <= step; ++i)
        {
            if (i % 2 == 1)
            {
                cout << "step" << i << ": l2r: " << path[i] / 100 / 10 << "Un misionero " << path[i] / 100 % 10 << "Un canibal " << endl;
            }
            else
            {
                cout << "step" << i << ": r2l: " << path[i] / 10 << "Un misionero " << path[i] % 10 << "Un canibal " << endl;
            }
        }
        return;
    }
    if (step % 2 == 0)
    {
        // l2r
        for (int i = 0; i < 5; ++i)
        {
            if ((m1[i] + lastm1 == 0) && (m2[i] + lastm2 == 0))
                continue;
            if ((x1 + m1[i]) >= 0 && (x1 + m1[i]) <= 3 && (y1 + m2[i]) >= 0 && (y1 + m2[i]) <= 3 && (x2 - m1[i]) >= 0 && (x2 - m1[i]) <= 3 && (y2 - m2[i]) >= 0
                && (y2 - m2[i]) <= 3
                && !visit[x1 + m1[i]][y1 + m2[i]][x2 - m1[i]][y2 - m2[i]][0]
                && ((x1 + m1[i]) >= (y1 + m2[i]) || x1 + m1[i] == 0) && ((x2 - m1[i]) >= (y2 - m2[i]) || x2 - m1[i] == 0))
            {
                visit[x1 + m1[i]][y1 + m2[i]][x2 - m1[i]][y2 - m2[i]][0] = true;
                path[step + 1] = 1000 * (-m1[i]) + 100 * (-m2[i]);
                dfs(x1 + m1[i], y1 + m2[i], x2 - m1[i], y2 - m2[i], m1[i], m2[i], step + 1);
                visit[x1 + m1[i]][y1 + m2[i]][x2 - m1[i]][y2 - m2[i]][0] = false;
            }
        }
    }
    else
    {
        // r2l
        for (int i = 5; i < 10; ++i)
        {
            if ((m1[i] + lastm1 == 0) && (m2[i] + lastm2 == 0))
                continue;
            if (((x1 + m1[i]) >= 0) && ((x1 + m1[i]) <= 3) && ((y1 + m2[i]) >= 0) && ((y1 + m2[i]) <= 3) && ((x2 - m1[i]) >= 0)
                && ((x2 - m1[i]) <= 3) && ((y2 - m2[i]) >= 0) && ((y2 - m2[i]) <= 3)
                && !visit[x1 + m1[i]][y1 + m2[i]][x2 - m1[i]][y2 - m2[i]][1]
                && (((x1 + m1[i]) >= (y1 + m2[i])) || (x1 + m1[i] == 0)) && (((x2 - m1[i]) >= (y2 - m2[i]))) || (x2 - m1[i] == 0))
            {
                visit[x1 + m1[i]][y1 + m2[i]][x2 - m1[i]][y2 - m2[i]][1] = true;
                path[step + 1] = 10 * m1[i] + m2[i];
                dfs(x1 + m1[i], y1 + m2[i], x2 - m1[i], y2 - m2[i], m1[i], m2[i], step + 1);
                visit[x1 + m1[i]][y1 + m2[i]][x2 - m1[i]][y2 - m2[i]][1] = false;
            }
        }
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(visit, 0, sizeof(visit));
    visit[3][3][0][0][0] = true;
    dfs(3, 3, 0, 0, 0, 0, 0);
    return 0;
}