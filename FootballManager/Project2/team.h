#ifndef __TEAM_H
#define __TEAM_H
#include "person.h" // For NAME_SIZE definition.
#include "coach.h"
#include "manager.h"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <vector>

#define LINEUP_MAX_SIZE 5 // size of the team lineup 
#define BENCH_SIZE_MULTI 3 // Multiplier for bench size.
// Added array for each role for toString purposes -Amit

class Coach;
class Player;
class Manager;
class Team 
{

public:
	Team(std::string name,
		Manager* manager = nullptr,
		Coach* coaches = nullptr,
		std::vector<Player*> lineup = std::vector<Player*>(),
		std::vector<Player*> benchPlayers = std::vector<Player*>(),
		int points=0);

	Team();
	void setManager(Manager* manger);
	void addCoach(Coach* coach);
	void addPlayer(Player* player);
	const Team& operator+=(int points); // Changed from operator+ confirmed with Riki it was a mistake.
	bool operator >=(const Team& otherTeam) const; //Team is bigger if team have more pointprivate:
	const std::string getName() const; // Added method for Player to display team name, as team name is private -Amit
	bool isReady() const; //  Check if lineup is full and team is ready for a match
	void show() const; // Print team's information to console.
	std::vector<Player*> getLineup() const;
	int getLineupSize();
	int getPoints() const;	//added  for printing- Asaf

private:

	std::string name;
	Manager * manager;
	Coach * coaches;
	std::vector<Player*> benchPlayers;
	std::vector<Player*> lineup;
	int points;
};

#include "player.h" // for forward declaration of player class.

#endif // !__TEAM_H
