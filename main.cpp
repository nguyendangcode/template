#include <iostream>
using namespace std;

template <class T>
class Mang {
    int sl;     
    T* data;    
public:

    Mang(int n = 0) {
        sl = n;
        data = new T[sl];
    }
    ~Mang() {
        delete[] data;
    }
    T& operator[](int i) {
        return data[i];
    }
    int size() const { return sl; }
};

int main() {
    Mang<float> a(4);   
    for (int i = 0; i < a.size(); i++) {
        a[i] = i * 10.11;   
    }
    for (int i = 0; i < a.size(); i++) {
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    return 0;
}
