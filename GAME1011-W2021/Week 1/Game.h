#pragma once
#include <string>

class Achievement;
using namespace std;

class Game
{
private:
	string m_name, m_publi, m_devel;

public:
	Achievement ach_array[25]{};
	Achievement* p_achievement = ach_array;
	Game()
	{

	}
	void setName(string name)
	{
		m_name = name;
	}
	void setPubli(string publi)
	{
		m_publi = publi;
	}
	void setDevel(string devel)
	{
		m_devel = devel;
	}
	string getName()
	{
		return m_name;
	}
	string getPubli()
	{
		return m_publi;
	}
	string getDevel()
	{
		return m_devel;
	}

	
};
