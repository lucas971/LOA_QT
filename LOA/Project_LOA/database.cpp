#include "database.h"

Database::Database()
{
    players = QMap<int, Player>();
    teams = QMap<int, Team>();
    tournaments = QMap<int, Tournament>();
}
