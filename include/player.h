#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
	private:
		std::string name;
		std::string type;
		int hp;
		int mp;
		int lv;
	public:
		Player(std::string, std::string);
		std::string get_name();
		std::string get_type();

		// level
		int get_lv();
		void set_lv(int);

		// hp
		int get_hp();
		void set_hp(int);

		// mp
		int get_mp();
		void set_mp(int);
};

#endif
