package org.cocos2dx.dgsample;

import com.deploygate.sdk.DeployGate;

public class DeployGateHelper
{
	public static final int ANDROID_LOG_UNKNOWN = 0;
	public static final int ANDROID_LOG_DEFAULT = 1;
	public static final int ANDROID_LOG_VERBOSE = 2;
	public static final int ANDROID_LOG_DEBUG = 3;
	public static final int ANDROID_LOG_INFO = 4;
	public static final int ANDROID_LOG_WARN = 5;
	public static final int ANDROID_LOG_ERROR = 6;
	public static final int ANDROID_LOG_FATAL = 7;

	/**
	 * Record VERBOSE, DEBUG, INFO, WARN, ERROR level event on DeployGate
	 * @param level Output log level
	 * @param text Text body to be send. May be truncated if it's too long.
	 */
	public static void log( int level, String text )
	{
		switch( level )
		{
		case ANDROID_LOG_VERBOSE:
	        DeployGate.logVerbose(text);
			break;
		case ANDROID_LOG_DEBUG:
	        DeployGate.logDebug(text);
			break;
		case ANDROID_LOG_INFO:
	        DeployGate.logInfo(text);
			break;
		case ANDROID_LOG_WARN:
	        DeployGate.logWarn(text);
			break;
		case ANDROID_LOG_ERROR:
	        DeployGate.logError(text);
			break;
		}
	}

	/**
	 * Get current app's author (i.e.
	 * @return Author username of current app. May be null.
	 */
	public static String getAuthorUsername()
	{
		return DeployGate.getAuthorUsername();
	}

	/**
	 * Get current DeployGate username.
	 * @return Current user of DeployGate. May be null.
	 */
	public static String getLoginUsername()
	{
		return DeployGate.getLoginUsername();
	}

	/**
	 * Get whether current DeployGate user has this application in his/her available list.
	 * @return true if current DeployGate user has available list which contains this application. false otherwise. If no install() called ever, this always returns false.
	 */
	public static boolean isAuthorized()
	{
		return DeployGate.isAuthorized();
	}

	/**
	 * Get whether this application and its package is known and managed under the DeployGate.
	 * @return true if DeployGate knows and manages this package. false otherwise. If no install() called ever, this always returns false.
	 */
	public static boolean isManaged()
	{
		return DeployGate.isManaged();
	}

	/**
	 * Get whether DeployGate client service is available on this device.
	 * @return true if valid DeployGate client is available. false otherwise. If no install() called ever, this always returns false.
	 */
	public static boolean isDeployGateAvaliable()
	{
		return DeployGate.isDeployGateAvaliable();
	}

	/**
	 * Get whether SDK is completed its intialization process and ready after install(Application).
	 * @return true if SDK is ready. false otherwise. If no install() called ever, this always returns false.
	 */
	public static boolean isInitialized()
	{
		return DeployGate.isInitialized();
	}

	/**
	 * Request refreshing cached session values (e.g., isAuthorized, etc.) to the DeployGate service.
	 */
	public static void refresh()
	{
		DeployGate.refresh();
	}

	/**
	 * Throw RuntimeException
	 * @param text Detail message.
	 */
	public static void crash( String text )
	{
		throw new RuntimeException(text);
	}
}
