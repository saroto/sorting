#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int system ( const char * command );
// start of insertion
class Sort
{
public:
    void insertionSort(int x[], int lenght);
    void driver();
    void display();
    int arr[15]; // because insertion sort is less efficient with large list
    int size;
    int i, x, y, z, key;
};

void Sort::driver()
{
    cout << "Enter size of Array: ";
    cin >> size;
    cout << "Enter " << size << " values" << endl;
    for (y = 0; y < size; y++)
    {
        cin >> arr[y];
    }
    cout << "Elements of your unsorted Array: ";
    for (y = 0; y < size; y++)
    {
        cout << arr[y] << " ";
    }
    cout << endl;

    insertionSort(arr, size);
    cout << "Elements of your sorted Array: ";
    for (z = 0; z < size; z++)
    {
        cout << arr[z] << " ";
    }

    fstream myfile("insertion.txt", ios::out | ios::app);
    for (int i = 0; i < size; i++)
    {   
        myfile<< arr[i] << " ";
    }

    myfile.close();
}

void Sort::insertionSort(int x[], int length)
{
    for (int j = 1; j < length; j++)
    {
        key = x[j];
        i = j - 1;
        while (x[i] > key && i >= 0)
        {
            x[i + 1] = x[i];
            i--;
        }
        x[i + 1] = key;
    }
}

// end

// quicksort
class QuickSort
{
    int n, a[100];

public:
    void Run();
    void swap(int &, int &);
    void print(int[], int);
    int partition(int[], int, int);
    void quicksort(int[], int, int);
};
void QuickSort::Run()
{
    cout << "\nEnter the size of Array: ";
    cin >> n;
     cout << "Enter " << n << " values" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[n + 1] = 1000;
    quicksort(a, 0, n + 1);
    print(a, n);
}
void QuickSort::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void QuickSort::print(int a[], int size)
{   
    int p;
    cout << "Elements of your unsorted Array: ";
    for (p = 0; p < size; p++)
    {
        cout << a[p] << " ";
    }
    cout << endl;
    cout << "Elements of your sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    ofstream myfile("quick.txt", ios::out | ios::app);

    for(int i=0;i<size;i++){
        myfile<<a[i]<<" ";
    }
    myfile.close();

}

int QuickSort::partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= pivot);

        do
        {
            j--;

        } while (a[j] > pivot);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }

    swap(a[l], a[j]);

    return j;
}
void QuickSort::quicksort(int a[], int l, int h)
{
    if (l < h)
    {
        int q = partition(a, l, h);
        quicksort(a, l, q);
        quicksort(a, q + 1, h);
    }
}

// end

// heapsort
class MinHeap
{
public:
    int *harr;     // pointer to array of elements in heap
    int capacity;  // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap

    MinHeap(int cap)
    {
        heap_size = cap;
        capacity = cap;
        harr = new int[cap];
    }

    void printArray()
    {
        for (int i = 0; i < heap_size; i++)
            cout << harr[i] << " ";
        cout << endl;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }
    int getMin()
    {
        return harr[0];
    }
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }
    // Method to remove minimum element (or root) from min heap
    int extractMin()
    {
        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        // Store the minimum value, and remove it from heap
        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);
        // printArray();
        // cout <<"--"<<harr[0]<<"--";
        return root;
    }

    void getUnsortedArray()
    {
        cout << "Enter " << capacity << " values" << endl;
        for (int i = 0; i < capacity; i++)
            cin >> harr[i];
    }

    void heapSort()
    {
        int temp[capacity];
        for (int j = 0; j < capacity; j++)
        {
            // cout<<extractMin()<<" ";
            temp[j] = extractMin();
            cout << temp[j] << " ";
        }
        fstream myfile("heapsort.txt",ios::app | ios::out);


        for(int i=0;i<capacity;i++){
            myfile<<temp[i]<<" ";
            
        }
        
        myfile.close();
    }
};

int main()
{
    int choice;
    do
    {
        cout << "\n------------Menu------------" << endl;
        cout << "1. Insertion sort \n";
        cout << "2. Quick sort \n";
        cout << "3. Heapsort \n";
        cout << "0. Exit \n";
        cout << "------------End-------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Sort frank;
            frank.driver();
            cout << endl;
        }
        break;
        case 2:
        {
            QuickSort q;
            q.Run();
        }
        break;
        case 3:
        {
            int s;
            cout << "Enter Size of Array: ";
            cin >> s; 
            MinHeap obj(s);
            obj.getUnsortedArray(); 

            cout << "Elements of your unsorted Array: ";
            obj.printArray();

            for (int i = s / 2 - 1; i >= 0; i--)
            {
                obj.MinHeapify(i);
            }


            cout << "Elements of your sorted Array: ";
            obj.heapSort();
        }
        break;
        case 0:
        {
            cout << "Exit";
        }
        break;
        default:
            cout << "Invalid input";
            break;
        }
    } while (choice != 0);

    return 0;
}
