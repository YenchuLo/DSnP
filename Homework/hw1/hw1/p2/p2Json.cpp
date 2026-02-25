/****************************************************************************
  FileName     [ p2Json.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define member functions of class Json and JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include "p2Json.h"

#include <algorithm>
#include <iostream>
#include <string>

#include <fstream>

// Implement member functions of class Row and Table here
bool Json::read(const std::string &jsonFile)
{   
    std::ifstream ifs(jsonFile);
    if (!ifs) {
        return false;  // Failed to open file
    }
    
    bool inBraces = false;
    std::string line;
    while (std::getline(ifs, line)) {
        if (line.empty()) continue;  // Skip empty lines

        if (line.find('{') != std::string::npos) {
            inBraces = true;
            continue;  // Skip the line with '{'
        }
        if (line.find('}') != std::string::npos) {
            inBraces = false;
            continue;  // Skip the line with '}'
        }
        /*
        if (inBraces) {
            // Remove whitespace and commas
            line.erase(std::remove_if(line.begin(), line.end(),
                                      [](unsigned char c) {
                                          return std::isspace(c) || c == ',';
                                      }),
                       line.end());

            // Split by ':'
            auto colonPos = line.find(':');
            if (colonPos != std::string::npos) {
                std::string key = line.substr(0, colonPos);
                std::string valueStr = line.substr(colonPos + 1);

                // Remove quotes from key
                key.erase(std::remove(key.begin(), key.end(), '\"'),
                          key.end());

                // Convert value to int
                int value = std::stoi(valueStr);

                _obj.emplace_back(std::move(key), value);
            }
        }
        */

        // To support more flexible formatting, we can directly parse the line for key-value pairs when we are inside the braces
        if (inBraces) {
            size_t firstQuote = line.find('\"');
            size_t secondQuote = line.find('\"', firstQuote + 1);
            size_t colonPos = line.find(':', secondQuote);
            if (firstQuote != std::string::npos && secondQuote != std::string::npos && colonPos != std::string::npos) {
                std::string key = line.substr(firstQuote + 1, secondQuote - firstQuote - 1);
                std::string valueStr = line.substr(colonPos + 1);
                valueStr.erase(std::remove_if(valueStr.begin(), valueStr.end(),
                                      [](unsigned char c) { return std::isspace(c) || c == ','; }),
                       valueStr.end());
                int value = std::stoi(valueStr);
                _obj.emplace_back(std::move(key), value);
            }
        }
    }
    return true;  // TODO
}

std::ostream &operator<<(std::ostream &ost, const JsonElem &elem)
{
    return (ost << "\"" << elem._key << "\" : " << elem._value);
}

// C++17: Implement optional-based find method
std::optional<JsonElem> Json::find(const std::string &key) const
{
    auto it =
        std::find_if(_obj.begin(), _obj.end(), [&key](const JsonElem &elem) {
            return elem.getKey() == key;
        });

    if (it != _obj.end()) {
        return *it;
    }
    return std::nullopt;
}
