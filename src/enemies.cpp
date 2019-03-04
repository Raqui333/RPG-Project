#include "../include/enemies.h"

rpg::Enemies rpg::dragon("Dragon", 1000, 1000);
rpg::Enemies rpg::goblin("Goblin", 50  , 50);
rpg::Enemies rpg::demon_lord("Demon Lord", 10000, 10000);
rpg::Enemies rpg::wolf("Wolf", 100, 100);
rpg::Enemies rpg::vampire("Vampire", 300, 200);
rpg::Enemies rpg::raqui333("?????", 100000, 100000);

std::vector<rpg::Enemies> rpg::enemy {
	rpg::dragon,
	rpg::goblin,
	rpg::demon_lord,
	rpg::wolf,
	rpg::vampire,
	rpg::raqui333,
};