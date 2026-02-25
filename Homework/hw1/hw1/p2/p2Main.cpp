/****************************************************************************
  FileName     [ p2Main.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define main() function ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2016-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include "p2Json.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>

#include <sstream>
#include <vector>
#include <iomanip>

int main()
{
    try {
        Json json;

        // Read in the csv file. Do NOT change this part of code.
        std::string jsonFile;
        std::cout << "Please enter the file name: ";
        std::cin >> jsonFile;
        if (json.read(jsonFile))
            std::cout << "File \"" << jsonFile
                      << "\" was read in successfully.\n";
        else {
            std::cerr << "Failed to read in file \"" << jsonFile << "\"!\n";
            std::exit(-1);  // jsonFile does not exist.
        }
        
        /*
        // C++17: Demonstrate structured bindings and modern features
        std::cout << "JSON contains " << json.size() << " elements\n";

        // Example of using structured bindings (if we had key-value pairs)
        for (const auto &elem : json) {
            const auto &[key, value] =
                std::make_pair(elem.getKey(), elem.getValue());
            std::cout << "Key: " << key << ", Value: " << value << '\n';
        }

        // Example of using std::optional
        if (auto result = json.find("example"); result.has_value()) {
            std::cout << "Found element: " << result.value() << '\n';
        }
        else {
            std::cout << "Element not found\n";
        }
        */

        // TODO read and execute commands
        // std::cout << "Enter command: ";
        while (true) {
            // Parse commands (arguments separated by space)
            std::string command;
            std::cout << "Enter command: ";
            std::getline(std::cin, command); // Read entire line for command
            std::stringstream ss(command);
            std::vector<std::string> args;
            std::string arg;
            while (ss >> arg) {
                args.emplace_back(arg);
            }
            
            // Process commands
            if (args.empty()) continue;
            else if (args.size() == 1) {
                if (args[0] == "EXIT") break;
                else if (args[0] == "PRINT") {
                    json.print();
                }
                else if (args[0] == "SUM") {
                    if (json.empty()) {
                        std::cerr << "Error: No element found!!\n";
                    } 
                    else {
                        long long sum = json.sum();
                        std::cout << "The summation of the values is: " << sum << ".\n";
                    }
                }
                else if (args[0] == "AVE") {
                    if (json.empty()) {
                        std::cerr << "Error: No element found!!\n";
                    }
                    else {
                        long long sum = json.sum();
                        double average = static_cast<double>(sum) / json.size();
                        std::cout << "The average of the values is: " << std::fixed << std::setprecision(1) << average << ".\n";
                    }
                }
                else if (args[0] == "MAX") {
                    if (json.empty()) {
                        std::cerr << "Error: No element found!!\n";
                    } 
                    else {
                        JsonElem maxElem = json.max();
                        int max = maxElem.getValue();
                        std::string maxKey = maxElem.getKey();
                        std::cout << "The maximum element is: { \"" << maxKey << "\" : " << max << " }.\n";
                    }
                }
                else if (args[0] == "MIN") {
                    if (json.empty()) {
                        std::cerr << "Error: No element found!!\n";
                    } 
                    else {
                        JsonElem minElem = json.min();
                        int min = minElem.getValue();
                        std::string minKey = minElem.getKey();
                        std::cout << "The minimum element is: { \"" << minKey << "\" : " << min << " }.\n";
                    }
                }
                else {
                    std::cerr << "Invalid command!!\n";
                }
            }
            else if (args.size() == 3) {
                if (args[0] == "ADD") {
                    std::string key = args[1];
                    int value = std::stoi(args[2]);
                    if (auto result = json.find(key); result.has_value()) {
                        std::cerr << "Error: Element with key \"" << key << "\" already exists!!\n";
                        continue;
                    }
                    else {
                        json.add(key, value);
                    }
                }
                else {
                    std::cerr << "Invalid command!!\n";
                    continue;
                }
            }
            else {
                std::cerr << "Invalid command!!\n";
                continue;
            }
        }
    }
    catch (...) {
        std::cerr << "Unexpected error occurred\n";
        return 1;
    }
}
