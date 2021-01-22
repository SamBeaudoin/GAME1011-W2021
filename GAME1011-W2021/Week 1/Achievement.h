#pragma once
#include <string>

using namespace std;


class Achievement
{
private:
	string m_title, m_descrip, m_value;

public:

	Achievement()
	{

	}
	void setTitle(string title)
	{
		m_title = title;
	}
	void setDescrip(string descrip)
	{
		m_descrip = descrip;
	}
	void setValue(string value)
	{
		m_value = value;
	}
	string getTitle()
	{
		return m_title;
	}
	string getDescrip()
	{
		return m_descrip;
	}
	string getValue()
	{
		return m_value;
	}

};