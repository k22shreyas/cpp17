#include<stdio.h>

//issue
int& foo(){
    int localVar = 10;
    return localVar;
    //int& indicates that foo() will return a reference as return value, in this case, reference of localVar
}
//solution
int foo1(){
    int localVar = 10;
    return localVar;
}
int main(){
    int& ref = foo();
    int rref = foo1();
    //ref is pointing to a memory location that is deallocated after the function foo() executes and exits the scope
}




/*
//Reference to dynamically allocated memory
//issue
int* foo(){
    int* localVar = new int(10);
    return localVar;
}
//solution
//use std::shared_ptr<int> foo(){
    //no need to manually delete the memory allocation
}
int main(){
    int* ref = foo();
    delete ref;

    int& rref = *ptr;
    //rref is pointing to a pointer that is dynamically deleted in the memory location.
}
*/

//reference to containers before modifications
/*
int main(){
    //issue
    std::vector<int>  vec(3) = {1,2,3};
    int& ref = vec[0];
    vec.push_back(10);

    //solution
    //make modifications first and create reference later
    vec.push_back(20);
    int& rref = vec[0];
}
*/

//after the vector got modified, the memory location might have changed and ref might be pointing to deallocated memory location

