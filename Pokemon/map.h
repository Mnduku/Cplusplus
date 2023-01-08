#include<iostream>
#include "pokemon.h"
using namespace std;

class map{
	friend ostream& operator<<(ostream& a, const map& b);
	public:
		map(int _size);
		~map();
                char** getstate();
                int getx();
                int gety();
                int getsize();
                void updatepoke();
                void updateplayer(player& a);
                void updateloot();
	private:
		const int maxloot;
		int numloot;
		const int maxpoke;
		int numpoke;
		int size;
		char** state;
		int** loot;
		int** poke;
		int startx;
		int starty;
		void setstart();
		void setloot();
		void setpoke();

};
