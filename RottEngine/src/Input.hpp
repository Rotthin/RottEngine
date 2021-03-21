#pragma once
#include <unordered_map>

#define ROTT_ENGINE_PRESSED true
#define ROTT_ENGINE_NOT_PRESSED false

class Input {
public:
	/// <summary> Returns the state of the specified key. True if pressed, false if not.</summary>
	static bool getKeyState(int key);

	/// <summary> Sets the state of the specified key to the specified value. </summary>
	static void setKeyState(int key, bool value);

private:
	Input() {}

private:
	static std::unordered_map<int, bool> m_keys;
};

