#include <string>
#include <iostream>
#include "GameOfLife.h"
#include "ArrayHelper.h"
#include "GameRunner.h"
#include <fstream>

using namespace std;




int main(int argc, char** argv)
{
  // ArrayHelper* thehelper  = new ArrayHelper();
  // char** newArray;
  // int n = 5, m = 3;
  // // newArray = new char*[n];
  // // for(int i = 0; i<n;++i)
  // // {
  // //   newArray[i] = new char[m];
  // // }
  // thehelper -> initializeGrid(newArray,n,m);
  // cout << "init"<<endl;
  // thehelper -> fillGrid(newArray,n,m);
  // cout << "fill" <<endl;
  // thehelper -> printGrid(newArray,n,m);
  // thehelper -> deleteArray(newArray,n);
  // delete thehelper;
  cout << "Welcome to the Game of Life"<<endl;
  cout<< "This game simulates the lifecylce of bacteria." <<endl;
  cout << "First and foremost, would you like to provide a file to simulate with?" <<endl;
  cout<< "Type 'n' for no or 'y' for yes" <<endl;
  GameOfLife* theGame;
  char response,mode;
  char** holder;
  bool withFile,pauses,outputToFile;
  string fileName,inContent,saveFile;
  int length,width,genCount=0;
  float density;

  ifstream inputStream;
  ofstream outputStream;
  cin >>response;
  while(response != 'n'&&response != 'y')
  {
    cout<< "Invalid command entered. Try again." <<endl;
    cin >> response;
  }
  if(response  == 'y')
  {
    cout << "Type the name of the file you would like to use next: " <<endl;
    cin >>fileName;
    withFile = true;
    inputStream.open(fileName);
    cout<<"File successfully opened" << endl;
    //ensures successful input stream established
    //reference: stack overflow
    if(!inputStream)
    {
      cout << "Error occurred trying to read file." << endl;
      exit(1);
    }
  }
  else if(response == 'n')
    withFile = false;

  cout << "Now, would you liked to have pauses in between generations of the simulation?"<<endl;
  cout<< "Type 'n' for no or 'y' for yes" <<endl;
  cin >>response;
  while(response != 'n'&&response != 'y')
  {
    cout<< "Invalid command entered. Try again." <<endl;
    cin >> response;
  }
  if(response  == 'y')
    pauses = true;
  else if(response == 'n')
    pauses = false;

  cout<<"Lastly, would you like to have the outputs printed to the screen or saved to a file?"<<endl;
  cout << "Enter 'p' for print or 's' for save"<<endl;
  cin >>response;
  while(response != 'p'&&response != 's')
  {
    cout<< "Invalid command entered. Try again." <<endl;
    cin >> response;
  }
  if(response  == 's')
  {
    outputToFile = true;
    cout << "Please enter the name of the file you wish to save to:" <<endl;
    cin >>saveFile;
    outputStream.open(saveFile);
    if(!outputStream)
    {
      cout << "Error occurred trying to read file." << endl;
      exit(1);
    }
  }
  else if(response == 'p')
    outputToFile = false;

  if(!withFile)
  {
    cout <<"Enter the length and width of the simulation:" <<endl;
    cout << "Length: " <<endl;
    cin >>length;
    cout << "Width: " <<endl;
    cin >>width;
    cout<< "Now enter the initial density of the initial population." <<endl;
    cout << "Please enter it as a number between 0 and 1" <<endl;
    cin >> density;
    theGame = new GameOfLife(length,width);
    theGame -> createRandomPopulation(density);
  }
  if(withFile)
  {
    cout << "Reading file contents"<<endl;
    inputStream >>length;
    inputStream >>width;
    theGame = new GameOfLife(length,width);
    cout<<"Constructed" <<endl;
    while(inputStream >> inContent)
      theGame ->fillGridLine(inContent);
  }
  cout<< "Lastly, enter what game mode you wish to have:" << endl;
  cout << "Enter 'c' for classic, 'm' for mirror mode, or 'd' for doughnut mode"<<endl;
  cin >> mode;
  while(mode != 'c'&&mode != 'm' && mode != 'd')
  {
    cout<< "Invalid command entered. Try again." <<endl;
    cin >> mode;
  }
  // GameRunner* runner = new GameRunner(theGame,pauses);
  if(mode == 'c')
  {
    while(theGame -> checkStability() == 0)
    {
      cout<< "Generation " <<genCount<< endl;
      theGame -> printCurrentGrid();
      if(pauses)
        system("read -p 'Press Enter to continue...' var");
      if(outputToFile)
      {
        char **  holder = theGame->returnCurrentGrid();
        outputStream << "Generation " <<genCount<< "\r\n";
        for(int i = 1;i<length+1;++i)
        {
          for(int j = 1; j <width+1;++j)
          {
            outputStream << holder[i][j];
          }
          outputStream << "\r\n";
        }
      }
      theGame -> calculateNextGen();
      genCount++;
    }
    cout<<"Population stable, simulation aborted"<<endl;
  }
  if(mode == 'm')
  {
    while(theGame -> checkStability() ==0)
    {
      theGame -> fillMirrorGrid();
      cout << "Generation " << genCount <<endl;
      theGame ->printCurrentGrid();
      if(pauses)
        system("read -p 'Press Enter to continue...' var");
      if(outputToFile)
      {
        char **  holder = theGame->returnCurrentGrid();
        outputStream << "Generation " <<genCount<< "\r\n";
        for(int i = 1;i<length+1;++i)
        {
          for(int j = 1; j <width+1;++j)
          {
            outputStream << holder[i][j];
          }
          outputStream << "\r\n";
        }
      }
      theGame -> calculateNextGen();
      genCount ++;
    }
    cout<<"Population stable, simulation aborted"<<endl;
  }
  if(mode == 'd')
  {
    while(theGame -> checkStability() ==0)
    {
      cout<< "Generation " << genCount << endl;
      theGame -> fillDoughnutGrid();
      theGame ->printCurrentGrid();
      if(pauses)
        system("read -p 'Press Enter to continue...' var");
      if(outputToFile)
      {
        holder = theGame->returnCurrentGrid();
        outputStream << "Generation " <<genCount<< "\r\n";
        for(int i = 1;i<length+1;++i)
        {
          for(int j = 1; j <width+1;++j)
          {
            outputStream << holder[i][j];
          }
          outputStream << "\r\n";
        }
      }
      theGame ->calculateNextGen();
      genCount ++;
    }
    cout<<"Population stable, simulation aborted"<<endl;
  }






  delete theGame;
  outputStream.close();
  inputStream.close();
  return 0;





}
