#include <iostream>

using namespace std;

struct Journey {
    string name;
    int order = 0;
    int mana = 0;
};

class Heap {
    Journey* arr;
    int capacity;
    int size;

    void heap_up(int index) {
        if (index == 0) {
            return;
        }
        int parent = (index - 1) / 2;
        if (arr[parent].mana < arr[index].mana || ((arr[parent].mana == arr[index].mana) && (arr[index].order < arr[parent].order))) {
            custom_swap(arr[parent], arr[index]);
            heap_up(parent);
        }
    }

    void heap_down(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < size && (arr[largest].mana < arr[left].mana || (arr[largest].mana == arr[left].mana && arr[left].order < arr[largest].order))) {
            largest = left;
        }
        if (right < size && (arr[largest].mana < arr[right].mana || (arr[largest].mana == arr[right].mana && arr[right].order < arr[largest].order))) {
            largest = right;
        }
        if (largest != index) {
            custom_swap(arr[index], arr[largest]);
            heap_down(largest);
        }
    }

    void custom_swap(Journey& a, Journey& b) {
        Journey temp = a;
        a = b;
        b = temp;
    }

public:
    Heap(int capacity) : capacity(capacity), size(0) {
        arr = new Journey[capacity];
    }

    ~Heap() {
        delete[] arr;
    }

    void push(Journey a) {
        if (size == capacity) {
            capacity *= 2;
            Journey* temp = new Journey[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[size] = a;
        int index = size;
        size++;
        heap_up(index);
    }

    void sort() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heap_down(i);
        }
        for (int i = size - 1; i > 0; i--) {
            custom_swap(arr[0], arr[i]);
            heap_down(0);
        }
    }

    Journey pop() {
        Journey top = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heap_down(0);

        return top;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int N;
    std::cin >> N;

    Heap heap(N);

    for (int i = 0; i < N; ++i) {
        Journey place;
        std::cin >> place.name >> place.mana;
        place.order = i;
        heap.push(place);
    }

    //heap.sort();

    int K;
    std::cin >> K;

    int iterator = 0;

    while (K > 0 && iterator < N) {
        Journey current = heap.pop();
        iterator++;

        if (current.mana <= K) {
            cout << current.name << " ";
            K -= current.mana;
        }
    }

    return 0;
}