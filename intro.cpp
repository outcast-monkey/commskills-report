// this file provides an example of how to create a basic class inheritance in C++
// this code is adapted from lectures 10-12 in COMP SCI 1102 Object Oriented Programming 2015. University of Adelaide
// to run the code, type g++ -Wall <filename>.cpp and then ENTER. this will create an executable object file.
// then type ./a.out to run the executable file

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

class Panda : public Animal {
protected:
  int n_books;
public:
  Panda(string _name, string _food, int _age);
  void readsBooks();
};

// implementation of special constructor- base constructor called simultaneously
Panda::Panda(string _name, string _food, int _age) : Animal(_name,_food,_age), n_books(0) {
  cout << "Panda constructor: " << "Hi my name is " << name << " and I am a Panda. " << endl;
}
void Panda::readsBooks(){
  n_books++;
  cout << "Panda specific: " << name << " the Panda has read " << n_books << " book/s. " << endl;
}

//Derived class - Tiger
class Tiger : public Animal {
protected:
  int n_prey;
public:
  Tiger(string _name, string _food, int _age);
  void killsPrey();
};

// implementation of special constructor- base constructor called simultaneously
Tiger::Tiger(string _name, string _food, int _age) : Animal(_name,_food, _age), n_prey(0){
  cout << "Tiger constructor: " << "Hi my name is " << name << " and I am a Tiger. " << endl;
}

void Tiger::killsPrey(){
  n_prey++;
  cout << "Tiger specific: " <<name << " the Tiger has killed " << n_prey << " animal/s. " << endl;
}
// driver code
int main(){
  // Stack objects -- can also use dynamic variables
  // Generic Animal
  Animal A1("Bob","chicken", 40);
  A1.eatFood("pasta");
  A1.makeNoise();
  cout << A1.name << " is " << A1.getAge() << " years old. " << endl ;
  
  // Panda
  Panda P1("Petra","fish",26);
  A1.eatFood("pasta");
  P1.readsBooks();
  P1.makeNoise();
  cout << P1.name << " is " << P1.getAge() << " years old. " << endl ;
  
  // Tiger
  Tiger T1("Ted","carrots",37);
  A1.eatFood("pasta");
  T1.killsPrey();
  T1.makeNoise();
  cout << T1.name << " is " << T1.getAge() << " years old. " << endl ;
}
