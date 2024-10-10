#include <iostream>
#include <vector>
#include <unordered_set> // duplicate removal
#include <algorithm>
#include <string>

struct Player
{
	std::vector<int> expected_hand;
	bool is_computer = false;
	std::vector<int> hand; // 2 through 14
	Player(const int HAND_SIZE, const bool IS_COMPUTER)
	{
		hand.reserve(HAND_SIZE);
		is_computer = IS_COMPUTER;
	}

	void remove_card(const int CARD_TO_REMOVE)
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

	bool check_for_card(const int card_requested)
	{
		for (const auto i : hand)
		{
			if (i == card_requested) return true; // if we have the wanted card
		}
		return false;
	}

	bool remove_duplicates()
	{
		bool were_pairs_found = false;
		std::unordered_set<int> test_set;
		for (auto i = hand.begin(); i != hand.end(); ++i)
		{
			if (!test_set.insert(*i).second)
			{
				hand.erase(i);
				i--;
				were_pairs_found = true;
			}
		}
		return were_pairs_found;
	}

	void ask_for_card(const int CARD_REQUESTED, Player& asked_player)
	{
		if (!check_for_card(CARD_REQUESTED))
		{
			std::cout << "You must have a card to ask for it.\n";
			return;
		}
		if (!asked_player.check_for_card(CARD_REQUESTED))
		{
			std::cout << "They didn't have a(n) " << CARD_REQUESTED << ".\n";
			return;
		}
		expected_hand.push_back(CARD_REQUESTED);
		remove_card(CARD_REQUESTED);
		asked_player.remove_card(CARD_REQUESTED);
		std::cout << "They had a(n) " << CARD_REQUESTED << ".\n";
	}

	void sort()
	{
		std::sort(hand.begin(), hand.end());
	}

	std::string generate_hand_string()
	{
		if (hand.size() == 0) return ""; // shouldn't ever happen

	}

	bool check_win_condition()
	{
		return hand.size() == 0;
	}
};
