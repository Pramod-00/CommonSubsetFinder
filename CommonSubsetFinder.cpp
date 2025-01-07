// Description: This program finds the common sub-set between two arrays.

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void getInput(int[], int[], const int);
void getnum(int[], const int, int, int&);
void findSubset(int[], int[], int[], int&, const int);

void getInput(int user_nums[], int rand_nums[], const int SIZE)
{
    cout << "Please enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> user_nums[i];
    }

    for (int i = 0; i < SIZE; i++)
    {
        rand_nums[i] = rand() % 100 + 1;
    }
}


void getnum(int numbers[], const int SIZE, int num, int &index)
{
    index = -1;
    for (int i = 0; i < SIZE; i++)
    {
        if (numbers[i] == num)
        {
            index = i;
        }
    }
}

void findSubset(int user_nums[], int rand_nums[], int sub_array[], int &sub_SIZE, const int SIZE)
{
    sub_SIZE = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int index;
        getnum(rand_nums, SIZE, user_nums[i], index);
        if (index != -1)
        {
            sub_array[sub_SIZE++] = user_nums[i];
        }
    }
}


void printData(int user_nums[], int rand_nums[], const int SIZE, int sub_array[], int sub_SIZE)
{
    cout << "The random number array is: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << rand_nums[i] << " ";
    }
    cout << endl;

    cout << "The subset is: ";
    for (int i = 0; i < sub_SIZE; i++)
    {
        cout << sub_array[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int SIZE = 10;
    int user_nums[SIZE], rand_nums[SIZE], sub_array[SIZE];
    int sub_SIZE;

    getInput(user_nums, rand_nums, SIZE);
    findSubset(user_nums, rand_nums, sub_array, sub_SIZE, SIZE);
    printData(user_nums, rand_nums, SIZE, sub_array, sub_SIZE);

    return 0;
}
