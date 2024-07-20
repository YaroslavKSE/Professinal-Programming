// swift-tools-version: 5.10
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "ProfessinalProject",
    dependencies: [
        .package(url: "https://github.com/apple/swift-collections.git", from: "1.0.0")
    ],
    targets: [
        .executableTarget(
            name: "ProfessinalProject",
            dependencies: ["Presentation", "BusinessLogic", "DataAccess"],
            path: "Sources/ProfessinalProject"
        ),
        .target(
            name: "Presentation",
            dependencies: ["BusinessLogic"],
            path: "Sources/Presentation"
        ),
        .target(
            name: "BusinessLogic",
            dependencies: ["DataAccess"],
            path: "Sources/BusinessLogic"
        ),
        .target(
            name: "DataAccess",
            dependencies: [.product(name: "Collections", package: "swift-collections")],
            path: "Sources/DataAccess"
        ),
        .testTarget(
            name: "PresentationTests",
            dependencies: ["Presentation"],
            path: "Tests/PresentationTests"
        ),
        .testTarget(
            name: "BusinessLogicTests",
            dependencies: ["BusinessLogic"],
            path: "Tests/BusinessLogicTests"
        ),
        .testTarget(
            name: "DataAccessTests",
            dependencies: ["DataAccess"],
            path: "Tests/DataAccessTests"
        )
    ]
)