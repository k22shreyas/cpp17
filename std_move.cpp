#include <stdio.h>
#include <iostream>


int main(){
    std::string str = "String that needs to copied";

    std::string str2 = str;
    std::cout<<"copy:"<<str<<std::endl;
    std::cout<<"copy:"<<str2<<std::endl;

    std::string str3 = std::move(str2);
    std::cout<<"move:"<<str2<<std::endl;
    std::cout<<"move:"<<str3<<std::endl;
}



//use STD::MOVE() to return large values rather that creating a copy of them.
int foo(){
    std::<vector> vec = (1000,1);
    return (std::move(vec));
}



//use STD::MOVE to pass large data values to functions and telling them to own the resources of the data.
int main(){
    std::vector<int> vec = (1000,1);
    foo(std::move(vec));    
}


//use STD::MOVE() to insert elements into containers such as vectors, maps, sets
int main(){
    std::vector<int> vec(3);
    int x = 100;
    vec.push_back(std::move(x));
}


//How std::move() is implemented under the hood
int main(){
    std::string str = "Hello world";
    std::move(str) /*is nothing but below*/ 
    std::string move_str = static_cast<std::string&&>(str);
    //&& is an rvalue reference that moves the location of str to move_str variable.
}

//MOVE constructor
class Resource{
    public:
        ...
    
    //STD::MOVE() constructor
    classname(classname&& other) noexcept{
        //move constructor operations
        //other is pointing to the rvalue reference used in std::move(res1)

        //1. transfering ownership of res1 to res2
        //2. setting a nullptr to 0 to other.value(res1) to keep it in a valid state

    }

    classname& operator=(classname&& other) noexcept {
        //move assignment operations
        //1. transfering ownership if res2 to res3
        //2.freeing of existing resources from this.value(res3)
        //3. setting a nullptr to 0 to other.value(res2) to keep it in a valid state
    }
}

int main(){
    Resource res1(10);
    Resource res2 = std::move(res1); //move constructor will be invoked
    // res2 data members can be accessed by 'this' keyword
    // res1 data members can be accessed by 'other' keyword

    Resource res3(20);
    res3 = std::move(res2); //move assignment operator will be invoked
    // res3 data members can be accessed by 'this' keyword
    // res2 data members can be accessed by 'other' keyword
}