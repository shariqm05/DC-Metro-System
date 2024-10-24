//.cpp file for Metro class

#include "Metro.h"

//CONSTRUCTORS AND DESTRUCTOR

// Name: Metro (default constructor)
  // Desc: Populates m_fileLine and m_filePass with default values
  //       Calls LoadLines, LoadPassengers, and then MainMenu
  // Preconditions: None
  // Postconditions: A new metro system is created.
Metro::Metro(){}

  // Name: Metro (overloaded constructor)
  // Desc: Populates m_fileLine and m_filePass.
  //       Calls LoadLines, LoadPassengers, and then MainMenu
  // Preconditions: Filename is included
  // Postconditions: A new metro system is created with lines and
  //                 passengers using passed input files
Metro::Metro(string fileLine, string filePass){}

// Name:  Metro (destructor)
  // Preconditions: None
  // Postconditions: All lines (linked lists) are destroyed.
  //                 All vectors are cleared out.
Metro::~Metro(){
    //for emptying Line vector
    for(int i = 0; i < m_lines.size(); i++){ 
        delete m_lines[i]; //delete that line (line destructor)
    }
    //for emptying Passenger vector
    for(int i = 0; i < m_passengers.size(); i++){
        delete m_passengers[i]; //delete that passenger
    }
    //reset both vector lengths
    m_lines.resize(0);
    m_passengers.resize(0);
}

//FUNCTIONS

 // Name:  LoadLines
  // Desc: Populates a vector of dynamically allocated
  //       Lines (Lines are linked lists) for input file of metro lines
  // Preconditions: Valid file name of lines
  // Postconditions: Loads all lines in input file (can be many)
void Metro::LoadLines(){

  //Dynamically allocate all 6 lines of the Metro System
  Line* redLine = new Line("red");
  Line* greenLine = new Line("green");
  Line* blueLine = new Line("blue");
  Line* yellowLine = new Line("yellow");
  Line* silverLine = new Line("silver");
  Line* orangeLine = new Line("orange");


  ifstream m_fileLines("proj3_stations.txt"); //sets m_fileLines to the input text file explicitly, since theres only 1
  string line; //represents a a single line, for a single stop's info

  //opening and processing stops into respective Lines
  if (m_fileLines.is_open()){
    while(getline(m_fileLines, line)){
      //variabels for a single stop
      int num; //Stop number
      string lineName; //lineName
      string stationName; //StationName

      char delim = ',';
      int pos = 0; //string index
      string extractorString = ""; //an empty string which we'll load characters to extract variables


      //stop Number (num)
      while(pos < line.length() && line.at(pos) != delim){
        extractorString = extractorString + line.at(pos); //add character to the string holder
        pos++; //move index down one
      }
      pos++; //one more increment to move past the delimiter.
      num = stoi(extractorString); //stoi to conver to int
      extractorString = ""; //clear the string for next variable
      
      //lineName (color of line)
      while(pos < line.length() && line.at(pos) != delim){
        extractorString = extractorString + line.at(pos); //add character to the string holder
        pos++; //move index down one
      }
      pos++; //one more increment to move past the delimiter.
      lineName = extractorString;
      extractorString = ""; //clear the string for next variable

      //stationName
      while(pos < line.length()){ 
        extractorString = extractorString + line.at(pos); //add character to the string holder
        pos++; //move index down one
      }
      pos++; //one more increment to move past the delimiter.
      stationName = extractorString; //stoi to conver to int

      //adding the stop to its respective line
      if (lineName == "red"){
        redLine->AddStop(num, stationName);
      }
      else if (lineName == "green"){
        greenLine->AddStop(num, stationName);
      }
      else if (lineName == "blue"){
        blueLine->AddStop(num, stationName);
      }
      else if (lineName == "yellow"){
        yellowLine->AddStop(num, stationName);
      }
      else if (lineName == "silver"){
        silverLine->AddStop(num, stationName);
      }
      else if (lineName == "orange"){
        orangeLine->AddStop(num, stationName);
      }
    }     
  }
  m_fileLines.close(); //close the input file
  //add all 6 populataed lines to the line vector
  m_lines.push_back(redLine);
  m_lines.push_back(greenLine);
  m_lines.push_back(blueLine);
  m_lines.push_back(yellowLine);
  m_lines.push_back(silverLine);
  m_lines.push_back(orangeLine);
}

  // Name:  LoadPasses
  // Desc: Populates vector of dynamically allocated passengers
  //       from input file
  // Preconditions: Valid file name of lines
  // Postconditions: Loads all passengers in input file to m_passengers
  void Metro::LoadPasses(){} 

// Name: LineToIndex
  // Desc: Returns the index of the line based on the name
  //       For example, if the red line is in m_lines index 0, returns 0
  // Preconditions: m_lines must be populated
  // Postconditions: Returns the index of the line based on the name
  int Metro::LineToIndex(string name){}

  // Name: MainMenu
  // Desc: Asks user to Display Lines, Display Passengers per Line,
  //       Calculate Earnings by Line, or exit.
  // Preconditions: None
  // Postconditions: When exit, quits program with no memory leaks or errors
  void Metro::MainMenu(){}

   // Name:  DisplayLines
  // Desc: Iterates over the vector and calls the
  //       PrintLineDetails for each line
  // Preconditions: At least one line in m_lines;
  // Postconditions: Displays details of each line in m_lines
  void Metro::DisplayLines(){}

  // Name:  DisplayPassengers
  // Desc: Displays information about each passenger from each line
  // Preconditions: Has line loaded and passenger loaded
  // Postconditions: Displays information about each passenger
  void Metro::DisplayPassengers(){}

// Name:  CalcEarnings()
  // Desc: Displays total earnings based on passengers
  //       Displays earnings by line
  // Preconditions: Has lines and passengers loaded
  // Postconditions: Displays line with stop data
  void Metro::CalcEarnings(){}