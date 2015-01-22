/*
 * Licensed Materials - Property of IBM
 * 5725-I43 (C) Copyright IBM Corp. 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

//
//  WL.h
//  WorklightStaticLibProject
//
//

#import <Foundation/Foundation.h>
#import "WLWebFrameworkInitResult.h"
#import "WLActionReceiver.h"

#pragma mark -
#pragma mark - WL public API
/**
 * @ingroup hybrid main
 *
 * The WLInitWebFrameworkDelegate protocol declares the method wlInitWebFrameworkDidCompleteWithResult.
 * This method provides information about the result of the IBM Worklight web framework initialization.
 *
 */
@protocol WLInitWebFrameworkDelegate <NSObject>
@required
/**
 *
 * This method is called after the Worklight web framework initialization is complete and web resources are ready to be used.
 *
 *@param WLWebFrameworkInitResult: result The initialization result
 */
-(void)wlInitWebFrameworkDidCompleteWithResult:(WLWebFrameworkInitResult *)result;
@end
/**
 * @ingroup hybrid main
 *
 * The WL singleton class provides a centralized point of control and coordination for Worklight hybrid apps.
 * A major role of this class is to handle the initialization of a Worklight hybrid application.
 *
 */
@interface WL : NSObject
/**
 * Get the singleton instance
 */
+ (id)sharedInstance;

/** Initialize the IBM Worklight web framework
 
 @param delegate The delegate conforming to the WLInitWebFrameworkDelegate protocol
 */
-(void) initializeWebFrameworkWithDelegate :(id<WLInitWebFrameworkDelegate>)delegate;
/**
 * This method returns the path to the application main HTML file.
 @attention This API should be used after the successful callback of wlInitWebFrameworkDidCompleteWithResult. This is to ensure that the Worklight framework initialization is complete and the web resources are ready to be used.
 *
 * @Returns the URL of the main HTML file
 */
-(NSString *) mainHtmlFilePath;
/**
 * This method will show a splash screen on-top of the current window.
 * Worklight default application will show a splash screen during application start-up, and will hide it using the JavaScript API WL.App.hideSplashScreen(), once the main html page is loaded.
 * This is done to improve the user experience and allow smooth transition from the native application container to the WebView, hiding the underlying page loading activity.
 * This method will use the launch images supplied in the application XCode project.
 * This method is not related to the splash screen feature which is available through the Cordova framework. 
 
   @attention A root view controller must be defined before calling this method.
 */
-(void) showSplashScreen;
/**
 * Hides a shown splash screen.
 *
 */
-(void) hideSplashScreen;

/**
 * Sends action to JavaScript action receivers. 
 * 
 * Note: if there are no JavaScript action receivers registered, the action is queued until a JavaScript action receiver is registered. 
 * 
 * @param action custom string representing an action
*/
-(void)sendActionToJS:(NSString*)action;

/**
 * Sends action and optional data object to JavaScript action receivers.
 *
 * Note: if there are no JavaScript action receivers registered, the action is queued until a JavaScript action receiver is registered.
 * @param action custom string representing an action
 * @param data (optional) custom NSDictionary instance containing key-value pairs
 * <p>
 * Example:
 * </p>
 * <pre> <code>
 * [[WL sharedInstance] sendActionToJS:@"doSomething"];
 * NSMutableDictionary *data = [NSDictionary dictionaryWithObject:@"12345" forKey:@"customData"];
 * [[WL sharedInstance] sendActionToJS:@"doSomething" data:data];
 * </code></pre>
*/
-(void)sendActionToJS:(NSString *)action withData:(NSDictionary*)data;

 /**
 * Registers a new native action receiver with the Worklight framework.
 *
 * @param actionReceiver object that implements the WLActionReceiver protocol
 * @since IBM Worklight V6.2.0
 *
 * <p>
 * Example:
 * </p>
 * <pre> <code>
 * MyReceiver *myReceiver = [MyReceiver new];
 * [[WL sharedInstance] addActionReceiver:myReceiver];
 * </code></pre>
 */
-(void)addActionReceiver:(id<WLActionReceiver>)wlActionreceiver;

/**
 * Unregisters a receiver from receiving actions.
 * After calling this API, the receiver will no longer receive actions.
 *
 * @param actionReceiver object that implements the WLActionReceiver protocol
 *
 * <p>
 * Example:
 * </p>
 * <pre> <code>
 * MyReceiver *myReceiver = [MyReceiver new];
 * [[WL sharedInstance] removeActionReceiver:myReceiver];
 * </code></pre>
*/
-(void)removeActionReceiver:(id<WLActionReceiver>)wlActionreceiver;

@end

