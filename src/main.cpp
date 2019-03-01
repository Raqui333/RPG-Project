#include <iostream>
#include <map>
#include "../include/entity.h"

std::map<std::string, std::string> color {
	{"reset" , "\e[00m"  },
	{"red"   , "\e[1;31m"},
	{"green" , "\e[1;32m"},
	{"yellow", "\e[1;33m"},
	{"blue"  , "\e[1;34m"},
	{"purple", "\e[1;35m"},
	{"cyan"  , "\e[1;36m"},
	{"white" , "\e[1;37m"},
};

// player
Player player("raqui", "knight");

// enemies
Enemies dragon("dragon", 1000, 1000);
Enemies goblin("goblin", 50, 50);

void clear() { std::cout << "\e[2J\e[H";};

void hud_player() {
	std::cout << color["red"] << "[" << player.type() << "] " << color["white"];
	std::cout << player.name() << "(" <<  player.lv() << ")" << color["reset"] << "  |  ";
	std::cout << color["green"] << "HP: " << player.hp() << color["reset"] << ", ";
	std::cout << color["blue"] << "MP: " << player.mp() << color["reset"] << "\n\n";
}

int main() {
	clear();
	hud_player();

	return 0;
}
