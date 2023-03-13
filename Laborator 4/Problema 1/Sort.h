#pragma once
class Sort {
    int* vector;
    int count;
    void QuickSort(int low, int high, bool ascendent);
    int partition(int low, int high, bool ascendent);
public:
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
    Sort(int nr_elemente, int min_element, int max_element);
    Sort(int* vector, int nr_elemente);
    Sort(int count, ...);
    Sort(char* c);
    Sort();
};