#include <iostream>
using namespace std;

template <class T>
class Mang {
    int sl;        
    int capacity; 
    T* data;
    void resize(int newCap) {
        if (newCap <= capacity) return;
        T* newData = new T[newCap];
        for (int i = 0; i < sl; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }
public:
    Mang(int n = 0) {
        sl = 0;
        capacity = (n > 0) ? n : 1;
        data = new T[capacity];
    }
    ~Mang() {
        delete[] data;
    }
    T& operator[](int i) {
        if (i >= capacity) {
            resize(i + 1);
        }
        if (i >= sl) {
            sl = i + 1;
        }
        return data[i];
    }

    int size() const { return sl; }
    int getCapacity() const { return capacity; }

    void print() const {
        for (int i = 0; i < sl; i++) cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    Mang<int> a;
    a[0] = 10;   
    a[1] = 20;   
    a[9] = 50;   
    cout << "Mang hien tai: ";
    a.print();
    cout << "So phan tu = " << a.size() 
         << ", capacity = " << a.getCapacity() << endl;
    return 0;
}
