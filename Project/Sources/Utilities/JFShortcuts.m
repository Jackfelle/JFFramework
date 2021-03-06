//
//	The MIT License (MIT)
//
//	Copyright © 2015-2018 Jacopo Filié
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in all
//	copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//	SOFTWARE.
//

////////////////////////////////////////////////////////////////////////////////////////////////////

#import "JFShortcuts.h"

#import "JFVersion.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

NS_ASSUME_NONNULL_BEGIN
@implementation JF

// =================================================================================================
// MARK: Generic
// =================================================================================================

+ (AppDelegate* __nullable)applicationDelegate
{
	Class class = NSClassFromString(@"AppDelegate");
	if(!class)
		return nil;
	
	id<JFApplicationDelegate> retObj = self.sharedApplication.delegate;
	if(!retObj || ![retObj isKindOfClass:class])
		return nil;
	
	return (AppDelegate*)retObj;
}

#if JF_IOS || JF_TVOS
+ (UIDevice*)currentDevice
{
	return [UIDevice currentDevice];
}
#endif

#if JF_IOS
+ (UIDeviceOrientation)currentDeviceOrientation
{
	return self.currentDevice.orientation;
}

+ (UIInterfaceOrientation)currentInterfaceOrientation
{
	return self.sharedApplication.statusBarOrientation;
}
#endif

+ (NSBundle*)mainBundle
{
	return [NSBundle mainBundle];
}

+ (NSNotificationCenter*)mainNotificationCenter
{
	return [NSNotificationCenter defaultCenter];
}

+ (NSOperationQueue*)mainOperationQueue
{
	return [NSOperationQueue mainQueue];
}

#if JF_IOS || JF_TVOS
+ (UIScreen*)mainScreen
{
	return [UIScreen mainScreen];
}
#endif

+ (NSProcessInfo*)processInfo
{
	return [NSProcessInfo processInfo];
}

+ (JFApplication*)sharedApplication
{
	return [JFApplication sharedApplication];
}

#if JF_MACOS
+ (NSWorkspace*)sharedWorkspace
{
	return [NSWorkspace sharedWorkspace];
}
#endif

#if JF_IOS || JF_TVOS
+ (UIViewAutoresizing)viewAutoresizingFlexibleMargins
{
	return (UIViewAutoresizing)(UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleTopMargin);
}

+ (UIViewAutoresizing)viewAutoresizingFlexibleSize
{
	return (UIViewAutoresizing)(UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth);
}
#endif

// =================================================================================================
// MARK: Info
// =================================================================================================

+ (NSString* __nullable)appBuild
{
	return JFApplicationInfoForKey(@"CFBundleVersion");
}

+ (NSString* __nullable)appDetailedVersion
{
	NSString* appVersion = self.appVersion;
	NSString* appBuild = self.appBuild;
	
	BOOL isAppVersionValid = !JFStringIsNullOrEmpty(appVersion);
	BOOL isAppBuildValid = !JFStringIsNullOrEmpty(appBuild);
	
	if(isAppBuildValid)
		return [NSString stringWithFormat:@"%@ (%@)", (isAppVersionValid ? appVersion : @"0.0"), appBuild];
	else if(isAppVersionValid)
		return appVersion;
	
	return nil;
}

+ (NSString* __nullable)appDisplayName
{
	return JFApplicationInfoForKey(@"CFBundleDisplayName");
}

+ (NSString* __nullable)appIdentifier
{
	return JFApplicationInfoForKey(@"CFBundleIdentifier");
}

+ (NSString* __nullable)appLaunchStoryboard
{
	return JFApplicationInfoForKey(@"UILaunchStoryboardName");
}

+ (NSString* __nullable)appName
{
	return JFApplicationInfoForKey(@"CFBundleName");
}

+ (NSString* __nullable)appMainStoryboard
{
	return JFApplicationInfoForKey(@"UIMainStoryboardFile");
}

+ (NSString* __nullable)appVersion
{
	return JFApplicationInfoForKey(@"CFBundleShortVersionString");
}


// =================================================================================================
// MARK: System
// =================================================================================================

#if JF_IOS || JF_TVOS
+ (BOOL)isAppleTV
{
	return (self.userInterfaceIdiom == UIUserInterfaceIdiomTV);
}

+ (BOOL)isCarPlay
{
	return (self.userInterfaceIdiom == UIUserInterfaceIdiomCarPlay);
}

+ (BOOL)isIPad
{
	return (self.userInterfaceIdiom == UIUserInterfaceIdiomPad);
}

+ (BOOL)isIPhone
{
	return (self.userInterfaceIdiom == UIUserInterfaceIdiomPhone);
}

+ (NSString*)systemVersion
{
	return self.currentDevice.systemVersion;
}

+ (UIUserInterfaceIdiom)userInterfaceIdiom
{
	return self.currentDevice.userInterfaceIdiom;
}
#endif

@end
NS_ASSUME_NONNULL_END
