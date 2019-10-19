#include "match.h"


Match::Match()
{
}

Match::Match(Team* homeTeam, Team* awayTeam, Referee* referee)
	: homeTeam(homeTeam), awayTeam(awayTeam), referee(referee)
{
	result[0] = 0;
	result[1] = 0;
	++(*referee);
	this->playMatch();
	if (result[0] > result[1]) // Home wins
		(*homeTeam) += 3;
	else if (result[0] < result[1]) // Away wins
		(*awayTeam) += 3;
	else // Draw
	{
		(*awayTeam) += 1;
		(*homeTeam) += 1;
	}

}

void Match::playMatch()
{
	if (homeTeam != nullptr && awayTeam != nullptr)
		if (homeTeam->isReady() && awayTeam->isReady())
		{
			srand(time(0));
			int r=0, scoreIndex=0;
			Player** currLineup;
			int totalScore = (rand() % MAX_GOALS_IN_MATCH); // total goals in this match
			while (totalScore > 0)
			{
				scoreIndex = (rand() % (LINEUP_MAX_SIZE - 1)); // Generates a number [0 , LINEUP_MAX_SIZE - 1]
				r = (rand() % 10) + 1;
				if (r < 6)
				{
					currLineup = homeTeam->getLineup();
					++(result[0]);
				}
				else
				{
					currLineup = awayTeam->getLineup();
					++(result[1]);
				}

				std::cout << currLineup[scoreIndex]->getName() << " of " << currLineup[scoreIndex]->getTeam()->getName() << " Has scored a goal." << std::endl;
				++(*currLineup[scoreIndex]);
				--totalScore;
			}
		}
}

Match::~Match()
{

}

void Match::show() const
{
	std::cout << homeTeam->getName() << " vs " << awayTeam->getName();
	std::cout << " Endded with score " << result[0] << " - " << result[1] << std::endl; //bug here: result[1] contains garbage
	//std::cout << "Referee: " << std::endl;
	referee->show();
}
