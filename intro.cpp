#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
  string name;
  int age;
  
  Animal();
  Animal(string _name, int _age);
};

Animal::Animal():name("Bob"),age(35) {}

Animal::Animal(string _name, int _age){
  name = _name;
  age = _age;
}
