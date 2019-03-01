#include "../include/player.h"

Player::Player(std::string x, std::string y) {
	name = x;
	type = y;
	hp = 100;
	mp = 100;
	lv = 1;
}

std::string Player::get_name() { return name; }
std::string Player::get_type() { return type; }

int Player::get_lv() { return lv; }
void Player::set_lv(int new_lv) { lv = new_lv; }

int Player::get_hp() { return hp; }
void Player::set_hp(int new_hp) { hp = new_hp; }

int Player::get_mp() { return mp; }
void Player::set_mp(int new_mp) { mp = new_mp; }