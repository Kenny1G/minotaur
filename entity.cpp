#include "entity.h"
#include "entitycontroller.h"


Entity::Entity()
{}
Entity::~Entity()
{}

// Set the glyph that will represent this Entity.
// Should consist of a single character.
void Entity::setGlyph(const std::string &glyph)
{
}

// Set the properties of this Entity.  Each character in the
// string represents a single property.
void Entity::setProperties(const std::string &props)
{
}

// Get the glyph representing this Entity.
std::string Entity::getGlyph() const
{
	return "M";
}

// Get the string containing this Entity's properties.
std::string Entity::getProperties() const
{
	return "JOJO";
}

// Return true if the Entity's properties contain the specified
// character, false otherwise.
bool Entity::hasProperty(char prop) const
{
	return true;
}

// Set this Entity's EntityController, which will determine how it moves.
// The Entity assumes responsibility for deleting it.
void Entity::setController(EntityController *controller)
{
}

// Get this Entity's EntityController.
EntityController Entity::*getController()
{
	return nullptr;
}

// Set this Entity's Position.
void Entity::setPosition(const Position &pos)
{
}

// Return this Entity's Position.
Position Entity::getPosition() const
{
	Position *pos = new Position();
	return *pos;
}
