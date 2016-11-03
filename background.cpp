// this file provides an example of how to create a class in C++
// this code is adapted from lectures 10-12 in COMP SCI 1102 Object Oriented Programming 2015. University of Adelaide
// to run the code, type g++ -Wall <filename>.cpp and then ENTER. this will create an executable object file.
// then type ./a.out to run the executable file
// C++ has several standard libraries which contain functions
// These are included by the following code #include <library_name>
#include <iostream>
#include <string>

using namespace std;

// declaration of class and contained members

class Animal {
public:
  // Public member variables (state) can be accessed from the main program directly
  string name;
  string food;
protected:
  // Protected member variables (state) cannot be accessed from the main program directly
  int age;
public:
  /** constructors == template for standard object **/
  // default constructor
  Animal();
  // special constructor
  Animal(string _name, string _food, int _age);
  // member functions ( behaviour )
  void eatFood(string _food);
  void makeNoise();
  int getAge();
};

// implementation of members
Animal::Animal(){
  name = "Bob";
  food = "chicken";
  age = 35;
  cout << "Animal default constructor: " << "An animal called " << name << " is eating " << food << endl;
  cout << "Default values for name and food have been used when no values have been provided" << endl;
}

Animal::Animal(string _name, string _food, int _age){
  name = _name;
  food = _food;
  age = _age;
  cout << "Animal special constructor: " << "An animal called " << name << " is eating " << food << endl;
  cout << "A special constructor allows me to initialize state from the initial creation of the object" << endl;
}

void Animal::eatFood(string _food){
  cout << "Animal generic:" << name << " loves " << food << " but is eating " << _food << endl;
}
void Animal::makeNoise(){
  cout << "Animal generic:" << name << " is making a noise. " << endl;
}

int Animal::getAge(){
  return age;
}
// driver code
int main(){
  // Stack object
  Animal Bob("Bob","chicken", 40);
  Bob.eatFood("pasta");
  Bob.makeNoise();
  // Dynamic variable on the heap referred to by stack pointer from Animal
  Animal *Barry = new Animal("Barry","chocolate",24);
  Barry -> eatFood("kiwis");
  Barry -> makeNoise();
  // direct access to public members
  cout << Bob.name << endl;
  cout << Barry->name << endl;
  // no direct acces to protected/private members - need to be obtained using
  // a  public member function
  cout << Bob.getAge() << endl;
  cout << Barry -> getAge() << endl;
}
