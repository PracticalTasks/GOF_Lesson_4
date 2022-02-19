#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

#define HOUSE_WIDTH 14
#define HOUSE_HIGHT 7


class House : public DestroyableGroundObject
{
public:
	House();
	bool isInside(double x1, double x2) const override;
	inline uint16_t GetScore() const override { return score; }
	void Draw() const override;

private:
	char look[HOUSE_HIGHT][HOUSE_WIDTH];
	const uint16_t score = 40;

	friend class HouseBuilderA;
};

class HouseBuilder
{
protected:

	virtual void setHouse() = 0;
	virtual void setRoof() = 0;
	virtual void setPipe() {};
	virtual void setWindow() {};

};

class HouseBuilderA : public HouseBuilder
{

public:
	House* house;
	
	HouseBuilderA();
	~HouseBuilderA() { delete house; };
	void setHouse() override;
	void setRoof() override;
	void setPipe() override;
	//void setWindow() override;

};