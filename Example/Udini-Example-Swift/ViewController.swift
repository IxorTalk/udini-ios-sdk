//
//  ViewController.swift
//  Udini-Example-Swift
//
//  Created by Andy Jacobs on 30/07/2019.
//  Copyright © 2019 IxorTalk. All rights reserved.
//

import UIKit
import UdiniSDK

class ViewController: UITableViewController {


    var authenticated = false {
        didSet {
            updateNavigationBarButtons()
        }
    }

    var badges: [UdiniBadge] = [] {
        didSet {
            tableView.reloadData()
        }
    }


    override func viewDidLoad() {
        super.viewDidLoad()

        // configure UdiniSDK
        let options = UdiniOptions(callbackScheme: "udini-example://")
        options.environment = kUdiniProductionEnvironment
        options.clientId = "udiniMobileIOSExampleClient"
        options.clientSecret = "FutGFhKVL7h4g63"
        UdiniApp.configure(options: options)


        authenticated = UdiniApp.hasValidUserSession() != nil
        updateNavigationBarButtons()

        if authenticated {
            loadData()
        }

    }

    func loadData() {
        UdiniServiceRequests.getBadges { (badges, error) in
            if let error = error {
                self.showAlert(for: error)
            } else if let badges = badges {
                self.badges = badges
            }
        }
    }

    func updateNavigationBarButtons() {
        if authenticated {
            self.navigationItem.rightBarButtonItem = UIBarButtonItem(title: "Logout", style: .plain, target: self, action: #selector(logout))
        } else {
            self.navigationItem.rightBarButtonItem = UIBarButtonItem(title: "Login", style: .plain, target: self, action: #selector(login))
        }
    }

    @objc func login() {
        UdiniServiceRequests.login(from: self) { (user, error) in
            if let error = error {
                self.authenticated = false
                self.showAlert(for: error)
            } else {
                self.authenticated = true
                UdiniApp.invalidateBadgesCache()
                self.loadData()
            }
        }
    }

    @objc func logout() {
        UdiniServiceRequests.logout(from: self) { error in
            if let error = error {
                self.showAlert(for: error)
            } else {
                self.authenticated = false
                self.badges = []
            }
        }
    }

    func showAlert(for error: Error) {
        let alertController = UIAlertController(title: "Error", message: error.localizedDescription, preferredStyle: .alert)
        alertController.addAction(UIAlertAction(title: "OK", style: .cancel, handler: nil))
        present(alertController, animated: true, completion: nil)
    }

    // MARK: - Table view data source
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return badges.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell: UITableViewCell = {
            guard let cell = tableView.dequeueReusableCell(withIdentifier: "UITableViewCell") else {
                // Never fails:
                return UITableViewCell(style: .subtitle, reuseIdentifier: "UITableViewCell")
            }
            return cell
        }()
        let badge = badges[indexPath.row]
        cell.textLabel?.text = "\(badge.name ?? "Badge \(indexPath.row)")"
        cell.detailTextLabel?.text = "devices: \(badge.devices?.count ?? 0)"
        cell.accessoryType = .disclosureIndicator
        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let badge = badges[indexPath.row]
        let devicesViewController = DevicesViewController(badge: badge)
        navigationController?.pushViewController(devicesViewController, animated: true)
    }

}

