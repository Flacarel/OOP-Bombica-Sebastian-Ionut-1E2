#include <iostream>
using namespace std;

template <class K, class V>
class Map {
private:
    struct element {
        K key;
        V value;
        int index;
    };
    element* x = new element[100];
    int count = 0;
public:

    V& operator[](K key) {
        for (int i = 0; i < this->count; i++)
            if (x[i].key == key)
                return x[i].value;
        x[count].key = key;
        x[count].value = V{};
        x[count].index = count;
        count++;
        return x[count - 1].value;
    }

    bool Get(const K& key, V& value) {
        for (int i = 0; i < this->count; i++)
            if (this->x[i].key == key)
            {
                value = this->x[i].value;
                return true;
            }
        return false;
    }

    int Count() {
        return this->count;
    }

    void Clear() {
        delete[] x;
        this->x = new element[100];
        this->count = 0;
    }

    bool Delete(const K& key) {
        for (int i = 0; i < this->count; i++)
            if (this->x[i].key == key) {
                for (int j = i + 1; j < this->count; j++)
                {
                    x[j].index--;
                    x[j - 1] = x[j];
                }
                this->count--;
                return true;
            }
        return false;
    }

    void Set(K key, V value) {
        int gasit = 0;
        for (int i = 0; i < this->count; i++)
            if (x[i].key == key)
            {
                gasit = 1;
                x[i].value = value;
                break;
            }
        if (gasit == 0)
        {
            x[count].key = key;
            x[count].value = value;
            x[count].index = count;
            this->count++;
        }

    }

    element* begin() {
        return &x[0];
    }
    element* end() {
        return &x[count];
    }

    bool Includes(const Map<K, V>& newmap) {
        int ok = 0;
        for (int j = 0; j < newmap.count; j++) {
            K keys = newmap.element[j].key;
            ok = 0;
            for (int i = 0; i < this->count; i++) {
                if (element[i].key == keys) ok = 1;
            }
            if (ok == 0) return false;
        }
        return true;
    }
};

int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}