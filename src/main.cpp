#include "header.h"

#include "header.h"

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

const int nmax = 1000;

void Merge(vector<int>& nums,  int idx_start, int idx_end)
{
    // вспомогательные переменные - счётчики
    int i = idx_start;
    int idx_mid = idx_start + (idx_end - idx_start)/2;
    int j = idx_mid + 1;
    
    // итератор по массиву merge_arr
    int k = 0;

    // массив, в который будут объединяться элементы
    int merge_arr[nmax];

    // проверка на выход за пределы разбитых массивов
    while(i <= idx_mid && j <= idx_end)
    {
        // простенький алгоритм сортировки по величине "ячейки"
        if(nums[i] <= nums[j])
        {
            merge_arr[k] = nums[i];
            ++i;
        }
        else
        {
            merge_arr[k] = nums[j];
            ++j;
        }

        // в любом случае переходим к следующему элементу массива merge_arr 
        ++k;
    }

    // дополняем массив, если остались элементы
    while(i <= idx_mid)
    {
        merge_arr[k] = nums[i];
        ++i;
        ++k;
    }
    
    while(j <= idx_end)
    {
        merge_arr[k] = nums[j];
        ++j;
        ++k;
    }

    // переносим массив в основной
    for(i = 0; i < k; ++i)
    {
        nums[idx_start + i] = merge_arr[i];
    }
}


void MergeSort(vector<int>& nums, int idx_start, int idx_end)
{
    /*
        Этапы:
            1. Проверить массив на число элементов: 
              1.1. если 1, то возвращаем
              1.2. если 2, то сравниваем и возвращаем
              1.3. если более 2, то производим рекурсивную сортировку
            2. Кусочки отсортированных массивов объединяем в один массив

    */

    int temp = 0;

    // проверка на более чем 1 элемент
    if(idx_start < idx_end)
    {
        cout << idx_end << " " << idx_start << endl;
        // проверка на 2 элемента в массиве
        if((idx_end - idx_start) == 1)
        {
            // обмен значений переменных без 3 переменной
            if(nums[idx_start] > nums[idx_end])
            {
                temp = nums[idx_start];
                nums[idx_start] = nums[idx_end];
                nums[idx_end] = temp;
            }
        }
        else
            {
                // рекурсивный вызов, для деления левой части на подмассивы до тех пор, 
                // пока не останется массивы из 2 элементов
                MergeSort(nums, idx_start, idx_start + (idx_end - idx_start)/2);

                // рекурсивное деление второй половинки массива
                MergeSort(nums, idx_start + (idx_end - idx_start)/2 + 1, idx_end);
            
                // функция объединения массивов
                Merge(nums, idx_start, idx_end);
            }
    }
}

void toSquare(vector<int>& nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        nums[i] *= nums[i];
    }
}


vector<int> sortedSquares(vector<int>& nums) 
    {
        toSquare(nums);
        MergeSort(nums, 0, nums.size() - 1);
        return nums;    
    }


int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    sortedSquares(nums);
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    
    return 0;
}
