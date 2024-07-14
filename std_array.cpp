#include<iostream>
#include<string>
#include<array>
#include<algorithm>
int main(){
    std::array<int,5> str1(10,20,34,56,67);
    
    //element access
    str1[10] = 10; //no out of range/out of bound error/segementation fault
    
    //str1.at(7) = 20; OUT of range/ out of BOUND
    
    str1 = {3,4,5,6,7};

    std::cout<<str1.data()<<std::endl;
    //returns a pointer of the underlying countiguous array, like a standard C style array
    
    for(const auto& ele:str1){
        std::cout<<ele<<std::endl;
    }

    std::cout<<str1.front()<<std::endl;
    std::cout<<str1.back()<<std::endl;    

    //capacity
    std::cout<<str1.size()<<std::endl;
    std::cout<<str1.max_size()<<std::endl;
    std::cout<<str1.empty()<<std::endl;

    //iterators
    *str1.begin() = 100;
    std::cout<<*str1.begin()<<std::endl;
    //*(str1.cbegin()) = 200; .cbegin() is constant begin iterator (read-only pointer pointing to the first element of the array)

    std::for_each(str1.cbegin(), str1.cend(), [](int x){
        std::cout<<x<<std::endl;
    });
    //str1.end() will return pointer of the element next to the last element of the array.

    //modifiers
    str1[2] = 20;
    str1.at(3) = 30;
    str1 = {1,2,3,4,5};
    //Since array is a fixed size, modification is very limited, only possible with its index in bound/range.
}
