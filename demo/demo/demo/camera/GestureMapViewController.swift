//
//  GestureMapViewController.swift
//  demo
//
//  Created by KT on 2021/01/25.
//  Copyright © 2021 박주철. All rights reserved.
//

import gmaps

class GestureMapViewController: BaseViewController {
    var mapView: GMapView?
    
    override func viewDidLoad() {
        mapView?.delegate = self
    }
}


extension GestureMapViewController: GMapViewDelegate {
    func mapView(_ mapView: GMapView!, didTapAt coord: GCoord!) {
        
    }
    
    func mapView(_ mapView: GMapView!, didLongPressAt coord: GCoord!) {
        
    }
    
    func mapView(_ mapView: GMapView!, didTap info: GMapLabelInfo!) -> Bool {
        return false
    }
    
    func mapView(_ mapView: GMapView!, didLongPress info: GMapLabelInfo!) -> Bool {
        return false
    }
    
    func mapView(_ mapView: GMapView!, didIdleAt viewpoint: GViewpoint!) {
        
    }
    
    /**
     *  Pan, Tilt, Rotate, Zoom 는  mapView(_ mapView: GMapView!, didChange viewpoint: GViewpoint!, withGesture gesture: Bool) 로 응답이 내려온다.
     *  viewpoint.center        : 지도의 중심점.
     *  viewpoint.rotation      : 지도의 방위각.
     *  viewpoint.zoom          : 지도의 줌레벨.
     *  viewpoint.tilt          : 지도의 기울기.
     */
    func mapView(_ mapView: GMapView!, didChange viewpoint: GViewpoint!, withGesture gesture: Bool) {
        
    }
}
