//.cpp file for Line class

#include "Line.h"

//CONSTRUCTORS AND DESTRUCTOR

// Name: Line() - Default Constructor
  // Desc: Creates a new empty line
  // Preconditions: None
  // Postconditions: Sets everything to either nullptr or 0
Line::Line(): m_head(nullptr), m_tail(nullptr), m_totalStops(0){}

  // Name: Line() - Overloaded Constructor
  // Desc: Creates a new empty line with passed name
  // Preconditions: None
  // Postconditions: Sets everything to either nullptr or 0
Line::Line(string line): m_head(nullptr), m_tail(nullptr), m_totalStops(0), m_lineName(line){}

  // Name: ~Line - Destructor
  // Desc: Removes all of the stops from the line
  // Preconditions: Line must have nodes
  // Postconditions: Line will be empty and m_head and m_tail
  //                  will be nullptr
Line::~Line(){
    Stop* curr = m_head;
    while(curr != nullptr){ //Iterate until the end of the line
        Stop* next = curr->GetNext();
        delete curr;
        curr = next
    }
}
