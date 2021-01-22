#include <iostream>
#include <string>
#include "Achievement.h"
#include "Game.h"
#include "Platform.h"

using namespace std;

int main()
{

	int platform_Choice, game_Choice, achieve_Choice;

	string userString;
	
	cout << "Welcome, we will be going through the following steps:"
		<< "\n1: Designate the size of each array. Platform/Game/Achievement"
		<< "\n2: Name and assign values to each of their properties."
		<< "\n\n*Note You may have up to 20 Platforms with 20 games each with 25 Achievements each";
	cout << "\n\n First, please enter the amount of Platforms you would like to create:" << endl;
	cin >> platform_Choice;

	Platform plat_array[20]{};
	Platform* p_platform = plat_array;
	
	cout << "Now please enter the following information for each Platform:\n";
	
	cin.ignore();

	for (int i = 0; i < platform_Choice; i++)
	{
	
		cout << "Please enter the Manufacturer for # " << i + 1 << endl;
		getline(cin, userString);
		p_platform[i].setManu(userString);
		
		cout << "Please enter the Name for # " << i + 1 << endl;
		getline(cin, userString);
		p_platform[i].setName(userString);
		
	}
	system("CLS");
	for (int y = 0; y < platform_Choice; y++)
	{
		cout << "\n\n Now please enter the amount of Games you would like to create for platform " << plat_array[y].getName() << endl;
		cin >> game_Choice;

		cin.ignore();
		
		for (int i = 0; i < game_Choice; i++)
		{

			cout << "Please enter the Name for Game # " << i+1 << endl;
			getline(cin, userString);
			p_platform[y].p_game[i].setName(userString);

			cout << "Please enter the Publisher for Game # " << i + 1 << endl;
			getline(cin, userString);
			p_platform[y].p_game[i].setPubli(userString);
			
			cout << "Please enter the Developer for Game # " << i + 1 << endl;
			getline(cin, userString);
			p_platform[y].p_game[i].setDevel(userString);
			
		}
	}

	system("CLS");
	
	for (int y = 0; y < platform_Choice; y++)
	{
		for (int i = 0; i < game_Choice; i++)
		{
			cout << "\n\nNow please enter the total number of achievements for the game: " << p_platform[y].p_game[i].getName() << endl;
			cin >> achieve_Choice;

			cin.ignore();

			for (int x = 0; x < achieve_Choice; x++)
			{

				cout << "Please enter the Title for Achievement # " << x + 1 << endl;
				getline(cin, userString);
				p_platform[y].p_game[i].p_achievement[x].setTitle(userString);

				cout << "Please enter the Description for Achievement # " << x + 1 << endl;
				getline(cin, userString);
				p_platform[y].p_game[i].p_achievement[x].setDescrip(userString);

				cout << "Please enter the Value for Achievement # " << x + 1 << endl;
				getline(cin, userString);
				p_platform[y].p_game[i].p_achievement[x].setValue(userString);

			}
		}
	}
	system("pause");
	system("CLS");

	cout << "Here is a compiled list of all your Platforms / Games / Achievements.\n" << endl;

	for (int y = 0; y < platform_Choice; y++)
	{
		if (!p_platform[y].getName().empty())
		{
			cout << "\nFor The Platform: " << plat_array[y].getName() << "\nMade by " << plat_array[y].getManu() << endl << endl;
		}
		for (int i = 0; i < game_Choice; i++)
		{
			if (!p_platform[y].game_array[i].getName().empty())
			{
				cout << "\nYou have The Following Game:\n" << plat_array[y].p_game[i].getName() << "\nPublished by " << plat_array[y].p_game->getPubli()
					 << "\nDeveloped by " << plat_array[y].p_game->getDevel() << endl << endl;
			}
			for (int x = 0; x < achieve_Choice; x++)
			{
				if (!p_platform[y].game_array[i].ach_array->getTitle().empty())
				{
					cout << "That has the Achievement:\n" << p_platform[y].game_array[i].ach_array->getTitle() << "\nWith the description: "
						<< p_platform[y].game_array[i].ach_array->getDescrip() << "\nWith a value of " << p_platform[y].game_array[i].ach_array->getValue() << endl << endl;
				}
			}
		}
	}

	cout << "\n\nThank you for using the Platform / Game / Achievement Program!\n\n";
	
	return 0;
}