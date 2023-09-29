/*
Author: Michael Mathews
Assignment Title: Assignment 3.1
Assignment Description: Implement Quicksort with different methods of
    choosing a pivot value
Due Date: 9/19/22
Date Created: 9/19/22
Date Last Modified: 9/19/22
*/
#include <iostream>
#include <fstream>

using namespace std;

/*
precondition: an unsorted array is given to the function and no recursions
    have occurred
postcondition: the array is sorted with respect to a pivot value and
    any recursions have been recorded
return type: none
description: this function recursively sorts and splits a group of numbers and
    counts its recursions. the pivot is picked by choosing the first element
    in the array
*/
void quickSort1(int [], int, int, int*);

/*
precondition: an unsorted array is given to the function and no recursions
    have occurred
postcondition: the array is sorted with respect to a pivot value and
    any recursions have been recorded
return type: none
description: this function recursively sorts and splits a group of numbers and
    counts its recursions. the pivot is picked by choosing the last element
    in the array
*/
void quickSort2(int [], int, int, int*);

/*
precondition: an unsorted array is given to the function and no recursions
    have occurred
postcondition: the array is sorted with respect to a pivot value and
    any recursions have been recorded
return type: none
description: this function recursively sorts and splits a group of numbers and
    counts its recursions. the pivot is picked by choosing a random element
    in the array
*/
void quickSort3(int [], int, int, int*);

/*
precondition: an unsorted array is given to the function and no recursions
    have occurred
postcondition: the array is sorted with respect to a pivot value and
    any recursions have been recorded
return type: none
description: this function recursively sorts and splits a group of numbers and
    counts its recursions. the pivot is picked by choosing the median of
    the first, last and middle elements in the array
*/
void quickSort4(int [], int, int, int*);

/*
precondition: an unsorted array is given to the function
postcondition: the array is sorted with respect to a pivot value
return type: the index of the sorted pivot
description: this function sorts a group of numbers. the pivot is picked
    by choosing the first element in the array
*/
int partition1(int [], int, int);

/*
precondition: an unsorted array is given to the function
postcondition: the array is sorted with respect to a pivot value
return type: the index of the sorted pivot
description: this function sorts a group of numbers. the pivot is picked
    by choosing the last element in the array
*/
int partition2(int [], int, int);

/*
precondition: an unsorted array is given to the function
postcondition: the array is sorted with respect to a pivot value
return type: the index of the sorted pivot
description: this function sorts a group of numbers. the pivot is picked
    by choosing a random element in the array
*/
int partition3(int [], int, int);

/*
precondition: an unsorted array is given to the function
postcondition: the array is sorted with respect to a pivot value
return type: the index of the sorted pivot
description: this function sorts a group of numbers. the pivot is picked
    by choosing the median of the first, last, and middle elements in
    an array
*/int partition4(int [], int, int);

/*
Data Abstraction: 4 files and 4 arrays are initiallized
Input: None
Process: Call a quicksort on each type of choosing a pivot
Output: The amount of recursions per type of choosing a pivot (tested on
    each file)
Assumptions: The user runs the program
*/
int main(){
    const int MAX = 10000;
    string fileName1 = "QuickSort10k.txt";
    string fileName2 = "QuickSort10kR.txt";
    string fileName3 = "QuickSort10kSemi2k.txt";
    string fileName4 = "QuickSort10kSemi4k.txt";
    ifstream inputFile;
    int array1[MAX], array2[MAX], array3[MAX], array4[MAX], num, count = 0;
    int* total = new int;
    
    //QuickSort10k
    inputFile.open(fileName1);
    
    while(inputFile >> num){
        array1[count] = num;
        array2[count] = num;
        array3[count] = num;
        array4[count] = num;
        count++;
    }
    
    cout << fileName1 << ":" << endl;
    *total = 0;
    quickSort1(array1, 0, count-1, total);
    cout << "Total Recursions (first): " << *total << endl;
    *total = 0;
    quickSort2(array2, 0, count-1, total);
    cout << "Total Recursions (last): " << *total << endl;
    *total = 0;
    quickSort3(array3, 0, count-1, total);
    cout << "Total Recursions (random): " << *total << endl;
    *total = 0;
    quickSort4(array4, 0, count-1, total);
    cout << "Total Recursions (medianOfThree): " << *total << endl;
    
    inputFile.close();
    cout << endl;
    
    //QuickSort10kR
    inputFile.open(fileName2);
    count = 0;
    
    while(inputFile >> num){
        array1[count] = num;
        array2[count] = num;
        array3[count] = num;
        array4[count] = num;
        count++;
    }
    
    cout << fileName2 << ":" << endl;
    *total = 0;
    quickSort1(array1, 0, count-1, total);
    cout << "Total Recursions (first): " << *total << endl;
    *total = 0;
    quickSort2(array2, 0, count-1, total);
    cout << "Total Recursions (last): " << *total << endl;
    *total = 0;
    quickSort3(array3, 0, count-1, total);
    cout << "Total Recursions (random): " << *total << endl;
    *total = 0;
    quickSort4(array4, 0, count-1, total);
    cout << "Total Recursions (medianOfThree): " << *total << endl;
    
    inputFile.close();
    cout << endl;
    
    //QuickSort10kSemi2k
    inputFile.open("QuickSort10kSemi2k.txt");
    count = 0;
    
    while(inputFile >> num){
        array1[count] = num;
        array2[count] = num;
        array3[count] = num;
        array4[count] = num;
        count++;
    }
    
    cout << fileName3 << ":" << endl;
    *total = 0;
    quickSort1(array1, 0, count-1, total);
    cout << "Total Recursions (first): " << *total << endl;
    *total = 0;
    quickSort2(array2, 0, count-1, total);
    cout << "Total Recursions (last): " << *total << endl;
    *total = 0;
    quickSort3(array3, 0, count-1, total);
    cout << "Total Recursions (random): " << *total << endl;
    *total = 0;
    quickSort4(array4, 0, count-1, total);
    cout << "Total Recursions (medianOfThree): " << *total << endl;
    
    inputFile.close();
    cout << endl;
    
    //QuickSort10kSemi4k
    inputFile.open(fileName3);
    count = 0;
    
    while(inputFile >> num){
        array1[count] = num;
        array2[count] = num;
        array3[count] = num;
        array4[count] = num;
        count++;
    }
    
    cout << fileName4 << ":" << endl;
    *total = 0;
    quickSort1(array1, 0, count-1, total);
    cout << "Total Recursions (first): " << *total << endl;
    *total = 0;
    quickSort2(array2, 0, count-1, total);
    cout << "Total Recursions (last): " << *total << endl;
    *total = 0;
    quickSort3(array3, 0, count-1, total);
    cout << "Total Recursions (random): " << *total << endl;
    *total = 0;
    quickSort4(array4, 0, count-1, total);
    cout << "Total Recursions (medianOfThree): " << *total << endl;
    
    inputFile.close();
    
    return 0;
}
 

