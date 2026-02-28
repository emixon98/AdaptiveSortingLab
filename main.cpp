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

    if (badCases == 49) return WORST; //do I want to change this to make it more consistent for our "in between" cases
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

//choose algorithm to use based on classification type
void chooseSort(classification a, vector<int>& arr){
    if (a == WORST){
        selectionSort(arr);
    } else {
        insertionSort(arr);
    }
}

void printArr(vector<int>& arr){
    for(int i : arr) cout << i << " ";
    cout << "\n\n";
}

int main() {
    vector<int> arr(N);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 999);

    //will just make a copy paste of 50 integers for this one, 
    //dont want to over do it since have avg with rands
    //cout << "Please enter 50 value for the array: ";
    //for (int i =0; i < N; i++) cin >> arr[i]; 

    //random/user array
    vector<int> avgArr(N);
    for (int i =0; i<N; i++) avgArr[i] = dist(gen);

    vector<int> bestCaseArr(N);
    for (int i = 0; i < N; i++) bestCaseArr[i] = i +1;
    
    vector<int> worstArr(N);
    for (int i = 0; i < N; i++) worstArr[i] = 50 - i;
    
    //presorted array cout so I can see the sort's actions for verification
    cout << "The generated random array is: \n";
    for (int i=0; i<N; i++){
        cout << avgArr[i] << " ";
    }
    cout << "\n\n";

    classification a = arrType(avgArr);
    classification b = arrType(bestCaseArr); 
    classification c = arrType(worstArr);
    //classification d = arrType(arr);

    chooseSort(a, avgArr); 
    chooseSort(b, bestCaseArr); 
    chooseSort(c, worstArr); 
    //chooseSort(d, arr); 
    cout << "The sorted average/random array is now: \n\n";
    printArr(avgArr); // Or can comment this and class a if not doing random inputs
    cout << "The sorted best case array is now: \n\n";
    printArr(bestCaseArr);
    cout << "The sorted worst case array is now: \n\n";
    printArr(worstArr);
    //printArr(arr); //can comment this and classification d out if not doing use inputted

    return 0;
}

//I personally want strict best and worst case scenarios for both clarity and to maximize efficiency when an array
//is best csae

//Assuming that if every i is < i+1 then the array is ordered, nice and logical
//I know that under best case insertion sort is O(N), and that selection sor tis always O(N^2)
//The book details how on average selection sor tis o(n^2/1.8), insertion was defined by prof as O(N^2)
// based on this conclusion, I would want to use insertion for all best case and selection for everything else
//But I should look into the logistics of this and ensure I choose the right algo for the job rather than go on hunches