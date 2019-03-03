#include "../include/rpg.h"
#include "../include/enemies.h"

rpg::Player rpg::player("Raqui", "Knight");

int main() {
	std::string aws;

	while(1) {
		rpg::clear();
		std::cout << rpg::color["yellow"] << "Class ..: " << rpg::color["reset"]  << rpg::player.type() << "\n";
		std::cout << rpg::color["yellow"] << "Name ...: " << rpg::color["reset"]  << rpg::player.name();
		std::cout << " (" << rpg::win_lose.first << "/"   << rpg::win_lose.second << ")\n";
		std::cout << rpg::color["yellow"] << "Level ..: " << rpg::color["reset"]  << rpg::player.lv() << "\n";
		std::cout << rpg::color["yellow"] << "Status .: " << rpg::color["reset"]  << "HP " << rpg::player.hp() << ", ";
		std::cout << "MP " << rpg::player.mp() << "\n";

		std::cout << "\nActions\n[1] Battle, [0] Exit\n";
		std::cout << "> ";
		std::cin >> aws;

		if(aws == "1") {
			rpg::battle(rpg::goblin);
		} else if (aws == "0" || aws == "q") {
			exit(0);
		}
	}

	return 0;
}
