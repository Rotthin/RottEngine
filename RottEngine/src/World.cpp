#include "World.hpp"

std::unordered_map<std::string, Entity*> World::m_entities;
std::unordered_map<std::string, UIEntity*> World::m_uiEntities;

void World::terminate() {
	for (auto& entity : m_entities) {
		delete entity.second;
	}

	for (auto& entity : m_uiEntities) {
		delete entity.second;
	}
}

void World::addUiEntity(std::string name, UIEntity* entity) {
	m_uiEntities.insert({name, entity});
}

void World::addEntity(std::string name, Entity* entity) {
	m_entities.insert({name, entity});
}

void World::render() {
	for (auto& entity : m_entities) {
		entity.second->render();
	}
	
	// Draw the UI at the end.
	for (auto& entity : m_uiEntities) {
		entity.second->render();
	}
}

Entity* World::findEntity(std::string name) {
	return m_entities[name];
}

UIEntity* World::findUiEntity(std::string name) {
	return m_uiEntities[name];
}