cc_library(
    name = "factorial_lib",
    srcs = ["factorial_lib.cc"],
    hdrs = ["factorial_lib.h"],
)

cc_binary(
    name = "factorial",
    srcs = ["factorial_binary.cc"],
    deps = [":factorial_lib"],
)

cc_test(
    name = "factorial_test",
    srcs = ["factorial_test.cc"],
    deps = [
        ":factorial_lib",
        "@catch2//:main",
    ],
)
