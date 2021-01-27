//
//  MapShapeOverlayViewController.swift
//  demo
//
//  Created by 박주철 on 2021/01/25.
//  Copyright © 2021 박주철. All rights reserved.
//

import gmaps

enum ShapeType {
    case circle
    case polygon
    case polyline
}

class MapShapeOverlayViewController: BaseViewController {
    var overlay: GOverlay?
    var points: [GCoord] = []
    // default radius = 100
    var radius:Double = 100
    var demoType: ShapeType = .circle
    
    @IBOutlet weak var mapView: GMapView!
    
    override func viewDidLoad() {
        mapView.delegate = self
    }
}


extension MapShapeOverlayViewController: GMapViewDelegate {
    func mapView(_ mapView: GMapView!, didTapAt coord: GCoord!) {
        
    }
}


extension MapShapeOverlayViewController {
    func clearOverlay() {
        if let shape = overlay {
            mapView.remove(shape)
        }
    }
    
    func addPoint(coord:GCoord) {
        
    }
}
