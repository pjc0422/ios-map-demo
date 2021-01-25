//
//  AppDelegate.swift
//  demo
//
//  Created by 박주철 on 2021/01/24.
//  Copyright © 2021 박주철. All rights reserved.
//

import UIKit
import gmaps

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    let gisKey = "3e2f226e0761da9eda5d597709803af904111c47c2d88bbd51b77c6eb4437bb57cf1576f"

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        GMapShared.authKeyRegist(Bundle.main, withKey: gisKey)
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
    }


}

