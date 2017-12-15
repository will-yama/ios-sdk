//
//  KintoneError.h
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
 Error class.
 
If an error is created as a 'CBError', it is outputted to the log as a log level of 'CBLogLevelError'.
Using 'CBError'allows: wrapping of 'NSError'; displaying errors as 'UIAlertView'; providing resource controlled exclusive error data.
 */

@interface CBError : NSError

/// ---------------------------------
/// @name Property
/// ---------------------------------

/**
 Error code of 'CBError'.
 
 If 'CBError', 'code' becomes '-1', and an error code provided by the kintone SDK will be set in this property. If 'CBError' is based on 'NSError', 'code' and this property will become the same value.
 */
@property (nonatomic, copy, readonly) NSString *cbErrorCode;

/// ---------------------------------
/// @name Create CBError instance
/// ---------------------------------

/**
 Create a 'CBError' instance with the specified 'key'
 
The 'key' specified in 'KintoneErrorMessages.plist' of 'kintoneResouces.bundle' will be used.
The wording format in 'KintoneErrorMessages.plist' will follow  ["Formatting String Objects"](http://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/Strings/Articles/FormatStrings.html), 
and parameters included in the format can be denoted after 'key'.
 
 @param key     //'key' defined in 'KintoneErrorMessages.plist' of 'kintoneResouces.bundle'
 @param ...     //Error message format. Issued in order of 'DescriptionKey', 'FailureReasonKey', 'RecoverySuggestionKey'. If the specified 'key' does not exist in 'KintoneErrorMessages.plist', 'assert' will fail.
 
 @return        //Newly created 'CBError' instance
 */
+ (CBError *)errorWithFormat:(NSString *)key, ...;

/**
 Specified 'NSError" is wrapped, and returned as 'CBError'
 
 @param error 'NSError'
 
 @return Newly created 'CBError' instance
 */
+ (CBError *)errorWithNSError:(NSError *)error;

/**
 Creates an 'CBError' instance with the specified error data
 
 A low level method to create 'CBError' instance
 
 @param code                //error code
 @param description         //error description
 @param failureReason       //reason for error
 @param recoverySuggestion  //suggestions for overcoming the error
 
 @return                    //a newly created 'CBError' instance
 */
+ (CBError *)errorWithCode:(NSString *)code description:(NSString *)description failureReason:(NSString *)failureReason recoverySuggestion:(NSString *)recoverySuggestion;

/// ---------------------------------
/// @name Create UIAlertView
/// ---------------------------------

/**
 Returns UIAlertView that contains error data
 
The 'code', 'description', 'failureReason', 'recoverySuggestion' that are set are displayed in the alert view.
If parameters are set as 'nil' or empty strings, they will not be visible.
 */
- (UIAlertView *)alertView;

@end
