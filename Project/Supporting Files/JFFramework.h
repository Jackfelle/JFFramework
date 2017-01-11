//
//	The MIT License (MIT)
//
//	Copyright © 2015-2017 Jacopo Filié
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



#if FRAMEWORK
#pragma mark - Version info

//! Project version number for JFFramework.
FOUNDATION_EXPORT double JFFrameworkVersionNumber;

//! Project version string for JFFramework.
FOUNDATION_EXPORT const unsigned char JFFrameworkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <JFFramework/PublicHeader.h>

#endif



#pragma mark - Common headers

// System
#import	<CoreData/CoreData.h>
#import	<Foundation/Foundation.h>

// User
#import	"JFPreprocessorMacros.h"



#if JF_IOS || JF_TVOS
#pragma mark - iOS/tvOS specific system headers

// System
#import	<UIKit/UIKit.h>

#endif



#if JF_MACOS
#pragma mark - OSX specific system headers

// System
#import	<AppKit/AppKit.h>

#endif



#pragma mark - Common headers

// Core
#import	"JFAppDelegate.h"
#import	"JFConnectionMachine.h"
#import	"JFErrorsManager.h"
#import	"JFManager.h"
#import	"JFOpenCloseMachine.h"
#import	"JFStateMachine.h"
#import	"JFStateMachineErrors.h"

// Data Objects
#import	"JFByteStream.h"
#import	"JFColor.h"
#import	"JFString.h"
#import	"JFVersion.h"
#import	"JFWeakHook.h"

// User Interface
#import	"JFWindowController.h"

// Utilities (Addons)
#import	"NSBundle+JFFramework.h"

// Utilities
#import	"JFAsynchronousOperation.h"
#import	"JFLogger.h"
#import	"JFPreprocessorMacros.h"
#import	"JFShortcuts.h"
#import	"JFTypes.h"
#import	"JFUtilities.h"



#if JF_IOS
#pragma mark - iOS specific headers

// User interface (Addons)
#import	"UIButton+JFFramework.h"
#import	"UILabel+JFFramework.h"
#import	"UIStoryboard+JFFramework.h"

// User interface
#import	"JFActivityIndicatorView.h"
#import	"JFAlert.h"
#import	"JFAlertsController.h"

#endif



#if JF_MACOS
#pragma mark - OSX specific headers

// User interface (Addons)
#import	"NSStoryboard+JFFramework.h"

// User interface
#import	"JFAlert.h"
#import	"JFAlertsController.h"

#endif



#if JF_TVOS
#pragma mark - tvOS specific headers

// User interface (Addons)
#import	"UIButton+JFFramework.h"
#import	"UILabel+JFFramework.h"
#import	"UIStoryboard+JFFramework.h"

#endif