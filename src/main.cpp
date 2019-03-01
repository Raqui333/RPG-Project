#include <iostream>
#include "../include/enemies.h"
#include "../include/player.h"

int main() {
	Enemies dragon("dragon", 1000, 1000);
	Player player("raqui", "knight");

	std::cout << dragon.get_name() << ", " << dragon.get_hp() << ", " << dragon.get_mp() << std::endl; 
	
	auto pp = [&player] () {
		std::cout << player.get_name() << "," << player.get_type() << ", " << player.get_hp() << ", ";
		std::cout << player.get_mp() << ", " << player.get_lv() << std::endl;
	};

	pp();

	player.set_lv(player.get_lv() + 1);

	pp();

	return 0;
}
