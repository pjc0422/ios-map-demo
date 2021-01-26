//
//  InfoWindowViewController.swift
//  demo
//
//  Created by 박주철 on 2021/01/25.
//  Copyright © 2021 박주철. All rights reserved.
//

import gmaps

enum InfoWindowType {
    case defaultAdapter
    case customAdapter
}

class InfoWindowViewController: BaseViewController {
    
    @IBOutlet weak var mapView: GMapView!
    
    var overlays:[GOverlay] = []
    
    let menuList:[String: Selector] = [
//        "Default Mode":#selector(modeDefault),
//        "Custom Mode":#selector(modeCustom),
        "clearOverlays":#selector(clearOverlay)
    ]
    
    
    override func viewDidLoad() {
        mapView.delegate = self
        
        setNavigationTitle("InfoWindow")
        addMenuButton()
    }
    
    override func showMenu() {
        showAlert(title: "InfoWindow", message: "infomation overlay", actions: Array(menuList.keys)) { (title, index) in
            if let call = self.menuList[title] {
                self.perform(call)
            }
        }
    }
}



extension InfoWindowViewController: GMapViewDelegate {
    func mapView(_ mapView: GMapView!, didTapAt coord: GCoord!) {
        if let infoWindow = GInfoWindow.infowWindow(options: [
            "position":coord!,
            "title":"infoWindow"
        ]) {
            mapView.add(infoWindow)
            overlays.append(infoWindow)
        }
    }
}



extension InfoWindowViewController {
    @objc
    func clearOverlay() {
        overlays.forEach { (overlay) in
            mapView.remove(overlay)
        }
        
        overlays.removeAll()
    }

    @objc
    func modeDefault() {
        
    }
    
    @objc
    func modeCustom() {
        
    }
}
