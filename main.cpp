/* ------------------------
 Nicholas Chen
 ICS4U1 - 2
 Assignment #3: Working with 2D arrays
--------------------------- */
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void employeeInfo();

void highestPaid();

void lowestPaid();

void sumOfAllEmployeePay();

void averageEmployeePayMonthly();

struct Employee {
  string first;
  string last;
  double wages[4];
};
Employee emps[10];
int main() {
  cout << "-----------------------------------------------------------" << endl;
  cout << "Choose one of the following options: " << endl;

  ifstream fin;
  
  //opens file for program to read and use data for functions
  fin.open("data.txt");

  for (int i = 0; i < 10; i++) {

    //adds the file data into array for use
    fin >> emps[i].first;
    fin >> emps[i].last;

    for (int j = 0; j < 4; j++) {
      fin >> emps[i].wages[j];
    }
  }
  
  //allows for decimal places in numbers that are outputted
  cout << fixed << setprecision(2);

  int choice;

  string answer;

  do {

    // questions for user to choose from
    cout << "1) Employee name and their monthly average wages" << endl;
    cout << "2) Highest paid employee and his/her pay" << endl;
    cout << "3) Lowest paid employee and his/her pay" << endl;
    cout << "4) Sum of wages paid to all employees" << endl;
    cout << "5) Average wage of all employees for a given month" << endl;

    cin >> choice;
    cin.ignore();

    // condition for choices
    while (choice < 1 || choice > 5) {
      cout << "Invalid choice! Your choice must be between 1 and 5." << endl;
      break;
    }

    switch (choice) {

    case 1:
      employeeInfo();
      break;
    case 2:
      highestPaid();
      break;
    case 3:
      lowestPaid();
      break;
    case 4:
      sumOfAllEmployeePay();
      break;
    case 5:
      averageEmployeePayMonthly();
      break;
    }

    //allows user to continue or stop program
    cout << "Would you like to see more info? (y/n)" << endl;
    cin >> answer;
    while (answer == "n" || answer == "N") {

      // ends program after user enters n or N
      exit(0);
    }

  }

  while (choice != 6);
}

//function to calculate all employee wages and display info
void employeeInfo() {
  string employeeName;
  double employeePays[10];
  string employeeNames[10];

  cout << "Average Monthy Wages: " << endl;

  //loops through the array to calculate the wages of each employee
  for (int i = 0; i < 10; i++) {
    double employeePay = 0;
    for (int j = 0; j < 4; j++) {
      employeePay += emps[i].wages[j];
    }

    //finds average of employee pay and prints it out 
    double average = employeePay / 4;
    cout << setw(15) << emps[i].first + " " + emps[i].last << ": " << setw(10)
         << "$" << average << endl;
  }
}

//finds the highest paid employee
void highestPaid() {
  string employeeName;
  double employeePays[10];
  string employeeNames[10];
  double highestPay;

  //loops through arrays
  for (int i = 0; i < 10; i++) {
    double employeePay = 0;
    for (int j = 0; j < 4; j++) {
      employeePay += emps[i].wages[j];

      //adds each employee pay to an array
      employeePays[i] = employeePay;

      //adds each employee name to an array
      employeeNames[i] = emps[i].first + " " + emps[i].last;
    }
  }

  //for loop to compare values in array to find highest paid employee
  for (int i = 0; i < 10; i++) {
    if (highestPay < employeePays[i]) {
      highestPay = employeePays[i];
      employeeName = employeeNames[i];
    }
  }

  //displays the highest paid employee and their name
  cout << "The highest paid employee, " << employeeName
       << " has a total pay of $" << highestPay << endl;
}

//function to find the lowest paid employee
void lowestPaid() {
  string employeeName;
  double employeePays[10];
  string employeeNames[10];
  double lowestPay;

  //for loop to store and add employee names and pays each to seperate arrays
  for (int i = 0; i < 10; i++) {
    double employeePay = 0;
    for (int j = 0; j < 4; j++) {
      employeePay += emps[i].wages[j];
      employeePays[i] = employeePay;
      employeeNames[i] = emps[i].first + " " + emps[i].last;
    }
  }
  
  //for loop to compare values in array to find lowest paid employee
  for (int i = 0; i < 10; i++) {
    if (lowestPay > employeePays[i]) {
      lowestPay = employeePays[i];
      employeeName = employeeNames[i];
    }
  }
  
  //displays the lowest paid employee and their name
  cout << "The lowest paid employee, " << employeeName
       << " has a total pay of $" << lowestPay << endl;
}

//function to find sum of all the employee pays
void sumOfAllEmployeePay() {
  double sumOfEmployeePay = 0;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 4; j++) {
      sumOfEmployeePay += emps[i].wages[j];
    }
  }
  // prints the sum of all the wages of employees
  cout << "The sum of all the employee pays is equal to: "
       << "$" << sumOfEmployeePay << endl;
}

//finds the avergae employee pay per month
void averageEmployeePayMonthly() {

  // initialize an array to store monthly sums
  double monthlyEmployeeSum[4] = {0}; 

  // Calculate the monthly sums for all employees
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 4; j++) {
      monthlyEmployeeSum[j] += emps[i].wages[j];
    }
  }

  // Calculate and display the monthly averages for all employees
  for (int month = 0; month < 4; month++) {
    double monthlyAveragePay = monthlyEmployeeSum[month] / 10;
    cout << "Monthly average pay for the employees for month " << (month + 1)
         << ": $" << monthlyAveragePay << endl;
  }
}
