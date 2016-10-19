#include "Mirror.h"



Mirror::Mirror()
{
}

void Mirror::Create(int x1, int y1,int r)
{
	x = x1;
	y = y1;
	radius = r;
	circle.setRadius(r);
	circle.setPosition(x, y);
	circle.setFillColor(sf::Color::Yellow);

}

Mirror::~Mirror()
{
}
