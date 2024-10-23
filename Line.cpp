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
        curr = next;
    }
    //free m_head and m_tail ptrs
    m_head = nullptr;  
    m_tail = nullptr;
}

//FUNCTIONS

// Name: GetLineName
  // Desc: Returns the name of the line
  // Preconditions: Line must have a name
  // Postconditions: Returns m_lineName;
string Line::GetLineName(){return m_lineName;}

  // Name: AddStop()
  // Desc: Dynamically allocates new stop and inserts at end of line
  //        (passes stop number and name)
  // Preconditions: Line allocated and data for stop available
  // Postconditions: New stop inserted in end of line
void Line::AddStop(int num, string name){

    Stop* temp = new Stop(num, name); //make new stop/node

    if (m_head == nullptr){ //if the line is empty
        m_head = temp; //update m_head to point at temp's node (since its the only Stop in the line)
        temp->SetNext(nullptr); //set temp's m_next to nullptr.
        m_tail = temp; //update tail to point at temp's node
    }
    else{ //If the line is not empty
        m_tail->SetNext(temp); // set last node to point at temp
        temp->SetNext(nullptr); //set newly added Stop at the end of the line to nullptr
        m_tail = temp; //update m_tail to represent new end of the line
        temp = nullptr; //free the temp ptr
    }
    temp = nullptr; //free the temp ptr
  }

  // Name: PrintLineDetails()
  // Desc: Prints information about a specific line
  // Preconditions: Line allocated and data for next stop available
  // Postconditions: Displays list of each stop on a line
  //                 including number, name, and (lineName)
void Line::PrintLineDetails(){
    cout << "**" << m_lineName << " Line Stops**" << endl;
    Stop* curr = m_head;

    while(curr != nullptr){
        cout << curr->GetNumber() << ". " << curr->GetName()<< "(" << m_lineName << ")" << endl;
        curr = curr->GetNext(); //increment curr by a node
    }
}

// Name: CalculateDistance(string start, string end)
  // Desc: Calculates the number of stops between the
  //        starting station and ending station
  // Preconditions: Line allocated with start and stop on correct line
  // Postconditions: Returns number of stops between two stations
  // There will always be at least two stops (start != stop)
  // For example, if the line is station 1 to station 2, the distance is 2
  // If the line is station 1 to station 4, the distance is 4
int Line::CalculateDistance(string start, string end){
    int count = 1;
    Stop* startPtr = m_head;
    Stop* endPtr = m_head;
    Stop* temp;
    //flag for input val
    bool startExists = false; 
    bool endExists = false; 

    //input val for start
    temp = m_head;
    while(temp != nullptr){
        if (temp->GetName() == start)
            startExists = true;
        temp = temp->GetNext();
    }
    //input val for start
    temp = m_head;
    while(temp != nullptr){
        if (temp->GetName() == end)
            endExists = true;
        temp = temp->GetNext();
    }

    if(startExists && endExists){
        //iterate through the line and fine the start node
        while(startPtr->GetName() != start){
            startPtr = startPtr->GetNext();
        }
        //iterate through the line and fine the end node
        while(endPtr->GetName() != end){
            endPtr = endPtr->GetNext();
        }
        //for loop to count each node from start param to end param
        for (Stop* temp = startPtr; temp != endPtr; temp = temp->GetNext()){
            count++;
        }
        return count;
    }
    //Invalid input message
    else{
        cout << "Invalid input, stop or end does not exist in this line" << endl;
        return -1; //-1 to signal an error
    }
}
