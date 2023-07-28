#include <iostream>
#include "Zero.cpp" //Yes, we can include classes
using namespace std;
// OOP
// Access modifiers for properties: public(can be accessed anywhere), protected, private(can only be accessed inside the class)(bu default) 


// Class - a user defined data type (size of empty class=1)
class Hero{

// Properties

private: //Can't access anything inside it(including getters and setters, so declare them in public)
    char level='A';

public:
    int health=100;


// Getters
    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }

// Setters
    void setHealth(int h){
        health=h;
    }
    void setlevel(char l){
        level=l;
    }

// Manually creating a constructor
    Hero(){
        cout<<"Constructor acts"<<endl;
    }
};





int main(){cout<<endl;

// // Static allocation 
//     Hero h1;
// // h1 is an object now

// // Access the properties
//     cout<<h1.health<<endl;

// // Change/assign them
//     h1.health=70;
//     cout<<h1.health<<endl;


// // Getting the private property
//     cout<<h1.getLevel()<<endl;
// // Setting the private property (maybe handy setting passwords etc.)
//     h1.setlevel('B');
//     cout<<h1.getLevel()<<endl;



// Dynamic allocation
    //Hero *b;
    //(*b).setHealth(40);
    //cout<<(*b).getHealth()<<endl;//M1

    //b->setHealth(80);
    //cout<<b->getHealth()<<endl; //M2 for the same


// Manually creating a constructor
// When we write [Hero h1;], by default a constructor [h1.Hero()] will be created  
// As we've created a Hero(){...} constructor manually inside the class, if we now call Hero h1;, the constructor will act
// Creating a constructor manually, the constructor created by default by the system will cease to exist

// Statically
    // Hero h1;

// Dynamically
    //Hero *h=new Hero();
    //Hero *j=new Hero;




return 0;}
