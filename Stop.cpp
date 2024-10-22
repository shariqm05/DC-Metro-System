//.cpp file for Stop class

#include "Stop.h"

//CONSTRUCTORS

 // Name: Stop - Default constructor
  // Desc - Default constructor for a Stop node
  // Preconditions - None
  // Postconditions - Creates a new Stop (for the Route)
Stop::Stop()
    :m_number(0), m_name(""){} //assigned defualt values

  // Name: Stop (number, name) - Overloaded Constructor
  // Desc - Overloaded constructor
  // Preconditions - Must have number and name to create new stop
  // Postconditions - Creates a new Stop (for the Line)
Stop::Stop(int number, string name)
    :m_number(number), m_name(name){}

//GETTERS AND SETTERS

// Name: GetNumber()
  // Desc - Returns the number of the stop
  // Preconditions - None
  // Postconditions - Returns a read-only m_number
int Stop::GetNumber(){return m_number;}

  // Name: GetName()
  // Desc - Returns the name of the stop
  // Preconditions - None
  // Postconditions - Returns a read-only m_name
string Stop::GetName(){return m_name;}

// Name: GetNext()
  // Desc - Returns a pointer to the next stop
  // Preconditions - None
  // Postconditions - Returns the pointer to the next stop
Stop* Stop::GetNext(){return m_next;}

  // Name: SetNext()
  // Desc - Sets the pointer to the next stop
  // Preconditions - Pointer has been defined
  // Postconditions - Updates m_next to next stop on Route
void Stop::SetNext(Stop* newStop){
    m_next = newStop;
}


