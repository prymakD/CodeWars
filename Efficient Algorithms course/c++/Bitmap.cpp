#include <stdio.h>
#include <queue>

// ---------------------------   GLOBALE  --------------------------- //
std::queue<std::pair<short int, short int> >Q;
int ltestow, h, w, w_a, h_a, tab[200][200];

char c;

// ---------------------------  FUNCTIONS --------------------------- //
void READ();
void PRINT();
void BFS();
void START_Q();
void CLEAR();
// ---------------------------    MAIN    --------------------------- //
int main ()
{
    scanf("%d", &ltestow);
    while(ltestow--)
    {
        CLEAR();
        READ();
        BFS();
        PRINT();
    }

}

// ---------------------------  FUNCTIONS --------------------------- //
void READ()
{
    while(Q.size())
        Q.pop();
    scanf("%d%d ", &h, &w);
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            scanf("%c", &c);
            if(c=='1')
            {
                tab[j][i]=0;
                Q.push(std::make_pair(j, i));
            }
        }
        scanf("\n");
    }
}
void PRINT()
{
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
            printf("%d ", tab[j][i]);
        printf("\n");
    }
}
void BFS()
{
    while(Q.size())
    {
        w_a=Q.front().first;
        h_a=Q.front().second;
// SZEROKOŚĆ
        if(w_a>0 && tab[w_a-1][h_a]==-1)
        {
                tab[w_a-1][h_a]=tab[w_a][h_a]+1;
                Q.push(std::make_pair(w_a-1, h_a));
        }
        if(w_a<w && tab[w_a+1][h_a]==-1)
        {
                tab[w_a+1][h_a]=tab[w_a][h_a]+1;
                Q.push(std::make_pair(w_a+1, h_a));
        }
// WYSOKOŚĆ
        if(h_a>0 && tab[w_a][h_a-1]==-1)
        {
                tab[w_a][h_a-1]=tab[w_a][h_a]+1;
                Q.push(std::make_pair(w_a, h_a-1));
        }
        if(h_a<h && tab[w_a][h_a+1]==-1)
        {
                tab[w_a][h_a+1]=tab[w_a][h_a]+1;
                Q.push(std::make_pair(w_a, h_a+1));
        }
        Q.pop();
    }
}
void CLEAR()
{
    for(int i=0; i<200; i++)
        for(int j=0; j<200; j++)
            tab[j][i]=-1;
}
