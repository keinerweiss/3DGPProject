#include "Config.h"

	String Config::get(String section, String key, String default) {
		static ConfigFile* config = new ConfigFile();
		static bool loaded = false;
		// TODO: re-read every 3 seconds ?
		if(!loaded) {
			config->load("config.txt", "=");
			loaded = true;
		}
		String ret = config->getSetting(key, section, default);
		return ret;
	}

	Real Config::getReal(String section, String key, Real default) {
		return StringConverter::parseReal(Config::get(section, key), default);
	}

	int Config::getInt(String section, String key, int default) {
		return StringConverter::parseInt(Config::get(section, key), default);
	}

	bool Config::getBool(String section, String key, bool default) {
		return StringConverter::parseBool(Config::get(section, key), default);
	}