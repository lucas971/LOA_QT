#include "tournament.h"
#include <string>

using namespace std;

int Tournament::_tourn_id=0;

Tournament::Tournament(){
    _id=_tourn_id++;
    return;
}

