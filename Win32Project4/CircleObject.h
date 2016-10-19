#pragma once

#include <SFML/Graphics.hpp>

class CircleObject 
{
protected:
	//sf::RenderWindow* window; // ”казатель на окно, нужен дл€ отрисовки
	sf::CircleShape circle; // круг
	int radius;
	int x;
	int y;

	bool b_selected;


public:
	//  онструктор по умолчанию
	CircleObject();

	//создание обьекта с заданием координат
	void Create(int,int,int);
	//~CircleObject();
	
	void Draw(sf::RenderWindow &window);   // рисует круг по заданным R и c центром в точке x,y
	void SetNewPos(int,int);  // уст-ет координаты центра	
	bool UnderCursor(int, int); // возвращает 1 если объект под курсором, 0 если нет

	bool IsSelected();
	void ClearSelection();
	void SetSelection();
	
};