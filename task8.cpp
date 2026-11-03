#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
    vector<int> heap;

public:

   
    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (heap[index] > heap[parent])
            {
                int temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;

                index = parent;
            }
            else
            {
                break;
            }
        }
    }

  
    void insert(int priority)
    {
        heap.push_back(priority);

        int index = heap.size() - 1;

        heapifyUp(index);
    }

   
    int extractMax()
    {
        if (heap.empty())
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int maximum = heap[0];

        heap[0] = heap[heap.size() - 1];

        heap.pop_back();

        
        heapifyDown(0);

        return maximum;
    }

   
    void heapifyDown(int index)
    {
        int size = heap.size();

        while (true)
        {
            int largest = index;

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left] > heap[largest])
            {
                largest = left;
            }

            if (right < size &&
                heap[right] > heap[largest])
            {
                largest = right;
            }

            if (largest != index)
            {
                int temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;

                index = largest;
            }
            else
            {
                break;
            }
        }
    }

  
    void display()
    {
        for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    MaxHeap h;

   
    h.insert(40);
    h.insert(15);
    h.insert(30);
    h.insert(50);
    h.insert(10);
    h.insert(60);

 
    cout << "Max Heap: ";
    h.display();

  
    cout << "Removed Maximum: "
         << h.extractMax() << endl;

  
    cout << "Updated Max Heap: ";
    h.display();

    return 0;
}
