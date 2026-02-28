# AdaptiveSortingLab
Adaptive Sorting Lab CISC187

## Part A: Adaptive Sorting Selection
### Task 1a
Create an array of 50 integers. Simple
### Task 2a
Implement selection and insertion sort algorithms
### Task 3a
Determine which scenario is presented (best, average, or worst case) clearly define this
Can count pairs, two indexes at a time, and see if the left index is smaller or larger than the right, if larger than it is out of order and we can count it as a bad match, a certain amount of bad matches is classified as a worst case, best case, or avg case. Cant compare in a say binary search pattern because that requires the array to be sorted already, so by making pairs I can sort of supersede this and compare two indexes at a time in ascending order.
### Task 4a
Choose appropriate sorting algorithm
If the array is already sorted in ascending order (or nearly sorted based on your defined threshold), your program should choose Insertion Sort, since Insertion Sort runs in linear time O(n) in the best case

If the array is in strictly descending order and the goal is to sort in ascending order, your program may decide to use Selection Sort, assuming under your defined threshold that it performs more consistently than Insertion Sort in this scenario.

## Part B: Case Classificatation Without Sorting

### Task 1b
User inputs 50 integers

### Task 2b
Without sorting analyze the order of elements

### Task 3b

Define order as average or worst case

## Part C: Documentation

### Choosing insertion sort vs selection sort
The best case (sorted array) for an insertion sort as described in our book is a time complexity of O(n), coming out ahead of selection sort which has an O(n^2) for all cases. Selection sort does not consider order, its operations remain the same regardless of the current order of the elements, whereas insertion sort become a heftier operation the more disordered an array is. While they share the same worst case time complexity in a general sense, selection sort always performs n(n-1)/2 comparisons, insertions only shifts elements until theyre in the right place making it more adaptive, which wold lead to reason, since it doesnt scan the entire remaining array every operation, that it is more efficient at an average case scenario than selection sort. We can see in the worst case (descending array), insertion sort would have to repeatedly shift each element through the entire sorted portion of the array, leading to a quadratic shift count. Selection sort, while still quadratic, only performs one swap per pass, behaving more consistently when the array leans towards the worst case.

Detail All the above on my readme in this section, can include code snippets above, but written explanation should be here.
The threshold definition you used to differentiate between best, average, and worst cases.
The reasoning behind your assumption.
Why your program selects one sorting algorithm over the other in specific scenarios.
A brief discussion of how input order affects the time complexity of Selection Sort and Insertion Sort.