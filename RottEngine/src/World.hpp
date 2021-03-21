#pragma once
#include <unordered_map>
#include "Entity.hpp"
#include "RenderWindow.hpp"
#include "ui/UIEntity.hpp"

class World {
public:
	/// <summary> Adds the specified ui entity with specified name to the map. </summary>
	static void addUiEntity(std::string name, UIEntity* entity);

	/// <summary> Adds the specified entity with specified name to the map. </summary>
	static void addEntity(std::string name, Entity* entity);
	
	/// <summary> Renders all the entites. </summary>
	static void render();

	/// <summary> Returns the entity with specified name. Returns nullptr if entity with that name was not found. </summary>
	static Entity* findEntity(std::string name);

	/// <summary> Returns the ui entity with specified name. Returns nullptr if ui entity with that name was not found. </summary>
	static UIEntity* findUiEntity(std::string name);

	/// <summary> Cleans up the entities. </summary>
	static void terminate();

private:
	World();

private:
	static std::unordered_map<std::string, Entity*> m_entities;
	static std::unordered_map<std::string, UIEntity*> m_uiEntities;
};

