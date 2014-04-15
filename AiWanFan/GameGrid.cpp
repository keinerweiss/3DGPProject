#include "GameGrid.h"


GameGrid::GameGrid(SceneManager* sceneMgr, SceneNode* parentNode) : GameObject(sceneMgr, parentNode)
{
	createGameObject("GridCenter", "cube.mesh");
}


GameGrid::~GameGrid(void)
{
}
