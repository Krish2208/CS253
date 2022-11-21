#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<char, int> PAIR;

struct cmp {
	bool operator()(const PAIR& a, const PAIR& b)
	{
		if(a.second < b.second) return true;
		else if(a.second > b.second) return false;
		else return a.first > b.first;
	}
};

void rearrange(char* str, int d)
{
	int n = strlen(str);
	unordered_map<char, int> m;
	for (int i = 0; i < n; i++) {
		m[str[i]]++;
		str[i] = '\0';
	}
	priority_queue<PAIR, vector<PAIR>, cmp> pq(m.begin(),m.end());
	while (pq.empty() == false) {
		char x = pq.top().first;
		int p = 0;
		while (str[p] != '\0')
			p++;
		for (int k = 0; k < pq.top().second; k++) {
			if (p + d * k >= n) {
				cout << "''";
				exit(0);
			}
			str[p + d * k] = x;
		}
		pq.pop();
	}
}
int main()
{
	char str[] = "aa";
	rearrange(str,2);
	cout << str;
}
