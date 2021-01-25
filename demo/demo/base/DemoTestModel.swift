//
//  DemoTestModel.swift
//  demo
//
//  Created by 박주철 on 2021/01/24.
//  Copyright © 2021 박주철. All rights reserved.
//

import Foundation
import UIKit

struct DemoTestModel {
    var title: String
    var description: String?
    var viewController: UIViewController?
}


func testModelList() -> Dictionary<String, Array<DemoTestModel>> {
    var testSet: Dictionary<String, Array<DemoTestModel>> = Dictionary()
    testSet["test"] = Array()
    return testSet
}
