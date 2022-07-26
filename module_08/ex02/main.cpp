
#include <iostream>
#include <list>

#include "MutantStack.h"

int main() {
  {
    std::cout << "## List ##" << std::endl;

    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
  }
  {
    std::cout << "## MutantStack ##" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }
  {
    std::cout << "## Const ##" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    MutantStack<int>::const_iterator it = mstack.begin();
    ++it;
    // *it = 2;
  }
  {
    std::cout << "## Reverse ##" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(188);

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
      std::cout << *it << std::endl;
    }

    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
      std::cout << *rit << std::endl;
    }
  }
}