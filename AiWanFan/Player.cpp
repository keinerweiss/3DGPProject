#include "Player.h"


Player::Player(SceneManager* sceneMgr, SceneNode* parentNode) : GameObject(sceneMgr, parentNode)
{
	createGameObject("Player", "robot.mesh");
	mSceneNode->yaw(Radian(Degree(90)));
}


Player::~Player(void)
{
}
