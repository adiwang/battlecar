#include "configfile.h"

#include <fstream>

std::string trim(std::string const& source, char const* delims = " \t\r\n")
{
	std::string result(source);
	std::string::size_type index = result.find_last_not_of(delims);
	if(index != std::string::npos)
		result.erase(++index);

	index = result.find_first_not_of(delims);
	if(index != std::string::npos)
		result.erase(0, index);
	else
		result.erase();
	return result;
}

bool ConfigFile::LoadConf(std::string const& configFile)
{
	std::ifstream file(configFile.c_str());
	if(!file) return false;

	std::string line;
	std::string name;
	std::string value;
	std::string inSection;
	int posEqual;
	while (std::getline(file,line))
	{
		if (! line.length()) continue;

		if (line[0] == '#') continue;
		if (line[0] == ';') continue;

		if (line[0] == '[')
		{
			inSection=trim(line.substr(1,line.find(']')-1));
			continue;
		}

		posEqual=line.find('=');
		name  = trim(line.substr(0,posEqual));
		value = trim(line.substr(posEqual+1));

		_content[inSection+'/'+name] = value;
	}
	return true;
}

std::string const& ConfigFile::Value(std::string const& section, std::string const& entry) const
{
	std::map<std::string, std::string>::const_iterator ci = _content.find(section + '/' + entry);

	if (ci == _content.end()) throw "does not exist";

	return ci->second;
}

std::string const& ConfigFile::Value(std::string const& section, std::string const& entry, std::string const& value)
{
	try
	{
		return Value(section, entry);
	} 
	catch(const char *)
	{
		return _content.insert(std::make_pair(section+'/'+entry, value)).first->second;
	}
}
