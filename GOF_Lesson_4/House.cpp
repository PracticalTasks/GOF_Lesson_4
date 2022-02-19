
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

# define START_HOUSE 3

House::House()
{
	for (int i{}; i < HOUSE_HIGHT; i++)
	{
		for (int j{}; j < HOUSE_WIDTH; j++)
		{
			look[i][j] = 0;
		}
	}
}

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	MyTools::ScreenSingleton::getInstance().SetColor(CC_Yellow);
	for (int i{ HOUSE_HIGHT - 1 }, k{}; i >= 0; k++, i--)
	{
		ScreenSingleton::getInstance().GotoXY(x, y - i);
		for (int j{}; j < HOUSE_WIDTH; j++)
		{
			cout << this->look[k][j];
		}
	}
}

HouseBuilderA::HouseBuilderA()
{
	house = new House;
	this->setHouse();
	this->setRoof();
	this->setPipe();

}
void HouseBuilderA::setHouse()
{
	for (int i{START_HOUSE}; i < HOUSE_HIGHT; i++)
	{
		for (int j{}; j < HOUSE_WIDTH; j++)
		{
			if (i == START_HOUSE)
			{
				house->look[i][j] = '#';
				continue;
			}
			if (i == HOUSE_HIGHT - 1)
			{
				house->look[i][j] = '#';
				continue;
			}
			if (j == 0 || j == HOUSE_WIDTH - 1)
				house->look[i][j] = '#';
			else
				house->look[i][j] = ' ';
		}
	}
}

void HouseBuilderA::setRoof()
{
	for (int i{1}; i < START_HOUSE; i++)
	{
		for (int j{}; j < HOUSE_WIDTH; j++)
		{
			if ((i == 1 && j > 1) && (i == 1 && j < HOUSE_WIDTH - 2))
			{
				house->look[i][j] = '#';
				continue;
			}
			else if ((i == 2 && j < 2 ) || (i == 2 && j > HOUSE_WIDTH - 3))
			{
				house->look[i][j] = '#';
				continue;
			}
			else
				house->look[i][j] = ' ';

		}
	}
}

void HouseBuilderA::setPipe()
{
	for (int i{}; i < HOUSE_WIDTH; i++)
	{
		if (i > 7 && i < 10)
		{
			house->look[0][i] = '#';
			continue;
		}
		house->look[0][i] = ' ';
	}
}
