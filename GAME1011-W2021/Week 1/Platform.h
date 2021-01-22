#pragma once
#include <string>

class Game;
using namespace std;

class Platform
{
private:
	string m_name, m_manu;

public:
	Game game_array[20]{};
	Game* p_game = game_array;
	Platform()
	{

	}
	void setManu(string manu)
	{
		m_manu = manu;
	}
	void setName(string name)
	{
		m_name = name;
	}
	string getName()
	{
		return m_name;
	}
	string getManu()
	{
		return m_manu;
	}
	

};