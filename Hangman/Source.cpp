#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>
#include <set>
#include <algorithm>
#include <windows.h>
const int HEIGHT=25;
const int WIDTH=80;
using namespace std;

bool draw(string pass, int error, set<char> index, set<char> alph)
{
	
	int letcount;//kinda a shity var.
	set<char>::iterator it = alph.begin();
	int count = 0;
	int next = 0;
	bool space = true;
	for (int height = 0; height < HEIGHT; height++)
	{
		
		cout << "\t";
		for (int width = 0; width < WIDTH; width++)
		{
			space = true;
			if (height >= 1 && width == 0)
			{
				cout << "|";// Left border
				space = false;
			}
			if (height == 0 && (width < 50 || width >= 59))  
			{
				cout << "_";// top border
				space = false;
			}
			if ((height == 1 || height == 2) && (width == 50))
			{
				cout << "|";// Rope
				space = false;
			}
			if (error >= 1&&height==3&&width==50)
			{
				cout << "O";// face
				space = false;
			}
			if (error >= 2 && height == 4 && width == 50)
			{
				cout << "|";//body
				space = false;
			}
			if (error >= 3 && height == 4 && (width == 49||width==51))
			{
				cout << "_";//arms
				space = false;
			}
			if (error >= 4 && height == 5 && width == 50)
			{
				cout << "^";// hip
				space = false;
			}
			if (error >= 5 && height == 6 && width == 49)
			{
				cout << "/";// leg
				space = false;
			}
			if (error >= 6 && height == 6 && width == 51)
			{
				cout << "\\";// leg
				space = false;
			}

			if ((height >= 1 && height <= 10) && (width == 59 || width == 79))
			{
				cout << "|";// border for character box
				space = false;
			}
			if (height == 10 && width > 59 && width < 79)
			{
				cout << "_";
				space = false;
			}
			if (height == 1 + next && (width > 59 && width <= 67))
			{

				if (it != alph.end())
				{
					cout << *it;
					space = false;
					it++;
					count++;
					if (count == 6)
					{
						count = 0;
						next++;
					}
				}
			}
			if (height == 11 && width == 59)
			{
				cout << "YOU HAVE " << 7-error << " CHANCES LEFT";// If i add more things, need to change this.
				space = false;
			}
			if(space)
			{
				cout << " ";
			}
			
		}
		cout << endl;
	}
	letcount = 0;
	cout << endl << endl;
	cout << "\t\t\t\t";
	for (int x=0;x<pass.size();x++)
	{
		if (index.find(pass.at(x))!=index.end())
		{
			letcount++;
			char c = toupper(pass.at(x));
			cout << " " <<c<< "  ";
		}
		else
		{
			cout << "    ";
		}
	}

	if (pass.size() == letcount || (7 - error == 0))// Will not work for words that reepat
	{
		return true;
	}

	cout <<endl<< "\t\t\t\t";
	for (int i = 0; i < pass.length(); i++)
	{
		cout << "___ ";
	}
	cout << endl<< "\t\t\tEnter a letter you'd like to guess!:  ";;
	return false;
}




char getinput(set<char>& al)
{
	string input;
	bool error = true;
	while (error)
	{
		error = false;
		getline(cin, input);
		if (input.size() != 1 || !isalpha(input.at(0)) || al.find(tolower(input.at(0)))!=al.end())// Check if this is right size, was counting null
		{
			error = true;
			cout << "Please retry an input. One character please and no repeats!" << endl;
		}
	}
	return tolower(input.at(0));
}
string guessword()
{
	string testword;
	char guess;
	cout << endl << "Welcome to Console Hangman! Goodluck!" << endl;
	do
	{
		cout << "Do you want to set the guessed word? (Y/N)" << endl;
		cin >> guess;		
		cin.ignore(100, '\n');
		cin.clear();
	} while (guess != 'Y' && guess != 'N');
	
	if (guess == 'Y')
	{
		cout << "Enter the word you want entered.(One a single word.)" << endl;
		cin >> testword;
		cin.ignore(100, '\n');
		cin.clear();
		transform(testword.begin(), testword.end(), testword.begin(), ::tolower);// Turns string to lowercase
		return testword; //no error checking.
	}
	else if (guess == 'N')
	{
		testword = "guardians";
		
		return testword;
	}
	else
	{
		cout << "Please enter one character in caps. Y or N." << endl;
	}
	// Ask whether they want random generated word
	// Or if they want to input word.
}

int main()
{
	set <char> index;
	int sol[26];
	bool finish = false;
	int error = 0;
	set<char> alphabet;
	char guess;
	string testword;
	testword = guessword();

	finish = draw(testword, error, index, alphabet);//
	while (!finish)
	{

		guess = getinput(alphabet);
		alphabet.insert(guess);
		size_t loc = testword.find(guess); // Checking if the letter is in the word
		if (loc == string::npos)// If it is, signal error
		{
			error++;
		}
		else// else add to set to draw in. 
		{
			index.insert(guess);
		}
		finish = draw(testword, error, index, alphabet);
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	if (error <7)
	{
		cout << "Thanks for playing.Congratulations. You won!";
	}
	else
	{
		cout << "You lost. Remember to blame the player not the game! Thanks for playing!";
	}
}
