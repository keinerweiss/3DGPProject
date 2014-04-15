#include "GameObject.h"

unsigned int GameObject::nameIndex = 0;

GameObject::GameObject(SceneManager* sceneMgr, SceneNode* parentNode)
{
	mSceneMgr = sceneMgr;
	if(parentNode == NULL) {
		parentNode = mSceneMgr->getRootSceneNode();
	}
	mParentNode = parentNode;
	mRadius = 10;
	mMass = 1.0;
	mVelocity = Vector3(0, 0, 0);
	mSpeedFactor = 1.0;
	mInitDirection = Vector3(1, 0, 0);

	mMaxLifeTime = 10;
	mLifeTime = mMaxLifeTime;
	mIsAlive = false;
	mTime = 0;
	mRandSpeed = (rand()%100)/100.0;
	mAmplitude = 20;
	mAnimationState = 0;
}


GameObject::~GameObject(void)
{
}

void GameObject::translate(const Vector3 &v)
{
	mSceneNode->translate(v);
}

void GameObject::setTarget(GameObject* a_Target)
{
	mTarget = a_Target;
}

void GameObject::setVisible(bool flg)
{
	mSceneNode->setVisible(flg);
}

void GameObject::setVisibilityFlags(unsigned int m)
{
	mEntity->setVisibilityFlags(m);
}

void GameObject::makeAlive(bool flg)
{
	mIsAlive = flg;
	if (flg) {
		mSceneNode->setVisible(true);
	} else {
		mSceneNode->setVisible(false);
	}
}


void GameObject::setLife(Real cLife, Real cMaxLife)
{
	mLifeTime = cLife;
	if (cMaxLife > 0) {
		mMaxLifeTime = cMaxLife;
	}
}

bool GameObject::isAlive() const
{
	return mIsAlive;
}


void GameObject::update(const Ogre::FrameEvent& evt)
{

}

void GameObject::createGameObject(const String &name, const String &meshName)
{
	mEntity = mSceneMgr->createEntity(generateName(name), meshName);
	mSceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	mSceneNode->getUserObjectBindings().setUserAny("GameObject", Any(this));
	mSceneNode->attachObject(mEntity);
}

Ogre::String GameObject::generateName(const Ogre::String& name)
{
	GameObject::nameIndex++;
	return name + "_go_" + Ogre::StringConverter::toString(static_cast<int>(GameObject::nameIndex));
}

void GameObject::scale(Real sx, Real sy, Real sz)
{
	mSceneNode->scale(sx, sy, sz);
}


void GameObject::setSpeedFactor(Real f)
{
	mSpeedFactor = f;
}

void GameObject::setPosition(const Vector3 &pos)
{
	mSceneNode->setPosition(pos);
}

void GameObject::setInitPosition(const Vector3 &pos)
{
	mInitPosition = pos;
}

void GameObject::setVelocity(const Vector3 &v)
{
	mVelocity = v;
}

void GameObject::rotateToPosition(Vector3 targetPosition) {
	Vector3 direction = targetPosition - mSceneNode->getPosition();
	Vector3 src = mSceneNode->getOrientation() * Vector3::UNIT_X;
	src.y = 0;
	direction.y = 0;
	src.normalise();
	Real mDistance = direction.normalise();
	Quaternion quat = src.getRotationTo(direction); 
	mSceneNode->rotate(quat);
}