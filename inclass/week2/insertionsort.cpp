#include <iostream>
#include <vector>

using namespace std;
void insertionSort(vector<int>& arr) {
    int n=arr.size();
    for (int j=1;j<n;j++){
        int key=arr[j];
        int i=j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
    
}
int main(){
    vector<int> arr={12, 13, 11, 6, 5};
    cout<<"Original array: "<<endl;
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
    insertionSort(arr);
    cout<<"Sorted array: "<<endl;
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}