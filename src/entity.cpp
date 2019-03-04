#include "../include/rpg.h"

// Enemies Class
rpg::Enemies::Enemies(std::string x, int y, int z) {
	name_t = x;
	hp_t = std::make_pair(y, y);
	mp_t = std::make_pair(z, z);
}

std::string rpg::Enemies::name() { return name_t; }
int rpg::Enemies::dmg_rate() { return hp_t.second / 10; }
int rpg::Enemies::xp() { return hp_t.second / 2; }

int rpg::Enemies::hp() { return hp_t.first <= 0 ? 0 : hp_t.first; }
void rpg::Enemies::hp(int new_hp) { hp_t.first = new_hp; }

int rpg::Enemies::mp() { return mp_t.first <= 0 ? 0 : mp_t.first; }
void rpg::Enemies::mp(int new_mp) { mp_t.first = new_mp; }

// Player Class
rpg::Player::Player(std::string x) {
	name_t = x;
	type_t = "none";
	hp_t = std::make_pair(100, 100);
	mp_t = std::make_pair(100, 100);
	xp_t = std::make_pair(0  , 100);
	lv_t = 1;
}

int rpg::Player::dmg_rate() { return hp_t.second / 10; }

std::string rpg::Player::name() { return name_t; }
void rpg::Player::name(std::string new_name) { name_t = new_name; }

std::string rpg::Player::type() { return type_t; }
void rpg::Player::type(std::string new_type) { type_t = new_type; }

int rpg::Player::lv() { return lv_t; }
void rpg::Player::lv(int new_lv) { lv_t = new_lv; }

int rpg::Player::xp() { return xp_t.first; }
int rpg::Player::xp_lvl() { return xp_t.second; }
void rpg::Player::xp(int new_xp) { xp_t.first = new_xp; }
void rpg::Player::xp_lvl(int new_xp) { xp_t.second = new_xp; }

int rpg::Player::hp() { return hp_t.first <= 0 ? 0 : hp_t.first; }
int rpg::Player::hp_max() { return hp_t.second; }
void rpg::Player::hp(int new_hp) { hp_t.first = new_hp; }
void rpg::Player::hp_max(int new_hp) { hp_t.second = new_hp; }

int rpg::Player::mp() { return mp_t.first <= 0 ? 0 : mp_t.first; }
int rpg::Player::mp_max() { return mp_t.second; }
void rpg::Player::mp(int new_mp) { mp_t.first = new_mp; }
void rpg::Player::mp_max(int new_mp) { mp_t.second = new_mp; }
