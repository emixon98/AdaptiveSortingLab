#include <iostream>
#include <vector>
#include <random>
using namespace std;

static const int N = 50;

enum classification {BEST, AVG, WORST};

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

void selectionSort(){

}

void insertionSort(){

}

int main() {
    
}