#include <iostream>
#include <ucontext.h>

using namespace std;

ucontext_t ucp;
ucontext_t ucp2;

void Foo() {
  cout << "Foo Begin" << endl;
  getcontext(&ucp);
  cout << "Foo End" << endl;
}

void Tom() {
  cout << "Tom Begin" << endl;
  swapcontext(&ucp2, &ucp);
  cout << "Tom End" << endl;
}

int main() {
  Foo();
  Tom();
  setcontext(&ucp2);
  cout << "main exit" << endl;
  return 0;
}
