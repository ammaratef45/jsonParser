# jsonParser
Just a small jsonParser written in c++11

Its an adabtive parser for a huge application but can be easily used in other relations.

Expecting the json format as following:
```json
{
  "string-key": "string-val",
  "int-key": "int-val",
  "bool-key": "bool-key"
}
```

The return when parsing the data is ```std::map<std::string, std::string>```.
The return when generating json is ```std::string```.
