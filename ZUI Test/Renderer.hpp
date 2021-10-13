#pragma once
#include <SFML/Graphics.hpp>
#include <ZUI.hpp>

class Renderer {
private:
	sf::RenderWindow window;
	bool running;
	bool paused;


	sf::Font font;
	zui::Frame frame;
	float val;
	zui::Button_ptr rectB;
	zui::TextButton_ptr button, button2, button3, dbutton1, dbutton2, dbutton3, dbutton4, dbutton5, dbutton6;
	zui::Page_ptr page, page2, page3;
	zui::Slider_ptr slider;
	zui::Textbox_ptr text;
	zui::Dropdown_ptr drop;

	zui::Inputbox_ptr ibox, ibox2;

	void initWindow();
public:
	Renderer();
	~Renderer();

	bool isRunning();

	void update();
	void pollEvents();
	void render();

	sf::Vector2f getMousePosition();
	sf::Vector2f getWinSize();
};
