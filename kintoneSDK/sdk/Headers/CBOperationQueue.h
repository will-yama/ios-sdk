//
//  CBOperationQueue.h
//
//  Copyright 2013 Cybozu
//
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not
//  use this file except in compliance with the License.  You may obtain a copy
//  of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
//  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
//  License for the specific language governing permissions and limitations under
//  the License.
//

#import <Foundation/Foundation.h>

/**
  A Class that provides the 'NSOperationQueue' Singleton
 */
@interface CBOperationQueue : NSOperationQueue

/**
 Returns the Singleton default settings 'NSOperationQueue'
 
 @return `NSOperationQueue`
 */
+ (CBOperationQueue *)sharedConcurrentQueue;

/**
 Returns 'NSOperationQueue' Singleton with Concurrent operation count 1
 
 Use when you need to ensure the execution sequence of 'NSOperation' set in 'NSOperationQueue'
 
 @return 'NSOperationQueue' with 'maxConcurrentOperationCount' of 1 
 */
+ (CBOperationQueue *)sharedNonConcurrentQueue;

@end
