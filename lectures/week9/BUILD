cc_library(
    name = "animal",
    srcs = [],
    hdrs = ["animal.h"],
    deps = [
    ],
)

cc_binary(
    name = "basic",
    srcs = ["basic.cpp"],
    deps = [
        ":animal",
        ":cat",
        ":dog",
    ],
)

cc_binary(
    name = "cast",
    srcs = ["cast.cpp"],
    deps = [
        ":animal",
        ":cat",
        ":dog",
    ],
)

cc_library(
    name = "cat",
    srcs = [],
    hdrs = ["cat.h"],
    deps = [":animal"],
)

cc_library(
    name = "dog",
    srcs = [],
    hdrs = ["dog.h"],
    deps = [":animal"],
)
