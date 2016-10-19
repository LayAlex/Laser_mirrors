#include <SFML/Graphics.hpp>
#include "CircleObject.h"
#include "Mirror.h"
#include "Glass.h"
#include "LazerGun.h"
#include <windows.h>


#define sm(s) _CrtDbgReport(_CRT_WARN, NULL, 0, NULL, "%s \r\n", s, __LINE__)



//MessageBox(NULL, TEXT("����� ������"), TEXT("Hey!"), MB_ICONHAND);

enum {Z_CNT=3};
enum { window_height = 480,window_width = 640};
enum {radius=30};

int main()
{


	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "SFML works!");
	
	CircleObject c1;

	Mirror zerkalo[Z_CNT];
	LazerGun Gun;
	Glass SuperGlass;

	c1.Create(20, 30,radius);

	// ������� �������
	// 3 �������
	zerkalo[0].Create(100, 100, radius);
	zerkalo[1].Create(200, 100, radius);
	zerkalo[2].Create(200, 300, radius);

	//�����
	Gun.Create(100, 200, radius);

	//������ � ������� ���������� ����������� �����
	SuperGlass.Create(500,400, radius);
	
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
		
			switch (event.type)
			{
			case sf::Event::Closed: 	
			{
				window.close();
			}			break;

			case sf::Event::MouseButtonPressed:
			{			
				

				switch (event.key.code)
				{				

				case sf::Mouse::Left:
				{	
					int xf = sf::Mouse::getPosition(window).x;
					int yf = sf::Mouse::getPosition(window).y;

					
						if (c1.UnderCursor(xf, yf))
						{
							c1.SetSelection();
							sm("c1 ������");
						};	

						if (Gun.UnderCursor(xf, yf))
						{
							Gun.SetSelection();
							sm("Gun ������");
						};

						
					};
					
				
				}break;

				case sf::Mouse::Right:
				{
					sm("��� ������");
				}break;

				}
			break;
			
			case sf::Event::MouseMoved:
			{
				int x_pos = sf::Mouse::getPosition(window).x;
				int y_pos = sf::Mouse::getPosition(window).y;

				if ((x_pos < window_width-radius) && (y_pos < window_height-radius) && (x_pos>radius) && (y_pos>radius))
				{

					if (c1.IsSelected())
					{
						c1.SetNewPos(x_pos, y_pos);
					}

					if (Gun.IsSelected())
					{
						Gun.SetNewPos(x_pos, y_pos);
					}
				};

			}break;

			case sf::Event::MouseButtonReleased:
			{		

				switch (event.key.code)
				{

				case sf::Mouse::Left:
				{
					if (c1.IsSelected())
					{
						c1.ClearSelection();
					};

					if (Gun.IsSelected())
					{
						Gun.ClearSelection();
					};

					sm("��� ��������");
				}break;

				case sf::Mouse::Right:
				{
					sm("��� ��������");
				}break;

				}
			}break;

			

			}
		}


		window.clear();

		
		zerkalo[0].Draw(window);
		zerkalo[1].Draw(window);
		zerkalo[2].Draw(window);
		Gun.Draw(window);
		SuperGlass.Draw(window);
		c1.Draw(window);
		
		window.display();
	}

	return 0;
}