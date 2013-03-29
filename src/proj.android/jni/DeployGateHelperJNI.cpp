#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <android/log.h>
#include <string>

using namespace cocos2d;

#define LOG_TAG		"DeployGateHelperJNI"
#define LOGD(...)	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define CLASS_NAME	"org/cocos2dx/dgsample/DeployGateHelper"

#define _GET_METHOD(info, name, param)	JniHelper::getStaticMethodInfo(info, CLASS_NAME, name, param)

extern "C" {
//-----------------------------------------------------------------------------

// Record VERBOSE, DEBUG, INFO, WARN, ERROR level event on DeployGate
void logJNI( int level, const char *text )
{
	JniMethodInfo methodInfo;

	if( !_GET_METHOD(methodInfo, "log", "(ILjava/lang/String;)V") )
		return;

	jstring textArg = methodInfo.env->NewStringUTF(text);

	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, level, textArg);
	methodInfo.env->DeleteLocalRef(textArg);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

// Get current app's author (i.e.
std::string getAuthorUsernameJNI()
{
	JniMethodInfo methodInfo;
	std::string ret = "";

	if( _GET_METHOD(methodInfo, "getAuthorUsername", "()Ljava/lang/String;") )
	{
		jstring string = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
		const char *str = methodInfo.env->GetStringUTFChars(string, NULL);
		if( str != NULL )
			ret = str;
		methodInfo.env->ReleaseStringUTFChars(string, str);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	return ret;
}

// Get current DeployGate username.
std::string getLoginUsernameJNI()
{
	JniMethodInfo methodInfo;
	std::string ret = "";

	if( _GET_METHOD(methodInfo, "getLoginUsername", "()Ljava/lang/String;") )
	{
		jstring string = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
		const char *str = methodInfo.env->GetStringUTFChars(string, NULL);
		if( str != NULL )
			ret = str;
		methodInfo.env->ReleaseStringUTFChars(string, str);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	return ret;
}

// Get whether current DeployGate user has this application in his/her available list.
bool isAuthorizedJNI()
{
	JniMethodInfo methodInfo;

	if( !_GET_METHOD(methodInfo, "isAuthorized", "()Z") )
		return false;

	bool ret = methodInfo.env->CallStaticFloatMethod(methodInfo.classID, methodInfo.methodID);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);

	return ret;
}

// Get whether this application and its package is known and managed under the DeployGate.
bool isManagedJNI()
{
	JniMethodInfo methodInfo;

	if( !_GET_METHOD(methodInfo, "isManaged", "()Z") )
		return false;

	bool ret = methodInfo.env->CallStaticFloatMethod(methodInfo.classID, methodInfo.methodID);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);

	return ret;
}

// Get whether DeployGate client service is available on this device.
bool isDeployGateAvaliableJNI()
{
	JniMethodInfo methodInfo;

	if( !_GET_METHOD(methodInfo, "isDeployGateAvaliable", "()Z") )
		return false;

	bool ret = methodInfo.env->CallStaticFloatMethod(methodInfo.classID, methodInfo.methodID);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);

	return ret;
}

// Get whether SDK is completed its intialization process and ready after install(Application).
bool isInitializedJNI()
{
	JniMethodInfo methodInfo;

	if( !_GET_METHOD(methodInfo, "isInitialized", "()Z") )
		return false;

	bool ret = methodInfo.env->CallStaticFloatMethod(methodInfo.classID, methodInfo.methodID);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);

	return ret;
}

// Request refreshing cached session values (e.g., isAuthorized, etc.) to the DeployGate service.
void refreshJNI()
{
	JniMethodInfo methodInfo;

	if( !_GET_METHOD(methodInfo, "refresh", "()V") )
		return;

	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	methodInfo.env->DeleteLocalRef( methodInfo.classID );
}

// Throw RuntimeException
void crashJNI( const char *text )
{
	JniMethodInfo methodInfo;

	if( !_GET_METHOD(methodInfo, "crash", "(Ljava/lang/String;)V") )
		return;

	jstring textArg = methodInfo.env->NewStringUTF(text);

	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, textArg);
	methodInfo.env->DeleteLocalRef(textArg);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

//-----------------------------------------------------------------------------
}
