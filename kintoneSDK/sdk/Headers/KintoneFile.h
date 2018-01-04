//
//  KintoneFile.h
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
 kintone file class.
 
 To be used for file operations on Attachment fields. Use together with 'KintoneFileField'.
 */
@interface KintoneFile : NSObject

/// ---------------------------------
/// @name Property
/// ---------------------------------

/**
 The mime type of the file.
 */
@property (nonatomic, copy, readonly) NSString *contentType;

/**
 The fileKey, which is needed for file operations on kintone Apps.
 */
@property (nonatomic, copy, readonly) NSString *fileKey;

/**
 The file name.
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 The file size.
 */
@property (nonatomic, readonly) int size;

/**
 The file data.
 */
@property (nonatomic, readonly) NSData *data;

/**
 Flag for deletion. If YES, the file will be deleted.
 */
@property (nonatomic) bool deleted;

/// ---------------------------------
/// @name KintoneFile //Create instance
/// ---------------------------------

- (KintoneFile *)initWithProperties:(NSDictionary *)properties;

/**
 Return a newly created 'kintoneFile' instnace
 
 @param data //The file data
 @param name //The file name
 @param contentType //The mime type of the file
 
 @return 'kintone File' instance
 */
- (KintoneFile *)initWithData:(NSData *)data name:(NSString *)name contentType:(NSString *)contentType;

/// ---------------------------------
/// @name Other methods
/// ---------------------------------

- (NSDictionary *)json;

/**
 Sets the fileKey from json format data.
 
 To be used within the success block of '[KintoneAPI fileUploadWithFile:success:failure:queue:]'/
 
 @param fileKey //The value of the fileKey
 */
- (void)setFileKeyWithJSONDictionary:(NSDictionary *)fileKey;

@end
