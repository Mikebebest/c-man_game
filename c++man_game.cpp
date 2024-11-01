/*
#include <iostream>
#include <string>
#include <random>
#include <vector>
using namespace std;

namespace WordList
{
	vector<string> randomList = { "mystery","broccoli","account","almost","spaghetti","opinion","beautiful","distance","luggage" };

}

class Session
{

public:
	string randomWordPick(const vector<string>& wordlist);
};

string Session::randomWordPick(const vector<string>& wordlist)
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> dist(0, wordlist.size() - 1);

	size_t randomIndex = dist(gen);


	return wordlist[randomIndex];
}

void checkTheLetter(string& guesslist, char guess)
{
	string alreadyGuess = guesslist;
	char myGuess = guess;

	if (guesslist.find(myGuess) != string::npos)
		cout << "You already guessed that. Try again.";
	else
		guesslist += guess;
}



void gameState(const string word, const string guesslist)
{
	string answerWord = word;
	string guessList = guesslist;
	cout << guessList;
	for (int i = 0; i < answerWord.size(); i++)
		if (guessList.find(answerWord[i] != string::npos))
			cout << answerWord[i];
		else
			cout << "_";
}

char getPlayerInput()
{
	char c = '0';

	while (true)
	{
		cout << "\nEnter your next letter: " ;
		cin >> c;
		if (static_cast<int>(c) > 96 && static_cast<int>(c) < 123)
		{
			cout << "You entered: " << c << endl;
			break;
		}

		else
		{
			cout << "That's wasn't a valid input. Try again.";
		}

	}
	return c;
}

int main()
{
	cout << "Welcome to C++man (a variant of Hangman)" << endl;
	cout << "To win: guess the word. To lose: run out of pluses." << endl;

	Session randWord;
	string randomWord = randWord.randomWordPick(WordList::randomList);
	string plyarGuess = "";

	int count = 6;
	while(count >0)
	{
		cout << "\nThe word is: ";
		gameState(randomWord, plyarGuess);
		char playerGuess = getPlayerInput();
		checkTheLetter(plyarGuess, playerGuess);

		count--;
	}

	return 0;
}
*/

