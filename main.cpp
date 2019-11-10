/*
	Input Validation with Ref Functions 
	A cleaner way to do input validation
	Validating input, an essential process.
	Source: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c
	Keeping Dr. McMillan from breaking my code, defend against "dark side of the force",
	and/or legitimate user error. 
	//Try and Catch blocks are used in error checking
	Teacher: Dr. Tyson McMillan 
*/
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
                              // Extended 2-11-2016 by Dr. McMillan to add validation methods by datatype
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison and over riding toString.
using namespace std;

// Declaring Sturcts of Unit 7 *Building a Data Type for C++ to recognize. Always Above
// Int Main, Creating a Variable
struct timeOfDay
{
  short Hour;
  short Minute;
  short Second;
};

struct appDate
{
  short dayOfMonth;
  short month;
  int year;
};

struct event
{
  string eventName;
  timeOfDay eventTime; //Defining the DataType "timeOfDay" with "eventTime" 
  appDate eventDate;
  bool isUrgent;

  //make a toString() member function for event #include<sstream> need for overriding toString()
  //giving event instructions for how to print itself!!!!!!
  string toString()
  { // Build the Date string
    short dayOfMonth =  eventDate.dayOfMonth;
    short month = eventDate.month;
    int year = eventDate.year;

    stringstream ss; // a custom style cout ********* Build string named "ss"
    ss << month << "/" << dayOfMonth << "/" << year;

    string date = ss.str();//assign "ss.str()" data to the word "date"*******


    //Build the Time string
    short Hour = eventTime.Hour;
    short Minute = eventTime.Minute;
    short Second = eventTime.Second;

    stringstream sst; //Build string name "sst"
    sst << Hour << ":" << Minute << ":" << Second << endl;
    string time = sst.str(); //assign "sst.str()" data to the word "time"******


    return ("Date = " + date + "\nTime: " + time);
  }
  
};

 void createEvent(timeOfDay &t, appDate &d, event &e);


int main()
{
  // Assigning Data inside Int Main
  // date m/d/y time: hr: min: sec:
  timeOfDay t; //instance of the timeOfDay struct
  t.Hour = 7; 
  t.Minute = 45; //intializing hard data for each "member" of the "timeOfDay" struct 
  t.Second = 22;

  cout << "\nTime" << endl;
  cout << t.Hour << ":" << t.Minute << t.Second << endl; //OutPut the time to screen

  appDate d; //instance of the appDate struct STEP: 1
  d.dayOfMonth = 28;
  d.month = 03;  //intializing hard data for each "member" of the "appDate" struct
  d.year = 1982; // STEP: 2

  cout << "\nMy Birthday is " << endl;
  cout << d.month << "/" << d.dayOfMonth << "/" << d.year << endl;
                  // STEP: 3 Using it ^^^^^^^^^^^^^^^^

  event e;
  e.eventName = "My Birthday";
 //*********************Structures Above********************************************
  
  int decision = 0;
  string status = " "; //declare and intialize string "status"
  
  //determine if the event is urgent  
  cout << "\nIs the Event Urgent " << e.eventName << ": 1=y 2=n. " << endl;
  cin >> decision; //Input from User on "Event Status" 

  if (decision == 1)
  {
    e.isUrgent = true; // yes, urgent event
    status = "URGENT";
  }
  else if (decision == 2)
  {
    e.isUrgent = false; // no, not urgent event
    status = "NOT URGENT";
  }
  else
  {
    status = "error";
  }
  cout << "\n Event Name: " << e.eventName << ", Status: " << status << endl;

  //Populate the event "e" with a date and a time ****************************
  //put date into e.eventDate
  e.eventDate = d; // put data into e.eventDate using an existing "birthday" instance
  e.eventTime = t; // put data into e.eventdate using an existing "t" instance

  //Print (reprint) the date and time of the event
  // reprint the "e" date
  cout << "\nEvent date: " << endl;
  cout << e.eventDate.month << "/" 
       << e.eventDate.dayOfMonth << "/"
       << e.eventDate.year << endl;
  
  cout << "\nEvent time: " << endl;
  cout << e.eventTime.Hour << ":" 
       << e.eventTime.Minute << ":" 
       << e.eventTime.Second << endl;

  cout << e.toString();
//**************************************** PART 2 ******************************************
  
    cout << "^^^^^^^^^^^^^^^^^^^ PART 1 ************************************" << endl;
    cout << "vvvvvvvvvvvvvvvvvvv PART 2 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
   
   cout << "\nUnit 7, Part 2: Pass Event Objects by Reference &" << endl; 
    //declare instances of the STRUCT that we need for this work
    event eMain;
    timeOfDay tMain; //create a timeOfDay to share with eMain
    appDate dMain; //create a appDate to share with eMain
    //call a function here called void createEvent(timeOfDay &t, appDate &d, event &e);
    /*
       pass tMain, dMain, and eMain by reference
       ask for user input to populate tMain, dMain, with data
       store these data in eMain
       ask for and store the event name and urgency
       print all the event details to screen. 
    */
   
   
    createEvent(tMain, dMain, eMain); //function call 
    cout << eMain.toString(); // after the struc call






   
    return 0;
}
 void createEvent(timeOfDay &t, appDate &d, event &e)
  {
    short h = 0, m = 0, s = 0, mo = 0, day = 0;
    int y= 0, decision = 0;
    string urgent = " ", eName = " ", status = " ";
    cout << "\nWelcome to our custom Event Creator. " << endl;

    //populate time of day "t"
    cout << "\nPlease enter and hour(h), min(m), seconds(s) of the Event:  " << endl;
    cin >> h >> m >> s; // user input for hour, minute, second. 
    t = {h, m, s};// set the time to the value entered by the user
         

    //populate appDate "d"
    cout << "\nPlease enter the Day(day), Month(mo), and Year (y) of the Event: " << endl;
    cin >> day >> mo >> y;
    d = {day, mo, y};

    //Set event details
    //Populate the event "name"
    cout << "\nPlease Enter a Event Name: " << endl;
    cin >> eName;

    //Populate the event "urgency"
    cout << "\n Is the Event Urgent? ( 1=y 2=N)";
    cin >> decision;
    status = (decision == 1) ? "YES": "NO";
    cout << "Urgency: " << status << endl; 
    


    //put "dMain" into Event "eMain"
    e.eventDate = d;

    //put "tMain" into Event "eMain"
    e.eventTime = t;
    cout << e.toString();

    //Print the Event
    //name
    //urgency
    //date thint cout << e.toString() << endl
    //time
    //test this and upload your complted code to Unit 7 Assignment
  }
