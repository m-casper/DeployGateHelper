DeployGate Helper for Cocos2d-x
===============================

Cocos2d-x で DeployGate を使用するためのヘルパーです。
(Cocos2d-x version: 2.1.2 (2013-3-20))

※Cocos2d-x についてはこちら -> http://www.cocos2d-x.org/
※DeployGate についてはこちら -> https://deploygate.com/


1.組み込み方法
使用するために必要なファイルは4つで、srcフォルダ以下に入れています。
配置場所も同じようなフォルダ構成にしていますが、javaのパッケージ名
については組み込む先のプロジェクトに合わせて変更してください。

 /Classes/DeployGateHelper.cpp
 /Classes/DeployGateHelper.h
 /proj.android/jni/DeployGateHelperJNI.cpp
 /proj.android/src/org/cocos2dx/dgsample/DeployGateHelper.java

また、DeployGate SDKのライブラリ(deploygatesdk.jar)は /proj.android/libs
の配下に設置してください。


2.呼び出し方
DeployGateHelper クラスのメソッドを呼び出してください。

例）DeployGateHelper::logVerbose("Send log text : Verbose");


3.その他
DeployGate の設定等については公式のサンプルを参照してください。
一通りの設定はサンプルプログラムに組み込んでいます。
リモートLogCatを有効にする場合はAndroidManifest.xmlに

 <uses-permission android:name="android.permission.READ_LOGS" />

を追加してください。
（サンプルプログラムは追加しています。）


4.ライセンス
Cocos2d-xと同じ The MIT License (MIT) を採用しています。
http://opensource.org/licenses/MIT


5.更新履歴
・2013/3/30 v1.0 GitHubに公開
