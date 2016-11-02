// this file provides an example of how to implement polymorphism
// this code is adapted from lectures 10-12 in COMP SCI 1102 Object Oriented Programming 2015. University of Adelaide
#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
  // member variables ( state )
  string name;
  string food;
  int age;
  /** constructors == template for standard object **/
  // default constructor
  Animal();
  // special constructor
  Animal(string _name, string _food, int _age);
  // member functions ( behaviour )
  void eatFood(string _food);
  // base function declared virtual
  virtual void makeNoise();
  int getAge();
};

// implementation of members
Animal::Animal(){
  name = "Bob";
  food = "chicken";
  age = 35;
}

Animal::Animal(string _name, string _food, int _age){
  name = _name;
  food = _food;
  age = _age;
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

class Panda : public Animal {
protected:
  int n_books;
public:
  Panda(string _name, string _food, int _age);
  void readsBooks();
  //specific function
  void makeNoise();
};

// implementation of special constructor- base constructor called simultaneously
Panda::Panda(string _name, string _food, int _age) : Animal(_name,_food,_age), n_books(0) {}
void Panda::readsBooks(){
  n_books++;
  cout << "Panda specific: " << name << " the Panda has read " << n_books << " book/s. " << endl;
}
void Panda::makeNoise(){
  cout << name << " the Panda says " << " grrrrr!!!" << endl;
}

//Derived class - Tiger
class Tiger : public Animal {
protected:
  int n_prey;
public:
  Tiger(string _name, string _food, int _age);
  void killsPrey();
  //specific function
  void makeNoise();
};

// implementation of special constructor- base constructor called simultaneously
Tiger::Tiger(string _name, string _food, int _age) : Animal(_name,_food, _age), n_prey(0){}

void Tiger::killsPrey(){
  n_prey++;
  cout << "Tiger specific: " << name << " the Tiger has killed " << n_prey << " animal/s. " << endl;
}

void Tiger::makeNoise(){
  cout << name << " the Tiger says " << " meeoowww!!!!" << endl;
}

// driver code
int main(){
  // Stack objects -- can also use dynamic variables
  // Generic Animal
  Animal A1("Bob","chicken", 40);
  A1.makeNoise();
  cout << "Panda: ";
  // Panda
  Panda P1("Petra","fish",26);
  P1.makeNoise();
  cout << "Tiger: ";
  // Tiger
  Tiger T1("Ted","carrots",37);
  T1.makeNoise();
}
