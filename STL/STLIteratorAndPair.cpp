#include <iostream>
#include <utility> //pairs are defined in utility

using namespace std;

/*
Pairs : simple container -> contains 2 elements/objects
    * (first,second) : fixed order
    * Two different/similar entities could be bind together using this
    * Pairs can be copied/assigned/compared : Hashmap has pair by default
    * access : pair.first , pair.second
*/
void pairDemo();

/*
Iterators : These are the most general way to access data in containers.

*/
void iteratorDemo();

int main(){

    
}

void pairDemo(){
    //defination
    pair< int , int > p1;
    pair< string , pair <int ,int> > p2;
    pair g1;
    pair g2(1,2);
    pair g3(p2);

    //access
    cout << "p2.first : " << p2.first << endl;
    cout << "p2.second : " << p2.second.first << endl;
    cout << "p2.second : " << p2.second.second << endl;

    /*example :  vector< pair<double, pair<int,int> >
    where each element of vector is { polar angle, { x, y } }
    */

    //Member functions
    //make_pair
    pair < int, int > p3;
    p3 = make_pair(1,12);
    cout << "p3.first : " << p3.first << endl;
    cout << "p3.second : " << p3.second << endl;

    //Operators
    pair< int, int > p4;
    p4 = make_pair(9,12);
    cout << (p3 == p4) << endl; //0
    cout << (p3 != p4) << endl; //1
    cout << (p3>= p4) << endl; //0
    cout << (p3 <= p4) << endl; //1
    cout << (p3 > p4) << endl;  //0
    cout << (p3 < p4) << endl;  //1

    //Swap : swaps the content of one pair object with another
    p3.swap(p4);
    cout << "After Swap :" << endl;
    cout << "p3.first : " << p3.first << " p3.second : " << p3.second << endl;
    cout << "p4.first : " << p4.first << " p4.second : " << p4.second << endl; 

}