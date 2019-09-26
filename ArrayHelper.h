#ifndef ARRAY_HELPER_H
#define ARRAY_HELPER_H
#include <iostream>


class ArrayHelper
{
public:
  ArrayHelper();
  ~ArrayHelper();
  void deleteArray(char** &toDelete, int length);
  void copyArray(char** &initArray, char** &copyArray,int n, int m);
  void printGrid(char** &theArray, int n,int m);
  void printSelectGrid(char** &theArray, int n,int m);
  void initializeGrid(char** &emptyArray,int n, int m);
  void fillGrid(char** &grid,int n, int m);

};
#endif
