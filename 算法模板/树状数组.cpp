#include<iostream>
#include<vector>
using namespace std;

template <class T>
class BinaryIndexedTree {
private:
    int n;
    vector<T> F;
    vector<T> Num;

    int lowbit(int x) {
        return x & -x;
    }
    //let Num[i] add x
    void add(int i, T x) {
        Num[i] += x;
        while (i <= n) {
            F[i] += x;
            i += lowbit(i);
        }
    }
    //get the preSum Num[i] that means Num[1]+Num[2]....+Num[i]
    T sum(int i) {
        T res = 0;
        while (i > 0) {
            res += F[i];
            i -= lowbit(i);
        }
        return res;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    //get Num[i]
    T getNum(int i) {
        return Num[i];
    }

public:
    BinaryIndexedTree(int count) {
        n = count;
        F = vector<T>(n+1);
        Num = vector<T>(n+1);
    }
    void Add(int i, T x) {
        if (i > 0 && i <= n) {
            add(i, x);
        }
    }
    T GetNum(int i) {
        if (i > 0 && i <= n) {
            return getNum(i);
        }
        return -1;
    }
    T Sum(int i) {
        if (i > 0 && i <= n) {
            return sum(i);
        }
        return -1;
    }
    T Sum(int l, int r) {
        if (l > 0 && r >= l && r <= n) {
            return sum(l, r);
        }
        return -1;
    }
};
int main(){
    BinaryIndexedTree<int> a(10);
    for (int i = 1; i <= 10; i++) {
        a.Add(i, i);
    }
    //1+2+3+4
    cout << a.Sum(4)<<endl;
    //1+2+3
    cout << a.Sum(1, 3)<<endl;
    //10
    cout << a.GetNum(10)<<endl;
}