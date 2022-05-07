#include "../include/Lua/lua.hpp"
#include "headers/LuaManager.hpp"

lua_State* LuaManager::m_spLuaState = nullptr;

LuaManager::LuaManager() :m_Status(0) {}

LuaManager::compl LuaManager() {}

bool LuaManager::init() {
	m_spLuaState = luaL_newstate();
	luaL_openlibs(m_spLuaState);

	if (!m_spLuaState) return false;
	
	//load file:
	//m_Status = luaL_loadfile(m_spLuaState, PATH_TO_TILE_AS_STRING);
	if (m_Status) {
		//flag error
		return false;
	}
	return true;
}

bool LuaManager::getInit() { return m_spLuaState != nullptr; }

bool LuaManager::release() {
	if (m_spLuaState) {
		lua_close(m_spLuaState);
		return true;
	}
	return false;
}

lua_State* LuaManager::getState() const {
	return LuaManager::m_spLuaState;
}