#include <iostream>
#include "rover.h"
#include "scandata.h"
#include "queue.h"

using namespace std;

rover::rover(): ID(0), xCoordinate(0), yCoordinate(0), results(0) 
{
}

rover::rover(const int& newID, const int& MAX_RESULTS, queue& theResultqueue)
{
    ID = newID;
    resultsPointer = &theResultqueue;
}

rover::~rover()
{
}

void rover::deploy()
{
    std::cout << "Rover (" << ID << ") deploying..." << endl;
    std::cout << "Rover (" << ID << ") ready" << endl;
}

void rover::move(const int& newX, const int& newY)
{
    xCoordinate = newX;
    yCoordinate = newY;
    entry.x = xCoordinate;
    entry.y = yCoordinate;

    roverStack.push(entry);
}

void rover::corescan()
{
    std::cout << "Rover (" << ID << ") scanning.";
    //when to use static???
    results = scandata::getScandata(xCoordinate,yCoordinate);
    thisDatapoint.setRoverID(ID);
    thisDatapoint.setXCoordinate(xCoordinate);
    thisDatapoint.setYCoordinate(yCoordinate);
    thisDatapoint.setResults(results);
    //TODO: idk EVEN KNOW:w
    resultsPointer->enqueue(thisDatapoint);

    
    //resultsPointer->enqueue(thisDatapoint);
     
    

}

void rover::dock()
{
    std::cout << "Rover (" << ID << ") returning to base.";
    std::cout << "Rover (" << ID << ") moving to location"
    << xCoordinate << ", " << yCoordinate << "." << endl;


    entry.x = 0;
    entry.y = 0;
    roverStack.push(entry);
    


    std::cout << "Rover (" << ID << ") at base and docked";

}













