#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sorter {
public:
    void mergeSort(int arr[], int l, int r);
    void quickSort(int arr[], int low, int high);
    void quickSortM3(int arr[], int low, int high);

private:
    void merge(int arr[], int l, int m, int r);
    int partition(int arr[], int low, int high);
    int partitionM3(int arr[], int low, int high);
    int medianOfThree(int arr[], int low, int high);
};
// Merge helper (provided)
void Sorter::merge(int arr[], int l, int m, int r) {
int n1=m-l+1, n2=r-m;
vector<int> L(n1), R(n2);
for(int i=0;i<n1;i++) L[i]=arr[l+i];
for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
int i=0,j=0,k=l;
while(i<n1&&j<n2) arr[k++]=(L[i]<=R[j])?L[i++]:R[j++]; while(i<n1) arr[k++]=L[i++];
while(j<n2) arr[k++]=R[j++];
}
void Sorter::mergeSort(int arr[], int l, int r) { 
    if (l < r) {
        int m = l +( r-l) /2;
        mergeSort(arr, l ,m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m,r);
    }
}
int Sorter::partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot) {
            i++
            swap(arr[i], arr[j]);
        }

    }
    swap(arr[i+1], arr[high]);
    return (i + 1);

}
void Sorter::quickSort(int arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low , pi-1);
        quickSort(arr, pi+1, high);
    }


}
int Sorter::medianOfThree(int arr[], int low, int high) {
    int mid =low + (high - low)/2;
    if (arr[low]> arr[mid]) swap(arr[low], arr[mid]);
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);

    swap(arr[mid], arr[high]);

    return high;
    // Pick median of arr[low], arr[mid], arr[high].
// Swap median to arr[high] and return high.
// TODO
int Sorter::partitionM3(int arr[], int low, int high) { 
    medianOfThree(arr, low, high); 
    // sets pivot at arr[high] 
    return partition(arr, low, high);
}
}
void Sorter::quickSortM3(int arr[], int low, int high) { 
    if (low <high) {
        int pi = partitionM3(arr, low, high);
        quickSortM3(arr, low, pi - 1);
        quickSortM3(arr,pi + 1, high);
    }

}
