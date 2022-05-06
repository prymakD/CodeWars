#include <stack>
#include <iostream>

using namespace std;

struct Bucket {
  int r;
  long bot;
  int h;
};

int main() {

int numOfSets;
cin >> numOfSets;

while (numOfSets != 0) {
	int numOfBuckets;
	cin >> numOfBuckets;
  stack<Bucket> S;

	while (numOfBuckets > 0) {

		Bucket bucket1;
		cin >> bucket1.r;
		cin >> bucket1.h;

		int mTop = 0;
		if (!S.empty()) {
      mTop = S.top().bot;
    }

		while (!S.empty() && S.top().r <= bucket1.r) {

			Bucket bucket2 = S.top();
      S.pop();

			if (bucket2.h + bucket2.bot > mTop) {
        mTop = bucket2.h + bucket2.bot;
      }

		}

		bucket1.bot = mTop;
		S.push(bucket1);
    numOfBuckets--;
	}

	int notSym = 0;

	while (!S.empty()) {

		Bucket bucket2 = S.top();
    S.pop();
		if (bucket2.h + bucket2.bot > notSym) {
      notSym = bucket2.h + bucket2.bot;
    }
	}

	cout << notSym << endl;
	numOfSets--;
	}

}
