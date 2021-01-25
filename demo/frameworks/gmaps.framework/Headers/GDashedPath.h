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
 * @class GDashedPath
 *  GDashedPath 는 지도상에 일정한 폭(면적)을 갖는 점선을 그리기 위한 클래스이며 2개 이상의 연속된 점들로 구성되어있다. GOverlay 구현 클래스
 */
@interface GDashedPath : GOverlay

///**
// *  점선 이미지. 현재 지원되는 이미지 규격은 제한적이며 이미지에서 공백이 차지하는 영역이 가로 기준으로 10%, 좌측 라인캡에 해댱하는 이미지 25%, 우측 라인캡에 해당하는 이미지 75%, 우측 공백이 10%로 구성되어야한다.
// */
//@property (nonatomic, copy) NSObject *image;

/**
 *  버퍼 너비(미터 단위). 
 * @throws NSInvalidArgumentException <code>bufferWidth</code>가0 미만인 경우
 */
@property (nonatomic, assign) double bufferWidth;

/**
 *  선을 이루는 점의 목록. GCoord array.
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만인 경우<br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우
 */
@property (nonatomic, copy) NSArray *points;

/**
 *  선의 색상. 기본값은 Black.
 */
@property (nonatomic, assign) UIColor *color;

/**
 *  원형 모형의 dashed path사용여부
 */
@property (nonatomic, assign) bool isCircleType;


- (void)setVisible:(bool)visible;

-(void) bringToFront;

-(void) resetZIndex;
/**
 *  점의 목록을 이용하여 GDashedPath 객체를 생성한다.
 * @return 생성된 GDashedPath 객체
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만일 경우<br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우
 *
 * @code
 * GUtmk *c1 = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
 * GUtmk *c2 = [[GUtmk alloc]initWithX:959640.0 y:1943858.0];
 * GUtmk *c3 = [[GUtmk alloc]initWithX:959540.0 y:1943658.0];
 * NSArray *points = [NSArray arrayWithObjects: c1, c2, c3, nil];
 * GDashedPath *dashedPath = [GDashedPath dashedPathWithPoints:points BufferWidth:10];
 * [mapView addOverlay:dashedPath];
 * @endcode
 */
+ (instancetype)dashedPathWithPoints:(NSArray *)points BufferWidth:(double)width;

/**
 *  생성옵션을 이용한 GDashedPath 생성자
 * @param options GDashedPath 생성 옵션
 *        Key       |   valueType
 * ---------------- | -------------
 * visible          |   (bool)
 * bufferWidth      |   (double)
 * color            |   (UIColor *)
 * points           |   (NSArray *)
 * @return 생성된 GDashedPath 객체
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만일 경우<br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우<br/>
 *                                    <code>strokeWidth</code>가 1 미만일 경우<br/>
 *                                    <code>bufferWidth</code>가 지정되지 않거나 0보다 작거나 같을 경우 exception발생<br/>
 *
 * @code
 * GUtmk *c1 = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
 * GUtmk *c2 = [[GUtmk alloc]initWithX:959640.0 y:1943858.0];
 * GUtmk *c3 = [[GUtmk alloc]initWithX:959540.0 y:1943658.0];
 * GUtmk *c4 = [[GUtmk alloc]initWithX:958540.0 y:1943658.0];
 * NSArray *points = [NSArray arrayWithObjects: c1, c2, c3, c4, nil];
 * NSDictionary *options = @{
 *                      @"strokeColor":[UIColor redColor],
 *                           @"points":points,
 *                       @"bufferWidth:@10
 *                         };
 * GDashedPath *dashedPath = [GDashedPath dashedPathWithOptions:options];
 * [mapView addOverlay:dashedPath];
 * @endcode
 */
+ (instancetype)dashedPathWithOptions:(NSDictionary *)options;

@end
