cc_library(
    name = "factorial_lib",
    srcs = ["factorial.cpp"],
    hdrs = ["factorial.h"],
    deps = [],
)

cc_binary(
    name = "factorial",
    srcs = ["factorial_main.cpp"],
    deps = [":factorial_lib"],
)

cc_test(
    name = "factorial_test",
    srcs = ["factorial_test.cpp"],
    deps = [
        ":factorial_lib",
        "//:catch",
    ],
)
