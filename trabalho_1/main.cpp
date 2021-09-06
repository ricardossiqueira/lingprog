#include <iostream>
#include <string>
#include <Python.h>

#ifdef __unix__
#include <unistd.h>

#elif defined _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))

#endif

// #define BASH "/usr/bin/bash"

using namespace std;

int main(int argc, char *argv[])
{

  char filename[] = "python/interface.py";
  FILE *fp;

  PyObject *pInt;

  Py_Initialize();

  fp = _Py_fopen(filename, "r");
  PyRun_SimpleFile(fp, filename);

  Py_Finalize();

  // string command = "python3 resolveImage.py https://images.unsplash.com/photo-1494790108377-be9c29b29330?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=668&q=80";

  // system(command.c_str());

  return 0;
}
