//
//  MapStyleViewController.swift
//  demo
//
//  Created by 박주철 on 2021/01/25.
//  Copyright © 2021 박주철. All rights reserved.
//

import gmaps


class MapStyleViewController: BaseViewController {
    var isAnimationUse: Bool = false
    
    let menuList:[String:Selector] = [
        "default":#selector(applyDefault),
        "day drive":#selector(applyDayDrive),
        "night default":#selector(applyNightDefault),
        "night drive":#selector(applyNightDrive),
        "use Animtaion":#selector(useAnimation)
    ]
    
    
    @IBOutlet weak var mapView: GMapView!
    
    override func viewDidLoad() {
        setNavigationTitle("MapStyle")
        addMenuButton()
    }
    
    override func showMenu() {
        showAlert(title: "Map Style", message: "apply map theme", actions: Array(menuList.keys)) { (title, index) in
            if let call = self.menuList[title] {
                self.perform(call)
            }
        }
    }
}


extension MapStyleViewController {
    @objc
    func applyDefault() {
        
    }
    
    @objc
    func applyDayDrive() {
        
    }
    
    @objc
    func applyNightDefault() {
        
    }
    
    @objc
    func applyNightDrive() {
        
    }
    
    @objc
    func useAnimation() {
        
    }
}
