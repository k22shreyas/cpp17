#include<stdio.h>
#include <iostream>

int main(){
    int arr[] = {1,2,3,4,5};
    int* p_array = &arr[0];
    p_array++;
    p_array++;
    for(int i=0 ;i<sizeof(arr)/sizeof(arr[0]);++i){
        std::cout<<*p_array<<std::endl;

    }


    int x = 10;
    int* p_x = &x;

    int* pp_x = p_x;
    *p_x = 20;
    std::cout<<*p_x<<" "<<*pp_x;


}