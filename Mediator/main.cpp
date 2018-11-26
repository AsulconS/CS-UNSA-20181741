#include "includes.h"
#include "ship.h"
#include "mediator.h"

int main()
{
    auto ship1 = make_unique<Ship>(string("Scout"));
    auto ship2 = make_unique<Ship>(string("Extractor 1"));
    auto ship3 = make_unique<Ship>(string("Extractor 2"));
    auto ship4 = make_unique<Ship>(string("Extractor 3"));
    auto ship5 = make_unique<Ship>(string("Extractor 4"));

    auto mediator1 = make_unique<Mediator>();

    mediator1->addNewRegistered(move(ship2));
    mediator1->addNewRegistered(move(ship3));
    mediator1->addNewRegistered(move(ship4));
    mediator1->addNewRegistered(move(ship5));

    cout << endl;

    ship1->sendMessage(*mediator1, IShip::ORE_SILVER, 40.741895, -73.989308);
    cout << endl;
    cout << ship1->getName() << " is going to send a message:" << endl;
    ship1->sendMessage(*mediator1, IShip::ORE_GOLD, -33.856769, 151.215158);
    cout << endl;
    
    return 0;
}
