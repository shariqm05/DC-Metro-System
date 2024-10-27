//.cpp file for Metro class

#include "Metro.h"

//CONSTRUCTORS AND DESTRUCTOR

// Name: Metro (default constructor)
  // Desc: Populates m_fileLine and m_filePass with default values
  //       Calls LoadLines, LoadPassengers, and then MainMenu
  // Preconditions: None
  // Postconditions: A new metro system is created.
Metro::Metro(){
  LoadLines();
  LoadPasses();
  MainMenu();
}
 
  // Name: Metro (overloaded constructor)
  // Desc: Populates m_fileLine and m_filePass.
  //       Calls LoadLines, LoadPassengers, and then MainMenu
  // Preconditions: Filename is included
  // Postconditions: A new metro system is created with lines and
  //                 passengers using passed input files
Metro::Metro(string fileLine, string filePass):m_fileLines(fileLine),m_filePass(filePass){
  LoadLines();
  LoadPasses();
  MainMenu();
}

// Name:  Metro (destructor)
  // Preconditions: None
  // Postconditions: All lines (linked lists) are destroyed.
  //                 All vectors are cleared out.
Metro::~Metro(){
    //for emptying Line vector
    for(int i = 0; i < m_lines.size(); i++){ 
        delete m_lines[i]; //delete that line and any stops in it (line destructor)
    }
    //for emptying Passenger vector
    for(int i = 0; i < m_passengers.size(); i++){
        delete m_passengers[i]; //delete that passenger
    }
    //clear both vector lengths
    m_lines.clear();
    m_passengers.clear();
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


  ifstream file(m_fileLines); 

  //opening and processing stops into respective Lines
  if (file.is_open()){
    string numStr, lineName, stationName; //variables for a singl stop
    char delim = ','; //delimiter

    while(getline(file, numStr, delim) &&
          getline(file, lineName, delim) &&
          getline(file, stationName)){
    
      int num = stoi(numStr); //convert to an actual int

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
  file.close(); //close the input file
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
void Metro::LoadPasses(){

  ifstream file(m_filePass);
  if(file.is_open()){

    string numStr, line, startLoc, endLoc; //variables for a singl passenger
    char delim = ','; //delimiter

    while(getline(file, numStr, delim) &&
          getline(file, line, delim) &&
          getline(file, startLoc, delim) &&
          getline(file, endLoc)){
    
      //create and store passenger in the passenger Vector
      int num = stoi(numStr); //convert to an actual int
      Passenger* temp = new Passenger(num, line, startLoc, endLoc);
      m_passengers.push_back(temp);
    }
  }
  file.close(); 
} 

// Name: LineToIndex
  // Desc: Returns the index of the line based on the name
  //       For example, if the red line is in m_lines index 0, returns 0
  // Preconditions: m_lines must be populated
  // Postconditions: Returns the index of the line based on the name
int Metro::LineToIndex(string name){
  for (int i = 0; i < m_lines.size(); i++){
    if (m_lines[i]->GetLineName()== name){ //if it matches the param
      return i; //return index
    }
  }
  //input val
  cout << "Line not found. Pleaas enter valid line name." << endl;
  return -1;
}

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
void Metro::DisplayLines(){  
  for (int i = 0; i < m_lines.size(); i++){
    m_lines[i]->PrintLineDetails(); //print out info for the line
  }
}

  // Name:  DisplayPassengers
  // Desc: Displays information about each passenger from each line
  // Preconditions: Has line loaded and passenger loaded
  // Postconditions: Displays information about each passenger
void Metro::DisplayPassengers(){
  for (int j = 0; j < m_lines.size(); j++){
    string line = m_lines[j]->GetLineName(); //current line we are searching passengers for
    cout << "** " << line << " **\tPassengers:" << endl;
    for (int i = 0; i < m_passengers.size(); i++){
      if (m_passengers[i]->GetLine() == line){
        m_passengers[i]->DisplayPassenger(); //displat singular passenger's info
      }
    }
    cout << "\t" << endl; //indednt after one line of passengers is displayed
  }
}

// Name:  CalcEarnings()
  // Desc: Displays total earnings based on passengers
  //       Displays earnings by line
  // Preconditions: Has lines and passengers loaded
  // Postconditions: Displays line with stop data
  void Metro::CalcEarnings(){}