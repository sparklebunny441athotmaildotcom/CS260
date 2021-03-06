#include "linkedlist.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

linkedList::linkedList() : timeHead(nullptr), temperatureHead(nullptr), windspeedHead(nullptr), listSize(0)
{
}

linkedList::~linkedList()
{
    entryNode* currentTime = timeHead;
    while(timeHead)
    {
        currentTime = timeHead->nextTime;
        delete timeHead;
        timeHead = nullptr;
        timeHead = currentTime; 
    }
}

bool linkedList::insert(const weatherdata& thisEntry)
{
    bool isSuccessful;
    entryNode* previousTime = nullptr;
    entryNode* currentTime = timeHead;
    entryNode* previousTemperature = nullptr;
    entryNode* currentTemperature = temperatureHead;
    entryNode* previousWindspeed = nullptr;
    entryNode* currentWindspeed = windspeedHead;
    
    //Just making the node, it's hangin' out
    entryNode * newEntry = new entryNode;
    newEntry->entry = thisEntry;
    newEntry->nextTime = nullptr;
    newEntry->nextTemperature = nullptr;
    newEntry->nextWindspeed = nullptr;
    //ALSO: do I NEED to assert head?
    while(currentTime != nullptr && currentTime->entry.getTimestamp() < thisEntry.getTimestamp())
    {
        previousTime = currentTime;
        currentTime = currentTime->nextTime;
    }

    newEntry->nextTime = currentTime;

    if(previousTime == nullptr)
    {
        timeHead = newEntry;
    }
    else
    {
        previousTime->nextTime = newEntry;
    }
    //std::cout << newEntry->entry.getTemperature() << '\n';
        
    while(currentTemperature != nullptr && currentTemperature->entry.getTemperature() < thisEntry.getTemperature())
    
    {
        previousTemperature = currentTemperature;
        currentTemperature = currentTemperature->nextTemperature;
    }
    newEntry->nextTemperature = currentTemperature;
    if(previousTemperature == nullptr)
    {
        temperatureHead = newEntry;
    }
    else
    {
        previousTemperature->nextTemperature = newEntry;
    }

    while(currentWindspeed != nullptr && currentWindspeed->entry.getWindspeed() < thisEntry.getWindspeed())

    {
        previousWindspeed = currentWindspeed;
        currentWindspeed = currentWindspeed->nextWindspeed;
    }
    newEntry->nextWindspeed= currentWindspeed;
    if(previousWindspeed == nullptr)
    {
        windspeedHead = newEntry;
    }
    else
    {
        previousWindspeed->nextWindspeed = newEntry;
    }

    


    listSize++;
    return isSuccessful;
}

int linkedList::totalizer() const
{
    int total = 0;
    entryNode * current;
    for(current = timeHead; current; current = current ->nextTime)
    {
        total++;
    }
    return total;
}

int linkedList::pullTime(int target) const
{
    int index = 0;
    int timeStamp = 0;
    entryNode * current;
    current = timeHead;
    while(index < target-1)
    {
       // std::cout << "hi\n";
        current = current->nextTime;
        index++;
    }
    timeStamp = current->entry.getTimestamp();
    //std::cout << timeStamp;
    return timeStamp;
}

int linkedList::pullTemperature(int target) const
{
    int index = 0;
    int temperature = 0;
    entryNode * current;
    current = temperatureHead;
    while(index < target-1)
    {
       // std::cout << "hi\n";
        current = current->nextTemperature;
        index++;
    }
    temperature = current->entry.getTemperature();
    //std::cout << temperature;
    return temperature;
}

int linkedList::pullWindspeed(int target) const
{
    int index = 0;
    //WHY THE FUCK DOESN'T THIS WORK WITH ANYTHING BUT -1??
    int windspeed = 0;
    entryNode * current;
    current = windspeedHead;
    while(index < target-1)
    {
       // std::cout << "hi\n";
        current = current->nextWindspeed;
        index++;
    }
    windspeed = current->entry.getWindspeed();
    //std::cout << windspeed;
    return windspeed;
}

int linkedList::pullTempByTime(int target) const
{
    int index = -1;
    int temperature = 0;
    entryNode * current;
    current = timeHead;
    while(index < target-1)
    {
       // std::cout << "hi\n";
        current = current->nextTime;
        index++;
    }
    temperature = current->entry.getTemperature();
    return temperature;
}

int linkedList::pullWindByTime(int target) const
{
    int index = -1;
    int windspeed = 0;
    entryNode * current;
    current = timeHead;
    while(index < target-1)
    {
       // std::cout << "hi\n";
        current = current->nextTime;
        index++;
    }
    windspeed = current->entry.getWindspeed();
    //std::cout << timeStamp;
    return windspeed;
}

void linkedList::printMe() const
{
    entryNode * current = new entryNode;
    current = nullptr;
    for(current = timeHead; current; current = current->nextTime)
    {
        cout << current->entry; 
    }
    std::cout << endl;
    current = nullptr;
    for(current = temperatureHead; current; current = current->nextTemperature)
    {
        cout << current->entry; 
    }
    std::cout << endl;
    current = nullptr;
    for(current = windspeedHead; current; current = current->nextWindspeed)
    {
        cout << current->entry; 
    }
    std::cout << endl;
    delete current;
}



bool linkedList::timeComparison(int timestamp) const
{
    bool does = false;
    entryNode* previousTime = nullptr;
    entryNode* currentTime = timeHead;

    while(timeHead != nullptr && currentTime->nextTime != nullptr && timestamp >= currentTime->entry.getTimestamp())
    {
        previousTime = currentTime;
        currentTime = currentTime->nextTime;
        //std::cout << "THIS IS MY TIMESTAMP " << timestamp << " " << currentTime->entry.getTimestamp() << endl;
        if(timestamp == currentTime->entry.getTimestamp())
        {
            //std::cout << "IN HERE!! This timestamp: " << timestamp << " This node's timestamp:  " << currentTime->entry.getTimestamp() << endl;
            does = true;
        }
        
    }
    return does;
}

void linkedList::deleteNode(int timestamp)
{
    
    entryNode* previousTime = nullptr;
    entryNode* currentTime = timeHead;
    entryNode* flag;
    int testTimestamp;
    
    while(currentTime->nextTime != nullptr) 
    {
        if(currentTime->entry.getTimestamp() == timestamp)
        {
            if(!previousTime)
            {
                timeHead= currentTime->nextTime;
            }

            //std::cout << "DELET THIS" << endl;        
            //std::cout << "the repeat is: " << currentTime->entry.getTimestamp();
            else
                previousTime->nextTime = currentTime->nextTime;
            delete currentTime;
            currentTime = nullptr;
            
        }
        previousTime = currentTime;
        currentTime = currentTime->nextTime;
    }
    return;



    //while(currentTime->nextTime  != nullptr)
    //{
    //    testTimestamp = currentTime ->enry.getTimestamp();
    //    if(timestamp == testTimestamp)
    //    {
    //        if(!previousTime)
    //        {
    //            std::cout<<"YRULIKETHIS?" <<endl;
    //            timeHead = currentTime->nextTime;
    //            delete currentTime;
    //        }
    //        else
    //        {
    //          std::cout << "Delete this!" << endl;
    //          previousTime->nextTime = currentTime->nextTime;
    //          delete currentTime;
    //        }
    //    }
    //    else
    //    {
    //        std::cout << "FUCKDICK" << endl;
    //    }
    //    previousTime = currentTime;
    //    currentTime = currentTime->nextTime;
    //}
    
//***************IF IT ISN'T THE FIRST TIME HEAD AND IF IT ISNT AN EMPTY LIST
return;
}






























