#include "ParserFactory.h"
#include "IRule.h"
#include "OneSpaceOnlyParser.h"
#include "AddCurrentMonth.h"
#include "AddCurrentMonthParser.h"
#include "AddPrefixParser.h"
#include "RemoveSpecialCharsParser.h"
#include <string>
#include <iostream>
#include <vector>


int AddCurrentMonth::month = 12;
int AddCurrentMonth::date = 9;

int main() {
    ParserFactory factory;
    factory.registerWith(new RemoveSpecialCharsParser());
    factory.registerWith(new OneSpaceOnlyParser());
    factory.registerWith(new AddCurrentMonthParser());
    factory.registerWith(new AddPrefixParser());
    //factory.registerWith(new ReplaceParser());

    std::vector<std::string> hrRules = {
        "RemoveSpecialChars blacklist=-_+",
        "OneSpaceOnly",
        "AddCurrentMonth",
        "AddPrefix CV",
        //"Replace pattern=773423, to=devops"
    };

    std::vector<std::string> filenames = {
        "+++Cao---Minh----Long 773423.pdf",
        "Tran    Huu  Nhan 773423.pdf",
        "Do-Diem-Minh 773423.pdf",
        "CAO.TRAN.LUC 773423.pdf",
        "Hoang___Tan___Minh 773423.pdf"
    };

    std::vector<IRule*> rules;

    // Recreated all the rules from preset file "hrRules.txt"
    for (auto line : hrRules) { // line = "RemoveSpecialChars blacklist=-_+"
        int splitPosition = line.find_first_of(" ");
        std::string type = line.substr(0, splitPosition); // type = "RemoveSpecialChars"
        IParsable* parser = factory.create(type);

        // data = "blacklist=-_+"
        std::string data = line.substr(splitPosition + 1, line.length() - splitPosition - 1);
        IRule* rule = dynamic_cast<IRule*>(parser->parse(data));
        rules.push_back(rule);
    }

    // Apply all rename rules to each filename
    std::vector<std::string> renamedFiles;

    for (auto filename : filenames) {
        std::string newName = filename;

        for (auto rule : rules) {
            newName = rule->rename(newName);
        }

        renamedFiles.push_back(newName);
    }

    // Print out all renamed files
    for (int i = 0; i < filenames.size(); i++) {
        std::cout << filenames[i] << " => " << renamedFiles[i] << std::endl;
    }
}