#include<iostream>
int main(){
    int* arr = new int[3];
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i){
        arr[i] = i;
    }
    std::cout<<arr[2]<<std::endl;
    int* p_arr = arr;
    delete arr;

    std::cout<<p_arr[2]<<std::endl;

}