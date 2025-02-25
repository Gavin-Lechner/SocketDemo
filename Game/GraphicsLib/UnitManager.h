#pragma once

using namespace std;


#include <vector>
#include "Vector2D.h"
#include "Unit.h"
#include "Animation.h"

class UnitManager
{
private:
	vector<Unit*> mUnits;
	vector<int> deletedUnits;
	bool mCurrentlyPaused;

public:
	UnitManager();
	~UnitManager();

	void cleanup();

	//ADD UNIT
	void addUnit(Unit* newUnit);
	void addUnit();
	void addUnit(int x, int y);
	void addUnit(int x, int y, Sprite sprite);
	void addUnit(int x, int y, Sprite sprite, int type);
	void addUnit(int x, int y, Sprite sprite, int type, int uID);
	void addUnit(int x, int y, Animation anim1, Animation anim2);

	//DELETE UNIT
	void deleteUnit(int unitLoc);
	void deleteAllUnits();
	void deleteRandomUnit();
	void deleteUnit(Unit* delUnit);
	void deleteUnitID(int id);
	void erase(int mouseX, int mouseY, const int UNIT_WIDTH, const int UNIT_HEIGHT);
	void clear();

	//GET UNIT
	Unit* getUnit(int unitLoc);
	Unit* getLastUnit();
	Unit* getUnitWithID(int id);

	//SET ANIMATIONS
	void setUnitAnim(Unit* unit, int anim);
	void setUnitAnim(int unitLoc, int anim);
	void setUnitAnim(int anim);

	//ADD ANIMATIONS
	void addUnitAnim(Animation anim);
	void addUnitAnim(Animation anim, Unit* unit);
	void addUnitAnim(Animation anim, int unitLoc);

	//GET ANIMATIONS
	int getUnitAnim(int unitLoc);
	int getUnitAnim(Unit* unit);

	//PAUSE ANIMATIONS
	void pauseAnim();
	void pauseAnim(int unitLoc);
	void pauseAnim(Unit* unit);
	bool isPaused();

	//GAME FUNCTIONS
	void update(double deltaTime);
	void draw(GraphicsSystem* gSystem);
	void updatePositions(int xVel, int yVel);

	vector<vector<int>> getAllUnitsLocation();
	vector<int> getDeletedUnits();
	int* getAllUnitsTypes();
	Unit* getAllUnits();
	int getUnitCount();
};