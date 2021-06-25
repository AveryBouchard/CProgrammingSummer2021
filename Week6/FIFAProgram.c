//*************************************************************
// Program: FIFA Team Stats
//
// Description: This program takes in statistics from both the team's offense and defense
//                  and prints to the console a table with expanded statistics.
//*************************************************************

#include <stdio.h>


// initialize structure for all team statistics
struct teamStats
{
    float shotsOnGoalie;
    float goalsScoredAgainst;
    float goalieGamesWon;
    float goalieGamesLost;
    float scoringAttempts;
    float goalsScoredFor;
    float teamGamesWon;
    float teamGamesLost;
};

//main function begin
int main()
{
    // function prototypes
    void defenseStats(struct teamStats blueTeam);
    void offenseStats(struct teamStats blueTeam);

    // initialize structure
    struct teamStats blueTeam =
        {5, 2, 1, 1, 7, 3, 3, 4};

    // call functions
    defenseStats(blueTeam);

    offenseStats(blueTeam);

    return 0;
} //main function end


//*****************************************************************************************
//
// Function: defenseStats()
//
// Description: Takes in various stats from the defensive side and passes into formulas
//                  which further inspect the stats to ratios
//
// Parameters: Team Structure
//                  shotsOnGoalie - the number of shots the goalie had on him/her
//                  goalsScoredAgainst - how many goals the goalie let up
//                  goalieGamesWon - how many games were won with that goalie in net
//                  goalieGamesLost - how many games were lost with that goalie in net
//
// Returns: none. Results printed to console
//
//******************************************************************************************

void defenseStats(struct teamStats blueTeam)
{

    printf("Team Defense\n__________\n\nShots on Goalie: %f\nGoals Scored Against: %f\nGoalie Wins: %f\nGoalie Losses: %f\n\n", 
        blueTeam.shotsOnGoalie, blueTeam.goalsScoredAgainst, blueTeam.goalieGamesWon, blueTeam.goalieGamesLost);

    float goalieWinPercentage = 0.0;
    float goalieSavePercentage = 0.0;
    float goalieSaveRatio = 0.0;
    float goalieSaves = 0;

    goalieWinPercentage = blueTeam.goalieGamesWon / (blueTeam.goalieGamesWon + blueTeam.goalieGamesLost);
    goalieSaves = blueTeam.shotsOnGoalie - blueTeam.goalsScoredAgainst;
    goalieSavePercentage = goalieSaves / blueTeam.shotsOnGoalie;
    goalieSaveRatio = blueTeam.shotsOnGoalie / goalieSaves;

    printf("Win Percentage: %f\nSaves: %f\nSave Percentage: %f\nSave Ratio: %f\n\n\n", 
        goalieWinPercentage, goalieSaves, goalieSavePercentage, goalieSaveRatio);

}


//*****************************************************************************************
//
// Function: offenseStats()
//
// Description: Takes in various stats from the offensive side and passes into formulas
//                  which further inspect the stats to ratios
//
// Parameters: Team Structure
//                  scoringAttempts - the number of shots the offense took
//                  goalsScoredFor - how many goals the offense scored
//                  teamGamesWon - how many games were won 
//                  teamGamesLost - how many games were lost
//
// Returns: none. Results printed to console
//
//******************************************************************************************
void offenseStats(struct teamStats blueTeam)
{
    printf("Team Offense\n____________\n\nScoring Attempts: %f\nGoals Scored For: %f\nTeam Games Won: %f\nTeam Games Lost: %f\n\n", 
        blueTeam.scoringAttempts, blueTeam.goalsScoredFor, blueTeam.teamGamesWon, blueTeam.teamGamesLost);

    float scoringPercentage = 0.0;
    float scoringRatio = 0.0;
    float gamesWonPercentage = 0.0;

    scoringPercentage = (blueTeam.scoringAttempts - blueTeam.goalsScoredFor) / blueTeam.scoringAttempts;
    scoringRatio = blueTeam.scoringAttempts/ blueTeam.goalsScoredFor;
    gamesWonPercentage = blueTeam.teamGamesWon / (blueTeam.teamGamesWon + blueTeam.teamGamesLost);

    printf("Scoring Percentage: %f\nScoring Ratio: %f\nGames Won Percentage: %f\n\n", 
        scoringPercentage, scoringRatio, gamesWonPercentage);
}