#include <iostream>
void fun(std::string& str) {
    std::cout << "lvalue " << str << std::endl;
}

void fun(std::string&& str) {
    std::cout << "rvalue " << str << std::endl;
}

void fun(const std::string& str) {
    std::cout << "const ref " << str << std::endl;
}

int main() {
    // lvalue, lvalue reference to constant & rvalue references
    std::string string = "Hello";
    std::string& lvalue_ref = string;
    
    std::string&& rvalue_ref = "World";
    
    const std::string& const_ref = "new_world"; 
    //even though const_ref is refering to an rvalue, since it is a constant, compiler stores it in an memory location hence it becomes an lvalue ref;

    std::string str = "old_world";
    const std::string& const_lref = str; // makes it lvalue since it is referencing a variable 

    fun(lvalue_ref);    // Calls fun(std::string& str)
    fun(rvalue_ref);    // Calls fun(std::string& str) because "world" now has memory in the name rvalue_ref is an lvalue here
    fun("rrr");         // Calls fun(std::string&& str)
    fun(const_ref);     // Calls fun(const std::string& str)
    fun(const_lref);    // Calls fun(const std::string& str)
    
    return 0;
}
