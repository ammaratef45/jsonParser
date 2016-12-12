#ifndef OHBOT_JSONPARSER_H_
#define OHBOT_JSONPARSER_H_

#include "jsonParser.h"
#include <string>
#include<map>

using namespace std;

class JSONParser
{
private:

public:
  explicit JSONParser();
  ~JSONParser();
  JSONParser(JSONParser &) = delete;

  map<string, string> parseJSON(string &data);
  string generateJSON(map<string, string> &data);
};

#endif //OHBOT_JSONPARSER_H_
