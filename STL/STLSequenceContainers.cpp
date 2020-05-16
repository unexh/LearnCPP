#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <algorithm>
using namespace std;
//Note : printIt(Container,msg) : is UsrDef Func 

/*
1. Sequence Container
    *similar to array -> grows in one direction

    1.a Vectors : [][][][][][][->
        Properties of Vector:
            1. fast remove/insert at the end : O(1)
            2. slow insert/remove at begin/mid : O(n)
            3. slow search : O(n)
*/
void vectorDemo();

/*
    1.b Deque : <-][][][][][][->
        Properties of Deque:
            1. fast remove/insert at the begin/end : O(1)
            2. slow insert/remove at middle : O(n)
            3. slow search : O(n)
*/
void dequeDemo();

/*
    1.c List <Doubly linked list> :  <=>[]<=>[]<=>[]<=>[]<=>[]<=>[]<=>
        Properties of Deque:
            1. fast remove/insert at any palce : O(1)
            2. slow search: O(n) => much slower than Vector/Deque, Reason: Cache Misses
            3. no random access, i.e. no [] operator.
*/
void listDemo();

/*
    1.d Forward List <linked list> : ->[]->[]->[]->[]->[]->[]->
        Properties of Forward List:
            1. can only be traversed from head to Tail.
*/
//void fListDemo();

/*
    1.e Array <Array> : [][][][][][][][]
        Properties of array:
            1. can use Stl algorithms.
            2. two different arrays are actually different data type
            meaning, a function taking one may not accept other array.
*/
void arrayDemo();

template <class T>
void printIt(const T &container,string msg=""){
    if(msg != ""){cout<<msg<<endl;}
    for(auto element : container){
        cout<<element<< " ";
    }
    cout<<endl;
}

int main(){
    //uncommment to call
    
    //vectorDemo();
    //dequeDemo();
    //listDemo();
    //arrayDemo();
}

void vectorDemo(){
    cout<< "vectorDemo"<<endl;
    

    //1. definition
    vector< int > vec1;                     //vec1.size() == 0 //creates empty vector
    vector< int > vec2(vec1);               //copying vec1->vec2 => Copy Constructor
    vector< int > vec3(10);                 //vec3.size = 10, all elements zero
    vector< int > vec3 = vec1;              //vec3 is copy of vec1
    vector< int > vec4[10];                 //vec4 is an array of 10 int's vec, all initially zero
    vector< string > vec5(20,"unknown");    //size = 20 , content : "unknown"
    
    //2D-vector:
    vector< vector < int > > vecMatrix; //2D vec
    int N=12,M=12;
    vector< vector < int > > vecMatricSizeMN(N,vector < int >(M,0)); /* creates 2D vec of size N*M,
    and fill it with '0' */

    //2. insertion
    vec1.push_back(10); //insert at the end
    vec1.push_back(5);
    vec1.push_back(15);
    //vec1.insert()

    //3. accessing elements
    cout << "first element :"<<vec1[0] <<endl;    // no range check
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

    //5. Checking is vec is empty:
    bool is_non_empty_ok = !vec1.empty();
    /*Not
    bool is_nonempty_notgood = (v.size() >= 0); // as not all containers can return its size in O(1), 
    //hence for checking there exists atleast on element is better done with Vec.empty() func
    */

   //6. Resizing a vector 

   vec1.resize(20); // if size is dec : last elementsget deleted
   //if size is inc : and push_back is used : elements will be pushed back,
   //from the newly allocated space

   /*7. Passing vectors to the func:
    7a. readOnly mode:
        void func(const vector <int> &vecName){ Do Somthing..;}

    7b. update mode:
        void func(vector <int> vecName){ Do Something...;}
    */

   
}

void dequeDemo(){
    cout<< "dequeDemo"<<endl;
    
    //definition
    deque<int> deq1={5,4,7};

    printIt(deq1);

    //insertion
    deq1.push_back(1);
    deq1.push_front(6);
    
    printIt(deq1,"Two {1:back ,6:front} added");

    //access : similar to vector
    cout << deq1[0];//6
} 

void listDemo(){
    cout<< "listDemo"<<endl;
    
    //definition
    list<int> lis = {13,7,5};

    printIt(lis,"Lis created:");

    //insertion
    lis.push_back(2); //lis : {13,7,5,2}
    lis.push_front(17); //lis : {17,13,7,5,2}

    printIt(lis,"push_back(2), push_front(17):");

    //iterator access
    list< int > :: iterator it = find(lis.begin(),lis.end(),7); //it->7
    lis.insert(it,11);  //lis : {17,13,11,7,5,2}
                        //faster than vector/deque : O(1)

    printIt(lis,"{11} inserted at Iterator 'it':");

    it++;               //it->5
    lis.erase(it);      //lis : {17,13,11,7,2}

    printIt(lis,"Element at 'it' erased");

    //list Splice Function
    //lis2.splice(itr,lis1,itrl1,itrl2); //=> O(1)
    //cuts (itr1,itr2) range of data from *lis1* and place it at itr in *lis2*, all in O(1);
}

void arrayDemo(){
    cout<< "arrayDemo"<<endl;
    
    int arr1[3]= {10,20,30};
    
    //definition
    array<int,3> arr2 = {10,20,30};
    array<int,4> arr3 = {10,20,30,40};
    //both are diferent types

    //Member Functions
    /*
    arr2.begin();
    arr2.end();
    arr2.size();
    arr2.swap();
     */       
}