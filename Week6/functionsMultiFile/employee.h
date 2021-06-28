//define global structure for employee
struct employees
{
    long int clockNumber;
    float hourlyWage;
    float hoursWorked;
    float otHours;
    float gross;
};

// global constants
#define SIZE (5)                /* Number of employees to process <-- change this for more or less employees*/
#define STANDARD_HOURS (40)     /* standard 40 hour work week */
#define OT_RATE (1.5)           /* multiply OT hours by this number */

// function prototypes
void getHours(struct employees employeeData[]);
void calcOvertimeHours(struct employees employeeData[]);
void printTableHeader();                                                    // we can pass the employee structure as a parameter to each function
void calcGrossPay(struct employees employeeData[]);                         // instead of passing each variable individually
void printEmployeeTable(struct employees employeeData[]);
void printTotalsAndAverages(struct employees employeeData[]);