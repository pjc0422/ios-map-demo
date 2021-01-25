//
//  GLatLng.h
//  geom
//
//  Created by gisdev on 2015. 1. 29..
//  Copyright (c) 2015년 kt. All rights reserved.
//

#import "GCoord.h"

/**
 WGS84 좌표계를 나타내기 위한 GCoord 구현 클래스
 */
@interface GLatLng : NSObject<GCoord>

/**
 위도
 */
@property (readonly, nonatomic) double lat;

/**
 경도
 */
@property (readonly, nonatomic) double lng;

/**
 주어진 위도와 경도로 `GLatLng` 객체를 생성한다.
 
 @param lat 위도
 @param lng 경도
 @return `GLatLng`
 */
- (instancetype)initWithLat:(double)lat lng:(double)lng;

/**
 주어진 좌표로부터 `GLatLng` 객체를 생성한다.
 만일 `GCoord` 클래스가 `GLatLng` 클래스이면 `GCoord` 객체를 그대로 반환한다.
 
 @param 좌표
 @return `GLatLng`
 */
+ (GLatLng *)valueOf:(id<GCoord>)coord;

@end
