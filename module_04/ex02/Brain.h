#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain {
  std::string ideas[100];

public:
  Brain();
  Brain(Brain const& other);

  ~Brain();

  Brain& operator=(Brain const& other);

  std::string const* getIdeas() const;
};

#endif
