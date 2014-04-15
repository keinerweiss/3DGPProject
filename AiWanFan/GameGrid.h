#pragma once

#include "GameObject.h"

using namespace Ogre;

class GameGrid :
	public GameObject
{
public:
	GameGrid(SceneManager* sceneMgr, SceneNode* parentNode);
	virtual ~GameGrid(void);

protected:
	GameObject* walls;
	GameObject* enemies;
};