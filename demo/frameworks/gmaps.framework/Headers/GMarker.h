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

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIKit.h>

#import "GOverlay.h"
#import "GImage.h"
@protocol GCoord;

/**
 * @class GMarker
 *  GMarker는 지도 위에 특정 지점을 표시하기 위한 요소로 아이콘, 그림자, 캡션요소를 가지고 있다.
 * 지도가 Tilt되거나 회전, 확대/축소 될 경우에도 항상 같은 크기와 각도를 유지한다.
 */
@interface GMarker : GOverlay


/**
 * @struct CaptionPositionType (NS_ENUM)
 *  마커를 중심으로 한 caption의 위치
 *
 *        Type                  |   위치
 * ---------------------------- | -------------
 * CaptionPositionDefault       |   marker 하단
 * CaptionPositionTypeLeft      |   marker 좌측
 * CaptionPositionTypeTop       |   marker 상단
 * CaptionPositionTypeRight     |   marker 우측
 * CaptionPositionTypeBottom    |   marker 하단
 */
typedef NS_ENUM(NSInteger, CaptionPositionType) {
    CaptionPositionDefault,
    CaptionPositionTypeLeft,
    CaptionPositionTypeTop,
    CaptionPositionTypeRight,
    CaptionPositionTypeBottom
};

/**
 * @struct MarkerAnimationType (NS_ENUM)
 *  마커 애니메이션 타입
 *
 *       Type       |   위치
 * ---------------- | -------------
 * MARKER_DROP      |   공중에서 position위치로 떨어지는 애니메이션
 * MARKER_FLICK     |   마커의 사이즈가 anchor를 중심으로 커졌다 작아지는 애니메이션
 */
typedef NS_ENUM(NSInteger, MarkerAnimationType) {
    MARKER_DROP,
    MARKER_FLICK
};

/// marker의 위치
@property (nonatomic) id<GCoord> position;
/// 마커 아이콘 이미지. 지정하지 않을경우 기본 아이콘 이미지 출력.
@property (nonatomic) GImage *icon;
/// 마커 아이콘 사이즈. 화면 Point단위
@property (nonatomic) CGPoint iconSize;
/// 마커 그림자 이미지. 지정하지 않을경우 기본 그림자 이미지 출력.
//@property (nonatomic) GImage *shadow;
/// marker의 캡션텍스트
@property (nonatomic, copy) NSString *caption;
/**
 *        Key           |   valueType
 * -------------------- | -------------
 * captionText          |   (NSString)
 * captionSize          |   (NSUInteger)
 * captionColor         |   (UIColor *)
 * captionStrokeColor   |   (UIColor *)
 * captionPositionType  |   (CaptionPositionType)
 */
@property (nonatomic, copy) NSDictionary *captionOptions;
/// marker의 인포윈도우 제목텍스트
@property (nonatomic, copy) NSString *title;
/// marker의 인포윈도우 부제목텍스트
@property (nonatomic, copy) NSString *subTitle;
/// marker의 회전 각도(degree). 기본값은 0.0
@property (nonatomic, assign) float rotation;
/// marker의 anchor위치 (이미지 크기 대비 백분율 값). 기본값은 (0.5, 1.0)
@property (nonatomic) CGPoint anchor;
/// marker의 드래그 가능 여부. 기본값은 true
@property (nonatomic, assign) bool draggable;
/// marker의 flat 여부. 기본값은 false
@property (nonatomic, assign) bool flat;

/**
 *  마커의 위치정보를 이용한 기본 마커 생성자
 * @return 생성된 마커 객체
 *
 * @code
 * GCoord *c1 = [[GCoord alloc]initWithX:957590.0 y:1941834.0];
 * GMarker *marker = [GMarker markerWithPosition:c2];
 * marker.caption = @"caption";
 * [mapView addOverlay:marker];
 * @endcode
 */
+ (instancetype)markerWithPosition:(id<GCoord>)position;

/**
 *  마커의 생성옵션을 이용한 기본 마커 생성자
 * @param options 마커 생성 옵션
 *        Key       |   valueType
 * ---------------- | -------------
 * visible          |   (bool)
 * position         |   (GCoord *)
 * icon             |   (GImage *)
 * iconSize         |   (CGPoint)
 * caption          |   (NSString *)
 * captionOptions   |   (NSDictionary *)
 * title            |   (NSString *)
 * subTitle         |   (NSString *)
 * rotation         |   (float)
 * anchor           |   (CGPoint)
 * draggable        |   (bool)
 * flat             |   (bool)
 *
 * @return 생성된 GroundOverlay 객체
 *
 * @code
 * GCoord *c1 = [[GCoord alloc]initWithX:957590.0 y:1941834.0];
 * NSDictionary *options = @{
 *                      @"position":c1,
 *                          @"icon":[GImage imageWithFileName:@"icon.png"],
 *                       @"caption":@"testCaption"
 *                         };
 * GMarker *marker = [GMarker markerWithOptions:options];
 * [mapView addOverlay:marker];
 * @endcode
 */
+ (instancetype)markerWithOptions:(NSDictionary *)options;

/**
 *  인포윈도우를 표시한다.
 */
- (void)showInfoWindow;

/**
 *  인포윈도우를 표시하지 않는다.
 */
- (void)hideInfoWindow;
- (void)animate:(MarkerAnimationType)type;
/**
 *  이 마커를 다른 마커들이 가리지 않도록 최상위에 출력한다.
 */
- (void)bringToFront;
/**
 *  [bringToFront] 로 변경된 z-index 를 기본값으로 초기화한다.
 */
- (void)resetZIndex;
@end
