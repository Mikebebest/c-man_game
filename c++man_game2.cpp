#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include "Random.h"

using namespace std;

namespace WordList
{
	vector<string_view> words{ "mystery","broccoli","account","almost","spaghetti","opinion","beautiful","distance","luggage" };

	string_view getRandomWord()
	{
		return words[Random::get(0,words.size() - 1)];
	}

}

class Session
{
private:
	string_view random_word{ WordList::getRandomWord() };
	string guess_list = "";
	string wrong_list = "";

public:
	string_view getWord() const { return random_word; };
	string_view getList() const { return guess_list; };
	string getWrongList();
	void setLetter(char& c);
	void setWrongLetter(char& c);
	int remainLife();	
	bool checkLetter(char c) const;
	//bool checkWrong(char c) const;
	bool isWordGuessed() const;
};

void Session::setLetter(char& c)
{
	if (guess_list.find(c) == string::npos)
		guess_list = guess_list + c;
}

void Session::setWrongLetter(char& c)
{
	if(wrong_list.find(c) == string::npos)
		wrong_list = wrong_list + c;
}

int Session::remainLife()
{
	return 6 - wrong_list.size();
}

string Session::getWrongList()
{
	return wrong_list;
}

bool Session::checkLetter(char c) const
{
	if (guess_list.find(c) != string::npos)
		return true;
	else
		return false;
}

/*
bool Session::checkWrong(char c) const
{
	return (random_word.find(c) == string::npos) && (wrong_list.find(c) == string::npos);
}
*/


bool Session::isWordGuessed() const
{
	for (char c : random_word)
	{
		if (guess_list.find(c) == string::npos) 
			return false;
	}
	return true; 
}


void gameState( Session& s)
{
	cout << "\nThe word is: ";
	string_view word = s.getWord();


	for (int i = 0; i < word.size(); i++)
		{
			if (s.checkLetter(word[i]))
				cout << word[i];
			else
				cout << "_";

		}
	cout << "   Wrong guesses: ";
	for (int i = 0; i < s.remainLife(); i++)
		cout << "+";

	for (char c : s.getWrongList())
		cout << c;

}

char getGuess(Session& s)
{
	while (true)
	{
		cout << "\nEnter your next letter: ";
		char c{};
		cin >> c;

		if (!cin)
		{
			cin.clear();
			cout << "That wasn't a valid input.  Try again.\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (c < 'a' || c > 'z')
		{
			cout << "That wasn't a valid input.  Try again.\n";
			continue;
		}
		if (s.checkLetter(c))
		{
			cout << "You already guessed that. Try again.\n";
			continue;
		}	

		
		return c;
	}
}

void handleTheResult(Session& s, char& c)
{
	string_view word = s.getWord();
	if (word.find(c) == string::npos)
	{
		cout << "No, \'" << c << "\' is not in the word! " << endl;
		s.setWrongLetter(c);
	}
	else
	{
		cout << "Yes, \'" << c << "\' is in the word! " << endl;
		s.setLetter(c);
	}
}



int main()
{
	cout << "Welcome to C++ game (a variant of Hangman)" << endl ;
	cout << "To win: guess the word. To lose: run out of pluses." <<endl;
	
	
	Session s{};

	;

	while(s.remainLife()>0)
	{
		gameState(s);
		char your_guess = { getGuess(s) };
		handleTheResult(s, your_guess);
		
		if (s.isWordGuessed())
		{
			cout << "\n\nCongratulations! You've guessed the word: " << s.getWord() << endl;
			break;
		}
	
	}
	if (s.remainLife() == 0)
	{
		cout << "\n\nGame Over! The correct word was: " << s.getWord() << endl;
	}

	
	system("pause");
	return 0;


}