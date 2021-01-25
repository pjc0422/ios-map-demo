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
#import <UIKit/UIKit.h>
#import "GOverlay.h"
@protocol GCoord;

/**
 * @class GPolyline
 *  GPolyline 은 지도에 폴리라인을 그리기 위한 클래스이며 2개 이상의 연속된 점들로 구성되어있다. GOverlay 구현 클래스
 */
@interface GPolyline : GOverlay

/**
 *  선의 두께. 지정하지 않을 경우 기본값은 1.
 * @throws NSInvalidArgumentException <code>width</code>가 1 미만인 경우
 */
@property (nonatomic, assign) int width;

/**
 *  선의 색상. 기본값은 Black.
 */
@property (nonatomic, assign) UIColor *color;

/**
 *  선을 이루는 점의 목록. GCoord array.
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만인 경우<br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우
 */
@property (nonatomic, copy) NSArray *points;

/**
 *  점의 목록을 이용하여 GPolyline 객체를 생성한다.
 * @return 생성된 GPolyline 객체
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만일 경우<br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우
 *
 * @code
 * GUtmk *c1 = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
 * GUtmk *c2 = [[GUtmk alloc]initWithX:959640.0 y:1943858.0];
 * GUtmk *c3 = [[GUtmk alloc]initWithX:959540.0 y:1943658.0];
 * NSArray *points = [NSArray arrayWithObjects: c1, c2, c3, nil];
 * GPolyline *polyline = [GPolyline polylineWithPoints:points];
 * [mapView addOverlay:polyline];
 * @endcode
 */
+ (instancetype)polylineWithPoints:(NSArray *)points;


/**
 * @breif 연결된 선의 총 길이를 구하는 함수.
 */
-(double) getLength ;

/**
 *  생성옵션을 이용한 GPolyline 생성자
 * @param options GPolyline 생성 옵션
 *        Key       |   valueType
 * ---------------- | -------------
 * visible          |   (bool)
 * width            |   (int)
 * color            |   (NSString *UIColor *)
 * points           |   (NSArray *)
 * @return 생성된 GPolyline 객체
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만일 경우 <br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우<br/>
 *                                    <code>width</code>가 1 미만일 경우
 *
 * @code
 * GUtmk *c1 = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
 * GUtmk *c2 = [[GUtmk alloc]initWithX:959640.0 y:1943858.0];
 * GUtmk *c3 = [[GUtmk alloc]initWithX:959540.0 y:1943658.0];
 * NSArray *points = [NSArray arrayWithObjects: c1, c2, c3, nil];
 * NSDictionary *options = @{
 *                          @"color":[UIColor redColor],
 *                         @"points":points
 *                         };
 * GPolyline *polyline = [GPolyline polylineWithOptions:options];
 * [mapView addOverlay:polyline];
 * @endcode
 */
+ (instancetype)polylineWithOptions:(NSDictionary *)options;
@end
