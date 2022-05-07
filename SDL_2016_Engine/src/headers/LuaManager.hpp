#pragma once
#ifndef LUAMANAGER_H
#define LUAMANAGER_H

template<typename T> class SingletonHolder;
struct lua_State;
class LuaManager {
	public:
		bool init();
		bool getInit();
		bool release();
		
		lua_State* getState() const;
		//include get status function

	private:
		friend class SingletonHolder<LuaManager>;
		LuaManager();
		LuaManager(const LuaManager&) = delete;
		LuaManager& operator=(LuaManager) = delete;
		compl LuaManager();


	private:
		int m_Status;
		static lua_State* m_spLuaState;
};

#endif