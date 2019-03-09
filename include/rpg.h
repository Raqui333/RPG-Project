#ifndef RPG_H
#define RPG_H

#include <string>
#include <utility>
#include <map>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <fstream>

namespace rpg {
	class Enemies {
		private:
			std::string name_t;
			std::pair<int, int> hp_t, mp_t;
		public:
			Enemies(std::string, int, int);
			std::string name();
			int dmg_rate();
			int xp(), money();

			// hp
			int hp();
			void hp(int);
		
			// mp
			int mp();
			void mp(int);
	};

	class Player {
		private:
			std::string name_t;
			std::string type_t;
			std::pair<int, int> win_lose;
			std::pair<int, int> hp_t, mp_t;
			std::pair<int, int> xp_t;
			int lv_t;
			int money_t;
			std::map<std::string, int> items_t;
		public:
			Player(std::string);
			int dmg_rate();

			// win/lose
			int win(), lose();
			void win_add(), lose_add();

			// name
			std::string name();
			void name(std::string);

			// type
			std::string type();
			void type(std::string);

			// level
			int lv();
			void lv(int);

			int xp(), xp_lvl();
			void xp(int), xp_lvl(int);

			// hp
			int hp(), hp_max();
			void hp(int), hp_max(int);

			// mp
			int mp(), mp_max();
			void mp(int), mp_max(int);

			// money
			int money();
			void money(int);

			// items
			std::map<std::string, int> items();
			void items(std::string, int);

			// save & load
			friend std::ostream& operator<<(std::ostream&, const Player&);
			friend std::istream& operator>>(std::istream&, Player&);
	};

	int rate(int);
	void hud_player(int);
	void hud_enemy(Enemies);
	void battle(Enemies);
	void level_up();
	void clear();
	void load_game(Player&);
	void save_game(Player&);

	extern std::map<std::string, std::string> color;
	extern Player player;
}

#endif
