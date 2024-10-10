#include <iostream>
#include <vector>
#include <unordered_set> // duplicate removal
#include <algorithm>
#include <string>

struct Player
{
	std::vector<int> expectedHand;
	bool isComputer = false;
	std::vector<int> hand; // 2 through 14
	Player(const int HAND_SIZE, const bool IS_COMPUTER)
	{
		hand.reserve(HAND_SIZE);
		isComputer = IS_COMPUTER;
	}

	void removeCardWithValue(const int CARD_TO_REMOVE)
	{
		for (auto i = hand.begin(); i != hand.end(); ++i)
		{
			if (*i == CARD_TO_REMOVE)
			{
				hand.erase(i);
				i--;
			}
		}
	}

	bool checkForCard(const int CARD_REQUESTED)
	{
		for (const auto i : hand)
		{
			if (i == CARD_REQUESTED) return true; // if we have the wanted card
		}
		return false;
	}

	bool removeDuplicates()
	{
		bool werePairsFound = false;
		std::unordered_set<int> testSet;
		for (auto i = hand.begin(); i != hand.end(); ++i)
		{
			if (!testSet.insert(*i).second)
			{
				hand.erase(i);
				i--;
				werePairsFound = true;
			}
		}
		return werePairsFound;
	}

	void askForCard(const int CARD_REQUESTED, Player& AskedPlayer)
	{
		if (!checkForCard(CARD_REQUESTED))
		{
			std::cout << "You must have a card to ask for it.\n";
			return;
		}
		if (!AskedPlayer.checkForCard(CARD_REQUESTED))
		{
			std::cout << "They didn't have a(n) " << CARD_REQUESTED << ".\n";
			return;
		}
		expectedHand.push_back(CARD_REQUESTED);
		removeCardWithValue(CARD_REQUESTED);
		AskedPlayer.removeCardWithValue(CARD_REQUESTED);
		std::cout << "They had a(n) " << CARD_REQUESTED << ".\n";
	}

	void sort()
	{
		std::sort(hand.begin(), hand.end());
	}

    static char cardSymbol(const int card)
	{
		switch (card)
		{
		    case 11:
			    return 'J';
			    break; // not necessary but /shrug
    		case 12:
    			return 'Q';
    			break;
    		case 13:
    			return 'K';
    			break;
    		case 14:
    			return 'A';
    			break;
    		case 10:
    			return 'T'; // '10' is not a char. sorry.
    			break;
    		default:
    			return card + 48; // ascii offset
		}
    }

	std::string generateHandString()
	{
		if (hand.size() == 0) return ""; // shouldn't ever happen
        std::string functionOutput = "";
        for (auto i = hand.begin(); i != hand.end(); ++i)
        {
            functionOutput += *i;
            if (i != hand.end()) functionOutput += ", ";
        }
        return functionOutput;
	}

	static void checkWinCondition(const std::vector<Player>& playerList)
	{
        int winner = -1; // no win
        for (int i = 0; i < playerList.size(); i++)
        {
            if ((playerList[i].hand.size() == 0) && (winner == -1))
            {
                winner = i;
            }
        }
        if (winner != -1)
        {
            std::cout << "Player " << winner << " won!!!\n";
            std::exit(0); // /shrug
        }
	}
};

void Player::playerTurn(std::vector<Player>& playerList)
{
    removeDuplicates();
    int askedPlayerNumber, askedCard;
    // sort();
    std::cout << "Your cards are: " << generateHandString() << '\n';
    
}

void Player::computerTurn(std::vector<Player>& playerList)
{
    
}
