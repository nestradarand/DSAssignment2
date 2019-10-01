#include "ArrayHelper.h"
#include <iostream>
#include <string>

using namespace std;

ArrayHelper::ArrayHelper()
{

}
ArrayHelper::~ArrayHelper()
{

}
void ArrayHelper::deleteArray(char** toDelete, int length)
{
  for(int i = 0; i< length; ++i)
  {
    delete [] toDelete[i];
  }
  delete [] toDelete;
}
void ArrayHelper::copyArray(char** initArray,char** &copyArray,int n,int m)
{
  for(int i = 0; i<n;++i)
  {
    for(int j = 0;j<m;++j)
    {
      copyArray[i][j] = initArray[i][j];
    }
  }
}
void ArrayHelper::printGrid(char** &theArray, int n,int m)
{
  for(int i =0;i <n;++i)
  {
    for(int j=0;j<m;++j)
      cout<<theArray[i][j];
    cout << "\n";
  }
}
void ArrayHelper::printSelectGrid(char** &theArray, int n,int m)
{
  for(int i =1;i <n;++i)
  {
    for(int j=1;j<m;++j)
      cout<<theArray[i][j];
    cout << "\n";
  }
}
void ArrayHelper::initializeGrid(char** &newArray,int n, int m)
{
  newArray = new char*[n];
  for(int i = 0; i<n;++i)
  {
    newArray[i] = new char[m];
  }
}
void ArrayHelper::fillGrid(char** &grid,int n, int m)
{
  for (int i = 0; i < n; ++i) {   // for each row
    for (int j = 0; j < m; ++j) { // for each column
      grid[i][j] = '-';
    }
  }
}

//assumes both arrays have same length
bool ArrayHelper::checkEquality(char** firstGrid, char** secondGrid,int n,int m)
{
  for(int i =0;i<n;++i)
  {
    for(int j = 0; j<m;++j)
    {
      if(firstGrid[i][j] != secondGrid[i][j])
        return false;
    }
  }
  return true;
}
