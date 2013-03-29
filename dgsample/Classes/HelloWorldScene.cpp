#include "HelloWorldScene.h"
#include "DeployGateHelper.h"

using namespace cocos2d;

enum BUTTON_ID
{
	BUTTON_NONE = 0,
	BUTTON_VERBOSE,
	BUTTON_DEBUG,
	BUTTON_INFO,
	BUTTON_WARN,
	BUTTON_ERROR,
	BUTTON_CRASH,
};


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    // DeployGate test button : verbose
    CCMenuItemImage *pButtonItem;
    pButtonItem = CCMenuItemImage::create("btn_verbose1.png", "btn_verbose2.png", this, menu_selector(HelloWorld::buttonPushCallback) );
    pButtonItem->setPosition(ccp(100, size.height - 100));
    pButtonItem->m_uID = BUTTON_VERBOSE;
    pMenu = CCMenu::create(pButtonItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    // DeployGate test button : debug
    pButtonItem = CCMenuItemImage::create("btn_debug1.png", "btn_debug2.png", this, menu_selector(HelloWorld::buttonPushCallback) );
    pButtonItem->setPosition(ccp(100, size.height - 150));
    pButtonItem->m_uID = BUTTON_DEBUG;
    pMenu = CCMenu::create(pButtonItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    // DeployGate test button : info
    pButtonItem = CCMenuItemImage::create("btn_info1.png", "btn_info2.png", this, menu_selector(HelloWorld::buttonPushCallback) );
    pButtonItem->setPosition(ccp(100, size.height - 200));
    pButtonItem->m_uID = BUTTON_INFO;
    pMenu = CCMenu::create(pButtonItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    // DeployGate test button : warn
    pButtonItem = CCMenuItemImage::create("btn_warn1.png", "btn_warn2.png", this, menu_selector(HelloWorld::buttonPushCallback) );
    pButtonItem->setPosition(ccp(100, size.height - 250));
    pButtonItem->m_uID = BUTTON_WARN;
    pMenu = CCMenu::create(pButtonItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    // DeployGate test button : error
    pButtonItem = CCMenuItemImage::create("btn_error1.png", "btn_error2.png", this, menu_selector(HelloWorld::buttonPushCallback) );
    pButtonItem->setPosition(ccp(100, size.height - 300));
    pButtonItem->m_uID = BUTTON_ERROR;
    pMenu = CCMenu::create(pButtonItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    // DeployGate test button : crash
    pButtonItem = CCMenuItemImage::create("btn_crash1.png", "btn_crash2.png", this, menu_selector(HelloWorld::buttonPushCallback) );
    pButtonItem->setPosition(ccp(100, size.height - 380));
    pButtonItem->m_uID = BUTTON_CRASH;
    pMenu = CCMenu::create(pButtonItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);


    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::buttonPushCallback(CCObject* pSender)
{
	switch( pSender->m_uID )
	{
	case BUTTON_VERBOSE:
		DeployGateHelper::logVerbose("Send log text : Verbose");
		CCLOG("getAuthorUsername = %s", DeployGateHelper::getAuthorUsername().c_str());
		CCLOG("getLoginUsername = %s", DeployGateHelper::getLoginUsername().c_str());
		CCLOG("isAuthorized = %d", DeployGateHelper::isAuthorized());
		CCLOG("isManaged = %d", DeployGateHelper::isManaged());
		CCLOG("isDeployGateAvaliable = %d", DeployGateHelper::isDeployGateAvaliable());
		CCLOG("isInitialized = %d", DeployGateHelper::isInitialized());
		DeployGateHelper::refresh();
		break;
	case BUTTON_DEBUG:
		DeployGateHelper::logDebug("Send log text : Debug");
		break;
	case BUTTON_INFO:
		DeployGateHelper::logInfo("Send log text : Info");
		break;
	case BUTTON_WARN:
		DeployGateHelper::logWarn("Send log text : Warn");
		break;
	case BUTTON_ERROR:
		DeployGateHelper::logError("Send log text : Error");
		break;
	case BUTTON_CRASH:
		DeployGateHelper::crash("Crash!");
		break;
	}
}
