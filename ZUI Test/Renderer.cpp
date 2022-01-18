#include "Renderer.hpp"
#include <iostream>

void Renderer::initWindow()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	window.create(sf::VideoMode(1500, 700), "ZUI 3.0", sf::Style::Default, settings);
	window.setFramerateLimit(60);
}

Renderer::Renderer()
{
	this->initWindow();

	running = true;
	paused = false;

	font.loadFromFile("assets/consola.ttf");

	

	frame.setWindow(window);

	button = zui::create<zui::TextButton>();
	button->setSize({ 80, 40 });
	button->setPosition(20, 5);
	button->setFillColor(sf::Color::Transparent);
	button->setOutlineColor(sf::Color(160, 32, 240));
	button->setOutlineThickness(3);
	button->setSelectionFillColor(sf::Color(160, 32, 240, 126));
	button->setSelectionOutlineColor(sf::Color(124, 163, 251));
	button->setSelectionOutlineThickness(5);
	button->setCharacterSize(22);
	button->setTextFillColor(sf::Color::White);
	button->setFont(font);
	button->setString("Button 1");

	button2 = zui::copy(button);
	button2->setString("button2");
	button2->setPosition(120, 5);

	text = zui::create<zui::Textbox>();
	text->setSize({ 80, 40 });
	text->setPosition(50, 100);
	text->setFillColor(sf::Color::Transparent);
	text->setOutlineColor(sf::Color(160, 32, 240));
	text->setOutlineThickness(3);
	text->setCharacterSize(22);
	text->setTextFillColor(sf::Color::White);
	text->setFont(font);
	text->setString("TextButton");


	ibox = zui::create<zui::Inputbox>();
	ibox->setSize({ 80, 40 });
	ibox->setPosition(400, 105);
	ibox->setFillColor(sf::Color::Transparent);
	ibox->setOutlineColor(sf::Color(160, 32, 240));
	ibox->setSelectionFillColor(sf::Color::Transparent);
	ibox->setSelectionOutlineColor(sf::Color::White);
	ibox->setOutlineThickness(3);
	ibox->setSelectionOutlineThickness(3);

	ibox2 = zui::create<zui::Inputbox>();
	ibox2->setSize({ 80, 40 });
	ibox2->setPosition(400, 205);
	ibox2->setFillColor(sf::Color::Transparent);
	ibox2->setOutlineColor(sf::Color(160, 32, 20));
	ibox2->setSelectionFillColor(sf::Color::Transparent);
	ibox2->setSelectionOutlineColor(sf::Color::White);
	ibox2->setOutlineThickness(3);
	ibox2->setSelectionOutlineThickness(3);

	ibox->setCharacterSize(22);
	ibox->setTextFillColor(sf::Color::White);
	ibox->setFont(font);
	ibox->setString("TextButton");

	ibox2->setCharacterSize(22);
	ibox2->setTextFillColor(sf::Color::White);
	ibox2->setFont(font);
	ibox2->setString("TextButton2");


	slider = zui::create<zui::Slider>();
	slider->setSize({ 80, 40 });
	slider->setPosition(300, 5);
	slider->setBarFillColor(sf::Color::Red);
	slider->setBarSelectionColor(sf::Color::Yellow);
	slider->setFillColor(sf::Color::Transparent);
	slider->setOutlineColor(sf::Color::Blue);
	slider->setOutlineThickness(3);
	slider->setTextFillColor(sf::Color::White);
	slider->setFont(font);
	slider->setCharacterSize(22);
	slider->setString("Speed");
	slider->setVariable(val, 3, 200);
	

	page = zui::create<zui::Page>();
	page->setFillColor(sf::Color(255, 255, 255, 26));
	page->setMaxSize({ 1000, 1000 });
	page->setPosition(1050, 100);
	page->setActiveRegion({ 0,0, 400, 500 });
	//page->setScroll(zui::Page::RIGHT);
	page->setScroll(zui::Page::BOTTOM, 10);

	page->setHeader(true, true, true);

	page2 = zui::create<zui::Page>();
	page2->setFillColor(sf::Color(255, 255, 255, 78));
	page2->setMaxSize({ 1000, 1000 });
	page2->setPosition(500, 500);
	page2->setActiveRegion({ 0,0, 300, 300 });
	page2->setScroll(zui::Page::RIGHT);
	page2->setScroll(zui::Page::BOTTOM);

	page2->setHeader(true, true, true);

	drop = zui::create<zui::Dropdown>();
	drop->setItemHeight(40);
	drop->setHeaderSize({ 300, 40 });
	drop->setPosition(20, 20);
	drop->setFillColor(sf::Color(255, 255, 255, 26));

	dbutton1 = zui::create<zui::TextButton>();
	dbutton1->setFillColor(sf::Color::Transparent);
	dbutton1->setOutlineColor(sf::Color(160, 32, 240));
	dbutton1->setOutlineThickness(3);
	dbutton1->setSelectionFillColor(sf::Color(160, 32, 240, 126));
	dbutton1->setSelectionOutlineColor(sf::Color(124, 163, 251));
	dbutton1->setSelectionOutlineThickness(5);
	dbutton1->setCharacterSize(22);
	dbutton1->setTextFillColor(sf::Color::White);
	dbutton1->setFont(font);
	dbutton1->setString("dbutton1");
	drop->addItem(dbutton1.get());

	dbutton2 = zui::copy(dbutton1);
	dbutton2->setString("dbutton2");
	drop->addItem(dbutton2.get());

	dbutton3 = zui::copy(dbutton1);
	dbutton3->setString("dbutton3");
	drop->addItem(dbutton3.get());

	drop->setItemLimit(1);
	drop->setTitle("Drop", font, 24, sf::Color::White);

	rectB = zui::create<zui::Button>();
	rectB->setPointCount(4);
	rectB->setPoint(0, { 300, 300 });
	rectB->setPoint(1, { 600, 300 });
	rectB->setPoint(2, { 600, 500 });
	rectB->setPoint(3, { 300, 500 });
	rectB->setPosition(10, 10);
	page2->addEntity(drop.get());

	rectB->setFillColor(sf::Color::Red);
	rectB->setSelectionFillColor(sf::Color::Blue);

	page->setPosition(0, 10);

	page3 = zui::create<zui::Page>();
	page3->setFillColor(sf::Color(255, 255, 255, 78));
	page3->setMaxSize({ 500, 500 });
	page3->setPosition(20, 20);
	page3->setActiveRegion({ 0,0, 200, 200 });
	page3->setScroll(zui::Page::RIGHT);
	page3->setScroll(zui::Page::BOTTOM);
	page3->setHeader(true, true, true);


	/*page->rotate(45);
	page2->rotate(-45);
	page->scale(1->5, 1->5);*/


	page->addEntity(*text);
	page->addEntity(*button);
	page->addEntity(*button2);
	page->addEntity(*slider);
	frame.addEntity(*page2);
	page->addEntity(*ibox);
	page->addEntity(*ibox2);
	//page->rotate(45);

	frame.addEntity(*page);
	frame.removeEntity(*page2);
	//page->addEntity(*page2);

	frame.addEntity(*rectB);
	

	frame.push_in_navigationOrder(*rectB);
	frame.push_in_navigationOrder(*button);
	frame.push_in_navigationOrder(*button2);
	frame.push_in_navigationOrder(*slider);
	frame.push_in_navigationOrder(*ibox);
	frame.push_in_navigationOrder(*ibox2);

	rectB->setAction([this] {std::cout << "YO :)\n"; });
	button->setAction([this] {std::cout << "NO -> \n"; });
	button2->setAction([this] {std::cout << "OK !\n"; });

}

Renderer::~Renderer()
{
}

bool Renderer::isRunning()
{
	return this->running;
}

void Renderer::update()
{
	this->pollEvents();

	if (!this->paused) {
		frame.update();
	}
}

void Renderer::pollEvents()
{
	sf::Event event;

	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			this->running = false;

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)this->paused = !this->paused;

		if (!this->paused) {
			frame.pollEvents(event);
			if (event.type == sf::Event::MouseMoved) {
			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				
			}
			else if (event.type == sf::Event::MouseButtonReleased) {
				
			}
			else if (event.type == sf::Event::KeyPressed) {

			}
		}
	}
}

void Renderer::render()
{
	this->window.clear();

	frame.draw();

	this->window.display();
}

sf::Vector2f Renderer::getMousePosition()
{
	return window.mapPixelToCoords(sf::Mouse::getPosition(this->window));
}

sf::Vector2f Renderer::getWinSize()
{
	return sf::Vector2f(this->window.getSize());
}