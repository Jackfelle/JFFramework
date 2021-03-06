//
//	The MIT License (MIT)
//
//	Copyright © 2016-2018 Jacopo Filié
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

#import "JFTypes.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

@class JFStateMachine;

////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// MARK: Macros - State constants
// =================================================================================================

#define JFStateNotAvailable				NSUIntegerMax
#define JFStateTransitionNone			0
#define JFStateTransitionNotAvailable	NSUIntegerMax

////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma mark

// =================================================================================================
// MARK: Types - State
// =================================================================================================

typedef NSUInteger	JFState;
typedef NSUInteger	JFStateTransition;

////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma mark

NS_ASSUME_NONNULL_BEGIN
@protocol JFStateMachineDelegate <NSObject>

// =================================================================================================
// MARK: Protocol - State management
// =================================================================================================

@optional - (void)	stateMachine:(JFStateMachine*)sender didPerformTransition:(JFStateTransition)transition context:(id __nullable)context;
@required - (void)	stateMachine:(JFStateMachine*)sender performTransition:(JFStateTransition)transition context:(id __nullable)context completion:(JFSimpleCompletionBlock)completion;
@optional - (void)	stateMachine:(JFStateMachine*)sender willPerformTransition:(JFStateTransition)transition context:(id __nullable)context;

@end
NS_ASSUME_NONNULL_END

////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma mark

NS_ASSUME_NONNULL_BEGIN
@interface JFStateMachine : NSObject

// MARK: Properties - Observers
#if __has_feature(objc_arc_weak)
@property (weak, nonatomic, readonly)	id<JFStateMachineDelegate>	delegate;
#else
@property (unsafe_unretained, nonatomic, readonly)	id<JFStateMachineDelegate>	delegate;
#endif

// MARK: Properties - State
@property (assign, readonly)	JFState				currentState;
@property (assign, readonly)	JFStateTransition	currentTransition;

// MARK: Methods - Memory management
- (instancetype)	init NS_UNAVAILABLE;
- (instancetype)	initWithState:(JFState)state delegate:(id<JFStateMachineDelegate>)delegate NS_DESIGNATED_INITIALIZER;

// MARK: Methods - State management
- (JFState)				finalStateForFailedTransition:(JFStateTransition)transition;
- (JFState)				finalStateForSucceededTransition:(JFStateTransition)transition;
- (NSArray<NSNumber*>*)	initialStatesForTransition:(JFStateTransition)transition;
- (void)				performTransition:(JFStateTransition)transition completion:(JFSimpleCompletionBlock __nullable)completion;
- (void)				performTransition:(JFStateTransition)transition context:(id __nullable)context completion:(JFSimpleCompletionBlock __nullable)completion;

// MARK: Methods - Utilities management
- (NSString* __nullable)	debugStringForState:(JFState)state;
- (NSString* __nullable)	debugStringForTransition:(JFStateTransition)transition;

@end
NS_ASSUME_NONNULL_END

////////////////////////////////////////////////////////////////////////////////////////////////////
