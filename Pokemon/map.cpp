#include "map.h"
map::map(int _size=10):maxloot(_size/2),maxpoke(_size) {  //generating loot
	size = _size;
	state = new char*[size];
	for(int i = 0; i < size; i++) {
		state[i] = new char[size];
		for(int j = 0; j < size; j++) {
			if(i == 0 || i == size-1) {
				state[i][j]= '-';
				continue;
			} else if (j == 0 || j == size-1) {
				state[i][j] = '|';
				continue;
			}
			state[i][j] = ' ';
		}
        }
        setpoke();
        setloot();
        setstart();
}
map::~map(){
	cout << "Destroying map state..." << endl;      //map destructors
	for(int i = 0; i < size; i++) {
		delete [] state[i];
	}
	delete [] state;
	
	cout << "Destroying pokemon state..." << endl;
	for(int i = 0; i < numpoke; i++) {
		cout << "Destroying pokemon " << i << endl;
		delete [] poke[i];
	}
	cout << "Destroying pokemin list..." << endl;
	delete [] poke;
	
	cout << "Deallocating loot state..." << endl;
	for(int i = 0; i < numloot; i++) {
		cout << "Deallocating loot " << i << endl;
		delete [] loot[i];
	}
	delete [] loot;
}

ostream& operator<<(ostream& a, const map& b) {
	for(int i = 0; i < b.size; i++) {
		for(int j = 0; j < b.size; j++) {
			a << b.state[i][j] << "\t";
		}
		a << endl<<endl;
	}
	return a;
}

void map::setstart(){
        //instead of having an entrance i wanted the char randomly placed
	int row = rand()%(size-2) + 1;
        int column = rand()%(size-2) + 1;
        state[row][column] = 'U';
        startx =  row;
        starty = column;
}
void map::setloot() {
	numloot = rand() % maxloot + 1;
	loot = new int*[numloot];
	for(int i = 0; i < numloot; i++){
		int row = rand()%(size-2) + 1;
		int column = rand()%(size-2) + 1;
		state[row][column] = 'T';
		loot[i] = new int[2];
		loot[i][0] = row;
		loot[i][1] = column;
		cout << "Placed loot " << i << endl; 
	}
}

void map::setpoke() {
        srand(time(0));
	numpoke = rand() % maxpoke + 1;
	poke = new int*[numpoke];
	for(int i = 0; i < numpoke; i++) {
		int row = rand()%(size-2) + 1;
		int column = rand()%(size-2) + 1;      // sets the enemies on the map
		state[row][column] = 'M';               //type of enemy is not determined till encountered
		poke[i] = new int[2];
		poke[i][0] = row;
		poke[i][1] = column;
		cout << "Allocated pokemon " << i << endl;
	}
}
int map::getx(){
    return startx;
}
int map::gety(){
    return starty;
}
void map::updatepoke(){
}
void map::updateplayer(player& a){                    //used to update the players location on map
    state[startx][starty] = ' ';
    state[a.getx()][a.gety()] = 'U';
    startx = a.getx();
    starty = a.gety();
    return;
}
void map::updateloot(){
}
int map::getsize(){
   return size;
}
char** map::getstate(){
   return state;
}
