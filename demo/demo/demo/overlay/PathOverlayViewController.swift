//
//  PathOverlayViewController.swift
//  demo
//
//  Created by 박주철 on 2021/01/25.
//  Copyright © 2021 박주철. All rights reserved.
//

import gmaps


class PathOverlayViewController: BaseViewController {
    
    @IBOutlet weak var mapView: GMapView!
    
    
    override func viewDidLoad() {
        mapView.delegate = self
    }
}



extension PathOverlayViewController: GMapViewDelegate {
    func mapView(_ mapView: GMapView!, didTapAt coord: GCoord!) {
        
    }
}
