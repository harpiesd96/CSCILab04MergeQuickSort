#include <iostream>
#include <random>
#include <chrono>

static constexpr size_t ARRAY_SIZE = 128;

//swaps 2 integers
void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//print array
void PrintArray(int* array)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

//merge sort
void Merge(int* array, int low, int high, int mid);
void MergeSort(int* array, int low, int high)
{
    int mid;
    if (low < high)
    {
        //divide the array at mid and sort independently using merge sort
        mid = (low + high) / 2;
        MergeSort(array, low, mid);
        MergeSort(array, mid + 1, high);
        //merge or conquer sorted arrays
        Merge(array, low, high, mid);
    }
}
void Merge(int* array, int low, int high, int mid)
{
    int i, j, k, c[ARRAY_SIZE];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (array[i] < array[j]) {
            c[k] = array[i];
            k++;
            i++;
        }
        else {
            c[k] = array[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = array[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = array[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        array[i] = c[i];
    }
}


//quick sort
int partition(int* array, int low, int high)
{
    int pivot = array[high];    // pivot 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (array[j] <= pivot)
        {
            i++;    // increment index of smaller element 
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}
void QuickSort(int* array, int low, int high)
{
    if (low < high)
    {
        //partition the array 
        int pivot = partition(array, low, high);

        //sort the sub arrays independently 
        QuickSort(array, low, pivot - 1);
        QuickSort(array, pivot + 1, high);
    }
}


int main()
{
    std::cout << "Hello World!\n" << std::endl;

    //container for user input
    char input;

    do
    {
        //create arrays to be sorted
        int container0[ARRAY_SIZE];
        int container1[ARRAY_SIZE];
        //populate arrays randomly
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            int j = rand() % 100;
            container0[i] = j;
            container1[i] = j;
        }


        //show container
        std::cout << "merge sort:" << std::endl;
        PrintArray(container0);
        //record start time
        auto start = std::chrono::high_resolution_clock::now();
        //merge sort array
        MergeSort(container0, 0, ARRAY_SIZE-1);
        //record end time
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long double> delta_time = end - start;
        //show results of bubble sort
        PrintArray(container0);
        std::cout << "sort time: " << delta_time.count() << "s\n" << std::endl;

        
        //show container
        std::cout << "quick sort:" << std::endl;
        PrintArray(container1);
        //record start time
        start = std::chrono::high_resolution_clock::now();
        //selection sort array
        QuickSort(container1, 0, ARRAY_SIZE-1);
        //record end time
        end = std::chrono::high_resolution_clock::now();
        delta_time = end - start;
        //show results of bubble sort
        PrintArray(container1);
        std::cout << "sort time: " << delta_time.count() << "s\n" << std::endl;


        std::cout << "continue? y/n" << std::endl;
        std::cin >> input;
    } while (input == 'y');
}