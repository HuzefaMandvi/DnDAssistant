#ifndef COMMAND_ROUTING_H
#define COMMAND_ROUTING_H

#include <iostream>
#include <Windows.h>
#include <MMSystem.h>
#include <time.h>
#include <string>
#include <random>

using namespace std;

//simple die roller with rand
void rollDie(int numDice, string dieType)
{
	int result = 0;
	for (int i=1; i<= numDice; i++)
	{
		int tempResult = 0;
		if (dieType == "d4" || dieType == "4")
			tempResult = rand() % 4 + 1;
		else if (dieType == "d6" || dieType == "6")
			tempResult = rand() & 6 + 1;
		else if (dieType == "d8" || dieType == "8")
			tempResult = rand() % 8 + 1;
		else if (dieType == "d10" || dieType == "10")
			tempResult += rand() % 10 + 1;
		else if (dieType == "d12" || dieType == "12")
			tempResult += rand() % 12 + 1;
		else if (dieType == "d20" || dieType == "20")
			tempResult += rand() % 20 + 1;

		cout << tempResult << " ";
		result += tempResult;
	}
	cout << "Total: " << result << endl;
}

//takes in user command, routes until quit
void routeCommand()
{
	bool quitCommand = false;
	int songNum;
	string userCommand;
	int numDice;
	string dieType;

	while(!quitCommand)
		{
			cin.clear();
			songNum = 1;
			cout << "Enter a command: ";
			cin >> userCommand;

			if(userCommand == "help")
			{
				cout << "Currently supported commands:" << endl << "help" << endl << "mute" << endl << "quit" << endl << endl << "tools:" << endl << "roll (number of dice) (die type)" << endl << endl << "sounds: " << endl << "battle" << endl << "creepy" << endl << "epic" << endl << "forest" << endl << "music" << endl <<  "ocean" << endl << "storm" << endl << "tavern" << endl;
			}

			else if(userCommand == "mute" || userCommand == "stop")
			{
				PlaySound(NULL, NULL, SND_ASYNC);
			}

			else if(userCommand == "quit" || userCommand == "q")
			{
				cout << "Until next time, adventurer." << endl;
				quitCommand = true;
			}
			
			else if(userCommand == "battle")
			{
				cout << "War will make corpses of us all - Faramir, brother of Boromir" << endl;
				
				//randomly choose a song and play it
				songNum = rand() % 2 + 1;

				if(songNum == 1)
				{
					PlaySound("resources/battle1.wav", NULL, SND_ASYNC | SND_LOOP);
				}
				else if(songNum == 2)
				{
					PlaySound("resources/battle2.wav", NULL, SND_ASYNC | SND_LOOP);
				}
			}

			else if(userCommand == "creepy")
			{
				cout << "There are some things that it is better to begin than to refuse, even though the end may be dark - Aragorn" << endl;
				
				//randomly choose a song and play it
				songNum = rand() % 2 + 1;

				if(songNum == 1)
				{
					PlaySound("resources/creepy1.wav", NULL, SND_ASYNC | SND_LOOP);
				}
				else if(songNum == 2)
				{
					PlaySound("resources/creepy2.wav", NULL, SND_ASYNC | SND_LOOP);
				}
			}

			else if(userCommand == "epic")
			{
				cout << "Death is just another path, one we all must take. The grey rain curtain of this world rolls back, and all turns to silver glass - Gandalf the Grey" << endl;
					songNum = rand() % 3 + 1;
					if(songNum == 1)
					{
						PlaySound("resources/epic1.wav", NULL, SND_ASYNC | SND_LOOP);
					}
					else if(songNum == 2)
					{
						PlaySound("resources/epic2.wav", NULL, SND_ASYNC | SND_LOOP);
					}
					else if(songNum == 3)
					{
						PlaySound("resources/epic3.wav", NULL, SND_ASYNC | SND_LOOP);
					}
			}

			else if(userCommand == "forest")
			{
				cout << "The road goes ever on on, down from the door where it began - Bilbo Baggins" << endl;
				songNum = rand() % 2 + 1;
				if(songNum == 1)
				{
					PlaySound("resources/forest1.wav", NULL, SND_ASYNC | SND_LOOP);
				}
				else if(songNum == 2)
				{
					PlaySound("resources/forest2.wav", NULL, SND_ASYNC | SND_LOOP);
				}

			}

			else if(userCommand == "music")
			{
				cout << "Tinuviel was dancing there, to music of a pipe unseen, and light of stars was in her hair - The Grey Havens" << endl;
				songNum = rand() % 3 + 1;
				if(songNum == 1)
				{
					PlaySound("resources/music1.wav", NULL, SND_ASYNC | SND_LOOP);
				}
				else if(songNum == 2)
				{
					PlaySound("resources/music2.wav", NULL, SND_ASYNC | SND_LOOP);
				}
				else if(songNum == 3)
				{
					PlaySound("resources/music3.wav", NULL, SND_ASYNC | SND_LOOP);
				}
			}

			else if(userCommand == "ocean")
			{
				cout << "To the sea, to the sea! The white gulls are crying, the wind is blowing, and the white foam is flying - Legolas's Song of the Sea" << endl;
				songNum = rand() % 1 + 1;

				if(songNum == 1)
				{
					PlaySound("resources/ocean1.wav", NULL, SND_ASYNC | SND_LOOP);
				}
			}

			else if(userCommand == "storm" | userCommand == "rain")
			{
				cout << "This is not the weather of the world. This is the device of of Sauron's making - Gandalf the Gray" << endl;
				PlaySound("resources/storm1.wav", NULL, SND_ASYNC | SND_LOOP);
			}

			else if(userCommand == "tavern" | userCommand == "pub" | userCommand == "inn")
			{
				cout << "Oh you can search far and wide, you can drink the whole town dry, but you'll never find a beer so brown, as comes from the Green Dragon! - Merry Brandybuck and Peregrin Took" << endl;
				songNum = rand() % 1 + 1;

				if(songNum == 1)
				{
					PlaySound("resources/tavern1.wav", NULL, SND_ASYNC | SND_LOOP);
				}
			}

			else if(userCommand == "test")
			{
				cout << "testing..." << endl;
				PlaySound("SystemStart", NULL, SND_LOOP | SND_ASYNC);
			}

			else if(userCommand == "roll")
			{
				cin >> numDice >> dieType;
				rollDie(numDice, dieType);
			}

			else
			{
				cout << "Sorry, I didn't recognize your command. Please try again or type 'help' for help." << endl;
			}

			cin.clear();
		}
}

#endif