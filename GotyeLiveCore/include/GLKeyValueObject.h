//
//  GLKeyValueObject.h
//  Wowooh
//
//  Created by ouyang on 15/5/7.
//  Copyright (c) 2015年 Gotye. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GLKeyValueObject : NSObject <NSCoding>

+ (instancetype)objectWithDictionary:(NSDictionary *)dict;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

- (void)_setValue:(id)value forKey:(NSString *)key;
@end
