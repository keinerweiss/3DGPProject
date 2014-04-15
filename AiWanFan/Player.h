#pragma once

#include "GameObject.h"

using namespace Ogre;

class Player : public GameObject
{
public:
	Player(SceneManager* sceneMgr, SceneNode* parentNode);
	virtual ~Player(void);
};

