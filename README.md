# Udini SDK

## Features

- [x] BLE Device Scanning, connecting, Action execution
- [x] Udini api integration: Data fetching, user management, remote actions
- [x] Secure emory & disk persistence
- [x] RSA asymmetric security
- [x] OAuth2 authentication
- [x] Notification support

## Requirements

- iOS 10.0+
- Xcode 10.2+


## Installation
### Manually

You can integrate UdiniSDK into your project manually.

#### Embedded Framework

Add the UdiniSDK.framework to the embedded binaries section of your app target

_Attention_: The Debug variant is a fat framework containing device and simulator architectures. For app submission you must make sure to include the Release variant of the UdiniSDK.framework which includes only device architectures since Apple is rejecting apps submitted with simulator slices.


## Getting Started

Configure the UdiniOptions, with a callbackScheme, environment, clientId & clientSecret
```swift
let options = UdiniOptions(callbackScheme: "udini://")
options.environment = kUdiniProductionEnvironment
options.clientId = "foo"
options.clientSecret = "bar"
UdiniApp.configure(options: options)
```

Start a user session
```swift
UdiniServiceRequests.login(from: viewController,
                           completionHandler: { (user, error) in
                            // handle completionHandler
                            })
```

Start the udini services
```swift
UdiniApp.start()
```

## API Documentation

Browse the [API documentation](https://udini.eu/sdk/ios/docs).

## Included Samples

Sample apps that explore core Udini features are available for iOS, See Example to get started.
