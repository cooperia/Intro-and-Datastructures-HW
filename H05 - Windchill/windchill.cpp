//Author: Ian Cooper
//Date: Feb 25, 08
//Purpose: Calculates wind chill. 


#include <iostream>
#include <cmath>
using namespace std;

//Function that requests and gets the user's desired initial temperature.
double GetTemp(double temp, char unit);

//Function that requests and gets the user's desired wind speed. 
double GetSpeed(double speed, char unit);

//Function that requests and gets the user's desired units(metric or english).
char GetUnit(char unit);

//Function that calculates wind chill using the user's desired values for wind speed and temperature and reports in the user's desired units. 
double WindChill(double speed, double temp, char unit);

int main(){
  char unit;
  double temp;
  double speed;
  double chill;

  //Calls the funtion that requests and gets the user's desired units.
  unit = GetUnit(unit);

  if(unit == 'm'){
    temp = 0;
    speed = 10;
  }
  else{
    temp = 32;
    speed = 22.3694;
  }
  do{
    //Calls the function that requests and gets the user's desired initial temperature. 
    temp = GetTemp(temp, unit);
    //Calls the function that requests and gets the user's desired wind speed.
    speed = GetSpeed(speed, unit);
    //Calls the function that calculates wind chill. 
    chill = WindChill(speed, temp, unit);

    cout << "You entered:\n";
    cout << "\n";
    cout << "  Initial Temperature = " << temp << "\n";
    cout << "  Wind Speed = " << speed << "\n";
    cout << "  Units = " << unit << ", where m is Metric and e is English.\n";
    cout << "\n";
    cout << "The new temperature with adjustment for windchill is >>" <<chill<<"<<" << " degrees.\n";
    cout << "\n";
    
    cout << "Would you like to do another calculation[Y/n]\n";
    
    if(cin.peek() == 'n' || cin.peek() == 'N'){
      break;
    }
    else{
      while(cin.peek() != '\n'){cin.get();}
      cin.get();
    }
  }while(1);
  

}
//Requests and gets the user's desired units.
char GetUnit(char unit){
  cout<< "Please enter either 'm' for Metric units or 'e' for English units[m]\n";

  if(cin.peek() != '\n'){
    cin >> unit;
  }
  cin.get();
  return unit;
}

//Requests and gets the user's desired value for initial temperature. 
double GetTemp(double temp, char unit){
  cout<< "Please enter the current temperature without windchill["<<temp<<"]:\n";
  if(cin.peek()!= '\n'){
    cin >> temp;
  }
  cin.get();
  return temp;
}

//Requests and gets the user's desired value for wind speed.    
double GetSpeed(double speed, char unit){
  cout<< "Please enter the current wind speed["<<speed<<"]:\n";
  if(cin.peek() != '\n'){
    cin >> speed;
  }
  cin.get();
  return speed;
}
//Calculates windchill using the user's input.
double WindChill(double speed, double temp, char unit){
  double chilly;
  if(unit != 'm'){
    speed = speed/2.23693629;
    temp = (temp - 32)*(5.0/9.0);
  }

  chilly = 13.12 + (0.6215*temp) - (11.37*(pow(speed,0.16))) + (0.3965*temp*(pow(speed,0.16)));

  if(unit != 'm'){
    chilly = ((9.0/5.0) * chilly) + 32;
  }
  
  return chilly;
}


