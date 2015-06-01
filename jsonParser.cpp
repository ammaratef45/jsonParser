#include "jsonParser.h"

using namespace std;

JSONParser::JSONParser(){}
JSONParser::~JSONParser(){}


std::map<std::string, std::string> JSONParser::parseJSON(std::string &data) {
  std::map<std::string, std::string> dataMap;
  std::string buffer = data;
  std::string key = "", val = "";
  uint8_t posStartKey = 0, posEndKey = 0, posStartVal = 0, posEndVal = 0;

  do {
    posStartKey = buffer.find_first_of("\"");
    posEndKey   = buffer.find_first_of("\"", posStartKey + 1);

    posStartVal = buffer.find_first_of("\"", posEndKey + 1);
    posEndVal   = buffer.find_first_of("\"", posStartVal + 1);

    key = buffer.substr(posStartKey + 1, posEndKey - (posStartKey + 1 ));
    val = buffer.substr(posStartVal + 1, posEndVal - (posStartVal + 1 ));

    Print("[JSONPARSER] Key: "+key+", Val: "+val);
    dataMap.insert(std::pair<std::string, std::string>(key, val));

    buffer = buffer.substr(posEndVal+1);
  } while(buffer.find("\"")!=std::string::npos);

  return dataMap;
}

std::string JSONParser::generateJSON(std::map<std::string, std::string> &data) {
  std::string dataString = "{";

  typedef std::map<std::string, std::string>::iterator iterat;

  for(iterat iterator = data.begin(); iterator != data.end(); iterator++) {
    dataString += "\"" + iterator->first + "\": \"" + iterator->second + "\",";
  }
  dataString.pop_back();
  dataString += "}";

  return dataString;
}
