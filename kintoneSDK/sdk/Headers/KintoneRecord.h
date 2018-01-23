//
//  KintoneRecord.h
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

@class KintoneField;
@class KintoneRecordNumberField;
@class KintoneCreatorField;
@class KintoneCreatedTimeField;
@class KintoneModifierField;
@class KintoneUpdatedTimeField;

/**
 A class to represent kintone App records
 */
@interface KintoneRecord : NSObject

/// ---------------------------------
/// @name Property
/// ---------------------------------

/**
 Fields in the record
 */
@property (nonatomic, readonly) NSMutableDictionary *fields;

/**
The record number field.

'nil' if not set.
 */
@property (nonatomic, readonly) KintoneRecordNumberField *recordNumber;

/**
 The 'Created by' field of the record.
 
'nil' if not set.
 */
@property (nonatomic, readonly) KintoneCreatorField *creator;

/**
 The 'Created datetime' field of the record
 
'nil' if not set.
 */
@property (nonatomic, readonly) KintoneCreatedTimeField *createdTime;

/**
 The 'Updated by' field of the record.
 
'nil' if not set.
 */
@property (nonatomic, readonly) KintoneModifierField *modifier;

/**
 The 'Updated datetime' field of the record.
 
'nil' if not set.
 */
@property (nonatomic, readonly) KintoneUpdatedTimeField *updatedTime;

/// ---------------------------------
/// @name Add fields
/// ---------------------------------

/**

 レコードに指定したフィールドを追加します。
 
 @param field //The field to add
 */
- (void)addField:(KintoneField *)field;

/// ---------------------------------
/// @name Create a KintoneRecord from json data
/// ---------------------------------

/**
 Creates 'KintoneRecord' from json data.
 
 @param JSON // The JSON for the success Block parameter for '[KintoneAPI record:success:failure:queue:]'
 
 @return The created 'KintoneRecord' object
 */
+ (KintoneRecord *)kintoneRecordFromJSON:(id)JSON;

+ (KintoneRecord *)kintoneRecordFromDictionary:(NSDictionary *)record;

/**
 Creates 'NSArray' of 'KintoneRecord' from json data
 
 @param JSON `[KintoneAPI recordsWithFields:query:success:failure:queue:]` の success Block 引数の JSON
 
 @return 生成された `KintoneRecord`
 */
+ (NSArray *)kintoneRecordsFromJSON:(id)JSON;

@end
