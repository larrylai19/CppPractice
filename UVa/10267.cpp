#include <bits/stdc++.h>

using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int M, N;
int X1, Y1;
int X2, Y2;
int d[] = { 1, 0, -1, 0, 1 };
char C;
char G[251][251];
string fileName, trash;

void drawRectangle(int x1, int y1, int x2, int y2, int reset = 0)
{
    if (reset) C = 'O';
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);

    for (int i = y1; i <= y2; ++i) for (int j = x1; j <= x2; ++j)
        G[i][j] = C;
}

void resetGraph() { drawRectangle(1, 1, M, N, 1); }

void verticalLine() { drawRectangle(X1, Y1, X1, Y2); }

void horizontalLine() { drawRectangle(X1, Y1, X2, Y1); }

void floodFill(int x, int y, char present)
{
    if (x < 1 || x > M || y < 1 || y > N) return;
    if (G[y][x] == C || G[y][x] != present) return;

    G[y][x] = C;
    for (int i = 0; i < 4; ++i)
        floodFill(x + d[i], y + d[i + 1], present);
}

void printGraph()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j) cout << G[i][j];
        cout << '\n';
    }
}

int main()
{
    char cmd;

    while (cin >> cmd, cmd != 'X') switch (cmd)
    {
    case 'I':
        cin >> M >> N;
        resetGraph();
        break;

    case 'C':
        resetGraph();
        break;

    case 'L':
        cin >> X1 >> Y1 >> G[Y1][X1];
        break;

    case 'V':
        cin >> X1 >> Y1 >> Y2 >> C;
        verticalLine();
        break;

    case 'H':
        cin >> X1 >> X2 >> Y1 >> C;
        horizontalLine();
        break;

    case 'K':
        cin >> X1 >> Y1 >> X2 >> Y2 >> C;
        drawRectangle(X1, Y1, X2, Y2);
        break;

    case 'F':
        cin >> X1 >> Y1 >> C;
        floodFill(X1, Y1, G[Y1][X1]);
        break;

    case 'S':
        cin >> fileName;
        cout << fileName << '\n';
        printGraph();
        break;

    default:
        cin.ignore();
        getline(cin, trash);
        break;
    }
}