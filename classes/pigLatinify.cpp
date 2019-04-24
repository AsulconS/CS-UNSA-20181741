#include <string>
#include <iostream>

static const std::string vowels = "aeiou";

std::string pigLatinify(const std::string& s)
{
    if(s.size() == 0)
        return s;
    
    if(s.find("qu") == 0)
        return s.substr(2, s.size() - 2) + '-' + s.substr(0, 2) + "ay";

    else if(vowels.find(s[0]) != std::string::npos)
        return s + "way";

    else
        return s.substr(1, s.size() - 1) + '-' + s[0] + "ay";
}
