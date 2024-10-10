#include <vector>
#include <iostream>
#include <random>

struct deck
{
	void addCardsToDeck()
	{
		cards.reserve(52); // sorry for the 2040 folks when they change decks to be 54 cards
		for (int i = 0; i < 52; i++)
		{
			cards.push_back((i % 13) + 2);
		}
	}

	std::vector<int> cards;
	std::random_device random;

	deck()
	{
		addCardsToDeck();
	}

	int pickCard()
	{
		if (cards.size() == 0)
		{
			std::cout << "pickCard called on empty deck!\n"; // I don't think this can happen normally
			std::exit(1);
		}
		std::uniform_int_distribution<> generateRandomNumber(0, cards.size()-1);
	}

	static char cardSymbol(const int card)
	{
		switch (card)
		{
		case 11:
			return 'J';
			break;
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
};
