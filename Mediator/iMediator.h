#ifndef IMEDIATOR_H
#define IMEDIATOR_H

#include "includes.h"
#include "iShip.h"

using std::unique_ptr;
using std::string;
using std::vector;
using std::cout;
using std::endl;

class IShip;

class IMediator
{
protected:
    vector<unique_ptr<IShip>> extractors;

public:
    virtual ~IMediator() { cout << __FUNCTION__ << endl; }
    
    virtual void spreadMessage(IShip::ENUM_ORE ore, double latitude, double longitude) = 0;
    virtual void addNewRegistered(unique_ptr<IShip> registered) = 0;
    virtual const vector<unique_ptr<IShip>>& getExtractors() const = 0;
};

#endif // IMEDIATOR_H
