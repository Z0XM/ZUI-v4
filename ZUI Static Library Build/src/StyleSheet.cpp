#include <pch.h>

#include <ZUI/StyleSheet.hpp>
#include <fstream>
#include <sstream>

#include <ZUI/Textbox.hpp>
#include <ZUI/TextButton.hpp>
#include <ZUI/Slider.hpp>
#include <ZUI/Inputbox.hpp>
#include <algorithm>

using namespace zui;

std::unordered_map<std::string, StyleSheet> StyleSheet::styleGroup;

StyleSheet::StyleSheet()
{

}

StyleSheet::~StyleSheet()
{

}

void StyleSheet::set(StyleType type, int value)
{
	if (type == FONT_SIZE || type == OUT_THICKNESS || type == S_OUT_THICKNESS || type == TEXT_OUT_THICKNESS) {
		m_style[type].integer = value;
	}
}

void StyleSheet::set(StyleType type, const sf::Color& value)
{
	if(type  == FILL_COLOR || type == OUT_COLOR || type == S_FILL_COLOR || type == S_OUT_COLOR || type == TEXT_FILL_COLOR || type == TEXT_OUT_COLOR || type == BAR_FILL_COLOR || type == S_BAR_FILL_COLOR){
		m_style[type].color = value;
	}
}

void StyleSheet::set(StyleType type, const sf::Vector2f& value)
{
	if (type == SIZE){
		m_style[type].vector = value;
	}
}

void StyleSheet::set(StyleType type, sf::Font& font)
{
	if (type == FONT) {
		m_style[type].font = &font;
	}
}

void StyleSheet::applyTo(zui::Entity& entity)
{
	auto classId = Entity::getClassID(entity);
	for (auto it = m_style.begin(); it != m_style.end(); it++) {

		if (classId == ZUI_ID_INPUTBOX || classId == ZUI_ID_TEXTBUTTON || classId == ZUI_ID_SLIDER || classId == ZUI_ID_TEXTBOX){
			Textbox* tb = (Textbox*)(&entity);
			switch (it->first){
			case FONT_SIZE: tb->setCharacterSize(it->second.integer); break;
			case FILL_COLOR: tb->setFillColor(it->second.color); break;
			case OUT_COLOR: tb->setOutlineColor(it->second.color); break;
			case OUT_THICKNESS: tb->setOutlineThickness(it->second.integer); break;
			case TEXT_FILL_COLOR: tb->setTextFillColor(it->second.color); break;
			case TEXT_OUT_COLOR: tb->setTextOutlineColor(it->second.color); break;
			case TEXT_OUT_THICKNESS: tb->setTextOutlineThickness(it->second.integer); break;
			case SIZE: tb->setSize(it->second.vector); break;
			case FONT: tb->setFont(*it->second.font); break;
			}
		}

		if (classId == ZUI_ID_TEXTBUTTON || classId == ZUI_ID_INPUTBOX) {
			TextButton* tbtn = (TextButton*)(&entity);
			switch (it->first) {
			case S_FILL_COLOR: tbtn->setSelectionFillColor(it->second.color); break;
			case S_OUT_COLOR: tbtn->setSelectionOutlineColor(it->second.color); break;
			case S_OUT_THICKNESS: tbtn->setSelectionOutlineThickness(it->second.integer); break;
			}
		}

		if (classId == ZUI_ID_SLIDER) {
			Slider* sld = (Slider*)(&entity);
			if (it->first == BAR_FILL_COLOR) sld->setBarFillColor(it->second.color);
			else if (it->first == S_BAR_FILL_COLOR)sld->setBarSelectionColor(it->second.color);
		}

		if (classId == ZUI_ID_BUTTON) {
			Button* btn = (Button*)(&entity);
			switch (it->first) {
			case FILL_COLOR: btn->setFillColor(it->second.color); break;
			case OUT_COLOR: btn->setOutlineColor(it->second.color); break;
			case OUT_THICKNESS: btn->setOutlineThickness(it->second.integer); break;
			case S_FILL_COLOR: btn->setSelectionFillColor(it->second.color); break;
			case S_OUT_COLOR: btn->setSelectionOutlineColor(it->second.color); break;
			case S_OUT_THICKNESS: btn->setSelectionOutlineThickness(it->second.integer); break;
			}
		}
	}
}

void StyleSheet::applyTo(Entity* entity)
{
	applyTo(*entity);
}


void StyleSheet::inheritFrom(StyleSheet& sheet)
{
	for (auto it = sheet.m_style.begin(); it != sheet.m_style.end(); it++)
	{
		if (m_style.find(it->first) == m_style.end())
			m_style.insert(std::make_pair(it->first, it->second));
	}
}