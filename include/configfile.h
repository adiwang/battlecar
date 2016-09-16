#ifndef _CONFIG_FILE_H
#define _CONFIG_FILE_H

#include <string>
#include <map>


class ConfigFile
{
public:
	static ConfigFile& GetInstance() { static ConfigFile instance; return instance; }
	bool LoadConf(std::string const& configFile);
	std::string const& Value(std::string const& section, std::string const& entry) const;
	std::string const& Value(std::string const& section, std::string const& entry, std::string const& value);

private:
	ConfigFile() : _content() {}

private:
	std::map<std::string, std::string> _content;
};

#endif	// end _CONFIG_FILE_H
