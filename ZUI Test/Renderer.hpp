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
	zui::Button rectB;
	zui::TextButton button, button2, button3, dbutton1, dbutton2, dbutton3, dbutton4, dbutton5, dbutton6;
	zui::Page page, page2, page3;
	zui::Slider slider;
	zui::Textbox text;
	zui::Dropdown drop;

	zui::Inputbox ibox, ibox2;

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
