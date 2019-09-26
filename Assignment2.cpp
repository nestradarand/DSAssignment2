#include <string>
#include <iostream>
#include "GameOfLife.h"
#include "ArrayHelper.h"
#include <fstream>

using namespace std;




int main(int argc, char** argv)
{

  ArrayHelper* newHelper = new ArrayHelper();
  string theStrings[4];
  theStrings[0] = "X---X";
  theStrings[1] = "X---X";
  theStrings[2]= "X---X";
  theStrings[3] = "X---X";

  int rows = 4;
  int cols = 5;

  // char** tempGrid;
  // newHelper -> initializeGrid(tempGrid,rows,cols);
  // cout << "Success" << endl;
  // newHelper -> fillGrid(tempGrid,rows,cols);
  // newHelper -> printGrid(tempGrid,rows,cols);
  GameOfLife* theGame = new GameOfLife(rows,cols);
  cout << "made" << endl;
  for(int i = 0;i<rows;++i)
    theGame -> fillGridLine(theStrings[i]);
  theGame -> printFull();


  cout << "reached the end" << endl;
  // newHelper -> deleteArray(tempGrid,rows);
  delete newHelper;
  delete theGame;
  // delete theGame;
  // for(int i =0;i<6;++i)
  //   newHelper -> fillGridLine(tempGrid,theStrings[i]);
  // newHelper -> printGrid(tempGrid,8,7);



  //
  // theGame -> printFull();
  //
  // for(int i =0;i<5;++i)
  //   theGame ->fillGridLine(theStrings[i]);
  // theGame -> fillDoughnutGrid();
  // cout<< "Initial Population:" << endl;
  // theGame -> printCurrentGrid();
  // theGame -> printFull();
  // for(int i = 0;i<3;i++)
  // {
  //   cout << "Generation: " << i <<endl;
  //   theGame -> calculateNextGen();
  //   theGame ->printCurrentGrid();
  //   theGame -> fillDoughnutGrid();
  //   theGame -> printFull();
  // }



////testing starts here

  // ArrayHelper* helper = new ArrayHelper();
  //
  //
  // ///for testing arrays
  // int n = 5;
  // int m = 5;
  // int rowNum = n;
  // int colNum = m;
  // char** theGrid;
  // helper -> initializeGrid(theGrid,5,5);
  // helper -> fillGrid(theGrid,5,5);
  // helper -> printGrid(theGrid,5,5);
  // cout << "First grid" <<endl;
  // for (int i = 0; i < rowNum; ++i) {   // for each row
  //   for (int j = 0; j < colNum; ++j) { // for each column
  //     std::cout << theGrid[i][j];
  //   }
  //   std::cout << "\n";
  // }
  //
  // //how to copy
  // char** secondGrid;
  // secondGrid =  new char*[n];
  // for(int i =0;i<m;i++)
  //   secondGrid[i] = new char[m];
  // for (int i = 0; i < rowNum; ++i) {   // for each row
  //   for (int j = 0; j < colNum; ++j) { // for each column
  //     secondGrid[i][j] = theGrid[i][j];
  //   }
  // }
  // cout<< "Second grid" <<endl;
  //
  // for (int i = 0; i < rowNum; ++i) {   // for each row
  //   for (int j = 0; j < colNum; ++j) { // for each column
  //     std::cout << secondGrid[i][j];
  //   }
  //   std::cout << "\n";
  // }
  //
  // for (int i = 0; i < rowNum; ++i) {   // for each row
  //   for (int j = 0; j < colNum; ++j) { // for each column
  //     std::cout << secondGrid[i][j];
  //   }
  //   std::cout << "\n";
  // }
  // ///deleting the arrays
  // for(int i = 0; i< rowNum; ++ i)
  //   delete [] theGrid[i];
  // delete [] theGrid;
  // for(int i = 0; i< rowNum; ++ i)
  //   delete [] secondGrid[i];
  // delete [] secondGrid;
  // helper ->deleteArray(theGrid,n);
  // delete helper;
  return 0;
}
