// Author: Ian Cooper
// Date: February 2, 2008
// Purpose: Checks credit card numbers to make sure they are valid. 



#include <iostream>
using namespace std;

int main() {

  char d01;
  char d02;
  char d03;
  char d04;
  char d05;
  char d06;
  char d07;
  char d08;
  char d09;
  char d10;	
  char d11;
  char d12;
  char d13;
  char d14;
  char d15;
  char d16;

  cout << "Please enter your 16 digit credit card number in the form XXXX XXXX XXXX XXXX. \n";
  cout << "Then press return. \n";

  cin >> d01 >> d02 >> d03 >> d04 >> d05 >> d06 >> d07 >> d08 >> d09 >> d10 >> d11 >> d12 >> d13 >> d14 >> d15 >> d16;

  int n01;
  int n02;
  int n03;
  int n04;
  int n05;
  int n06;
  int n07;
  int n08;
  int n09;
  int n10;
  int n11;
  int n12;
  int n13;
  int n14;
  int n15;
  int n16;

  n01 = (d01-'0');
  n02 = (d02-'0');
  n03 = (d03-'0');
  n04 = (d04-'0');
  n05 = (d05-'0');
  n06 = (d06-'0');
  n07 = (d07-'0');
  n08 = (d08-'0');
  n09 = (d09-'0');
  n10 = (d10-'0');
  n11 = (d11-'0');
  n12 = (d12-'0');
  n13 = (d13-'0');
  n14 = (d14-'0');
  n15 = (d15-'0');
  n16 = (d16-'0');

  int checksum;

  checksum = ((2*n01)/10 + (2*n01)%10 + n02 + (2*n03)/10 + (2*n03)%10 + n04 + (2*n05)/10 + (2*n05)%10 + n06 + (2*n07)/10 + (2*n07)%10 + n08 + (2*n09)/10 + (2*n09)%10 + n10 + (2*n11)/10 + (2*n11)%10 + n12 + (2*n13)/10 + (2*n13)%10 + n14 + (2*n15)/10 + (2*n15)%10 + n16);
  
  char good;

// Verify
  if((checksum%10) == 0) {
	good='y';
}
  
  else {
	good='n';
}

// Identify

  int identm;
  identm = (n01 * 10) + n02;

  int identd;
  identd = (n01 * 1000) + (n02 * 100) + (n03 * 10) + n04;

  char type;

  if((identm >= 51) && (identm <= 55)){
	type = 'm';
}
  else if(d01 == 4){
	type = 'v';
}
  else if(identd == 6011){
	type = 'd';
}
  else {
	type = 'u';
}

  if((good=='y') && ((type == 'v') || (type == 'd') || (type == 'm'))){
	cout << "The credit card number you entered is " <<d01 <<d02 <<d03 <<d04 <<" " <<d05 <<d06 <<d07 <<d08 <<" " <<d09 <<d10 <<d11 <<d12 <<" " <<d13 <<d14 <<d15 <<d16 << ".\n";
	
	cout << "This credit card number is valid.\n";
}
  else if((good == 'y') && (type == 'u')){
	cout << "The credit card number you entered is " <<d01 <<d02 <<d03 <<d04 <<" " <<d05 <<d06 <<d07 <<d08 <<" " <<d09 <<d10 <<d11 <<d12 <<" " <<d13 <<d  14 <<d15 <<d16 << ".\n";

	cout << "This credit card number is valid but of an unrecognized brand.\n";
	cout << "Unfortunately we only accept Mastercard, Visa, and Discover cards.\n";

}
  else{
	cout << "The credit card number you entered is " <<d01 <<d02 <<d03 <<d04 <<" " <<d05 <<d06 <<d07 <<d08 <<" " <<d09 <<d10 <<d11 <<d12 <<" " <<d13 <<d14 <<d15 <<d16 << ".\n";

	cout << "This credid card number is invalid.";
}

return 0;
}

