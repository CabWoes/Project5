#include <chrono>
#include <iostream>
#include <array>

using namespace std;
using namespace chrono;

void insSort(int array[], int n){
    int temp;
    
    for (int i=0; i < n; i++){
        for(int j=i+1; j <= n; j++){
            if(array[j] < array[i]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void bubsort(int array[], int n){

    int temp;
    for(int i = 0; i <= n-1 ; i++){
        for(int j = 0; j <= n-1 ; j++){
            if (array[i] < array[j]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

void selsort(int array[], int n){

    int mindex;
    int temp;
    
    for(int i=0; i <= n-1 ; i++){
        mindex = i;
        for(int j=0; j < n; j++){
            if (array[j] > array[mindex]){
                temp = array[mindex];
                array[mindex] = array[j];
                array[j] = temp;
                
           }
        }
    } 
}

void merge(int array[], int min, int middle, int max) 
{ 
    int sizeL = (middle - min) + 1; 
    int sizeR =  (max - middle); 
    int left[sizeL], right[sizeR]; 
  
    for (int i = 0; i < sizeL; i++) {
        left[i] = array[min + i]; 
    }
    for (int j = 0; j < sizeR; j++) {
        right[j] = array[(middle + j) + 1]; 
    }
        
    int i = 0; 
    int j = 0; 
    int k = min; 
    
    while ((i < sizeL) && (j < sizeR)) 
    { 
        if (left[i] <= right[j]) 
        { 
            array[k++] = left[i++]; 
        } else { 
            array[k++] = right[j++]; 
        } 
    } 
  
    while (i < sizeL) 
    { 
        array[k++] = left[i++]; 
    } 
  
    while (j < sizeR) 
    { 
        array[k++] = right[j++]; 
    } 
} 
  
void mergeSort(int array[], int min, int max) 
{ 
    if (max < 2) { 
        return; 
    } 
    
    if (min < max) 
    { 
        int middle = min + ( max - min)/2; 
  
        mergeSort(array, min, middle); 
        mergeSort(array, (middle + 1), max); 
        merge(array, min, middle, max); 
    } 
} 

int main()
{
    //measures elapsed time of the main driver. 
    auto start = high_resolution_clock::now();


    //creates the arrays
    int randomArray[10000];
    int almostSorted2[10000];
    int almostSorted5[10000];
    int almostSorted10[10000];
    int wrongOrder[10000];
    int j = 10000;
    int temp;
    
    
   //generates numbers for each array (including random ones for the random array)
for(int k = 0; k < 100; k++){
   for(int i = 0; i < 10000; i++){
	    int randNum = rand() % 100;
	    randomArray[i] = randNum;
	    almostSorted2[i] = i + 1;
	    almostSorted5[i] = i + 1;
	    almostSorted10[i] = i + 1;
	    wrongOrder[i] = j--;
    }
    
    //almostSorted2 has two numbers off; index 3 and 4 are swapped
    temp = almostSorted2[3];
    almostSorted2[3] = almostSorted2[4];
    almostSorted2[4] = temp;
    
    //almostSorted5 has 5 numbers off; indeces 4-8 are jumbled
    temp = almostSorted5[3];
    almostSorted5[3] = almostSorted5[4];
    almostSorted5[4] = temp;
    temp = almostSorted5[5];
    almostSorted5[5] = almostSorted5[7];
    almostSorted5[7] = temp;
    temp = almostSorted5[6];
    almostSorted5[6] = almostSorted5[7];
    almostSorted5[7] = temp;
    
    //almostSorted2 has 10 numbers off; indes 0-4 switched with 10-14
    for(int i=0; i < 5; i++){
        temp = almostSorted10[i];
        almostSorted10[i] = almostSorted10[i+10];
        almostSorted10[i+10] = temp;
    }
    
    //I changed the function call in here each time to get the duration for each individual sort per array
   mergeSort(randomArray, 0, 1000);
    
    //output finished time
    auto finish = high_resolution_clock::now();
    duration<double> elapsed = finish - start;
    cout << "Seconds: " << elapsed.count() << "\n";
    cout <<  "\n";
}
    
    cout << "\n\n";
    
   return 0;
}
