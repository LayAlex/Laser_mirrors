#pragma once

#include <SFML/Graphics.hpp>

class CircleObject 
{
protected:
	//sf::RenderWindow* window; // ��������� �� ����, ����� ��� ���������
	sf::CircleShape circle; // ����
	int radius;
	int x;
	int y;

	bool b_selected;


public:
	// ����������� �� ���������
	CircleObject();

	//�������� ������� � �������� ���������
	void Create(int,int,int);
	//~CircleObject();
	
	void Draw(sf::RenderWindow &window);   // ������ ���� �� �������� R � c ������� � ����� x,y
	void SetNewPos(int,int);  // ���-�� ���������� ������	
	bool UnderCursor(int, int); // ���������� 1 ���� ������ ��� ��������, 0 ���� ���

	bool IsSelected();
	void ClearSelection();
	void SetSelection();
	
};