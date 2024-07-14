#include<iostream>
#include<string>
#include<array>
#include<algorithm>
#include<vector>

struct Person{
    std::string name;
    int age;

    Person(std::string a, int b) : name(a), age(b) {}
};
int main(){
    //***Emplace_back
    /*people1(0) :- 
                name 
                age
      people1(2) :-
                name         } vector of type Person
                age
      people1(3) :-
                name
                age
    */
    std::vector<Person> people1{
                                {"first",1},
                                {"second", 2}
                                };
    for(auto it = people1.begin(); it!= people1.end(); ++it){
            std::cout<<it->name<<it->age<<std::endl;
    }

    people1[0] = {"last",0};
    for(auto it = people1.begin(); it!= people1.end(); ++it){
        std::cout<<it->name<<it->age<<std::endl;
    }

    people1.at(1) = {"at", 10};
    std::cout<<people1[1].name<<people1[1].age<<std::endl;

    std::cout<<"PUSH BACK"<<std::endl;
    people1.push_back(Person("push", 000));
    //people1.push_back("push",000) won't work because push_back(const _T _value) so need to construct the structure explicitly as Person("push",000) and then pass it to push_back()
    for(auto it = people1.begin(); it!= people1.end(); ++it){
        std::cout<<it->name<<it->age<<std::endl;
    }

    std::cout<<"EMPLACE BACK"<<std::endl;
    people1.emplace_back("empalce",111);
    //emplace_back() is cheaper as it constructs the vector in place and does not require copy or move unlike push_back() which first constructs the object and then copies it to the vector or moves if it is an rvalue
    for(auto it = people1.begin(); it!= people1.end(); ++it){
        std::cout<<it->name<<it->age<<std::endl;
    }

    //vector
    std::vector<int> str1{1,2,3,4,5};
    
    std::cout<<"access"<<std::endl;
    //element access
    str1[10] = 10; //no out of range/out of bound error/segementation fault
    
    str1.at(3) = 20; //OUT of range/ out of BOUND
    
    str1 = {3,4,5,6,7};

    std::cout<<"data"<<std::endl;
    std::cout<<str1.data()<<std::endl;
    //returns a pointer of the underlying countiguous array, like a standard C style array
    
    for(const auto& ele:str1){
        std::cout<<ele<<std::endl;
    }

    std::cout<<"front back"<<std::endl;
    std::cout<<str1.front()<<std::endl;
    std::cout<<str1.back()<<std::endl;    

    //capacity
    std::cout<<"capacity"<<std::endl;
    std::cout<<str1.size()<<std::endl;
    std::cout<<str1.max_size()<<std::endl;
    std::cout<<!str1.empty()<<std::endl;

    //iterators
    std::cout<<"iterators"<<std::endl;
    *str1.begin() = 100;
    std::cout<<*str1.begin()<<std::endl;
    //*(str1.cbegin()) = 200; .cbegin() is constant begin iterator (read-only pointer pointing to the first element of the array)
    std::cout<<"Begin"<<std::endl;
    for(auto itr = str1.begin(); itr!=str1.end(); ++itr){
        std::cout<<*itr<<std::endl;
    }
    std::cout<<"rBegin"<<std::endl;
    for(auto itr = str1.crbegin(); itr!=str1.crend(); ++itr){
        std::cout<<*itr<<std::endl;
    }

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
