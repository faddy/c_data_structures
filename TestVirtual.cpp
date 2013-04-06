#include <iostream>
//#include <conio>

using namespace std;

class A {
  public:
    void print() { cout << "A"; }
}

class B : A {
  public:
    void print() { cout << "B"; }
}

class C : B {
  public:
    void print() { cout << "C"; }
}

int main() {
  A *a = new A();
  B *b = new B();
  C *c = new C();

  a->print(); // "A"
  b->print(); // "B"
  c->print(); // "C"
  ((B *)c)->print(); // "B"
  ((A *)c)->print(); // "A"
  ((A *)b)->print(); // "A"
  return 0;
}
