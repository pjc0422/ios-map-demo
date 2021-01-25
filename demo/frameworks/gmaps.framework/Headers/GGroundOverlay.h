/*
 * Copyright (c) 2014 kt corp. All rights reserved.
 *
 * This is a proprietary software of kt corp, and you may not use this file
 * except in compliance with license agreement with kt corp. Any redistribution
 * or use of this software, with or without modification shall be strictly
 * prohibited without prior written approval of kt corp, and the copyright
 * notice above does not evidence any actual or intended publication of such
 * software.
 */

#import "GOverlay.h"
#import "GImage.h"

@protocol GBounds;

/**
 * @class GGroundOverlay
 *  GGroundOverlay는 지도 표면 위를 덮는 형태의 오버레이로 지도 좌표로 이루어진 특정 영역을 가진다.
 * 마커와는 달리 지도가 Tilt되거나 회전, 확대/축소 될 경우에 함께 회전, 확대/축소된다.
 */
@interface GGroundOverlay: GOverlay

/// 이미지 영역
@property (nonatomic) id<GBounds> bounds;
/// 이미지
@property (nonatomic) GImage *image;
//@property (nonatomic) NSUInteger minZoom;

/**
 *  영역와 이미지파일명을 이용한 groundOverlay 생성자
 * @param bounds 이미지 영역
 * @param image 이미지 파일명
 * @return 생성된 GroundOverlay 객체
 *
 * @code
 * GBounds *bounds;
 * GGroundOverlay *gOverlay = [GGroundOverlay groundOverlayWithBounds:bounds image:[GImage imageWithFileName:@"image.png"]];
 * [mapView addOverlay:gOverlay];
 * @endcode
 */
+ (instancetype)groundOverlayWithBounds:(id<GBounds>)bounds
                                  image:(GImage *) image;

/**
 *  생성옵션을 이용한 GroundOverlay 생성자
 * @param options GroundOveraly 생성 옵션
 *        Key       |   valueType
 * ---------------- | -------------
 * visible          |   (bool)
 * bounds           |   (GBounds *)
 * image            |   (NSString *)
 * @return 생성된 GroundOverlay 객체
 *
 * @code
 * UTMKBounds *bounds;
 * NSDictionary *options = @{
 *                          @"bounds":bounds,
 *                           @"image":@"image.png"
 *                         };
 * GGroundOverlay *gOverlay = [GGroundOverlay groundOverlayWithOptions:options];
 * [mapView addOverlay:gOverlay];
 * @endcode
 */
+ (instancetype)groundOverlayWithOptions:(NSDictionary *)options;

@end
