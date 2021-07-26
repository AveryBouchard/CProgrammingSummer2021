/* add supporting structures - expect many structure types here ... date is good example */
struct date       
{            
    int month;            
    int day;            
    int year;      
}; 

struct person
{
    char firstName[50];
    char lastName[50];
    struct date birthday;
    char role[50];
    struct movie movieAppearances [100];
};

struct cast
{
    struct person mainActor;
    struct person supportingActor;
    struct person actors[20];
    struct person director;
};



struct movie      
{                                   
    struct date releaseDate;    // the date the movie was released */
    struct cast cast;           // the list of actors  
    int starRating;             // the number of stars (out of 5) the movie received
    char title [100];           // the title of the movie 
    char description[2000];     // a short description of the movie
    char country[50];           // country the movie was made in
    int boxOfficeEarnings;      // the amount the movie made in the theater
    char language[50];          // language the movie is in
    float budget;               // the amount the movie took to make
    struct movie similarMovies[10]; // 10 movies that are like this movie
    
};      

int main  (  )      
{
    struct movie myMovie [1000];    /* nothing else needs to be added to main */             
    return (0);       
};