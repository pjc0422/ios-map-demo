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
    
    var locationManager: CLLocationManager?
    
    override func viewDidLoad() {
        mapView.delegate = self
    }
}



extension LocationViewController : GMapViewDelegate{
    func mapView(_ mapView: GMapView!, didChange viewpoint: GViewpoint!, withGesture gesture: Bool) {
        compassImage.transform = CGAffineTransform(rotationAngle: CGFloat(viewpoint.rotation))
    }
}

enum LocationUpdateState {
    case fail
    case monitor
    case update
}

protocol LocationHandler {
    func updateLocation(location:CLLocation, state:LocationUpdateState)
    
}

//MARK: - Location Manager
extension LocationViewController : CLLocationManagerDelegate{
    func initLocationManager()  {
        let manager = CLLocationManager.init()
        manager.delegate = self
        locationManager = manager
    }
    
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        
    }
    
    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        
    }
    
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        switch status {
        case .authorizedAlways, .authorizedWhenInUse:
            break
        case .denied:
            break
        case .notDetermined:
            // stop service
            break
        case .restricted:
            // stop service
            break
        @unknown default:
            fatalError()
        }
    }
    
    func checkPermission() -> Bool{
        if #available(iOS 14.0, *) {
            if let statues = locationManager?.authorizationStatus {
                
            }
        } else {
            // Fallback on earlier versions
            
        }
        return false
    }
    
}

extension LocationViewController: LocationHandler {
    func updateLocation(location: CLLocation, state: LocationUpdateState) {
        let azimuth = locationManager?.heading?.magneticHeading
        let lat = location.coordinate.latitude
        let lng = location.coordinate.longitude
    }
}
