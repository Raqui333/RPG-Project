#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Enemies {
	private:
		std::string name_t;
		int hp_t;
		int mp_t;
	public:
		Enemies(std::string, int, int);
		std::string name();

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
		int hp_t;
		int mp_t;
		int lv_t;
	public:
		Player(std::string, std::string);
		std::string name();
		std::string type();

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

#endif
