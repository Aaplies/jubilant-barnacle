#include <vector>
#include <iostream>
#include <random>

struct Deck
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
	std::random_device randomDevice;

	Deck()
	{
		addCardsToDeck();
	}

    void removeCard(const int card)
    {
        auto iter = cards.begin() + card;
        cards.erase(iter);
    }

	int pickCard()
	{
		if (cards.size() == 0)
		{
			std::cout << "pickCard called on empty deck!\n"; // can happen with a lot of players
			std::exit(1);
		}
		std::uniform_int_distribution<> generateRandomNumber(0, cards.size()-1);
        const int CHOSEN_CARD_ADDRESS = generateRandomNumber(randomDevice);
	const int CHOSEN_CARD = cards.at(CHOSEN_CARD_ADDRESS); // .at() safer than []
        removeCard(CHOSEN_CARD_ADDRESS);
        return CHOSEN_CARD;
	}
};
