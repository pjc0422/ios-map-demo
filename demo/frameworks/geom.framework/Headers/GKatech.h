//
//  GKatech.h
//  geom
//
//  Created by gisdev on 2015. 1. 29..
//  Copyright (c) 2015년 kt. All rights reserved.
//

#import "GCoord.h"

/**
  Katech 좌표계를 나타내기 위한 GCoord 구현 클래스
 */
@interface GKatech : NSObject<GCoord>

/**
  x 좌표
 */
@property (readonly, nonatomic) double x;

/**
  y 좌표
 */
@property (readonly, nonatomic) double y;

/**
  주어진 x,y 좌표로 GKatech 객체를 초기화 한다.
 
 @param x x좌표
 @param y y좌표
 @return GKatech 객체
 */
- (instancetype)initWithX:(double)x y:(double)y;

/**
  주어진 coord 좌표로 부터 GKatech 객체를 생성한다.
 만일 coord 클래스가 GKatech 이면 coord 객체를 그대로 반환한다.
 
 @param coord 좌표
 @return GKatech 객체
 */
+ (GKatech *)valueOf:(id<GCoord>)coord;

/**
  현재 좌표와 지정된 coord 좌표와의 각도를 계산해서 반환한다.
 
 @param coord 좌표
 @return 각도
 */
- (double)angleTo:(id<GCoord>)coord;


/**
  현재 좌표와 지정된 coord 좌표간의 거리를 반환한다.
 
 @param coord 좌표
 @return 거리, 미터 단위
 */
- (double)distanceTo:(id<GCoord>)coord;


/**
  현재 좌표와 명시된 other 좌표가 거의 일치하는지 여부를 반환한다.
 두 좌표간의 거리가 0.001 미터 이내라면 거의 일치한다고 간주된다.
 좌표계를 변환했거나 여러 좌표계의 좌표를 혼용하는 등 정확도 손실이 우려되는 경우 이 메소드를 사용하면 유용하다.
 
 @param coord 좌표
 @return 두 좌표가 거의 일치할 경우 true, 그렇지 않을 경우 false
 */
- (BOOL)almostEquals:(id<GCoord>)coord;

/**
  현재 좌표와 명시된 other 좌표가 거의 일치하는지 여부를 반환한다.
 두 좌표간의 거리가 epsilonInMeter 미터 이내라면 거의 일치한다고 간주된다.
 좌표계를 변환했거나 여러 좌표계의 좌표를 혼용하는 등 정확도 손실이 우려되는 경우 이 메소드를 사용하면 유용하다.
 
 @param coord 좌표
 @param EpsilonInMeter 기준거리, 미터단위
 @return 두 좌표가 거의 일치할 경우 true, 그렇지 않을 경우 false
 */
- (BOOL)almostEquals:(id<GCoord>)coord epsilonInMeter:(double)epsilonInMeter;

/**
  다른 좌표와의 중간점을 반환한다.
 
 @param coord 다른 좌표
 @return 중간점
 */
- (GKatech *)middle:(id<GCoord>)coord;

@end
