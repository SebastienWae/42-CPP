#ifndef BRAIN_H
#define BRAIN_H

#include <string>

#define IDEAS_N 100

class Brain {
  std::string ideas[IDEAS_N];

 public:
  Brain();
  Brain(const Brain& other);

  Brain& operator=(const Brain& other);

  std::string const* getIdeas(void) const;

  ~Brain();
};

#endif
