#ifndef RPG_H
#define RPG_H

#include <string>
#include <utility>
#include <map>
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace rpg {
	class Enemies {
		private:
			std::string name_t;
			int hp_t, mp_t;
			int dmg_rate_t;
		public:
			Enemies(std::string, int, int);
			std::string name();
			int dmg_rate();

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
			int hp_t, mp_t;
			int lv_t, xp_t;
			int dmg_rate_t;
		public:
			Player(std::string, std::string);
			std::string name();
			std::string type();
			int dmg_rate();

			// level
			int lv();
			void lv(int);

			// hp
			int hp();
			void hp(int);

			// mp
			int mp();
			void mp(int);
	};

	int rate(int);
	void hud_player();
	void hud_enemy(Enemies);
	void battle(Enemies);
	void clear();

	extern std::map<std::string, std::string> color;
	extern std::pair<int, int> win_lose;

	// player
	extern Player player;
}

#endif
