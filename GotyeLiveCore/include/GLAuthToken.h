//
//  GLAuthToken.h
//  GotyeLiveCore
//
//  Created by Nick on 15/10/29.
//  Copyright © 2015年 AiLiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GLKeyValueObject.h"

/**
 角色级别枚举
 */
typedef enum {
    /**
     *  后台用户
     */
    GLAuthTokenRoleAPI = 1,
    /**
     *  主播用户
     */
    GLAuthTokenRolePresenter = 2,
    /**
     *  助理用户
     */
    GLAuthTokenRoleAssitant = 3,
    /**
     *  普通用户
     */
    GLAuthTokenRoleOrdinaryUser = 4,
}GLAuthTokenRole;

@interface GLAuthToken : GLKeyValueObject

@property (nonatomic, copy) NSString * accessToken;     //有效时间,单位（秒）
@property (nonatomic, assign) NSInteger expiresIn;      //返回的token
@property (nonatomic, assign) GLAuthTokenRole role;     //角色
@property (nonatomic, assign) NSInteger createTime;     //创建时间，本地维护

@end
