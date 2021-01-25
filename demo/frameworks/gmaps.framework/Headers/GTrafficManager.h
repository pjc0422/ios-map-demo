//
//  GTrafficManager.h
//  gmaps
//
//  Created by SUN MIN KIM on 2018. 12. 5..
//  Copyright © 2018년 kt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GMapView.h"
#import "GMapShared.h"

@protocol GNetworkLayerDelegate;

@interface GTrafficManager : NSObject

//제한속도, 도로종별
typedef enum {MAX, PANE} GTrafficStateType;


-(id) initWithType:(GTrafficStateType) type;
-(id) initWithType:(GTrafficStateType) type links:(NSMutableDictionary *)links links_lock:(NSLock *)links_lock;
-(id) initWithType:(GTrafficStateType) type links:(NSMutableDictionary *)links routeLinks:(NSMutableDictionary *)routeLinks links_lock:(NSLock *)links_lock;

/**
 요청 된 링크중 cache에 데이터가 있는경우 cache를 반환
 그외의 링크는 교통정보를 획득하여 반환
 */
- (void)getTrafficState:(NSArray *)linkIds
                success:(void (^)(NSDictionary *responce)) success
                failure:(void (^)(NSError *err)) failure;

/**
 요청된 링크에 대한 교통정보를 획득하여 반환
 & cache에 업데이트 된 데이터 반영
 */
- (void)updateTrafficState:(NSArray *)linkIds
                success:(void (^)(NSDictionary *responce)) success
                failure:(void (^)(NSError *err)) failure;

/**
 SDK 내부 호출 함수
 */
- (NSDictionary *)getTrafficStateSync:(NSArray *)linkIds;

//- (void) requestTrafficInfo:(NSArray*) linkIds
//                    success:(void (^)(NSArray *responce)) success
//                    failure:(void (^)(NSError *err)) failure;

- (NSArray *)requestTrafficInfoSync:(NSArray*) linkIds;

-(void) setTrafficType: (GTrafficStateType) type;
-(void)deleteCachedLinks;

@property (nonatomic) PROVIDER_TYPE provider;
@property (nonatomic) NSString* type;
@property (atomic) NSMutableDictionary* links;
@property (atomic) NSMutableDictionary* routeLinks;
@property (atomic) NSLock* links_lock;
@property (nonatomic, weak) id<GNetworkLayerDelegate> delegate;
@property (weak, nonatomic) GMapView* mapView;

@end

@protocol GNetworkLayerDelegate <NSObject>

@required
- (void)didTrafficRequestFail:(GMapView *)mapView statusCode:(NSInteger)statusCode error:(NSError *) error;

@end
