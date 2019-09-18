//
//  DevicesViewController.swift
//  Udini-Example-Swift
//
//  Created by Andy Jacobs on 31/07/2019.
//  Copyright © 2019 IxorTalk. All rights reserved.
//

import UIKit
import UdiniSDK

class DevicesViewController: UITableViewController {

    let badge: UdiniBadge

    init(badge: UdiniBadge) {
        self.badge = badge
        super.init(nibName: nil, bundle: nil)
        self.title = "Devices"
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    // MARK: - Table view data source
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return badge.devices?.count ?? 0
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell: UITableViewCell = {
            guard let cell = tableView.dequeueReusableCell(withIdentifier: "UITableViewCell") else {
                // Never fails:
                return UITableViewCell(style: .subtitle, reuseIdentifier: "UITableViewCell")
            }
            return cell
        }()

        let device = badge.devices?[indexPath.row]
        cell.textLabel?.text = "\(device?.deviceName ?? "Device \(indexPath.row)")"
        cell.detailTextLabel?.text = "actions: \(device?.actions?.count ?? 0)"
        cell.accessoryType = .disclosureIndicator
        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        guard let device = badge.devices?[indexPath.row] else { return }
        let actionsViewController = ActionsViewController(badge: badge, device: device)
        navigationController?.pushViewController(actionsViewController, animated: true)
    }

}
