//define global structure for name
struct name
{
    char firstName[50];
    char middleInitial[3];
    char lastName[50];
};

//define global structure for employee
struct employees
{
    struct name employeeName;
    long int clockNumber;
    float hourlyWage;
    float hoursWorked;
    float otHours;
    float gross;
};

// global constants
#define SIZE 5            /* Number of employees to process <-- change this for more or less employees*/
#define STANDARD_HOURS 40 /* standard 40 hour work week */
#define OT_RATE 1.5       /* multiply OT hours by this number */

// function prototypes
void getHours(struct employees *pointer, int size);
void calcOvertimeHours(struct employees *pointer, int size);
void printTableHeader();                                // we can pass the employee structure as a parameter to each function
void calcGrossPay(struct employees *pointer, int size); // instead of passing each variable individually
void printEmployeeTable(struct employees *pointer, int size);
void printTotalsAndAverages(struct employees *pointer, int size);