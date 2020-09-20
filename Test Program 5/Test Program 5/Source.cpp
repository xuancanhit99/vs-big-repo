#include <iostream>
#include <set>

using namespace std;

int Build(multiset<int>& b)
{
	auto pre = b.end();
	pre--;
	int mer = *pre;
	b.erase(pre);
	return mer;
}
int main()
{
	int n, k;
	while (1)
	{
		cin >> n >> k;
		multiset<int> b;
		b.insert(n);
		int mer1, mer2;
		for (int i = 0; i < k; i++) {
			n = Build(b);
			mer1 = (n - 1) / 2;
			mer2 = n - 1 - mer1;
			b.insert(mer1);
			b.insert(mer2);
		}
		cout << mer1 << endl;
		cout << mer2 << endl;
		char c;
		cout << endl << "Do you want continue?(y/n):"; cin >> c;
		if (c == 'n')
			break;
	}
	return 0;
}
