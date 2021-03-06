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



@protocol JFStoryboardObserver <NSObject>

@optional

- (void)	jf_storyboard:(UIStoryboard*)storyboard didInstantiateInitialViewController:(__kindof UIViewController*)viewController;
- (void)	jf_storyboard:(UIStoryboard*)storyboard didInstantiateViewController:(__kindof UIViewController*)viewController withIdentifier:(NSString*)identifier;
- (void)	jf_storyboard:(UIStoryboard*)storyboard didPerformSegue:(UIStoryboardSegue*)segue;
- (void)	jf_storyboard:(UIStoryboard*)storyboard willPerformSegue:(UIStoryboardSegue*)segue;

@end



#pragma mark



@interface UIStoryboard (JFFramework)

#pragma mark Properties

// Relationships
@property (strong, nonatomic, readonly)	NSMutableSet<id<JFStoryboardObserver>>*	jf_observers;

@end
