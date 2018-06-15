#ifndef _TANK_H
#define _TANK_H
#include <graphics.h>

class Tank
{
public:
	Tank(int x,int y);
	~Tank();
private:
	int p[34] = { -4, 0, -4, 0, -2, 0, -2, 0, 2, 0, 2, 
				 0, 4, 0, 4, 0, 2, 0, 2, 0, 1, 0, 1, 0, 
				 -1, 0, -1, 0, -2, 0, -2, 0, -4, 0	};
	int positionX, positionY;


};



#endif // !_TANK_H
