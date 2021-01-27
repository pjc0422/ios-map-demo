//
//  LocationViewController.swift
//  demo
//
//  Created by 박주철 on 2021/01/28.
//  Copyright © 2021 박주철. All rights reserved.
//

import gmaps


class LocationViewController: BaseViewController {
    
    @IBOutlet weak var compassImage: UIImageView!
    @IBOutlet weak var mapView: GMapView!
    
    override func viewDidLoad() {
        mapView.delegate = self
    }
}



extension LocationViewController : GMapViewDelegate{
    func mapView(_ mapView: GMapView!, didChange viewpoint: GViewpoint!, withGesture gesture: Bool) {
        compassImage.transform = CGAffineTransform(rotationAngle: CGFloat(viewpoint.rotation))
    }
}




//MARK: - Location Manager
