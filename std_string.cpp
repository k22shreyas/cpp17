#include<iostream>
#include<string>
#include<algorithm>
int main(){
    //element access
    std::string str1("----------------");
    std::cout<<str1<<std::endl;
    
    str1.at(15) = 'X'; //at() checks bounds i.e checks if container index is out of bounds
    std::cout<<str1.at(0)<<std::endl;
    
    str1+="M";
    std::cout<<str1<<std::endl;

    std::cout<<str1.c_str()<<std::endl;

    str1[20] = 'Z'; //operator[] doesn't check bounds of the container  
    std::cout<<str1<<std::endl;

    std::cout<<str1.data()<<std::endl;
    //.data() provides a pointer to the underlying array i.e the address to the first element of the array.

    //iterators
    std::cout<<*str1.begin()<<std::endl;
    //str1.end() returns iterator of the character following th elast character if the string, used in iterators only, accessing it will result in undefined behavior
    std::for_each(str1.cbegin(), str1.cend(), [](char x){
        std::cout<<x<<std::endl;
    });

    //capacity
    std::cout<<str1.size()<<std::endl;
    std::cout<<str1.capacity()<<std::endl;
    std::cout<<str1.empty()<<std::endl;

    //modifiers
    str1.append("APPEND");
    std::cout<<str1<<std::endl;

    str1.erase(7,10);
    std::cout<<str1<<std::endl;;

    str1.insert(0,"INS");
    std::cout<<str1<<std::endl;

    str1.clear();

    //Algorithms
    str1 = "algorithm";
    for(auto str:str1){
        std::cout<<str<<std::endl;
    }

    if(str1.find('g') != std::string::npos){
        std::cout<<"Found g"<<std::endl;
    }else{
        std::cout<<"not found g"<<std::endl;
    }

    //string_view just gives a VIEW of the string and does not allocate memory in any sort similar to a referencing;
    std::string_view str("mike");
    std::cout<<str<<std::endl;

    //str[2] = 'K'; //ERROR string_view is const char*
    std::cout<<str1<<std::endl; 
}
