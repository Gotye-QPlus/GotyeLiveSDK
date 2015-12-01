//
//  GLPublisherDelegate.h
//  GotyeLiveSDK
//
//  Created by Nick on 15/11/26.
//
//

#import <Foundation/Foundation.h>

@protocol GLPublisherDelegate <NSObject>
@optional
- (void)publishClientDidPublishSuccess:(NSString *)roomId;
- (void)publishClientReconnecting:(NSString *)roomId;
- (void)publishClientFailedWithError:(NSError *)error room:(NSString *)roomId;
- (void)publishClientDidForceLogout:(NSString *)roomId;
@end
