//lambda
int funC(int a){
    cout<< "a:"<< a << std::endl;
}

main(){
    std::vector<int> x[5] = {1,2,3,4,5};

    for_each(x.begin(), x.end(), [](int i){
        
        cout<<"i:"<< i;
    });
};

//function pointers
int funcB(){

};

main(){
   int (*funPtr) = &funcB;   
}

//smart pointers
ptra -> varA 

ptra -> varB

std::unique_ptr<class_name> ptr1 = &xyz;

//move semantics
object->xyz
ptr1----> object
std::unique_ptr<class_name> ptr2
ptr2 = move(ptr1);

*ptr2 = ptr1;

//maps
98
myMap[10] = 100;

//cherry-pick vs checkout
commit id 1 parent a
commit id 2 parent a
commit id 3
commit id 4