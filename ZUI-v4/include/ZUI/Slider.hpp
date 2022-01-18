#pragma once

#include "Textbox.hpp"
#include "Button.hpp"

namespace zui {
class Slider : public Textbox {
public:
	////////////////////////////////////////////////////////////
	/// \brief Default constructor
	///
	/// \param size -> size of the box
	/// 
	////////////////////////////////////////////////////////////
	Slider(const sf::Vector2f& size = sf::Vector2f(0, 0));

	////////////////////////////////////////////////////////////
	/// \brief Default virtual destrcutor
	///
	////////////////////////////////////////////////////////////
	virtual ~Slider();

	////////////////////////////////////////////////////////////
	/// \brief Set pointer to variable and its limit
	/// 
	/// \param var -> refrence to variable
	/// \param lower_limit -> lower limit of variable
	/// \param upper_limit -> upper_limit of variable
	/// \param keepAsInteger -> flag to only use integer values of var
	///
	////////////////////////////////////////////////////////////
	void setVariable(float& var, float lower_limit, float upper_limit, bool keepAsInteger = false);

	////////////////////////////////////////////////////////////
	/// \brief Get the value of pointed variable
	/// 
	/// \return value of pointed float variable
	///
	////////////////////////////////////////////////////////////
	float getVariableValue();

	////////////////////////////////////////////////////////////
	/// \brief Increase object's offset by shift
	/// 
	/// \param shift Value to shift offset by
	/// 
	////////////////////////////////////////////////////////////
	void shiftOffset(float shift);

	////////////////////////////////////////////////////////////
	/// \brief Set the fill color of the slider bar
	///
	/// By default, the slider bar's fill color is opaque white
	/// 
	/// \param color -> New fill color of the box
	///
	////////////////////////////////////////////////////////////
	void setBarFillColor(sf::Color color);

	////////////////////////////////////////////////////////////
	/// \brief Set the fill color of the slider bar upon selection
	///
	/// By default, the silder bar's fill color upon selection is opaque white
	/// 
	/// \param color -> New fill color of the slider bar
	///
	////////////////////////////////////////////////////////////
	void setBarSelectionColor(sf::Color color);

	////////////////////////////////////////////////////////////
	/// \brief Set the size of the box
	///
	/// \param size -> New size
	///
	////////////////////////////////////////////////////////////
	void setSize(const sf::Vector2f& size) override;
	
	////////////////////////////////////////////////////////////
	/// \brief Reset the silder bar's offset
	///
	////////////////////////////////////////////////////////////
	void reset();

	////////////////////////////////////////////////////////////
	/// \brief Get the entity if the point is over the entity
	/// 
	/// \return Pointer to the entity if pointed by the point, nullptr otherwise
	/// 
	/// \param point -> Position of the point
	/// 
	////////////////////////////////////////////////////////////
	virtual Entity* isHit(const sf::Vector2f& point) override;

	////////////////////////////////////////////////////////////
	/// \brief Actions to take upon selection of the object
	///
	////////////////////////////////////////////////////////////
	virtual void activateSelection() override;

	////////////////////////////////////////////////////////////
	/// \brief Actions to take upon deselection of the object
	///
	////////////////////////////////////////////////////////////
	virtual void deactivateSelection() override;

	////////////////////////////////////////////////////////////
	/// \brief Draws the object to the target applying its states
	/// 
	/// \param target -> Render target to draw to
	/// \param states -> Current render states
	/// 
	////////////////////////////////////////////////////////////
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

	///////////////////////////////////////////////////////////
	/// action is defined automatically, users are not allowed to alter it
	/// 
	///////////////////////////////////////////////////////////
	void setAction(std::function<void()> func) = delete;

	///////////////////////////////////////////////////////////
	/// /brief Add an function which gets called whenever slider is moved
	/// 
	///////////////////////////////////////////////////////////
	void attachAction(std::function<void()> func);

	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
private:

	Button m_bar;								/// < Sider rectangle
	float m_offset;								/// < distance of slider bar from left position
	float* m_variable;							/// < pointer to variable whose value needs to be altered
	float m_limits[2];							/// < lower and upper limit of the variable
	bool m_keepAsInteger;						/// < does variable acts as an integer or not

	std::function<void()> m_attached_action;	/// < Function Attached to Slider Movement
};


typedef std::unique_ptr<zui::Slider> Slider_ptr;


} // namespace zui