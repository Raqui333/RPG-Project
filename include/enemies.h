#ifndef ENEMIES_H
#define ENEMIES_H

#include <string>

class Enemies {
	private:
		std::string name;
		int hp;
		int mp;
	public:
		Enemies(std::string, int, int);
		std::string get_name();

		// hp
		int get_hp();
		void set_hp(int);
		
		// mp
		int get_mp();
		void set_mp(int);
};

#endif
