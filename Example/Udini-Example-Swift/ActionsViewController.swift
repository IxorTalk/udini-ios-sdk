//
//  ActionsViewController.swift
//  Udini-Example-Swift
//
//  Created by Andy Jacobs on 31/07/2019.
//  Copyright © 2019 IxorTalk. All rights reserved.
//

import UIKit
import UdiniSDK

class ActionsViewController: UITableViewController {

    let badge: UdiniBadge
    let device: UdiniDevice

    weak var alertController: UIAlertController?

    init(badge: UdiniBadge, device: UdiniDevice) {
        self.badge = badge
        self.device = device
        super.init(nibName: nil, bundle: nil)

        UdiniApp.setFeedbackDelegate(self)
        self.title = "Actions"
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    // MARK: - Table view data source
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return device.actions?.count ?? 0
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell: UITableViewCell = {
            guard let cell = tableView.dequeueReusableCell(withIdentifier: "UITableViewCell") else {
                // Never fails:
                return UITableViewCell(style: .subtitle, reuseIdentifier: "UITableViewCell")
            }
            return cell
        }()

        let action = device.actions?[indexPath.row]
        cell.textLabel?.text = "\(action?.label ?? "Action \(indexPath.row)")"
        cell.detailTextLabel?.text = "Invoke on proximity: \(action?.invokeOnProximity ?? false), proximity required: \(badge.constraint?.proximityRequired ?? true)"
        cell.accessoryType = .disclosureIndicator
        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        guard let action = device.actions?[indexPath.row] else { return }
        let alertController = UIAlertController(title: "Invoke Action", message: "Starting...", preferredStyle: .alert)
        alertController.addAction(UIAlertAction(title: "Dismiss", style: .cancel, handler: nil))
        present(alertController, animated: true, completion: nil)
        self.alertController = alertController
        UdiniApp.invoke(action: action, device: device, badge: badge)
        tableView.deselectRow(at: indexPath, animated: true)
    }

}

extension ActionsViewController: UdiniFeedbackDelegate {
    func device(_ device: UdiniDevice, stateDidChange state: UdiniDeviceState, for action: UdiniDeviceAction?) {
        guard let alertController = self.alertController else { return }

        let stateName : () -> String = {
            switch state {
            case .connecting: return "connecting"
            case .connected: return "connected"
            case .discoveringServices: return "discoveringServices"
            case .discoveredServices: return "discoveredServices"
            case .discoveringCharacteristics: return "discoveringCharacteristics"
            case .discoveredCharacteristics: return "discoveredCharacteristics"
            case .performingAction: return "performingAction"
            case .actionPerfomed: return "actionPerfomed"
            case .disconnecting: return "disconnecting"
            case .disconnected: return "disconnected"
            default: return ""
            }
        }


        alertController.message = String(describing: stateName())
    }

    func device(_ device: UdiniDevice, didSucceedFor deviceAction: UdiniDeviceAction) {
        guard let alertController = self.alertController else { return }
        alertController.message = "Action `\(deviceAction.label ?? String(describing: deviceAction))` was invoked successfully"
    }

    func device(_ device: UdiniDevice, for deviceAction: UdiniDeviceAction, didFailWithError error: Error) {
        guard let alertController = self.alertController else { return }
        alertController.message = "Action `\(deviceAction.label ?? String(describing: deviceAction))` invocation failed with Error: \(error.localizedDescription)"
    }
}
