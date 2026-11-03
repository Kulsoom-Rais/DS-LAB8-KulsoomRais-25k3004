#include <iostream>
using namespace std;

class MinHeap
{
    int heap[100];
    int size;

public:

    MinHeap()
    {
        size = 0;
    }

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (heap[index] < heap[parent])
            {
                int temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;

                index = parent;
            }
            else
                break;
        }
    }

    void insert(int urgency)
    {
        if (size == 100)
        {
            cout << "Heap is full!" << endl;
            return;
        }

        heap[size] = urgency;

        heapifyUp(size);

        size++;
    }

    void heapifyDown(int index)
    {
        while (true)
        {
            int smallest = index;

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left] < heap[smallest])
                smallest = left;

            if (right < size &&
                heap[right] < heap[smallest])
                smallest = right;

            if (smallest != index)
            {
                int temp = heap[index];
                heap[index] = heap[smallest];
                heap[smallest] = temp;

                index = smallest;
            }
            else
                break;
        }
    }

    int extractMin()
    {
        if (size == 0)
            return -1;

        int minimum = heap[0];

        heap[0] = heap[size - 1];

        size--;

        if (size > 0)
            heapifyDown(0);

        return minimum;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";

        cout << endl;
    }
};

int main()
{
    MinHeap h;

    h.insert(35);
    h.insert(12);
    h.insert(25);
    h.insert(8);
    h.insert(40);
    h.insert(5);

    cout << "Min Heap: ";
    h.display();

    cout << "Removed minimum: "
         << h.extractMin() << endl;

    cout << "Updated Min Heap: ";
    h.display();

    return 0;
}
