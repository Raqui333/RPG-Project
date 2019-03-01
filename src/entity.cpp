#include "../include/entity.h"

// Enemies Class
Enemies::Enemies(std::string x, int y, int z) {
	name_t = x;
	hp_t = y;
	mp_t = z;
}

std::string Enemies::name() { return name_t; }

int Enemies::hp() { return hp_t; }
void Enemies::hp(int new_hp) { hp_t = new_hp; }

int Enemies::mp() { return mp_t; }
void Enemies::mp(int new_mp) { mp_t = new_mp; }

// Player Class
Player::Player(std::string x, std::string y) {
	name_t = x;
	type_t = y;
	hp_t = 100;
	mp_t = 100;
	lv_t = 1;
}

std::string Player::name() { return name_t; }
std::string Player::type() { return type_t; }

int Player::lv() { return lv_t; }
void Player::lv(int new_lv) { lv_t = new_lv; }

int Player::hp() { return hp_t; }
void Player::hp(int new_hp) { hp_t = new_hp; }

int Player::mp() { return mp_t; }
void Player::mp(int new_mp) { mp_t = new_mp; }