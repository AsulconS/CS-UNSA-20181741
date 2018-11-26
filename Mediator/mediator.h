#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "includes.h"
#include "iMediator.h"
#include "iShip.h"

class Mediator : public IMediator
{
public:
    Mediator() {}
    virtual ~Mediator();

    virtual void spreadMessage(IShip::ENUM_ORE ore, double latitude, double longitude);
    virtual void addNewRegistered(unique_ptr<IShip> registered);
    virtual const vector<unique_ptr<IShip>>& getExtractors() const;
};

#endif // MEDIATOR_H
