#include "mediator.h"

Mediator::~Mediator()
{
    cout << __FUNCTION__ << " byebye I was the Mediator." << endl;
}

void Mediator::spreadMessage(IShip::ENUM_ORE ore, double latitude, double longitude)
{
    for(auto const& element : getExtractors())
        element->receiveMessage(ore, latitude, longitude);
}

void Mediator::addNewRegistered(unique_ptr<IShip> registered)
{
    extractors.push_back(move(registered));
}

const vector<unique_ptr<IShip>>& Mediator::getExtractors() const
{
    return IMediator::extractors;
}
