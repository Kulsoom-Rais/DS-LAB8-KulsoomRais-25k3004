#include <iostream>
using namespace std;

struct Request
{
    int id;
    int priority;
    int order;
};

class PriorityQueue
{
    Request heap[100];
    int size;
    int counter;

    bool isSmaller(Request a, Request b)
    {
        if (a.priority == b.priority)
            return a.order < b.order;

        return a.priority < b.priority;
    }

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (isSmaller(heap[index], heap[parent]))
            {
                Request temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;

                index = parent;
            }
            else
                break;
        }
    }

    void heapifyDown(int index)
    {
        while (true)
        {
            int smallest = index;

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                isSmaller(heap[left], heap[smallest]))
                smallest = left;

            if (right < size &&
                isSmaller(heap[right], heap[smallest]))
                smallest = right;

            if (smallest != index)
            {
                Request temp = heap[index];
                heap[index] = heap[smallest];
                heap[smallest] = temp;

                index = smallest;
            }
            else
                break;
        }
    }

public:

    PriorityQueue()
    {
        size = 0;
        counter = 0;
    }

    void insert(int id, int priority)
    {
        if (size == 100)
        {
            cout << "Queue is full!" << endl;
            return;
        }

        Request r;

        r.id = id;
        r.priority = priority;
        r.order = counter++;

        heap[size] = r;

        heapifyUp(size);

        size++;
    }

    void extractMin()
    {
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Request r = heap[0];

        cout << "Processed Request ID: " << r.id
             << " Priority: " << r.priority << endl;

        heap[0] = heap[size - 1];

        size--;

        if (size > 0)
            heapifyDown(0);
    }

    void peek()
    {
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Next urgent Request ID: "
             << heap[0].id
             << " Priority: "
             << heap[0].priority << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "ID: " << heap[i].id
                 << " Priority: " << heap[i].priority
                 << endl;
        }
    }
};

int main()
{
    PriorityQueue q;

    q.insert(101, 3);
    q.insert(102, 1);
    q.insert(103, 4);
    q.insert(104, 2);
    q.insert(105, 1);
    q.insert(106, 5);

    cout << "Initial Priority Queue:\n";
    q.display();

    cout << "\nRemoving most urgent request:\n";
    q.extractMin();

    cout << "\nNext most urgent request:\n";
    q.peek();

    cout << "\nUpdated Priority Queue:\n";
    q.display();

    return 0;
}
