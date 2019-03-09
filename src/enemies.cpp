#include "../include/enemies.h"

rpg::Enemies::Enemies(std::string x, int y, int z) {
	name_t = x;
	hp_t = std::make_pair(y, y);
	mp_t = std::make_pair(z, z);
}

std::string rpg::Enemies::name() { return name_t; }
int rpg::Enemies::dmg_rate() { return hp_t.second / 10; }
int rpg::Enemies::xp() { return hp_t.second / 2; }
int rpg::Enemies::money() { return hp_t.second / 10; }

// hp
int rpg::Enemies::hp() { return hp_t.first <= 0 ? 0 : hp_t.first; }
void rpg::Enemies::hp(int new_hp) { hp_t.first = new_hp; }

// mp
int rpg::Enemies::mp() { return mp_t.first <= 0 ? 0 : mp_t.first; }
void rpg::Enemies::mp(int new_mp) { mp_t.first = new_mp; }

// set memebers
rpg::Enemies rpg::raqui333("??????", 999999, 999999);

typedef rpg::Enemies add;

add rpg::goblin("Goblin", 50, 50);
add rpg::wolf("Wolf", 100, 10);
add rpg::skeleton("Skeleton", 150, 150);
add rpg::vampire("Vampire", 300, 200);
add rpg::dark_wolf("Dark Wolf", 350, 200);
add rpg::goblin_champion("Goblin Champion", 400, 400);
add rpg::mage("Black Mage", 500, 1000);
add rpg::minotaur("Minotaur", 600, 200);
add rpg::knight("Black Knight", 900, 900);
add rpg::dragon("Dragon", 1000, 1000);
add rpg::demon("Demon", 1100, 2100);
add rpg::dead_knight("Dead Knight", 1200, 1200);
add rpg::ghoul("Ghoul", 1300, 1000);
add rpg::demon_lord("Demon Lord", 10000, 20000);

std::vector<rpg::Enemies> rpg::enemy {
	rpg::goblin,
	rpg::wolf,
	rpg::skeleton,
	rpg::vampire,
	rpg::dark_wolf,
	rpg::goblin_champion,
	rpg::mage,
	rpg::minotaur,
	rpg::knight,
	rpg::dragon,
	rpg::demon,
	rpg::dead_knight,
	rpg::ghoul,
	rpg::demon_lord,
};
