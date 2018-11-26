#include "ship.h"

Ship::Ship(string _name) : name(_name)
{
    ores.push_back("Silver");
    ores.push_back("Gold");
}

Ship::~Ship()
{
    cout << __FUNCTION__ << " byebye I was the " << name << endl;
}

const string& Ship::getName() const
{
    return name;
}

void Ship::sendMessage(IMediator& mediator, const IShip::ENUM_ORE& ore, double latitude, double longitude)
{
    cout << getName() << " is going to send a message to its Mediator:" << endl;
    cout << '\"' << getOreInString(ore) << "\" found! Latitude: " << latitude << " and longitude " << longitude << '.' << endl;
    mediator.spreadMessage(ore, latitude, longitude);
}

void Ship::receiveMessage(IShip::ENUM_ORE ore, double latitude, double longitude)
{
    cout << this->getName() << " is receiving a message: " << endl;
    cout << "Alright I'm going to extract \"" << getOreInString(ore) << "\" at coordinates (" << latitude << ", " << longitude << "). Let's go!" << endl;
}

const string Ship::getOreInString(const IShip::ENUM_ORE& ore) const
{
    return ores.at(ore);
}
