#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<queue>
#include<algorithm>
#include<cstring>
#include<deque>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<cctype>
#include<functional>

using namespace std;

int main(){
  int war[105][1000];
	int co, c = 1, se, qu;
	while (scanf("%d%d%d", &co, &se, &qu) == 3){
		if (co == 0 && se == 0 && qu == 0)
			break;
		if (c > 1){
    	putchar('\n');
    }
		for (int i = 0; i < 105; i++)
			for (int j = 0; j < 105; j++)
				war[i][j] = 1e9;
		for (int i = 0; i < se; i++){

			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			war[a][b] = war[b][a] = w;
		}
		for (int k = 1; k <= co; k++)
			for (int i = 1; i <= co; i++)
				for (int j = 1; j <= co; j++)
					war[i][j] = min(war[i][j], max(war[i][k], war[k][j]));
		printf("Case #%d\n", c++);
		for (int i = 0; i < qu; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			if (war[a][b] == 1e9) {
				puts("no path");
			}else {
				printf("%d\n", war[a][b]);
      }
		}
	}
	return 0;
}
