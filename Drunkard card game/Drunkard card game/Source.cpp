#include <queue>
#include <iostream>
using namespace std;

int main()
{
    int N = 10;
    queue<int> a, b;
    for (int i = 0, x; i < N / 2; ++i)
        cin >> x, 
        a.push(x);
    for (int i = 0, x; i < N / 2; ++i) cin >> x, b.push(x);
    int moves = 0;
    for (; !a.empty() && !b.empty() && moves <= 200000; ++moves)
    {
        int ac = a.front(), bc = b.front();
       
        a.pop(); b.pop(); // xoa phan tu dau tien

        queue<int> win;
        if (ac == 0 && bc == N - 1)
            win = a;
        else if (bc == 0 && ac == N - 1)
            win = b;
        else if (ac > bc)
            win = a;
        else
            win = b;
            



        /*queue<int>* win = (ac == 0 && bc == N - 1) ? &a :
            (bc == 0 && ac == N - 1) ? &b :
            (ac > bc) ? &a : &b;*/
        win.push(ac); win.push(bc);
    }
    if (a.empty()) cout << "second " << moves << endl;
    else if (b.empty()) cout << "first " << moves << endl;
    else cout << "botva\n";
}