//
//  GLPlayerDelegate.h
//  GotyeLiveSDK
//
//  Created by Nick on 15/11/26.
//
//

#import <Foundation/Foundation.h>

/**
 *  播放器的状态回调
 */
@protocol GLPlayerDelegate <NSObject>

@optional

/**
 *  开始播放的回调
 *
 *  @param roomId 当前房间号
 */
- (void)onPlayerStart:(NSString *)roomId;

/**
 *  播放出现错误时的回调
 *
 *  @param error  错误的详细信息
 *  @param roomId 当前房间号
 */
- (void)onPlayerError:(NSError *)error roomId:(NSString *)roomId;

/**
 *  播放器正在重新尝试连接服务器时的回调
 *
 *  @param roomId 当前房间号
 */
- (void)onPlayerReConnecting:(NSString *)roomId;

/**
 *  直播结束的回调。如果GLPlayer的autoPlay属性为YES，那么在收到这个回调的时候SDK底层会自动调用播放视频的接口尝试播放视频。如果为NO，那么需要开发者自行调用播放视频接口
 *
 *  @param roomId 当前房间号
 */
- (void)onLiveStop:(NSString *)roomId;

/**
 *  直播开始的回调
 *
 *  @param roomId 当前房间号
 */
- (void)onLiveStart:(NSString *)roomId;

@end
