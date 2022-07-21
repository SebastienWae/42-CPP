#include "ShrubberyCreationForm.h"

#include <fstream>
#include <iostream>

#include "Form.h"

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("Shrubbery Creation", SHRUBBERY_SIGN, SHRUBBERY_EXEC) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("Shrubbery Creation", SHRUBBERY_SIGN, SHRUBBERY_EXEC), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
    : Form(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other) {
  Form::operator=(other);
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
    throw(GradeTooLowException, FormNotSignedException) {
  Form::execute(executor);
  std::ofstream target_file((target + "_shrubbery").c_str());
  if (target_file.is_open()) {
    target_file << "            ,@@@@@@@," << std::endl;
    target_file << "    ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    target_file << " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    target_file << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    target_file << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    target_file << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    target_file << "`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    target_file << "    |o|        | |         | |" << std::endl;
    target_file << "    |.|        | |         | |" << std::endl;
    target_file << " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
    target_file.close();
  } else {
    std::cout << "Unable to open file" << std::endl;
  }
  target_file.close();
}
