#include<iostream>
#include<string>
#include<array>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

struct Person{
    int age;
    std::string name;
    std::string city;

    Person(int a, std::string b, std::string c) : age(a), name(b), city(c){};

    bool operator<(const Person& other) const {
        return (
            age < other.age 
            || (age == other.age && name < other.name) 
            || (age == other.age && name == other.name && city < other.city)
            );
    }
};
int main(){
    std::set<int> set = {10,20,30,40};

    for( auto S:set){
        std::cout<<S<<std::endl;
    }

    //modifiers
    set.insert(20); //duplicate intry, won't be inserted
    set.insert(100);

    set.erase(set.begin()); //key, or iterator, or range specified with iterators

    set.emplace(200);

    //set.clear();
    std::cout<<"Modifiers"<<std::endl;
    for( auto S:set){
        std::cout<<S<<std::endl;
    }

    //lookup or element access
    std::cout<<"Element lookup"<<std::endl;
    std::cout<<set.count(100)<<std::endl;

    auto it = set.find(100);
    if(it != set.end()){
        std::cout<<"Found"<<std::endl;
    }

    //capacity
    std::cout<<"Capacity"<<std::endl;

    std::cout<<set.empty()<<std::endl;

    std::cout<<set.size()<<std::endl;

    //Iterators
    std::cout<<"Iterators"<<std::endl;
    for(std::set<int>::iterator itr = set.begin(); itr != set.end(); ++itr){
        std::cout<<*itr<<std::endl;
    }

    std::cout<<"Reverse iterator"<<std::endl;
    for(std::set<int>::reverse_iterator itr = set.crbegin(); itr != set.crend(); ++itr){
        std::cout<<*itr<<std::endl;
    }

    //emplace with struct/class example + operator overloading for set to compare multiple data members to order sort
    std::cout<<"Emplace with class/struct"<<std::endl;
    std::set<Person> p;
    p.insert(Person(3,"name","city"));

    p.emplace(4,"newName", "newCity");
    
    for(auto itr1 = p.begin(); itr1 != p.end(); ++itr1){
        std::cout<<(*itr1).city<<std::endl;
    }

}