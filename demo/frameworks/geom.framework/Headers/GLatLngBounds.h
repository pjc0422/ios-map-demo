//
//  GLatLngBounds.h
//  geom
//
//  Created by gisdev on 2015. 2. 9..
//  Copyright (c) 2015년 kt. All rights reserved.
//

#import "GBounds.h"

@class GLatLng;

/**
 WGS84 좌표계로 Bounds(지도상의 직사가각형 영역) 를 표현하기 위한 클래스
 */
@interface GLatLngBounds : NSObject<GBounds>

#ifdef ONLY_FOR_DOXYGEN
/**
 @breif GLatLngBounds 를 정의하는 좌측하단좌표
 */
@property GLatLng *min;

/**
 @breif GLatLngBounds 를 정의하는 우측상단좌표
 */
@property GLatLng *max;
#endif

/**
 주어진 좌표로 객체를 초기화 한다.
 
 @param min Bounds를 구성하는 좌측하단 좌표
 @param max Bounds를 구성하는 우측상단 좌표
 @return GLatLngBounds 객체
 */
- (instancetype)initWithMin:(GLatLng *)min max:(GLatLng *)max;
- (GLatLng *)getMin;
- (GLatLng *)getMax;

/**
 Bounds 의 좌측하단 x 좌표를 반환한다.
 
 @return 좌측하단 x 좌표
 */
- (double)left;

/**
 Bounds 의 우측상단 x 좌표를 반환한다.
 
 @return 우측상단 x 좌표
 */
- (double)right;

/**
 Bounds 의 좌측하단 y 좌표를 반환한다.
 
 @retrun 좌측하단 y 좌표
 */
- (double)bottom;

/**
 Bounds 의 우측상단 y 좌표를 반환한다.
 
 @return 우측상단 y 좌표
 */
- (double)top;

/**
 bounds 로 부터 WGS84 좌표계로 이루어진 GLatLngBounds 객체를 생성한다.
 만일 bounds 객체의 클래스가 GLatLngBounds 이면 bounds 객체를 그대로 반환한다.
 
 @param bounds GBounds 객체
 @return GLatLngBounds 객체
 */
+ (GLatLngBounds *)valueOf:(id<GBounds>)bounds;


@end
