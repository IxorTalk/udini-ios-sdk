Pod::Spec.new do |s|
    s.name         = "UdiniSDK"
    s.version      = "1.0"
    s.summary      = "Udini is an access control tool that allows users to authenticate themselves against proprietary physical hardware devices."
    s.homepage     = "http://udini.eu"
    s.license      = { :type => "Commercial", :file => "UdiniSDK/LICENSE" }
    s.author       = { "IxorTalk" => "info@ixortalk.com" }
    s.source       = { :http => "https://manager.udini.eu/assets/instance/mobile-sdks/ios/UdiniSDK.zip" }
    s.platform     = :ios, "10.0"
    s.public_header_files = "UdiniSDK/UdiniSDK.framework/Headers/UdiniSDK.h"
    s.source_files = "UdiniSDK/UdiniSDK.framework/Headers/UdiniSDK.h"
    s.preserve_paths = "UdiniSDK/UdiniSDK.framework"
    s.ios.deployment_target = '10.0'
    s.ios.vendored_frameworks = 'UdiniSDK/UdiniSDK.framework'
    s.frameworks   = "UdiniSDK", "Security", "CoreBluetooth"
    s.xcconfig     =  { "FRAMEWORK_SEARCH_PATHS" => '"$(PODS_ROOT)/UdiniSDK/UdiniSDK"' }
    s.requires_arc = true
  end