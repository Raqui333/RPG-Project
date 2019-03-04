#include "../include/enemies.h"

rpg::Enemies rpg::raqui333("??????", 999999, 999999);

typedef rpg::Enemies add;

add rpg::goblin("Goblin", 50  , 50);
add rpg::wolf("Wolf", 100, 10);
add rpg::skeleton("Skeleton", 150, 150);
add rpg::vampire("Vampire", 300, 200);
add rpg::dark_wolf("Dark Wolf", 350, 200);
add rpg::goblin_champion("Goblin Champion", 400, 400);
add rpg::dragon("Dragon", 1000, 1000);
add rpg::demon_lord("Demon Lord", 10000, 20000);

std::vector<rpg::Enemies> rpg::enemy {
	rpg::goblin,
	rpg::wolf,
	rpg::skeleton,
	rpg::vampire,
	rpg::dark_wolf,
	rpg::goblin_champion,
	rpg::dragon,
	rpg::demon_lord,
};