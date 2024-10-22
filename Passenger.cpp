//.cpp file for Passenger class

#include "Passenger.h"

//CONSTRUCTORS

// Name: Passenger()
  // Desc: Default Constructor for a passenger with -1 for number
  //        no line, start or finish
  // Preconditions: None
  // Postconditions: Creates a new Passenger
Passenger::Passenger()
    :m_number(-1), m_line("N/A"), m_startLocation("N/A"), m_finalDestination("N/A"){} //assigned default values     

// Name: Passenger(int, string, string, string)
  // Desc: Overloaded Constructor for a passenger including number, line,
  //        start location (where they board), final destination
  //        (where they get off)
  // Preconditions: Passenger num, line, start, and end required
  // Postconditions: Creates a new Passenger
Passenger::Passenger(int number, string line, string start_loc , string final_loc)
    :m_number(number), m_line(line), m_startLocation(start_loc), m_finalDestination(final_loc){} //initialization list

//GETTER AND SETTERS

// Name: GetNumber
  // Desc: Returns passenger number
  // Preconditions: Passenger number required
  // Postconditions: Returns passenger number
  int Passenger::GetNumber(){return m_number;}

 // Name: GetLine
  // Desc: Returns line (red, orange, yellow, blue, green, or silver)
  // Preconditions: Passenger line required
  // Postconditions: Returns passenger line
  string Passenger::GetLine(){return m_line;}

// Name: GetStartLocation
  // Desc: Returns starting location
  // Preconditions: Passenger start location required
  // Postconditions: Returns starting location
  string Passenger::GetStartLocation(){return m_startLocation;}

  // Name: GetFinalDestination
  // Desc: Returns final location
  // Preconditions: Passenger final destination required
  // Postconditions: Returns final destination
  string Passenger::GetFinalDestination(){return m_finalDestination;}

  // Name: DisplayPassenger
  // Desc: Displays passenger information in this form:
  //       Passenger Number: starting location to final destination
  // Preconditions: Passenger data required
  // Postconditions: Outputs passenger data
  void Passenger::DisplayPassenger(){
    cout << "Passenger " << m_number << ": " << m_startLocation << " to " << m_finalDestination << endl;
  }





