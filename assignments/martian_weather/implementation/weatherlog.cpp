#include <iostream>
#include <fstream>
#include "datalogger.h"

using namespace std;

//void createReport(datalogger& dl,const char* label)
//{
//    dl.printReport(label);
//}

int main(int argc, char** argv) {

    datalogger rawDatalog;
//    datalogger cleanDatalog;

    if (argc != 2) {
	cout << "Usage: " << argv[0] << " <datafile>" << endl;
	exit(0);
    }

    // Read the data

    char* datafile = argv[1];
    ifstream inDatafile(datafile);
    int timestamp;
    int temperature;
    int windspeed;
    
    while (!inDatafile.eof()) {
	inDatafile >> timestamp;
    //cout << timestamp;
	inDatafile >> temperature;
    //cout << temperature;
	inDatafile >> windspeed;
    //cout << windspeed;
    rawDatalog.addData(timestamp, temperature, windspeed);


    }
    rawDatalog.doTheThing();

//TODO 1
//HEY!!! ARE WE TO ASSUME:
//that after cleanDatalog.removeData() deletes a node, we don't replace it?

// FOR TESTING PURPORSES! GO BACK TO THIS BLOCK AFTER YOU GET IT TO TAKE INFO IN
//	if (!inDatafile.eof()) {
//	    if (rawDatalog.containsTimestamp(timestamp)) {
//		cleanDatalog.removeData(timestamp);
//	    } else {
//		cleanDatalog.addData(timestamp,temperature,windspeed);
//	    }
//
//	    rawDatalog.addData(timestamp, temperature, windspeed);
//	}
//    }

//TODO 2
//LOOK!! CREATEREPORT IS AT THE TOP OF THIS FILE AND CALLS A FUNCTION THAT YOU NEED TO WRITE
//    createReport(rawDatalog,"raw data");
//    cout << endl;
//    createReport(cleanDatalog,"clean data");
    
    return(0);
}
