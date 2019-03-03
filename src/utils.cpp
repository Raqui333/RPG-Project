#include "../include/rpg.h"

std::map<std::string, std::string> rpg::color {
	{"reset" , "\e[00m"  },
	{"red"   , "\e[1;31m"},
	{"green" , "\e[1;32m"},
	{"yellow", "\e[1;33m"},
	{"blue"  , "\e[1;34m"},
	{"purple", "\e[1;35m"},
	{"cyan"  , "\e[1;36m"},
	{"white" , "\e[1;37m"},
};

std::pair<int, int> rpg::win_lose(0, 0);

void rpg::clear() { std::cout << "\e[H\e[2J"; }

int rpg::rate(int range) {
	srand(time(NULL));
	return rand() % range + 1;
}

void rpg::hud_player() {
	std::cout << rpg::color["red"]   << "["    << player.type() << "] " << rpg::color["white"];
	std::cout << player.name()  << "("    << player.lv()   << ")"  << rpg::color["reset"] << "  |  ";
	std::cout << rpg::color["green"] << "HP: " << player.hp()   << rpg::color["reset"] << ", ";
	std::cout << rpg::color["blue"]  << "MP: " << player.mp()   << rpg::color["reset"] << "\n";
}

void rpg::hud_enemy(rpg::Enemies emy) {
	std::cout << color["red"]   << emy.name() << color["reset"] << "  |  ";
	std::cout << color["green"] << "HP: " << emy.hp() << color["reset"] << ", ";
	std::cout << color["blue"]  << "MP: " << emy.mp() << color["reset"] << "\n";
}

void rpg::battle(rpg::Enemies emy) {
	std::string action = "\tVS", aws;
	int drate;

	auto attack_per = [&emy, &drate, &action] (int which) {
		if (which == 0) {
			drate = rpg::rate(player.dmg_rate());
			emy.hp(emy.hp() - drate);

			if (drate == player.dmg_rate())
				action = color["red"] + "\t*Critic*" + color["reset"];
			else
				action = "\tAttack";

			player.mp(player.mp() - 10);
		} else {
			drate = rpg::rate(emy.dmg_rate());
			player.hp(player.hp() - drate);

			if (drate == emy.dmg_rate())
				action = color["red"] + "\t*Critic*" + color["reset"];
			else
				action = "\tAttack";

			emy.mp(emy.mp() - 10);
		}
	};

	while(1) {
		if (emy.hp() == 0) {
			++win_lose.first; // player win
			return;
		} else if (player.hp() == 0) {
			++win_lose.second; // player lose
			return;
		}

		clear();
		hud_player();

		std::cout << "\n" << action << "\n\n";

		hud_enemy(emy);

		std::cout << "\nActions\n[1] Attack [0] Flee\n> ";
		std::cin >> aws;

		if (aws == "1") {
			attack_per(0); // player
			attack_per(1); // enemy
		} else if (aws == "0") {
			return;
		}
	}
}
