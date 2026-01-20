#include <vector>
#include <iostream>
using namespace std;

void conquer(vector<int> *v, int li, int mi, int ri){
    int lsize=mi-li+1;
    int rsize=ri-mi;
    vector<int> left(lsize);
    vector<int> right(rsize);
    for(int i=0;i<lsize;i++)
        left[i]=(*v)[li+i];
    for(int i=0;i<rsize;i++)
        right[i]=(*v)[mi+1+i];
    int i=0, j=0, k=li;
    while(i<lsize && j<rsize){
        if(left[i]<=right[j]){
            (*v)[k]=left[i];
            i++;
            k++;
        }
        else{
            (*v)[k]=right[j];
            j++;
            k++;
        }
    }
    while(i<lsize){
        (*v)[k]=left[i];
        i++;
        k++;
    }
    while(j<rsize){
        (*v)[k]=right[j];
        j++;
        k++;
    }
}

void divide(vector<int> *v, int li, int ri){
    if(ri<=li) return;
    int mi=li+(ri-li)/2;
    divide(v, li, mi);
    divide(v, mi+1, ri);
    conquer(v, li, mi, ri);
}




void mergeSort(vector<int> *v){
    divide(v, 0, v->size()-1);
}

int main(){
    vector<int> arr={12, 13, 11, 6, 5};
    cout<<"Original array: "<<endl;
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
    mergeSort(&arr);
    cout<<"Sorted array: "<<endl;
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}