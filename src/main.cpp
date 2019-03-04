#include "../include/rpg.h"
#include "../include/enemies.h"

rpg::Player rpg::player("Raqui", "Knight");

int main() {
	std::string aws;

	while(1) {
		if (rpg::player.xp() == rpg::player.xp_lvl())
			rpg::level_up();

		rpg::player.hp(rpg::player.hp_max());
		rpg::player.mp(rpg::player.mp_max());

		rpg::clear();
		rpg::hud_player(1);

		std::cout << "\nActions\n[1] Battle, [0] Exit\n> ";
		std::cin >> aws;

		if(aws == "1") {
			int aws_int;
			rpg::clear();
			for (int i = 0; i < rpg::enemy.size(); ++i)
				std::cout << "[" << i << "] " << rpg::enemy[i].name() << "\n";
			
			std::cout << "\nActions\nChoose an Enemy\n> ";
			if(std::cin >> aws_int)
				if (aws_int <= rpg::enemy.size())
					rpg::battle(rpg::enemy[aws_int]);
		
			std::cin.clear();
			std::cin.ignore();
		} else if (aws == "0" || aws == "q") {
			exit(0);
		}
	}

	return 0;
}
