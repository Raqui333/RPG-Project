#include "../include/rpg.h"
#include "../include/enemies.h"

int main(int argc, char **argv) {
	int aws;
	bool loop = true;

	rpg::load_game(rpg::player);

	if (argc > 1)
		rpg::player.name(argv[1]);

	while(loop) {
		if (rpg::player.xp() >= rpg::player.xp_lvl())
			rpg::level_up();

		rpg::player.hp(rpg::player.hp_max());
		rpg::player.mp(rpg::player.mp_max());

		rpg::clear();
		rpg::hud_player(1);

		std::cout << "\nActions\n[1] Battle, [2] Save, [3] Shop\n";
		std::cout << "[4] Items,  [0] Exit\n> ";
		
		if(std::cin >> aws) {
			switch (aws) {
				case 1:
					rpg::clear();
					for (int i = 0; i < rpg::enemy.size(); ++i) {
						std::cout << rpg::color["green"];
						std::cout << "[" << i << "]\e[00m ";
						std::cout << rpg::enemy[i].name() << "\n";
					}
					std::cout << "\nActions\nChoose an Enemy\n> ";
					if(std::cin >> aws) {
						if (aws < rpg::enemy.size())
							rpg::battle(rpg::enemy[aws]);
						else if (aws == 999)
							rpg::battle(rpg::raqui333);
					}
					break;
				case 2: rpg::save_game(rpg::player); break;
				case 3: std::cout << "Working\n"; std::cin.get(); break;
				case 4:
					{
						int i = 0;
						rpg::clear();
						for (auto& x : rpg::player.items()) {
							std::cout << rpg::color["green"];
							std::cout << "[" << i << "]\e[00m ";
							std::cout << x.first << " " << x.second << "x" << "\n";
							++i;
						}
						std::cout << "\nPress [Enter] to exit\n";
						std::cin.get();
						break;
					}
				case 0: loop = false; break;
			}
		}

		std::cin.clear();
		std::cin.ignore();
	}

	rpg::save_game(rpg::player);
	return 0;
}