int partition1(int array[], int front, int back){
    int pivIndex, count = 0;
    
    //set pivot to first value
    int piv = array[front];
    
    //find starting pivot index
    for (int i = front+1; i <= back; i++){
        if (array[i] <= piv){
            count++;
        }
    }
    //sort pivot to correct location
    pivIndex = front + count;
    swap(array[pivIndex], array[front]);
    
    //sort each side
    int i = front, j = back;
    while (i < pivIndex && j > pivIndex){
        while (array[i] <= piv){
            i++;
        }
        while (array[j] > piv){
            j--;
        }
        if (i < pivIndex && j > pivIndex){
            swap(array[i++], array[j--]);
        }
    }
    return pivIndex;
}

int partition2(int array[], int front, int back){
    int pivIndex, count = 0;
    
    //set pivot to last value
    int piv = array[back];
    swap(array[front],array[back]);
    
    
    //find starting pivot index
    for (int i = front+1; i <= back; i++){
        if (array[i] <= piv){
            count++;
        }
    }
    //sort pivot to correct location
    pivIndex = front + count;
    swap(array[pivIndex], array[front]);
    
    //sort each side
    int i = front, j = back;
    while (i < pivIndex && j > pivIndex){
        while (array[i] <= piv){
            i++;
        }
        while (array[j] > piv){
            j--;
        }
        if (i < pivIndex && j > pivIndex){
            swap(array[i++], array[j--]);
        }
    }
    return pivIndex;
}

int partition3(int array[], int front, int back){
    int pivIndex, count = 0;
    srand(time(nullptr));
    int random = (rand() % (back-front) + 1) + front;
    //set pivot to random value
    int piv = array[random];
    swap(array[front], array[random]);
    
    //find starting pivot index
    for (int i = front+1; i <= back; i++){
        if (array[i] <= piv){
            count++;
        }
    }
    //sort pivot to correct location
    pivIndex = front + count;
    swap(array[pivIndex], array[front]);
    
    //sort each side
    int i = front, j = back;
    while (i < pivIndex && j > pivIndex){
        while (array[i] <= piv){
            i++;
        }
        while (array[j] > piv){
            j--;
        }
        if (i < pivIndex && j > pivIndex){
            swap(array[i++], array[j--]);
        }
    }
    return pivIndex;
}

int partition4(int array[], int front, int back){
    int pivIndex, count = 0, median, mid, top, bot;
    //set pivot to median of 3 value
    mid = (back-front) / 2;
    int arr[3] = {array[front], array[mid], array[back]};
    for(int i = 0; i < 2; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    if(arr[0] > arr[1]){
        swap(arr[0], arr[1]);
    }
    for(int i = 0; i < 3; i++){
        if(arr[i] == array[front]){median = front;}
        else if(arr[i] == array[mid]){median = mid;}
        else{median = back;}
    }
    
    int piv = arr[1];
    swap(array[front], array[median]);
    
    //find starting pivot index
    for (int i = front+1; i <= back; i++){
        if (array[i] <= piv){
            count++;
        }
    }
    //sort pivot to correct location
    pivIndex = front + count;
    swap(array[pivIndex], array[front]);
    
    //sort each side
    int i = front, j = back;
    while (i < pivIndex && j > pivIndex){
        while (array[i] <= piv){
            i++;
        }
        while (array[j] > piv){
            j--;
        }
        if (i < pivIndex && j > pivIndex){
            swap(array[i++], array[j--]);
        }
    }
    return pivIndex;
}
 
void quickSort1(int array[], int front, int back, int* total){
    if (front < back){
        int piv = partition1(array, front, back);
        *total += (back-front-1);
        quickSort1(array, front, piv-1, total);
        quickSort1(array, piv+1, back, total);
    }
}
 
void quickSort2(int array[], int front, int back, int* total){
    if (front < back){
        int piv = partition2(array, front, back);
        *total += (back-front-1);
        quickSort2(array, front, piv-1, total);
        quickSort2(array, piv+1, back, total);
    }
}

void quickSort3(int array[], int front, int back, int* total){
    if (front < back){
        int piv = partition3(array, front, back);
        *total += (back-front-1);
        quickSort3(array, front, piv-1, total);
        quickSort3(array, piv+1, back, total);
    }
}

void quickSort4(int array[], int front, int back, int* total){
    if (front < back){
        int piv = partition4(array, front, back);
        *total += (back-front-1);
        quickSort4(array, front, piv-1, total);
        quickSort4(array, piv+1, back, total);
    }
}
