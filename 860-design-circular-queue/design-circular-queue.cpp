class MyCircularQueue {
public:
    int f = 0;
    int b = 0;
    int size = 0;
    int c;
    vector<int> arr;

    MyCircularQueue(int k) {
        c = k;
        arr.resize(c);
    }

    bool enQueue(int value) { // push
        if(size == c) return false;

        arr[b] = value;
        b++;

        if(b == c) b = 0;

        size++;
        return true;
    }

    bool deQueue() { // pop
        if(size == 0) return false;

        f++;

        if(f == c) f = 0;

        size--;
        return true;
    }

    int Front() {
        if(size == 0) return -1;

        return arr[f];
    }

    int Rear() {
        if(size == 0) return -1;

        if(b == 0) return arr[c-1];

        return arr[b-1];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == c;
    }
};