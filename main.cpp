#include <iostream>
#include <vector>
#include <random>
using namespace std;

static const int N = 50;

enum classification {BEST, AVG, WORST};

//This works for both Part A and B since it runs off pairs and always 50 integer sized arrays So Part B is knocked out
//Just make sure to incorporate random and seed gen later for user input, I guess its ok if a user input them as well
//will just comment out that line of code in case professor runs unit test
classification arrType(vector<int>& arr){
    int badCases = 0;
    //Check each element and the element to its right, if it is greater than we have an out of order pair
    //and hence a bad case.
    //Should best case be no badCases and worst be all? I think that si how Ill start
    for(int i =0; i < N-1; i++){
        if (arr[i] > arr[i+1]) badCases++;
    }

    if (badCases == 49) return WORST;
    if(badCases == 0) return BEST;
    return AVG;
}
//pass in address because we actually want to alter the array into order instead of producing a new one
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

int main() {
    vector<int> arr[N];
    
}

//I personally want strict best and worst case scenarios for both clarity and to maximize efficiency when an array
//is best csae

//Assuming that if every i is < i+1 then the array is ordered, nice and logical
//I know that under best case insertion sort is O(N), and that selection sor tis always O(N^2)
//The book details how on average selection sor tis o(n^2/1.8), insertion was defined by prof as O(N^2)
// based on this conclusion, I would want to use insertion for all best case and selection for everything else
//But I should look into the logistics of this and ensure I choose the right algo for the job rather than go on hunches