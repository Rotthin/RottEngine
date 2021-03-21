#include "Input.hpp"

std::unordered_map<int, bool> Input::m_keys;

void Input::setKeyState(int key, bool value) {
	m_keys[key] = value;
}

bool Input::getKeyState(int key) {
	return m_keys[key];
}
