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

#import <XCTest/XCTest.h>

#import "JFManager.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

NS_ASSUME_NONNULL_BEGIN
@interface JFManager_Tests : XCTestCase

// MARK: Methods - Tests management
- (void)	testInitialization;

@end
NS_ASSUME_NONNULL_END

////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma mark

NS_ASSUME_NONNULL_BEGIN
@implementation JFManager_Tests

// =================================================================================================
// MARK: Methods - Tests management
// =================================================================================================

- (void)testInitialization
{
	// +defaultManager
	XCTAssert([JFManager defaultManager], @"Initializer '+defaultManager' did not return any object.");
	
	// +sharedManager
	JFManager* manager = [JFManager sharedManager];
	XCTAssert(manager, @"Initializer '+sharedManager' did not return any object.");
	XCTAssert((manager == [JFManager sharedManager]), @"Initializer '+sharedManager' did not return a singleton.");
	
	// -init
	XCTAssert([[JFManager alloc] init], @"Initializer '-init' did not return any object.");
}

@end
NS_ASSUME_NONNULL_END

////////////////////////////////////////////////////////////////////////////////////////////////////
