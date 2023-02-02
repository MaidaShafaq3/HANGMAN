// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int check(char letter, string rand_name, string& unknown) {

	int length = rand_name.length();
	int count = 0;

	for (int i = 0; i < length; i++) {
		/*if (letter == unknown[i])
			return 0;*/
		if (letter == rand_name[i]) {
			unknown[i] = letter;
			count++;
		}
	}
	return count;
}

void triesleft(int tries) {
	switch (tries) {
	case 1:
		cout << "      (    " << endl;
		break;
	case 2:
		cout << "      ( )   " << endl;
		break;
	case 3:
		cout << "      ( )   " << endl;
		cout << "      / " << endl;
		break;
	case 4:
		cout << "      ( )   " << endl;
		cout << "      /| " << endl;
		break;
	case 5:
		cout << "      ( )   " << endl;
		cout << "      /|\\ " << endl;
		break;
	case 6:
		cout << "      ( )   " << endl;
		cout << "      /|\\ " << endl;
		cout << "       |" << endl;
		break;
	case 7:
		cout << "      ( )   " << endl;
		cout << "      /|\\ " << endl;
		cout << "       |" << endl;
		cout << "      / " << endl;
		break;
	case 8:
		cout << "      ( )   " << endl;
		cout << "      /|\\ " << endl;
		cout << "       |" << endl;
		cout << "      / \\ " << endl;
		break;
	default:
		cout << endl;
	}
}

int main() {
	char choice, letter;
	string names[20] = { "turkey","pakistan","indonesia","korea","malaysia","oman","egypt","afghanistan","bahrain","kuwait","malta","mexico","spain","qatar","russia","china" };
	string rand_name;
	srand(time(NULL));

	do {
		system("cls");
		cout << "\n\t\t------------------------- THIS IS HANGMAN -------------------------\t\t\n\t\t^^^^^^^^^^^^^^^^^^^^^^ ENJOY PLAYING THIS GAME ^^^^^^^^^^^^^^^^^^^^^^";
		cout << "\n\n\t\t``````````````````````````````` LET'S BEGIN !!! ```````````````````````````````";
		int tries = 0;

		int n = rand() % 16;
		rand_name = names[n];

		string unknown(rand_name.length(), '.');

		int max_tries = 8;

		while (max_tries != 0) {
			triesleft(tries);
			cout << "\n\nYou have " << max_tries << " tries to win the game!\n";
			cout << "\n\t\t\t\t\t\t" << unknown << "\n\nEnter a letter: ";
			cin >> letter;

			system("cls");

			if (check(letter, rand_name, unknown) == 0) {
				max_tries--;
				cout << "\n\nSORRY YOU LOST ONE LIFE AND YOU'RE LEFT WITH " << max_tries << " TRIES\n";
				tries++;
			}
			else {
				cout << "\n\nYOU ENTERED THE CORRECT LETTER\n";
			}

			cout << "\t\t\t\t\t\t" << unknown << endl;

			if (rand_name == unknown) {
				cout << "\n\n************************         ^_^     CONGRATULATIONS!! YOU GUESSED IT RIGHT    ^_^          ************************";
				cout << "\n\n~~~~~~~~~~~~~~~~~~~~               The correct answer is " << rand_name << "               ~~~~~~~~~~~~~~~~~~~~" << endl;
				break;
			}
			if (max_tries == 0) {
				triesleft(tries);
				cout << "\n\n----------!!!!!!!!!--------- OOPS!!!YOU LOST IT ----------!!!!!!!!!---------";
				cout << "\n\n----------!!!!!!!!!--------- The correct answer is " << rand_name << " ----------!!!!!!!!!---------" << endl;
				break;
			}

		}
		cout << "\n\nDO YOU WANT TO PLAY AGAIN?\n\nIF YES, PRESS 'Y' OR 'y': ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

	cout << "\n\nYOU ARE OUT OF THE GAME!!";
}