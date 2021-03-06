// this file provides an example of a class inheritance structure with protected and private members
// this code is adapted from lectures 10-12 in COMP SCI 1102 Object Oriented Programming 2015. University of Adelaide
// to run the code, type g++ -Wall <filename>.cpp and then ENTER. this will create an executable object file.
// then type ./a.out to run the executable file
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Animal {
// member variables ( state )
private:
  string id;
public:
  string name;
  string food;
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
  void setID(string _id);
  string getID();
};

// implementation of members
Animal::Animal(){
  name = "Bob";
  food = "chicken";
  age = 35;
  id = "a10000";
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
void Animal::setID(string _id){
  id = _id;
}
string Animal::getID(){
  return id;
}
class Panda : public Animal {
private:
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
private:
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
  cout << "Tiger specific: " << name << " the Tiger has killed " << n_prey << " animal/s. " << endl;
}

// driver code
int main(){
  // Generic Animal
  Animal A1("Bob","chicken", 40);
  // private member of Animal
  A1.setID("a1160775");
  cout << "Animal only attribute ( private ): " << A1.getID() << endl;
  A1.eatFood("pasta");
  A1.makeNoise();
  cout << "Animal " << " is " << A1.getAge() << " years old. " << endl ;
  cout << endl;
  // Panda
  Panda P1("Petra","fish",26);
  A1.eatFood("pasta");
  P1.readsBooks();
  P1.makeNoise();
  cout << "Panda " << " is " << P1.getAge() << " years old. " << endl ;
  cout << endl;
  // Tiger
  Tiger T1("Ted","carrots",37);
  A1.eatFood("pasta");
  T1.killsPrey();
  T1.makeNoise();
  cout << "Tiger " << " is " << T1.getAge() << " years old. " << endl ;
  
  // I can't set an ID for Panda/Tiger directly, as it is a private member
  // The public member function therefore returns a blank result, when we call it on a derived object
  // However, we can set it equal to a base object.
  Animal A2 = T1;
  A2.setID("a116611");
  // should print out the Tiger's name (Ted)
  cout << A2.name << " has ID" << A2.getID() << endl;
  
}
