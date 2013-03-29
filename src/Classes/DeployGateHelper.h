#ifndef  _DEPLOY_GATE_HELPER_H_
#define  _DEPLOY_GATE_HELPER_H_

#include <stdio.h>
#include <string>
#include <android/log.h>

class DeployGateHelper
{
public:
	static void log( int level, const char *text );
	static std::string getAuthorUsername();
	static std::string getLoginUsername();
	static bool isAuthorized();
	static bool isManaged();
	static bool isDeployGateAvaliable();
	static bool isInitialized();
	static void refresh();
	static void crash( const char *text );

	static void logVerbose( const char *text )	{ log( ANDROID_LOG_VERBOSE, text ); }
	static void logDebug( const char *text )	{ log( ANDROID_LOG_DEBUG, text ); }
	static void logInfo( const char *text )		{ log( ANDROID_LOG_INFO, text ); }
	static void logWarn( const char *text )		{ log( ANDROID_LOG_WARN, text ); }
	static void logError( const char *text )	{ log( ANDROID_LOG_ERROR, text ); }
};

#endif // _DEPLOY_GATE_HELPER_H_
