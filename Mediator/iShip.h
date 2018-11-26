#ifndef ISHIP_H
#define ISHIP_H

#include "includes.h"
#include "iMediator.h"

class IMediator;

class IShip
{
public:
    enum ENUM_ORE { ORE_SILVER, ORE_GOLD };

public:
    virtual ~IShip() { cout << __FUNCTION__ << endl; }
    
    virtual void sendMessage(IMediator& mediator, const ENUM_ORE& ore, double latitude, double longitude) = 0;
    virtual void receiveMessage(IShip::ENUM_ORE ore, double latitude, double longitude) = 0;
    virtual const string& getName() const = 0;
};

#endif // ISHIP_H
