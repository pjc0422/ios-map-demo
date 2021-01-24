//
//  ViewController.swift
//  demo
//
//  Created by 박주철 on 2021/01/24.
//  Copyright © 2021 박주철. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var demoListView: UITableView!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        demoListView.dataSource = self
        demoListView.delegate = self
        demoListView.estimatedRowHeight = 55
        demoListView.rowHeight = UITableView.automaticDimension

    }


}

extension ViewController: UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 10
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return 2
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "DemoCell", for: indexPath) as! DemoCell
        cell.model = DemoTestModel(title: "Test1", description: "hello world", viewController: nil)
        return cell
    }

//    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
//        return 100
//    }
}

extension ViewController:UITableViewDelegate {
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        print("section : \(indexPath.section) ,row : \(indexPath.row)")
    }
}
