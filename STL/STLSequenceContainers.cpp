#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;

/*
1. Sequence Container
    *similar to array -> grows in one direction

    1.a Vectors >=>     [][][][][][][->
        Properties of Vector:
            1. fast remove/insert at the end : O(1)
            2. slow insert/remove at begin/mid : O(n)
            3. slow search : O(n)
*/
void vectorDemo();

/*
    1.b Deque >=>    <-][][][][][][->
        Properties of Deque:
            1. fast remove/insert at the begin/end : O(1)
            2. slow insert/remove at middle : O(n)
            3. slow search : O(n)
*/
void dequeDemo();

/*
    1.c List <Doubly linked list>=>  <=>[]<=>[]<=>[]<=>[]<=>[]<=>[]<=>
        Properties of Deque:
            1. fast remove/insert at the begin/end : O(1)
            2. slow insert/remove at middle : O(n)
            3. slow search : O(n)
*/
void listDemo();

int main(){
    //vectorDemo();
    //dequeDemo();
    listDemo();
}

void vectorDemo(){
    //1. definition
    vector<int> vec1; //vec1.size() == 0
    vector<int> vec2(vec1); //copying vec1->vec2 => Copy Constructor


    //2. insertion
    vec1.push_back(10);
    vec1.push_back(5);
    vec1.push_back(15);

    //3. accessing elements
    cout << "first element :"<<vec1[0] <<endl; // no range check
    cout << "first element :"<<vec1.at(2) <<endl; // throws range exception error if out of range

    //4. traversing element

    //4a. not recommended :

    cout<<"Not recommened : "<< endl;
    for(int i=0;i<vec1.size();i++){
        cout << vec1[i] <<" ";
    }
    cout << endl;

    //4b. preffered way :
    cout<<"Preffered way : "<<endl;
    for(vector<int>::iterator it = vec1.begin();it != vec1.end();it++){
        cout<< *it << " ";
    }
    cout << endl;

    //4c. c++11 way:
    cout<<"c++11 way : "<<endl;
    for(auto it : vec1){
        cout << it << " ";
    }
    cout << endl;
    
    /* Note: Vector is the only dynamically allocated contiguous array in memory
    hence following is valid  */
    int* p=&vec1[0];
    cout << "Pointer access -> p[2] :"<< p[2] << endl; //15

    //Common member function across all the containers
    if(vec1.empty()){ cout << "Vector is empty" << endl;}

    cout << "Size :" <<vec1.size() <<endl; 
    vec2.clear(); //deletes vector
    vec1.swap(vec2); //swaps the contents

}

void dequeDemo(){
    //definition
    deque<int> deq1={5,4,7};

    //insertion
    deq1.push_back(1);
    deq1.push_front(6);

    //access : similar to vector
    cout << deq1[0];//6
} 

void listDemo(){
    //definition
}