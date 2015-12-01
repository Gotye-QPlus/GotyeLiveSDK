//
//  GLChatUser.h
//  GotyeLiveChat
//
//  Created by Nick on 15/11/4.
//  Copyright © 2015年 AiLiao. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  用户具体信息
 */
@interface GLChatUser : NSObject

@property (nonatomic, copy) NSString * account;     //用户账号，即唯一ID
@property (nonatomic, copy) NSString * nickname;    //用户昵称

- (instancetype)initWithAccount:(NSString *)account nickname:(NSString *)nickname;

@end
