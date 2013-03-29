/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.dgsample;

import org.cocos2dx.lib.Cocos2dxActivity;

import com.deploygate.sdk.DeployGate;
import com.deploygate.sdk.DeployGateCallback;

import android.os.Bundle;
import android.util.Log;

public class MainActivity extends Cocos2dxActivity implements DeployGateCallback
{
	static { System.loadLibrary("game"); }

	private static final String TAG = MainActivity.class.getName();

	protected void onCreate(Bundle savedInstanceState)
	{
		Log.d(TAG, "Cocos2d-x : onCreate");

		super.onCreate(savedInstanceState);
	}

	@Override
	protected void onResume()
	{
		Log.d(TAG, "Cocos2d-x : onResume");

		super.onResume();

		// register for callback, also request refreshing (second argument)
		DeployGate.registerCallback(this, true);
	}

	@Override
	protected void onPause()
	{
		Log.d(TAG, "Cocos2d-x : onPause");

		super.onPause();

		// unregister to stop callback
		DeployGate.unregisterCallback(this);
	}

	//-----------------------------------------------------------------------
	// DeployGate callback
	//-----------------------------------------------------------------------

	@Override
	public void onInitialized(boolean isServiceAvailable)
	{
		// will be called to notify DeployGate SDK has initialized
		Log.d(TAG, "DeployGate SDK initialized, is DeployGate available? : " + isServiceAvailable);
	}

	@Override
    public void onStatusChanged(boolean isManaged, boolean isAuthorized, String loginUsername, boolean isStopped)
	{
		// will be called when DeployGate status has changed, including this
		// activity starting and resuming.
		Log.d(TAG, "DeployGate Status Changed : isManaged = " + isManaged
				+ " : isAuthorized = " + isAuthorized
				+ " : loginUsername = " + loginUsername
				+ " : isStopped = " + isStopped);
	}

	@Override
    public void onUpdateAvailable(int serial, String versionName, int versionCode)
	{
		// will be called on app update is available.
		Log.d(TAG, "DeployGate Update Available : serial = " + serial
				+ " : versionName = " + versionName
				+ " : versionCode = " + versionCode);
	}
}
