#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>


//name space res
using std::cout;
using std::cin;
//flush prints out the characters 1 by 1
using std::flush;
using std::string;
//the thread makes the characters "sleep" until printed
using std::this_thread::sleep_for;
//the time for the lag is milliseconds
using std::chrono::milliseconds;
using std::endl;


//forward slow print
void slow_print(const string&, unsigned int);

int main()
{
	//seeding
	srand((NULL));

	system("title C.B.P.P");

	system("color 3F");

	string hewwo = "Welcome... To the Official CIA Code Breaking Practice Program...\n\n";
	slow_print(hewwo, 100);

	string shut = "Please unscramble these words to test your skills at decoding.\n";
	slow_print(shut, 60);

	string hint = "Enter 'hint' for a hint.\n";
	slow_print(hint, 60);

	string quit = "Enter 'quit' to quit the game.\n";
	slow_print(quit, 60);

	bool playAgain = false; //our flag / switch to paly again or not

	//remember each play is 3 turns

	do
	{
		//stuff here over and over as long as 'play it again' is true


	/*
	How to for loop
	1. where we start aka initilize the variable we will use
	2. where we go, where we stop
	3. How will you get there? We are going to get there one step at a time, or one turn in this case at a time
	*/


		for (int i = 0; i < 3; i++)
		{
			
			//enum = enumerator
			//defines enumerators for accessing the array
			enum fields { WORD, HINT, NUM_FIELDS };
			const int NUM_WORDS = 10;
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
			{"secret", "classified"},
			{"computer", "terminal"},
			{"agent", "james bond"},
			{"hack", "what hackers do"},
			{"law", "the rules we live by"},
			{"whisper", "what secrets are"},
			{"defrag", "reducing the fragmentation of files"},
			{"perish", "hewwo? Mr.Obama?"},
			{"bomb", "it go 'boom'"},
			{"coordinates", "numbered places on a map"},
			};


			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);
			//word to guess
			string theWord = WORDS[choice][WORD];
			//hint
			string theHint = WORDS[choice][HINT];

			//jumbles the characters
			string jumble = theWord;
			int length = jumble.size();
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}

			cout << "\nAgent you are on turn #" << i + 1 << " of 3.\n" << endl;

			cout << "The jumble is: " << jumble;

			string guess;
			cout << "\n\nYour guess: ";
			cin >> guess;

			if (guess == theWord)
			{
				cout << "\nCorrect.\n";
			}

			while ((guess != theWord) && (guess != "quit"))
			{
				if (guess == "hint")
				{
					cout << theHint;
				}
				else
				{
					cout << "\nIncorrect.\n";
				}

				cout << "\n\nYour guess: ";
				cin >> guess;
			}


		}//end of for loop

		cout << "\nWould you like to run the simulation again? (Y/N)";
		char playerChoice;
		cin >> playerChoice;


		if (playerChoice == 'y' || playerChoice == 'Y')
		{
			//flip play it again flag to true
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}

	} while (playAgain == true); //end of loop

	cout << "\nThanks for Playing!\n";

	system("pause");
	return 0;
}


//implementing slow print
void slow_print(const string& message, unsigned int millis_per_char)
{
	for (const char c : message)
	{
		//flush helps us put the text character by character
		cout << c << flush;
		//sleep_for maakes the characters lag for a specific amount of milliseconds.
		//you can choose how many milliseconds for the characters
		//millis_per_chr means that each character must wait the certain amount of time before printing 
		sleep_for(milliseconds(millis_per_char));
	}
}




