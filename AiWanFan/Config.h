#pragma once

#include <OgreConfigFile.h>
#include <OgreStringConverter.h>

using namespace Ogre;

class Config
{
public:
	static String get(String section, String key, String default="");
	static int getInt(String section, String key, int default=0);
	static Real getReal(String section, String key, Real default=0.0);
	static bool getBool(String section, String key, bool default=FALSE);
};
