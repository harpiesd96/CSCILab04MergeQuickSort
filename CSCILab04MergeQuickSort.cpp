#include <iostream>
#include <random>
#include <chrono>
#include <math.h>

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
void MergeSort(int* array)
{

}

//quick sort
void QuickSort(int* array)
{

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
        std::cout << "bubble sort:" << std::endl;
        PrintArray(container0);
        //record start time
        auto start = std::chrono::high_resolution_clock::now();
        //insertion sort array
        //BubbleSort(container0);
        //record end time
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long double> delta_time = end - start;
        //show results of bubble sort
        PrintArray(container0);
        std::cout << "sort time: " << delta_time.count() << "s\n" << std::endl;


        //show container
        std::cout << "selection sort:" << std::endl;
        PrintArray(container1);
        //record start time
        start = std::chrono::high_resolution_clock::now();
        //selection sort array
        //SelectionSort(container1);
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