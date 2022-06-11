#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <utility>
#include <functional>

using namespace std;

static const int MAXN = 5000;
int n;

priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
  while( scanf("%d", &n ) && n )
  {
    while( !pq.empty() )
    {
      pq.pop();
    }
      for( int i = 0; i < n; i++ )
      {
  int a = 0;
          scanf("%d", &a );
    pq.push( a );
      }
      int sum = 0;
    	while( pq.size() > 1 )
    	{
    		int min1 = pq.top();
    		pq.pop();
    		int min2 = pq.top();
    		pq.pop();
    		int min = min1 + min2;
    		sum += min;
    		pq.push( min );
    	}
    	cout << sum << endl;
  }
    return 0;
}
