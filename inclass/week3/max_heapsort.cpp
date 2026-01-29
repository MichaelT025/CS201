#include <iostream>
#include <vector>

using namespace std;

// Not stable
// Time complexity: O(nlogn)
// Space complexity: O(n)

void maxheapify(vector<int>& arr, int i) {
    int l=2*i;
    int r=2*i+1;
    int largest=i;
    if(l<arr.size()&&arr[l]>arr[largest]){
        largest=l;
    }
    if(r<arr.size()&&arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        maxheapify(arr,largest);
    }
}

void buildmaxheap(vector<int>& arr) {
    for(int i=arr.size()/2;i>=0;i--){
        maxheapify(arr,i);
    }
}
void heapSort(vector<int>& arr) {
    buildmaxheap(arr);
    for(int i=arr.size()-1;i>0;i--){
        swap(arr[0],arr[i]);
        maxheapify(arr,0);
     
    }

}

int main() {
    vector<int> arr={12, 13, 11, 6, 5};
    cout<<"Original array: "<<endl;
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
    heapSort(arr);
    cout<<"Sorted array: "<<endl;
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}