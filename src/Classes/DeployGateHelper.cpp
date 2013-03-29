#include "DeployGateHelper.h"

// Prototype
extern "C" void logJNI( int level, const char *text );
extern "C" std::string getAuthorUsernameJNI();
extern "C" std::string getLoginUsernameJNI();
extern "C" bool isAuthorizedJNI();
extern "C" bool isManagedJNI();
extern "C" bool isDeployGateAvaliableJNI();
extern "C" bool isInitializedJNI();
extern "C" void refreshJNI();
extern "C" void crashJNI( const char *text );


// Record VERBOSE, DEBUG, INFO, WARN, ERROR level event on DeployGate
void DeployGateHelper::log( int level, const char *text )
{
	logJNI( level, text );
}

// Get current app's author (i.e.
std::string DeployGateHelper::getAuthorUsername()
{
	return getAuthorUsernameJNI();
}

// Get current DeployGate username.
std::string DeployGateHelper::getLoginUsername()
{
	return getLoginUsernameJNI();
}

// Get whether current DeployGate user has this application in his/her available list.
bool DeployGateHelper::isAuthorized()
{
	return isAuthorizedJNI();
}

// Get whether this application and its package is known and managed under the DeployGate.
bool DeployGateHelper::isManaged()
{
	return isManagedJNI();
}

// Get whether DeployGate client service is available on this device.
bool DeployGateHelper::isDeployGateAvaliable()
{
	return isDeployGateAvaliableJNI();
}

// Get whether SDK is completed its intialization process and ready after install(Application).
bool DeployGateHelper::isInitialized()
{
	return isInitializedJNI();
}

// Request refreshing cached session values (e.g., isAuthorized, etc.) to the DeployGate service.
void DeployGateHelper::refresh()
{
	return refreshJNI();
}

// Throw RuntimeException
void DeployGateHelper::crash( const char *text )
{
	crashJNI( text );
}
