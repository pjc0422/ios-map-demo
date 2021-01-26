//
//  MarkerViewController.swift
//  demo
//
//  Created by 박주철 on 2021/01/25.
//  Copyright © 2021 박주철. All rights reserved.
//

import gmaps

class MarkerViewController: BaseViewController {
    
    @IBOutlet weak var mapView: GMapView!
    
    let menuList: [String: Selector] = [
        "Add Marker":#selector(addMarker),
        "Move Marker":#selector(moveMarker),
        "Add Caption":#selector(addCaptionMarker),
        "Marker Animation":#selector(markerAnimation),
        "Flat Marker":#selector(markerFlat),
        "Clear Markers":#selector(clearMarkers)
    ]
    override func viewDidLoad() {
        mapView.delegate = self
        addMenuButton()
    }
    
    override func showMenu() {
        showAlert(title: "", message: "", actions: Array(menuList.keys)) { (title, index) in
            if let call = self.menuList[title] {
                self.perform(call)
            }
        }
    }
}


extension MarkerViewController: GMapViewDelegate {
    func mapView(_ mapView: GMapView!, didTapAt coord: GCoord!) {
        
    }
}



extension MarkerViewController {
    @objc
    func addMarker() {
        
    }
    
    @objc
    func moveMarker() {
        
    }
    
    @objc
    func addCaptionMarker() {
        
    }
    
    @objc
    func markerAnimation() {
        
    }
    
    @objc
    func markerFlat() {
        
    }
    
    @objc
    func clearMarkers() {
        
    }
}
