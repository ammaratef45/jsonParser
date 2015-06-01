#ifndef OHBOT_JSONPARSER_H_
#define OHBOT_JSONPARSER_H_

#include "includes.h"

class JSONParser
{
private:

public:
  explicit JSONParser();
  ~JSONParser();
  JSONParser(JSONParser &) = delete;

  std::map<std::string, std::string> parseJSON(std::string &data);
  std::string generateJSON(std::map<std::string, std::string> &data);
};

#endif //OHBOT_JSONPARSER_H_
