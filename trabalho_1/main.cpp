#include <iostream>
#include <string>
#include "Menu.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  const string logFile = "tmp.log";

  string test;
  // https://images.unsplash.com/photo-1494790108377-be9c29b29330?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=668&q=80

  Menu menu = Menu();
  menu.run();
  string command = "python python/interface.py " + menu.parseCommand() + " > " + logFile;

  system(command.c_str());

  cout << "sent: " << command;

  return 0;
}
