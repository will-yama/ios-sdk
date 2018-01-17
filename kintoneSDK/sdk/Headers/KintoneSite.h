//
//  KintoneSite.h
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

@class CBCredential;
@class KintoneApplication;

/**
 A class to represent the kintone domain
 
 Objects are created per domain, by specifying the credentials to be used with the kintone domains.
 */
@interface KintoneSite : NSObject

/// ---------------------------------
/// @name Property
/// ---------------------------------

/**
 Credentials related to 'KintoneSite'
 */
@property (nonatomic) CBCredential *cbCredential;

/// ---------------------------------
/// @name Create instance
/// ---------------------------------

/**
 Create an instance by specifing the credentials to use to connect to the kintone domain.
 
 @param credential //domain credentials
 
 @return 'KintoneSite' object
 */
- (KintoneSite *)initWithCredential:(CBCredential *)credential;

/// ---------------------------------
/// @name KintoneApplication Get
/// ---------------------------------

/**
 Gets the object of the kintone App that exists in the kintone domain.
 
 @param appId //App ID of the kintone App
 
 @return 'KintoneApplication' object
 */
- (KintoneApplication *)kintoneApplication:(int)appId;

@end
