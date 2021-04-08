#include <iostream>

template<class T>
void merge(T* array, int start, int mid, int end) {

    int size = end - start + 1;
	int temp[size];
	int i = start, 
    j = mid+1, 
    k = 0;

    // store smaller value to temp
	while(i <= mid && j <= end) {
		if(array[i] <= array[j]) {
			temp[k] = array[i];
			k++;
            i++;
		}
		else {
			temp[k] = array[j];
			k++;
            j++;
		}
	}

	// store remaining elements 
	while(i <= mid) {
		temp[k] = array[i];
		k++;
        i++;
	}

	while(j <= end) {
		temp[k] = array[j];
		k++;
        j++;
	}


	for(i = start; i <= end; i++) {
		array[i] = temp[i - start];
	}
}

template<class T>
void mergeSort(T* array, int start, int end){
	if (start < end){
		int middle = start + (end - start) / 2;
		mergeSort(array, start, middle);
		mergeSort(array, middle + 1, end);
		merge(array, start, middle, end);
	}
}

int main() {
    int size = 100;
    int array[size];
    int randomVal;
    srand(time(0));

    std::cout << "|Before Sort|" << std::endl;

    // generate randomized array and print
    for(int i; i<size; i++){
        randomVal = rand() % 100;
        array[i] = randomVal;
        std:: cout << array[i] << " ";
    }

    std::cout << "\n|After Sort|" << std::endl;

    // selection sort
    mergeSort(array, 0, size-1);
    

    // print array
    for(int i: array){
        std::cout << i << " "; 
    }

    std::cout << "\nCompelete" << std::endl;
}