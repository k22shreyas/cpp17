
//FUNCTIONS AS REFERENCES
#include <iostream>
#include <stdio.h>
void sayHello(int x, int y){
    std::cout<<"Call from reference: Hello"<<std::endl;
    std::cout<<x+y<<std::endl;
}
void executeFunction(void (&fun)(int, int), int x, int y){
    sayHello(x, y);
}
int main() {
    // functions as references
    void (&ref_to_fun)(int, int) = sayHello;
    ref_to_fun(4, 10); // calls sayHello function
    
    executeFunction(ref_to_fun, 4, 5); //function reference as a parameter

    return 0;
}