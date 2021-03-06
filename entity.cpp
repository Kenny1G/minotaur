//Kenny O, Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2 
//CS220 Final Project SP20
//entity.cpp


#include "entity.h"
#include "entitycontroller.h"
#include "uicontrol.h"
#include "chasehero.h"


Entity::Entity():
m_pos(new Position),
m_glyph(""),
m_properties(""),
m_controller(nullptr)
 {}

Entity::~Entity() {
	if (m_controller) delete m_controller;
	delete m_pos;
}

// Set the glyph that will represent this Entity.
// Should consist of a single character.
void Entity::setGlyph(const std::string &glyph) {
  m_glyph = glyph;
}

// Set the properties of this Entity.  Each character in the
// string represents a single property.
void Entity::setProperties(const std::string &props) {
  m_properties = props;
}

// Get the glyph representing this Entity.
std::string Entity::getGlyph() const {
	return m_glyph;
}

// Get the string containing this Entity's properties.
std::string Entity::getProperties() const {
	return m_properties;
}

// Return true if the Entity's properties contain the specified
// character, false otherwise.
bool Entity::hasProperty(char prop) const {
	for (unsigned int i = 0; i < m_properties.length(); ++i) {
		if (prop == m_properties.at(i)) {
			return true;
		}
	}
  return false;
}

// Set this Entity's EntityController, which will determine how it moves.
// The Entity assumes responsibility for deleting it.
void Entity::setController(EntityController *controller) {
  m_controller = controller;
}

// Get this Entity's EntityController.
EntityController* Entity::getController() {
  return m_controller;
}

// Set this Entity's Position.
void Entity::setPosition(const Position &pos) {
  *m_pos = pos;
}

// Return this Entity's Position.
Position Entity::getPosition() const {
  return *m_pos;
}
