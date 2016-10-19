#include "CircleObject.h"




CircleObject::CircleObject()
{	
	b_selected = false;
		
		
	
}


void CircleObject::Draw(sf::RenderWindow &window)
{	
	window.draw(circle);
}

void CircleObject::Create(int x1 , int y1, int r)
{
	x = x1;
	y = y1;
	radius = r;
	circle.setRadius(r);
	circle.setPosition(x, y);
circle.setFillColor(sf::Color::Green);	

}


void CircleObject::SetNewPos(int x_new,int y_new)
{
	x = x_new-radius;
	y = y_new-radius;
	circle.setPosition(x, y);
}

bool CircleObject::UnderCursor(int x_pos, int y_pos) // возвращает 1 если объект под курсором, 0 если нет
{
	if ((x_pos >= x) && (x_pos <= (x + radius*2)))
	{
		if ((y_pos >= y) && (y_pos <= (y + radius*2)))
		{
			return true;
		}
	}
	return false;
}

void CircleObject::ClearSelection()
{
	b_selected = false;
}
void CircleObject::SetSelection()
{
	b_selected = true;
}

bool CircleObject::IsSelected()
{
	return b_selected;
}

