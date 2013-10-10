#pragma once

#include "defines.h"

namespace star 
{
	enum LogLevel : byte
	{
		Info, 
		Warning, 
		Error, 
		Debug
	};

    class Logger {
    public:
		~Logger();
		// Static methods
		static Logger* GetInstance();
		static void ResetSingleton();

		void Initialize();
		void Log(LogLevel level, const tstring& pMessage, const tstring& tag = ANDROID_LOG_TAG) const;
		void _CheckGlError(const char* file, int line);
		#define CheckGlError() _CheckGlError(__FILE__,__LINE__);
	private:
		//SINGLETON IMPLEMENTATION
		//----------------------------------
		Logger(void);
		static Logger* m_LoggerPtr;
		//----------------------------------

		#ifdef _WIN32
		HANDLE m_ConsoleHandle;
		#endif

		// -------------------------
		// Disabling default copy constructor and default 
		// assignment operator.
		// -------------------------
		Logger(const Logger& t);
#ifdef _WIN32
		Logger(Logger&& t);
#endif
		Logger& operator=(const Logger& t);
    };
}