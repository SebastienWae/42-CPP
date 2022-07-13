#include "ShrubberyCreationForm.h"

#include <fstream>
#include <iostream>
#include <string>

#include "Form.h"

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("shrubbery", SHRUBBERY_SIGN, SHRUBBERY_EXEC) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("shrubbery", SHRUBBERY_SIGN, SHRUBBERY_EXEC), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : Form(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
  setSigned(other.getIsSigned());
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

bool ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (!getIsSigned()) {
    return false;
  }
  if (executor.getGrade() > getGradeReqExec()) {
    throw GradeTooLowException();
  }
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
  return true;
}
