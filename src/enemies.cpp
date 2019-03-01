#include "../include/enemies.h"

Enemies::Enemies(std::string x, int y, int z) {
	name = x;
	hp = y;
	mp = z;
}

std::string Enemies::get_name() { return name; }

int Enemies::get_hp() { return hp; }
void Enemies::set_hp(int new_hp) { hp = new_hp; }

int Enemies::get_mp() { return mp; }
void Enemies::set_mp(int new_mp) { mp = new_mp; }
