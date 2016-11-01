#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

// declaration of class and contained members
class Animal {
  // member variables == state
protected:
  string name;
  string food;
  
public:
  /** constructors == template for standard object **/
  // default constructor
  Animal();
  // special constructor
  Animal(string _name, string _food);
  // member functions == behaviour
  void eatFood(string _food);
  void makeNoise();
};

// implementation of members
Animal::Animal(){
  name = "Bob";
  food = "chicken";
}

Animal::Animal(string _name, string _food){
  name = _name;
  food = _food;
  cout << "Animal constructor: " << "An animal called " << name << " is eating " << food << endl;
}

void Animal::eatFood(string _food){
  cout << "Animal generic:" << name << "loves" << food << "but is eating " << _food << endl;
}
void Animal::makeNoise(){
  cout << "Animal generic:" << name << " is making a noise. " << endl;
}

int main(){
  // Stack object
  Animal Bob("Bob","chicken");
  Bob.eatFood("pasta");
  Bob.makeNoise();
  // Dynamic variable on the heap referred to by stack pointer from Animal
  Animal *Barry = new Animal();
  Barry -> eatFood("kiwis");
  Barry -> makeNoise();
}
