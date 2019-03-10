#include "../include/rpg.h"

rpg::Player::Player(std::string x) {
	name_t = x;
	type_t = "none";
	hp_t = std::make_pair(100, 100);
	mp_t = std::make_pair(100, 100);
	xp_t = std::make_pair(0  , 100);
	lv_t = 1;
	money_t = 0;

	// initial items
	items_t["Low_HP_Potion"] = 10;
	items_t["Low_MP_Potion"] = 10;
}

int rpg::Player::dmg_rate() { return hp_t.second / 10; }

// name
std::string rpg::Player::name() { return name_t; }
void rpg::Player::name(std::string new_name) { name_t = new_name; }

// win/lose
int rpg::Player::win() { return win_lose.first; }
int rpg::Player::lose() { return win_lose.second; }

void rpg::Player::win_add() { ++win_lose.first; }
void rpg::Player::lose_add() { ++win_lose.second; } 

// type
std::string rpg::Player::type() { return type_t; }
void rpg::Player::type(std::string new_type) { type_t = new_type; }

// level
int rpg::Player::lv() { return lv_t; }
void rpg::Player::lv(int new_lv) { lv_t = new_lv; }

// xp
int rpg::Player::xp() { return xp_t.first; }
int rpg::Player::xp_lvl() { return xp_t.second; }

void rpg::Player::xp(int new_xp) { xp_t.first = new_xp; }
void rpg::Player::xp_lvl(int new_xp) { xp_t.second = new_xp; }

// hp
int rpg::Player::hp() { return hp_t.first <= 0 ? 0 : hp_t.first; }
int rpg::Player::hp_max() { return hp_t.second; }

void rpg::Player::hp(int new_hp) { hp_t.first = new_hp; }
void rpg::Player::hp_max(int new_hp) { hp_t.second = new_hp; }

// mp
int rpg::Player::mp() { return mp_t.first <= 0 ? 0 : mp_t.first; }
int rpg::Player::mp_max() { return mp_t.second; }

void rpg::Player::mp(int new_mp) { mp_t.first = new_mp; }
void rpg::Player::mp_max(int new_mp) { mp_t.second = new_mp; }

// money
int rpg::Player::money() { return money_t <= 0 ? 0 : money_t; }
void rpg::Player::money(int new_money) { money_t = new_money; }

// items
std::map<std::string, int> rpg::Player::items() { return items_t; }

void rpg::Player::items(std::string new_v_item, int new_k_item) {
	items_t[new_v_item] = new_k_item;
}

std::ostream& rpg::operator<<(std::ostream& out, const rpg::Player& obj) {
	auto write_pair = [&out] (auto the_pair) {
		out << the_pair.first << "\n";
		out << the_pair.second << "\n";
	};

	out << obj.name_t << "\n";
	out << obj.type_t << "\n";

	write_pair(obj.win_lose);
	write_pair(obj.hp_t);
	write_pair(obj.mp_t);
	write_pair(obj.xp_t);

	out << obj.lv_t << "\n";
	out << obj.money_t << "\n";

	for (auto& item : obj.items_t)
		write_pair(item);

	return out;
}

std::istream& rpg::operator>>(std::istream& in, rpg::Player& obj) {
	auto load_pair = [&in] (std::pair<int, int> &the_pair) {
		in >> the_pair.first;
		in >> the_pair.second;
	};

	auto load_map = [&in] (std::map<std::string, int> &the_map) {
		std::string first; int second;
		for (int i = 0; i < the_map.size(); ++i) {
			in >> first;
			in >> second;
			the_map[first] = second;
		}
	};

	in >> obj.name_t;
	in >> obj.type_t;

	load_pair(obj.win_lose);
	load_pair(obj.hp_t);
	load_pair(obj.mp_t);
	load_pair(obj.xp_t);

	in >> obj.lv_t;
	in >> obj.money_t;

	load_map(obj.items_t);

	return in;
}

std::map<int, std::string> types {
	{2 , "Noob"},
	{5 , "Knight"},
	{10, "Champion"},
	{15, "Dragon Slayer"},
	{20, "Dragon Lord"},
	{25, "Demon Slayer"},
	{30, "Demon Lord"},
	{40, "God Slayer"},
	{50, "God"},
};

rpg::Player& rpg::operator++(rpg::Player& obj) {
	obj.hp_t.second += 100;
	obj.mp_t.second += 100;
	
	obj.xp_t.first -= obj.xp_t.second;
	obj.xp_t.second += 100;
	
	++obj.lv_t;

	for (auto& it : types)
		if (obj.lv_t == it.first)
			obj.type_t = it.second;

	return obj;
}
