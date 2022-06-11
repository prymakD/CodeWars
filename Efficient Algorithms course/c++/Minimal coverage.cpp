#include <stdio.h>
#include <algorithm>

using namespace std;

int numOfTests;
int st,ed,n,f;

struct punkt{
    int st;
    int ed;};

punkt q[100005],p[100005];

int cmp (punkt m, punkt o) {
    return m.ed > o.ed;
}

int main() {
    scanf("%d", &numOfTests);
    while (numOfTests --) {
        n = 0;
        f = 0;
        st = 0;
        scanf("%d", &ed);
        while (scanf("%d%d", &q[n].st, &q[n].ed) && (q[n].st||q[n].ed)) {
            n++;
        }
        sort(q,q + n,cmp);
        while(st < ed) {
            int i;
            for (i=0;i<n;i++) {
                if (q[i].st <= st && q[i].ed > st)
                {
                    st = q[i].ed;
                    p[f] = q[i];
                    f++;
                    break;
                }
            }
            if (i==n) break;
        }
        if(st<ed) printf("0\n");

        else{
            printf("%d\n",f);
            for (int i = 0; i < f; i++)
                printf("%d %d\n", p[i].st,p[i].ed);
        }
        if (numOfTests) printf("\n");
    }
    return 0;
}
