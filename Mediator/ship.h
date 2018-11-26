#ifndef SHIP_H
#define SHIP_H

#include "includes.h"
#include "iMediator.h"
#include "iShip.h"

class Ship : public IShip
{
private:
    string name;
    vector<string> ores;

public:
    Ship(string _name);
    virtual ~Ship();

    virtual void sendMessage(IMediator& mediator, const IShip::ENUM_ORE& ore, double latitude, double longitude);
    virtual void receiveMessage(IShip::ENUM_ORE ore, double latitude, double longitude);
    virtual const string& getName() const;
    const string getOreInString(const IShip::ENUM_ORE& ore) const;
};

#endif // SHIP_H
