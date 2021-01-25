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
        return 20
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return 3
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "DemoCell", for: indexPath) as! DemoCell
        cell.model = DemoTestModel(title: "Test1", description: "hello world", viewController: nil)
        return cell
    }
    
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        let frame = CGRect.init(origin: view.frame.origin, size: CGSize(width: view.frame.size.width, height: 30))
        let view = UIView.init(frame: frame)
        let title = UILabel.init(frame: frame)
        title.text = "hello world \(section)"
        title.backgroundColor = .gray
        view.addSubview(title)
        return view
    }
}

extension ViewController:UITableViewDelegate {
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        print("section : \(indexPath.section) ,row : \(indexPath.row)")
        let storyBoard = UIStoryboard(name: "Main", bundle: nil)
        let mapViewController = storyBoard.instantiateViewController(identifier: "mapStroyBoard")
        self.show(mapViewController, sender: nil)
//        let mapView = MapViewStroyBoardController.init()
//        self.show(mapView, sender: nil)
//        self.navigationController?.pushViewController(mapView, animated: true)
    }
}
