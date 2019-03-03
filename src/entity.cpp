#include "../include/rpg.h"

// Enemies Class
rpg::Enemies::Enemies(std::string x, int y, int z) {
	name_t = x;
	hp_t = y;
	mp_t = z;
	dmg_rate_t = hp_t / 10;
}

std::string rpg::Enemies::name() { return name_t; }
int rpg::Enemies::dmg_rate() { return dmg_rate_t; }

int rpg::Enemies::hp() { return hp_t <= 0 ? 0 : hp_t; }
void rpg::Enemies::hp(int new_hp) { hp_t = new_hp; }

int rpg::Enemies::mp() { return mp_t <= 0 ? 0 : mp_t; }
void rpg::Enemies::mp(int new_mp) { mp_t = new_mp; }

// Player Class
rpg::Player::Player(std::string x, std::string y) {
	name_t = x;
	type_t = y;
	hp_t = 100;
	mp_t = 100;
	lv_t = 1;
	dmg_rate_t = hp_t / 10;
}

std::string rpg::Player::name() { return name_t; }
std::string rpg::Player::type() { return type_t; }
int rpg::Player::dmg_rate() { return dmg_rate_t; }

int rpg::Player::lv() { return lv_t; }
void rpg::Player::lv(int new_lv) { lv_t = new_lv; }

int rpg::Player::hp() { return hp_t <= 0 ? 0 : hp_t; }
void rpg::Player::hp(int new_hp) { hp_t = new_hp; }

int rpg::Player::mp() { return mp_t <= 0 ? 0 : mp_t; }
void rpg::Player::mp(int new_mp) { mp_t = new_mp; }
