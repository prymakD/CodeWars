#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <ctime>
#include <list>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>

#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity (1 << 28)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define SZ(v) (int)(v.size())

using namespace std;

struct point{double x, y;};

int d[110][110], inq[110][110];
struct edge
{
    int city, start, arr;
    edge(){};
    edge(int a, int b, int c)
    {
        city = a;
        start = b;
        arr = c;
    }
};

vector <edge> e[110];

int bfs(int start, int des)
{
    clr(inq, 0);
    queue <edge> q;
    q.push(edge(start, 18, 18));
    d[start][18] = 0;
    inq[start][18] = 1;
    edge u, v;
    int i, ucost, vcost, retrn = infinity;
    while(!q.empty())
    {
        u = q.front();
        if(u.city == des)
            retrn = min(retrn, d[u.city][u.arr]);
        q.pop();
        inq[u.city][u.arr] = 0;
        ucost = d[u.city][u.arr];
        for(i = 0; i < SZ(e[u.city]); i++)
        {
            v.city = e[u.city][i].city, v.start = e[u.city][i].start, v.arr = e[u.city][i].arr;
            vcost = ucost;
            if(v.start < u.arr)
                vcost++;
            if(d[v.city][v.arr] > vcost)
            {
                d[v.city][v.arr] = vcost;
                if(inq[v.city][v.arr] == 0)
                {
                    inq[v.city][v.arr] = 1;
                    q.push(v);
                }
            }
        }
    }
    return retrn;
}

int main()
{
    string a, b;
    int start, arrive, i, j, toTest, m, mc, kase = 1;
    char sa[110], sb[110];
    scanf("%d", &toTest);
    while(toTest--)
    {
        scanf("%d", &m);
        map <string, int> mp;
        mc = 0;
        for(i = 0; i < 110; i++)
        {
            e[i].clear();
            for(j = 0; j < 110; j++)
                d[i][j] = infinity;
        }
        while(m--)
        {
            scanf("%s %s %d %d", sa, sb, &start, &arrive);
            a = sa;
            b = sb;
            if(mp.find(a) == mp.end())
                mp[a] = mc++;
            if(mp.find(b) == mp.end())
                mp[b] = mc++;
            if(start <= 6) start += 24;
            if(arrive > 12) continue;
            arrive += start;
            if(start < 18 || arrive > 30) continue;
            e[mp[a]].pb(edge(mp[b], start, arrive));
        }
        scanf("%s %s", sa, sb);
        a = sa, b = sb;
        printf("Test Case %d.\n", kase++);
        if(mp.find(a) == mp.end() || mp.find(b) == mp.end())
        {
            printf("There is no route Vladimir can take.\n");
            continue;
        }
        arrive = bfs(mp[a], mp[b]);
        if(arrive >= infinity)
            printf("There is no route Vladimir can take.\n");
        else
            printf("Vladimir needs %d litre(s) of blood.\n", arrive);
    }
    return 0;
}
