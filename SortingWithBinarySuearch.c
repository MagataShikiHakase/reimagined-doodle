//This C program manages an array of counters with various operations, including printing,
//incrementing, and decrementing values based on their indices. It uses binary search functions to efficiently
//locate and update the positions of elements in the array. Users interact with the program through a
//menu-driven interface that performs operations like printing arrays, updating counts, and querying the number
//of values within a specified range.
//Name: Yuma Fukazawa
//Student ID: 1002236682
//Command used to compile: gcc -std=c99 -o t1 3318_lab1.c

#include <stdio.h>

int binSearchFirst(int *a, int n, int key){
    // Input:      int array a[] with n elements in ascending order.
    //             int key to find.
    // Output:     Returns subscript of the first a element >= key.
    //             Returns n if key>a[n-1].
    // Processing: Binary search.
    int high, mid, low;

    low = 0;
    high = n - 1;

// Subscripts between low and high are in search range.
// Size of range halves in each iteration.
// When low>high, low==high+1 and a[high]<key and a[low]>=key.
    while(low <= high){
        mid = (high + low) / 2;
        if(a[mid] < a[key])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int binSearchLast(int *a, int n, int key){
    // Input:      int array a[] with n elements in ascending order.
    //             int key to find.
    // Output:     Returns subscript of the last a element <= key.
    //             Returns -1 if key<a[0].
    // Processing: Binary search.   
    int high, mid, low;

        low = 0;
        high = n - 1;

// subscripts between low and high are in search range.
// size of range halves in each iteration.
// When low>high, low==high+1 and a[high]<=key and a[low]>key.
    while(low <= high){
        mid = (high + low) / 2;
        if(a[mid] <= a[key])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int binSearchFirst5(int *a, int n, int key){
    // Input:      int array a[] with n elements in ascending order.
    //             int key to find.
    // Output:     Returns subscript of the first a element >= key.
    //             Returns n if key>a[n-1].
    // Processing: Binary search.
    int high, mid, low;

    low = 0;
    high = n - 1;

// Subscripts between low and high are in search range.
// Size of range halves in each iteration.
// When low>high, low==high+1 and a[high]<key and a[low]>=key.
    while(low <= high){
        mid = (high + low) / 2;
        if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int binSearchLast5(int *a, int n, int key){
    // Input:      int array a[] with n elements in ascending order.
    //             int key to find.
    // Output:     Returns subscript of the last a element <= key.
    //             Returns -1 if key<a[0].
    // Processing: Binary search.   
    int high, mid, low;

        low = 0;
        high = n - 1;

// subscripts between low and high are in search range.
// size of range halves in each iteration.
// When low>high, low==high+1 and a[high]<=key and a[low]>key.
    while(low <= high){
        mid = (high + low) / 2;
        if(a[mid] <= key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

void swap(int *a, int *b){
    //Input:      Two pointers to integers (int *a, int *b)
    //Output:     None (The function is void and swaps the values of the two integers pointed to by the input pointers)
    //Processing: The values of the two integers are stored in temporary variables, 
    //            and then the values are swapped by assigning each pointer the value of the other.
    int tempA = *a, tempB = *b;
    *a = tempB;
    *b = tempA; 
}

int main(){
    //i: Loop counter variable.
    //n: Stores the number of elements.
    //operation: Represents the user-selected operation.
    //point_of_add_or_subtract: Indicates the index for which to add or subtract a count.
    //point_in_array: Represents the position in the array corresponding to the index being modified.
    //first: Holds the index of the first element found by binary search that is greater than or equal to the key.
    //last: Holds the index of the last element found by binary search that is less than or equal to the key.
    //number_of_same_count: Represents the number of elements between first and last.
    //inf: The lower bound used in a range query.
    //sup: The upper bound used in a range query.
    //index: An array storing the original indices.
    //count: An array storing the count values for each counter.
    //map: An array storing the mapping of indices.
    int i, n, operation, point_of_add_or_subtract, point_in_array, first, last, number_of_same_count, inf, sup;

    //Getting the number of elements
    scanf("%d", &n);
    int index[n], count[n], map[n];

    //Setting all values of arrays
    for(i = 0; i < n; i++){
        index[i] = i;
        count[i] = 0;
        map[i] = i;
    }
    //Keep doing entered #1-5 operation until 0 is entered
    while(operation != 0){
        scanf("%d", &operation);

        //Operation 1
        if(operation == 1){
            printf("------------\nprint by index\n");
            for(i = 0; i < n; i++){
                printf("%d %d\n", i, count[map[i]]);
            }   
        }
        //Operation 2
        else if(operation == 2){
            printf("------------\nprint by count\n");
            for(i = 0; i < n; i++){
                printf("%d %d\n", index[i], count[i]);
            }
        }
        //Operation 3
        else if(operation == 3){
            scanf("%d", &point_of_add_or_subtract);

            for(int i = 0; i < n; i++){
                if(point_of_add_or_subtract == index[i])
                    point_in_array = i;
            }

            first = binSearchFirst(count, n, point_in_array);
            last = binSearchLast(count, n, point_in_array);
            number_of_same_count = last - first + 1;
            
            //Case: No need to swap
            if(number_of_same_count == 1 || point_in_array == last){
                count[point_in_array]++;
            }
            //Case: Need to swap
            else{
                count[point_in_array]++;
                swap(&map[index[point_in_array]], &map[index[last]]);
                swap(&index[point_in_array], &index[last]);
                swap(&count[point_in_array], &count[last]);
            }
        }
        //Operation 4
        else if(operation == 4){
            scanf("%d", &point_of_add_or_subtract);
            for(int i = 0; i < n; i++){
                if(point_of_add_or_subtract == index[i])
                    point_in_array = i;
            }
            first = binSearchFirst(count, n, point_in_array);
            last = binSearchLast(count, n, point_in_array);
            number_of_same_count = last - first + 1;

            //Case: No need to swap
            if(number_of_same_count == 1 || point_in_array == first){
                count[point_in_array]--;
            }
            //Case: Need to swap
            else{
                count[point_in_array]--;
                swap(&map[index[point_in_array]], &map[index[first]]);
                swap(&index[point_in_array], &index[first]);
                swap(&count[point_in_array], &count[first]);
            }
        }
        //Operation 5
        else if(operation == 5){
            scanf("%d %d", &inf, &sup);
            int s = sup, number_of_values = 0;
            //Summing up the number of values entered range by 1
            for(int i = inf; i <= s; i++){
                first = binSearchFirst5(count, n, i);
                last = binSearchLast5(count, n, i);
                number_of_values += last - first + 1;
                }
            printf("%d counter(s) valued between %d and %d\n\n", number_of_values, inf, sup);
        }
    }
    return 0;
}