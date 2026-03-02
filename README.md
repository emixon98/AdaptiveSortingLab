# AdaptiveSortingLab
Adaptive Sorting Lab CISC187

## Part A: Adaptive Sorting Selection
### Task 1a
```cpp
static const int N = 50;
vector<int> arr(N);
```
### Task 2a
```cpp
void selectionSort(vector<int>& arr){
    for(int i =0; i < N-1; i++){
        int index = i;
        for (int j = i+1; j < N; j++){
            if(arr[j] < arr[index]) index = j;
        }
        swap(arr[i], arr[index]);
    }
}

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < N; i++){
        int checkVal = arr[i];
        int j = i - 1;
        while (j>=0){
            if(arr[j] > checkVal){
                arr[j+1] = arr[j];
                j--;
            } else break;
        }
        arr[j+1] = checkVal;
    }
}
```
### Task 3a
Determine which scenario is presented (best, average, or worst case) clearly define this
```cpp
classification arrType(vector<int>& arr){
    int badCases = 0;
    //Check each element and the element to its right, if it is greater than we have an out of order pair
    //and hence a bad case.

    for(int i =0; i < N-1; i++){
        if (arr[i] > arr[i+1]) badCases++;
    }

    if (badCases == 49) return WORST; //can change this to make it more consistent for our "in between" cases
    if(badCases == 0) return BEST;
    return AVG;
}
```

The approach I decided to take was to make an enum that classifies the array type. My first thought was a binary appraoch, comparing two elements at a time. With this application I can check if my arr[i] value is > arr{i+1]. If so, it is out of order, and hence a "bad case", if I go through the entire array doing this and have no bad cases, then the array is ordered. I felt this was a clean way to identify my arrays if using an integer vector because it 1) is a simple for loop and 2) allows me to change the definition of a good or bad case later on. For example, I chose in a later part of the assignment to make best case truly equal to 0 bad cases, in which case selection sort would occur. However, we can consider that insertion sort performs worse the more shifts it has to do selection sort is always the same, due to this I could classify a "close to worse" case, being maybe 40 bad cases or more, allowing flexibility of my choice/optimization.

### Task 4a
Choose appropriate sorting algorithm
If the array is already sorted in ascending order (or nearly sorted based on your defined threshold), your program should choose Insertion Sort, since Insertion Sort runs in linear time O(n) in the best case.

```cpp
void chooseSort(classification a, vector<int>& arr){
    if (a == WORST){
        cout << "This array is a worse case, choosing selectionSort: \n";
        selectionSort(arr);
    } else if( a == BEST) {
        cout << "This array is a best case, choosing insertionSort: \n";
        insertionSort(arr);
    } else if( a == BEST) {
        cout << "This array is an average case, choosing insertionSort: \n";
        insertionSort(arr);
    }
}

```

If the array is in strictly descending order and the goal is to sort in ascending order, your program may decide to use Selection Sort (under your defined threshold), considering that it performs more consistently than Insertion Sort in this scenario.

## Part B: Case Classificatation Without Sorting

### Task 1b
```cpp
    cout << "Please enter 50 value for the array: ";
    for (int i =0; i < N; i++) cin >> arr[i]; 
```
### Task 2b
Without sorting analyze the order of elements:

The function in 3a is able to classify and analyze the user entered elements.

### Task 3b

Define order as average or worst case:

I added cout statements in the function from 4a to be able to clearly display and define what case the array is, since it flows smoothly with the program, and it was only a few more lines of code
I implemented the sorting as well for demonstration. It will be commented out after recording my video and for the official submission.

## Part C: Documentation
### Threshold definition

See part 3a.

### Choosing insertion sort vs selection sort

The best case (sorted array) for an insertion sort as described in our book is a time complexity of O(n), more efficient than selection sort which has an O(n^2) for all cases. Selection sort does not consider order, its operations remain the same regardless of the element's state. While they share the same worst case big O time complexity, selection sort always performs n(n-1)/2 comparisons, insertion sort only compares and either shifts the element or not until the right position is found, making it more adaptive, and when the array is sorted no shifts occur, marking linear performance. Since it doesn't scan the entire remaining array every operation in an average case scenario it should perform fewer operations, and in turn should be utilized as that makes it more efficient in practice. That being said, the more shifts it needs to perform degrades its operation speed, and leads to much less consistency when compared to selection sort, which is why I reasoned that you can change the values of your best and worst cases, perhaps on an array of 100,000 disordered elements this would be more apparent. We can see in the worst case (descending array), insertion sort would have to repeatedly shift each element through the entire sorted portion of the array, leading to a quadratic shift count. Selection sort, while still quadratic, only performs one swap per pass regardless of order, behaving more consistently. Because of this consistency when the array leans towards the worst case and is highly disordered, selection sort may be  preferable.

Youtube Link: https://youtu.be/7fIE_Dq3FBg
